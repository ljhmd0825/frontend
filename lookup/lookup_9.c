#include <string.h>
#include "../common/common.h"
#include "lookup.h"

const LookupName lookup_9_table[] = {
    { "98best44", "98 네오프리 베스트 44" },
    { "99lstwar", "리펄스/ 99 더 라스트 워 (세트1)" },
    { "99lstwara", "리펄스/ 99 더 라스트 워 (세트2)" },
    { "99lstwarb", "리펄스/ 99 더 라스트 워" },
    { "99lstwark", "리펄스/ 99 더 라스트 워 (큐고)" },
    { "99lstwra", "리펄스/ 99 더 라스트 워 (대체)" },
    { "99lstwrk", "리펄스/ 99 더 라스트 워 (큐고)" },
    { "9ballsh2", "나인볼 셧아웃 (세트2)" },
    { "9ballsh3", "나인볼 셧아웃 (세트3)" },
    { "9ballsht", "나인볼 셧아웃" },
    { "9ballsht2", "나인볼 셧아웃 (세트2)" },
    { "9ballsht3", "나인볼 셧아웃 (세트3)" },
    { "9ballshtc", "나인볼 셧아웃 챔피언십" },
};

const size_t lookup_9_count = A_SIZE(lookup_9_table);

const char *lookup_9(const char *name) {
    if (!name) return NULL;
    for (size_t i = 0; i < lookup_9_count; i++) {
        if (strcmp(lookup_9_table[i].name, name) == 0) {
            return lookup_9_table[i].value;
        }
    }
    return NULL;
}

const char *r_lookup_9(const char *value) {
    if (!value) return NULL;
    for (size_t i = 0; i < lookup_9_count; i++) {
        if (strstr(lookup_9_table[i].value, value)) {
            return lookup_9_table[i].name;
        }
    }
    return NULL;
}

void lookup_9_multi(const char *term, void (*emit)(const char *name, const char *value, void *udata), void *udata) {
    if (!term) return;
    for (size_t i = 0; i < lookup_9_count; i++) {
        if (strcasestr(lookup_9_table[i].name, term))
            emit(lookup_9_table[i].name, lookup_9_table[i].value, udata);
    }
}

void r_lookup_9_multi(const char *term, void (*emit)(const char *name, const char *value, void *udata), void *udata) {
    if (!term) return;
    for (size_t i = 0; i < lookup_9_count; i++) {
        if (strcasestr(lookup_9_table[i].value, term))
            emit(lookup_9_table[i].name, lookup_9_table[i].value, udata);
    }
}
