#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <cassert>
#include <vector>

#define xisspace(x) isspace(static_cast<unsigned char>(x))
#define BUFSIZ  4096
#define size_t unsigned int

extern "C" const char * xitoa(int num);
extern "C"  char * xstrncpy(char *dst, const char *src, size_t n);
extern "C"  void *xmalloc(size_t sz);
extern "C"  void * xrealloc(void *s, size_t sz);
extern "C"  void free_const(const void *s_const);
//extern void fatalf(const char *fmt,...);


static inline void my_xfree(const void *p) { if (p) free_const((const void *)p); }
#define my_safe_free(x)    while ((x)) { free_const(((const void *)x)); (x) = NULL; }


static void
my_ReplaceSubstr(char*& str, int& len, unsigned substrIdx, unsigned substrLen, const char* newSubstr)
{
 //   assert(str != NULL);
 //   assert(newSubstr != NULL);
if(str==NULL or newSubstr==NULL)
	return;
    unsigned newSubstrLen = strlen(newSubstr);
    if (newSubstrLen > substrLen)
        str = (char*)realloc(str, len - substrLen + newSubstrLen + 1);

    // move tail part including zero
    memmove(str + substrIdx + newSubstrLen, str + substrIdx + substrLen, len - substrIdx - substrLen + 1);
    // copy new substring in place
    memcpy(str + substrIdx, newSubstr, newSubstrLen);

    len = strlen(str);
}

static void
my_SubstituteMacro(char*& line, int& len, const char* macroName, const char* substStr)
{
//    assert(line != NULL);
//    assert(macroName != NULL);
//    assert(substStr != NULL);
if(line==NULL or macroName==NULL or substStr==NULL)
	return;
	unsigned macroNameLen = strlen(macroName);
    while (const char* macroPos = strstr(line, macroName)) // we would replace all occurrences
        my_ReplaceSubstr(line, len, macroPos - line, macroNameLen, substStr);
}

static void
my_ProcessMacros(char*& line, int& len)
{
    my_SubstituteMacro(line, len, "${service_name}", "service_name.c_str()");
    my_SubstituteMacro(line, len, "${process_name}", "TheKidName.c_str()");
    my_SubstituteMacro(line, len, "${process_number}", xitoa(5));//see this int KidIdentifier
}



static const char*
my_skip_ws(const char* s)
{
    while (xisspace(*s))
        ++s;

    return s;
}

static void
my_trim_trailing_ws(char* str)
{
 //   assert(str != NULL);
 if(str==NULL)
	 return;
	unsigned i = strlen(str);
    while ((i > 0) && xisspace(str[i - 1]))
        --i;
    str[i] = '\0';
}

static const char*
my_FindStatement(const char* line, const char* statement)
{
 //   assert(line != NULL);
 //   assert(statement != NULL);
if(line==NULL or statement==NULL)
	return NULL;
    const char* str = my_skip_ws(line);
    unsigned len = strlen(statement);
    if (strncmp(str, statement, len) == 0) {
        str += len;
        if (*str == '\0')
            return str;
        else if (xisspace(*str))
            return my_skip_ws(str);
    }

    return NULL;
}

static bool
my_StrToInt(const char* str, long& number)
{
//    assert(str != NULL);
if(str==NULL)
	return false;
    char* end;
    number = strtol(str, &end, 0);

    return (end != str) && (*end == '\0'); // returns true if string contains nothing except number
}


static bool
my_EvalBoolExpr(const char* expr)
{
//    assert(expr != NULL);
if(expr==NULL)
	return false;
if (strcmp(expr, "true") == 0) {
        return true;
    } else if (strcmp(expr, "false") == 0) {
        return false;
    } else if (const char* equation = strchr(expr, '=')) {
        const char* rvalue = my_skip_ws(equation + 1);
        char* lvalue = (char*)xmalloc(equation - expr + 1);
        xstrncpy(lvalue, expr,equation - expr + 1);
        my_trim_trailing_ws(lvalue);

        long number1;
        if (!my_StrToInt(lvalue, number1))
		return false;	
		//exit(1);
//            fatalf("String is not a integer number: '%s'\n", lvalue);
        long number2;
        if (!my_StrToInt(rvalue, number2))
			exit(1);
//            fatalf("String is not a integer number: '%s'\n", rvalue);

        my_xfree(lvalue);
        return number1 == number2;
    }
//    fatalf("Unable to evaluate expression '%s'\n", expr);
    return false; // this place cannot be reached
}



extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    char *token = NULL;
    char *tmp_line = NULL;
    int tmp_line_len = 0;
    int err_count = 0;
    int config_lineno=0;
    unsigned int depth=(unsigned int )*data;
    char config_input_line[BUFSIZ];
if(size<5) return 2;
    
    memset(config_input_line, '\0', BUFSIZ);
    memcpy(config_input_line,data+4,(size-4)<(BUFSIZ-1)?size-4:BUFSIZ-1);
    config_lineno = 0;

	std::vector<bool> if_states;

        ++config_lineno;

        if ((token = strchr(config_input_line, '\n')))
            *token = '\0';

        if ((token = strchr(config_input_line, '\r')))
            *token = '\0';

        // strip any prefix whitespace off the line.
        const char *p = my_skip_ws(config_input_line);
        if (config_input_line != p)
            memmove(config_input_line, p, strlen(p)+1);

        if (strncmp(config_input_line, "#line ", 6) == 0) {
            static char new_file_name[1024];
            static char *file;
            static char new_lineno;
            token = config_input_line + 6;
            new_lineno = strtol(token, &file, 0) - 1;

            if (file == token)
	    {

		    return 1;
//		    continue;   /* Not a valid #line directive, may be a comment */
	    }
            while (*file && xisspace((unsigned char) *file))
                ++file;

            if (*file) {
                if (*file != '"')
		{
			return 2;
//                    continue;   /* Not a valid #line directive, may be a comment */
		}
                xstrncpy(new_file_name, file + 1, sizeof(new_file_name));

                if ((token = strchr(new_file_name, '"')))
                    *token = '\0';

            //    SetConfigFilename(new_file_name, false);
            }

            config_lineno = new_lineno;
        }

        if (config_input_line[0] == '#')
		return 3;
		//            continue;

        if (config_input_line[0] == '\0')
            return 4;
		//continue;

        const char* append = tmp_line_len ? my_skip_ws(config_input_line) : config_input_line;

        size_t append_len = strlen(append);

        tmp_line = (char*)xrealloc(tmp_line, (size_t)(tmp_line_len + append_len + 1));

        strcpy(tmp_line + tmp_line_len, append);

        tmp_line_len += append_len;

        if (tmp_line[tmp_line_len-1] == '\\') {
//            debugs(3, 5, "parseConfigFile: tmp_line='" << tmp_line << "'");
            tmp_line[--tmp_line_len] = '\0';
	    my_xfree(tmp_line);
	    return 6;
//            continue;
        }

        my_trim_trailing_ws(tmp_line);
        my_ProcessMacros(tmp_line, tmp_line_len);
//        debugs(3, (opt_parse_cfg_only?1:5), "Processing: " << tmp_line);

        if (const char* expr = my_FindStatement(tmp_line, "if")) {
            if_states.push_back(my_EvalBoolExpr(expr)); // store last if-statement meaning
        } else if (my_FindStatement(tmp_line, "endif")) {
            if (!if_states.empty())
                if_states.pop_back(); // remove last if-statement meaning
//           else
//                fatalf("'endif' without 'if'\n");
        } else if (my_FindStatement(tmp_line, "else")) {
            if (!if_states.empty())
                if_states.back() = !if_states.back();
//            else
//                fatalf("'else' without 'if'\n");
        } else if (if_states.empty() || if_states.back()) { // test last if-statement meaning if present
            /* Handle includes here */
            if (tmp_line_len >= 9 && strncmp(tmp_line, "include", 7) == 0 && xisspace(tmp_line[7])) {
//glob?                err_count += parseManyConfigFiles(tmp_line + 8, depth + 1);
				err_count++;
            } 
        }

        tmp_line_len = 0;


    my_xfree(tmp_line);
    return err_count;
}
