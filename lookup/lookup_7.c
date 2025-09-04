#include <string.h>
#include "../common/common.h"
#include "lookup.h"

typedef struct {
    const char *name;
    const char *value;
} LookupName;

static const LookupName lookup_table[] = {
        {"720", "720 도"},
        {"720g", "720 도 (독일판,개정판2)"},
        {"720gr1", "720 도 (독일판,개정판1)"},
        {"720r1", "720 도 (개정판1)"},
        {"720r2", "720 도 (개정판2)"},
        {"720r3", "720 도 (개정판3)"},
        {"7jigen", "7차원의 요정들"},
        {"7mezzo", "7 e 메조"},
        {"7ordi", "7 오디 (한국판)"},
        {"7smash", "7 스매쉬"},
        {"7toitsu", "마작 학원/ 치토이츠"},
};

const char *lookup_7(const char *name) {
    if (!name) return NULL;
    for (size_t i = 0; i < A_SIZE(lookup_table); i++) {
        if (strcmp(lookup_table[i].name, name) == 0) {
            return lookup_table[i].value;
        }
    }
    return NULL;
}

const char *r_lookup_7(const char *value) {
    if (!value) return NULL;
    for (size_t i = 0; i < A_SIZE(lookup_table); i++) {
        if (strstr(lookup_table[i].value, value)) {
            return lookup_table[i].name;
        }
    }
    return NULL;
}
