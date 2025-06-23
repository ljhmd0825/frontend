#include <string.h>
#include "../common/common.h"
#include "lookup.h"

typedef struct {
    const char *name;
    const char *value;
} LookupName;

static const LookupName lookup_table[] = {
        {"600", "600"},
        {"64streej", "64번가 - 탐정 이야기 (일본판)"},
        {"64street", "64번가 - 탐정 이야기 (세계판)"},
        {"64streetj", "64번가 - 탐정 이야기 (일본판,세트1)"},
        {"64streetja", "64번가 - 탐정 이야기 (일본판,대체)"},
};

const char *lookup_6(const char *name) {
    if (!name) return NULL;
    for (size_t i = 0; i < A_SIZE(lookup_table); i++) {
        if (strcmp(lookup_table[i].name, name) == 0) {
            return lookup_table[i].value;
        }
    }
    return NULL;
}

const char *r_lookup_6(const char *value) {
    if (!value) return NULL;
    for (size_t i = 0; i < A_SIZE(lookup_table); i++) {
        if (strstr(lookup_table[i].value, value)) {
            return lookup_table[i].name;
        }
    }
    return NULL;
}
