#include <string.h>
#include "lookup.h"

typedef struct {
    const char *name;
    const char *value;
} LookupName;

static const LookupName lookup_table[] = {
        {"30test", "30 시험"},
        {"39in1", "39합 게임"},
        {"3countb", "3 카운트 바웃/ 파이어 수플렉스"},
        {"3countba", "3 카운트 바웃/ 파이어 수플렉스"},
        {"3in1semi", "뉴 하이퍼맨 (3인1,쿠키앤비비,하이퍼맨,세트1)"},
        {"3in1semia", "뉴 하이퍼맨 (3인1,쿠키앤비비,하이퍼맨,세트2)"},
        {"3kokushi", "삼각지 (일본판)"},
        {"3on3dunk", "3 온 3 덩크 매드니스 (미국판,시제품?)"},
        {"3stooges", "세명의 바보들 - 신부는 신부다"},
        {"3stoogesa", "세명의 바보들 - 신부는 신부다 (세트2)"},
        {"3super8", "3 슈퍼 8"},
        {"3wonders", "쓰리 원더스 (기타)"},
        {"3wondersb", "쓰리 원더스 (해적판 세트2,기타)"},
        {"3wondersh", "쓰리 원더스 (해적판 세트1,기타)"},
        {"3wondersha", "쓰리 원더스 (해적판 세트3,기타)"},
        {"3wondersr1", "쓰리 원더스 (기타)"},
        {"3wondersu", "쓰리 원더스 (미국판)"},
        {"3wonderu", "쓰리 원더스 (미국판)"},
        {"3x3puzzl", "3X3 퍼즐 (엔터프라이즈)"},
        {"3x3puzzla", "3X3 퍼즐 (일반)"},
};

const char *lookup_3(const char *name) {
    if (!name) return NULL;
    for (size_t i = 0; i < sizeof(lookup_table) / sizeof(lookup_table[0]); i++) {
        if (strcmp(lookup_table[i].name, name) == 0) {
            return lookup_table[i].value;
        }
    }
    return NULL;
}

const char *r_lookup_3(const char *value) {
    if (!value) return NULL;
    for (size_t i = 0; i < sizeof(lookup_table) / sizeof(lookup_table[0]); i++) {
        if (strstr(lookup_table[i].value, value)) {
            return lookup_table[i].name;
        }
    }
    return NULL;
}
