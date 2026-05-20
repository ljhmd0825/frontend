#include <string.h>
#include "../common/common.h"
#include "lookup.h"

const LookupName lookup_8_table[] = {
    { "800fath", "800 패덤즈" },
    { "800fatha", "800 패덤즈 (구형)" },
    { "86lions", "86 라이온" },
    { "88games", "88 올림픽" },
    { "8ball", "비디오 에이트 볼" },
    { "8ball1", "비디오 에이트 볼 (개정판1)" },
    { "8ballact", "에이트 볼 액션" },
    { "8ballact2", "에이트 볼 액션 (DKJr 컨버젼)" },
    { "8ballat2", "에이트 볼 액션 (DKJr 컨버젼)" },
    { "8bpm", "에이트 볼 액션 (팩맨 컨버전)" },
};

const size_t lookup_8_count = A_SIZE(lookup_8_table);

const char *lookup_8(const char *name) {
    if (!name) return NULL;
    for (size_t i = 0; i < lookup_8_count; i++) {
        if (strcmp(lookup_8_table[i].name, name) == 0) {
            return lookup_8_table[i].value;
        }
    }
    return NULL;
}

const char *r_lookup_8(const char *value) {
    if (!value) return NULL;
    for (size_t i = 0; i < lookup_8_count; i++) {
        if (strstr(lookup_8_table[i].value, value)) {
            return lookup_8_table[i].name;
        }
    }
    return NULL;
}

void lookup_8_multi(const char *term, void (*emit)(const char *name, const char *value, void *udata), void *udata) {
    if (!term) return;
    for (size_t i = 0; i < lookup_8_count; i++) {
        if (strcasestr(lookup_8_table[i].name, term))
            emit(lookup_8_table[i].name, lookup_8_table[i].value, udata);
    }
}

void r_lookup_8_multi(const char *term, void (*emit)(const char *name, const char *value, void *udata), void *udata) {
    if (!term) return;
    for (size_t i = 0; i < lookup_8_count; i++) {
        if (strcasestr(lookup_8_table[i].value, term))
            emit(lookup_8_table[i].name, lookup_8_table[i].value, udata);
    }
}
