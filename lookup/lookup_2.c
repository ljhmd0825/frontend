#include <string.h>
#include "../common/common.h"
#include "lookup.h"

const LookupName lookup_2_table[] = {
    { "2020bb", "2020 슈퍼 베이스볼" },
    { "2020bba", "2020 슈퍼 베이스볼 (세트2)" },
    { "2020bbcd", "2020 슈퍼 베이스볼 (네오지오)" },
    { "2020bbh", "2020 슈퍼 베이스볼 (세트3)" },
    { "20pacgal", "미즈 팩맨/ 갤러그 - 20주년 기념판 (v1.08)" },
    { "20pacgalr0", "미즈 팩맨/ 갤러그 - 20주년 기념판 (v1.00)" },
    { "20pacgalr1", "미즈 팩맨/ 갤러그 - 20주년 기념판 (V1.01)" },
    { "20pacgalr2", "미즈 팩맨/ 갤러그 - 20주년 기념판 (v1.02)" },
    { "20pacgalr3", "미즈 팩맨/ 갤러그 - 20주년 기념판 (V1.03)" },
    { "20pacgalr4", "미즈 팩맨/ 갤러그 - 20주년 기념판 (v1.04)" },
    { "25pacman", "팩맨 - 25주년 기념판" },
    { "25pacmano", "팩맨 - 25주년 기념판 (개정판2.00)" },
    { "280zzzap", "닷선 280 짭" },
    { "2mindril", "투 미닛 드릴" },
    { "2mindrila", "투 미닛 드릴" },
};

const size_t lookup_2_count = A_SIZE(lookup_2_table);

const char *lookup_2(const char *name) {
    if (!name) return NULL;
    for (size_t i = 0; i < lookup_2_count; i++) {
        if (strcmp(lookup_2_table[i].name, name) == 0) {
            return lookup_2_table[i].value;
        }
    }
    return NULL;
}

const char *r_lookup_2(const char *value) {
    if (!value) return NULL;
    for (size_t i = 0; i < lookup_2_count; i++) {
        if (strstr(lookup_2_table[i].value, value)) {
            return lookup_2_table[i].name;
        }
    }
    return NULL;
}

void lookup_2_multi(const char *term, void (*emit)(const char *name, const char *value, void *udata), void *udata) {
    if (!term) return;
    for (size_t i = 0; i < lookup_2_count; i++) {
        if (strcasestr(lookup_2_table[i].name, term))
            emit(lookup_2_table[i].name, lookup_2_table[i].value, udata);
    }
}

void r_lookup_2_multi(const char *term, void (*emit)(const char *name, const char *value, void *udata), void *udata) {
    if (!term) return;
    for (size_t i = 0; i < lookup_2_count; i++) {
        if (strcasestr(lookup_2_table[i].value, term))
            emit(lookup_2_table[i].name, lookup_2_table[i].value, udata);
    }
}
