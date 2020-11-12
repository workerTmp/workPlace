#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

extern const char *mbox_from_create(const char *sender, time_t timestamp);
extern int mbox_from_parse(const unsigned char *msg, size_t size,
		    time_t *time_r, int *tz_offset_r, char **sender_r);

extern int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
// data [time_t][1byte:sizesender][sendername][data]
	struct tm *tm;
	char *sender;
	char *sender1;
	time_t t=(time_t)data;
	int tz;
	if(size<=sizeof(time_t)+1) return 2;
	size_t tmp=12;
	tmp=(uint8_t)*(data+sizeof(time_t));
	if(size<=1+sizeof(time_t)+tmp) return 3;
	char * tmpsender;
	tmpsender=malloc(tmp+1);
	memcpy(tmpsender,data+sizeof(time_t)+1,tmp);
	tmpsender[tmp]=0;
//10.20 always \n in end termination? see #14 issue
	size_t newsize=size-(1+sizeof(time_t)+tmp);
	unsigned char * tmpdata;
	tmpdata = malloc(newsize+1);
	memcpy(tmpdata,data+1+sizeof(time_t)+tmp,newsize);
	tmpdata[newsize]='\n';
//10.20	
	mbox_from_create(tmpsender,t);
	mbox_from_parse((const unsigned char *)(tmpdata),newsize+1, &t, &tz, &sender);
	free(tmpdata);
	free(tmpsender);
	free(sender);
	free(sender1);
  return 0;
}
