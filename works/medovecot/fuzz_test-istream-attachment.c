#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>




extern struct istream *i_stream_create_from_data(const void *data, size_t size);
extern void i_stream_unref(struct istream **stream);




extern int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
        struct istream *input;

        input = i_stream_create_from_data(data, size);
        i_stream_unref(&input);

  return 0;
}
