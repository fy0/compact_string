
#ifndef COMPACT_STRING_H
#define COMPACT_STRING_H

#include <stdint.h>

enum CMInnerEncoding {
    CMIE_LATIN1,
    CMIE_UCS2,
    CMIE_UCS4,
};

typedef uint8_t  CM_UCS1;
typedef uint16_t CM_UCS2;
typedef uint32_t CM_UCS4;

typedef struct CMString {
    enum CMInnerEncoding encoding;
    int length;
    union {
         void *any;
          CM_UCS1 *latin1;
          CM_UCS2 *ucs2;
          CM_UCS4 *ucs4;
    } data;
    struct u8cache {
        uint8_t *u8str;
        int raw_size;
    };
} CMString;

#endif
