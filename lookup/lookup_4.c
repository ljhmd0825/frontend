#include <string.h>
#include "lookup.h"

typedef struct {
    const char *name;
    const char *value;
} LookupName;

static const LookupName lookup_table[] = {
        {"40love", "포티 러브"},
        {"40lovebl", "포티 러브"},
        {"40lovej", "포티 러브"},
        {"47pie2", "아이돌 마작사 스치파이 2"},
        {"47pie2o", "아이돌 마작사 스치파이 2 (v1.0)"},
        {"4dwarrio", "4-D 워리어즈"},
        {"4enraya", "쿼트엔라야 (세트1)"},
        {"4enrayaa", "쿼트엔라야 (세트2)"},
        {"4in1", "4 펀 인 1"},
        {"4in1boot", "퍼즐 킹"},
        {"4play", "4인용 입력 테스트"},
        {"4psimasy", "마작 4P 합시다"},
};

const char *lookup_4(const char *name) {
    if (!name) return NULL;
    for (size_t i = 0; i < sizeof(lookup_table) / sizeof(lookup_table[0]); i++) {
        if (strcmp(lookup_table[i].name, name) == 0) {
            return lookup_table[i].value;
        }
    }
    return NULL;
}

const char *r_lookup_4(const char *value) {
    if (!value) return NULL;
    for (size_t i = 0; i < sizeof(lookup_table) / sizeof(lookup_table[0]); i++) {
        if (strstr(lookup_table[i].value, value)) {
            return lookup_table[i].name;
        }
    }
    return NULL;
}
