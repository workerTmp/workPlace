
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
assert(size>sizeof(time_t);
	struct tm *tm;
	char *sender;
	char *sender1;
	time_t t=(time_t)data;
	int tz;
	mbox_from_create(data+sizeof(time_t),t );
	mbox_from_parse((const unsigned char *)data,size, &t, &tz, &sender);
	mbox_from_parse((const unsigned char *)data,size>6?size-6:size, &t, &tz, &sender1);

	free(sender);
	free(sender1);
  return 0;
}
