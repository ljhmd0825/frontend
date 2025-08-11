#include <string.h>
#include "../common/common.h"
#include "lookup.h"

typedef struct {
    const char *name;
    const char *value;
} LookupName;

static const LookupName lookup_table[] = {
        {"99lstwar", "리펄스/ 99 더 라스트 워 (세트1)"},
        {"99lstwara", "리펄스/ 99 더 라스트 워 (세트2)"},
        {"99lstwarb", "리펄스/ 99 더 라스트 워"},
        {"99lstwark", "리펄스/ 99 더 라스트 워 (큐고)"},
        {"99lstwra", "리펄스/ 99 더 라스트 워 (대체)"},
        {"9ballsh2", "나인볼 셧아웃 (세트2)"},
        {"9ballsh3", "나인볼 셧아웃 (세트3)"},
        {"9ballsht", "나인볼 셧아웃"},
        {"9ballsht2", "나인볼 셧아웃 (세트2)"},
        {"9ballsht3", "나인볼 셧아웃 (세트3)"},
        {"9ballshtc", "나인볼 셧아웃 챔피언십"},
};

const char *lookup_9(const char *name) {
    if (!name) return NULL;
    for (size_t i = 0; i < A_SIZE(lookup_table); i++) {
        if (strcmp(lookup_table[i].name, name) == 0) {
            return lookup_table[i].value;
        }
    }
    return NULL;
}

const char *r_lookup_9(const char *value) {
    if (!value) return NULL;
    for (size_t i = 0; i < A_SIZE(lookup_table); i++) {
        if (strstr(lookup_table[i].value, value)) {
            return lookup_table[i].name;
        }
    }
    return NULL;
}
