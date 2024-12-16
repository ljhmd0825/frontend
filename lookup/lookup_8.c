#include <string.h>
#include "lookup.h"

typedef struct {
    const char *name;
    const char *value;
} LookupName;

static const LookupName lookup_table[] = {
        {"800fath", "800 패덤즈"},
        {"800fatha", "800 패덤즈 (구형)"},
        {"88games", "88 올림픽"},
        {"8ball", "비디오 에이트 볼"},
        {"8ball1", "비디오 에이트 볼 (개정판1)"},
        {"8ballact", "에이트 볼 액션"},
        {"8ballact2", "에이트 볼 액션 (DKJr 컨버젼)"},
        {"8ballat2", "에이트 볼 액션 (DKJr 컨버젼)"},
        {"8bpm", "에이트 볼 액션 (팩맨 컨버전)"},
};

const char *lookup_8(const char *name) {
    if (!name) return NULL;
    for (size_t i = 0; i < sizeof(lookup_table) / sizeof(lookup_table[0]); i++) {
        if (strcmp(lookup_table[i].name, name) == 0) {
            return lookup_table[i].value;
        }
    }
    return NULL;
}

const char *r_lookup_8(const char *value) {
    if (!value) return NULL;
    for (size_t i = 0; i < sizeof(lookup_table) / sizeof(lookup_table[0]); i++) {
        if (strstr(lookup_table[i].value, value)) {
            return lookup_table[i].name;
        }
    }
    return NULL;
}
