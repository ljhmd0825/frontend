#include <string.h>
#include "../common/common.h"
#include "lookup.h"

const LookupName lookup_4_table[] = {
    { "40love", "포티 러브" },
    { "40lovebl", "포티 러브" },
    { "40lovej", "포티 러브" },
    { "47pie2", "아이돌 마작사 스치파이 2" },
    { "47pie2o", "아이돌 마작사 스치파이 2 (v1.0)" },
    { "48in1", "48합 게임 (버전3.09)" },
    { "48in1a", "48합 게임 (버전3.02)" },
    { "4dwarrio", "4-D 워리어즈" },
    { "4enraya", "쿼트엔라야 (세트1)" },
    { "4enrayaa", "쿼트엔라야 (세트2)" },
    { "4in1", "4 펀 인 1" },
    { "4in1boot", "퍼즐 킹" },
    { "4play", "4인용 입력 테스트" },
    { "4psimasy", "마작 4P 합시다" },
    { "4roses", "포 로지즈" },
    { "4rosesa", "포 로지즈 (암호화,세트2)" },
};

const size_t lookup_4_count = A_SIZE(lookup_4_table);

const char *lookup_4(const char *name) {
    if (!name) return NULL;
    for (size_t i = 0; i < lookup_4_count; i++) {
        if (strcmp(lookup_4_table[i].name, name) == 0)
            return lookup_4_table[i].value;
    }
    return NULL;
}

const char *r_lookup_4(const char *value) {
    if (!value) return NULL;
    for (size_t i = 0; i < lookup_4_count; i++) {
        if (strstr(lookup_4_table[i].value, value))
            return lookup_4_table[i].name;
    }
    return NULL;
}

void lookup_4_multi(const char *term, void (*emit)(const char *name, const char *value, void *udata), void *udata) {
    if (!term) return;
    for (size_t i = 0; i < lookup_4_count; i++) {
        if (strcasestr(lookup_4_table[i].name, term))
            emit(lookup_4_table[i].name, lookup_4_table[i].value, udata);
    }
}

void r_lookup_4_multi(const char *term, void (*emit)(const char *name, const char *value, void *udata), void *udata) {
    if (!term) return;
    for (size_t i = 0; i < lookup_4_count; i++) {
        if (strcasestr(lookup_4_table[i].value, term))
            emit(lookup_4_table[i].name, lookup_4_table[i].value, udata);
    }
}
