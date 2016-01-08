/*
 * cmstr
 * fy, 2015
 */

#include "cmstr.h"


#ifdef DEMO

#ifdef _MSC_VER
#define _INLINE
#pragma execution_character_set("utf-8")
#else
#define _INLINE inline
#endif

void print_str_info(CMString *str) {
    if (str) {
        printf("encoding: %d\n", str->encoding);
        printf("length: %d\n", str->length);
        printf("data: %x\n", str->data);
        printf("u8cache: %x %d\n", str->u8cache.str, str->u8cache.raw_size);
    }
}

int main(int argc,char* argv[])
{
    CMString *str;
    str = cmstr_new("test", 4, CME_UTF8);
    print_str_info(str);
    cmstr_free(str);
    putchar('\n');

    str = cmstr_new("te中文st", strlen("te中文st"), CME_UTF8);
    print_str_info(str);
    cmstr_free(str);
    putchar('\n');

    str = cmstr_new("☭te中文st", strlen("\u262dte中文st"), CME_UTF8);
    print_str_info(str);
    cmstr_free(str);
    putchar('\n');

    str = cmstr_new("☭te中文st\xf0\x90\x80\x80", strlen("☭te中文st\xf0\x90\x80\x80"), CME_UTF8); // \U+10000
    print_str_info(str);
    cmstr_free(str);
    putchar('\n');

    system("pause");
    return 0;
}

#endif
