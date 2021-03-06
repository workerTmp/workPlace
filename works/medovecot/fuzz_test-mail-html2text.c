#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct buffer {
        const void *data;
        const size_t used;
        void *priv[5];
};
typedef struct buffer buffer_t;
typedef struct buffer string_t;
enum html_state {
        /* regular text */
        HTML_STATE_TEXT,
        /* tag outside "quoted string" */
        HTML_STATE_TAG,
        /* tag inside "double quoted string" */
        HTML_STATE_TAG_DQUOTED,
        /* tag -> "escape\ */
        HTML_STATE_TAG_DQUOTED_ESCAPE,
        /* tag inside 'single quoted string' */
        HTML_STATE_TAG_SQUOTED,
        /* tag -> 'escape\ */
        HTML_STATE_TAG_SQUOTED_ESCAPE,
        /* comment */
        HTML_STATE_COMMENT,
        /* comment is ending, we've seen "--" and now just waiting for ">" */
        HTML_STATE_COMMENT_END,
        /* (java)script */
        HTML_STATE_SCRIPT,
        /* CSS style */
        HTML_STATE_STYLE,
        /* <![CDATA[...]]> */
        HTML_STATE_CDATA
};
enum mail_html2text_flags {
        MAIL_HTML2TEXT_FLAG_SKIP_QUOTED = 0x01
};
struct mail_html2text {
        enum mail_html2text_flags flags;
        enum html_state state;
        buffer_t *input;
        unsigned int quote_level;
        bool add_newline;
};


extern struct mail_html2text * mail_html2text_init(enum mail_html2text_flags flags);
extern void mail_html2text_more(struct mail_html2text *ht,const unsigned char *data, size_t size,buffer_t *output);
extern string_t *t_str_new(size_t initial_size);
extern void str_free(string_t **str);
extern void mail_html2text_deinit(struct mail_html2text **ht);
extern int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {


string_t *str = t_str_new(128);
struct mail_html2text *ht;

if(size==0)
        return 15;
ht = mail_html2text_init(MAIL_HTML2TEXT_FLAG_SKIP_QUOTED);
mail_html2text_more(ht, data, size, str);
mail_html2text_deinit(&ht);
str_free(&str);

  return 0;
}
