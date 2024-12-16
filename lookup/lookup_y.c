#include <string.h>
#include "lookup.h"

typedef struct {
    const char *name;
    const char *value;
} LookupName;

static const LookupName lookup_table[] = {
        {"yachtmn", "요트맨"},
        {"yamagchi", "가라가라 야마구치군"},
        {"yamato", "야마토 (미국판)"},
        {"yamato2", "야마토 (세계판)"},
        {"yamatoa", "야마토"},
        {"yamatou", "야마토 (미국판)"},
        {"yamyam", "얌! 얌!"},
        {"yamyamk", "얌! 얌! (한국판)"},
        {"yanchamr", "똘이장군/ 쾌걸 얀차마루 (일본판)"},
        {"yankeedo", "양키 도!"},
        {"yard", "10 야드 파이트"},
        {"yarunara", "마작 한다면"},
        {"yellowcbb", "카미카제 캐비/ 옐로우 캡"},
        {"yellowcbj", "카미카제 캐비/ 옐로우 캡 (일본판)"},
        {"yesnoj", "예스/노 심리 두근두근 차트"},
        {"yiear", "이 얼 쿵푸 (프로그램 코드 I)"},
        {"yiear2", "이 얼 쿵후 (프로그램 코드 G)"},
        {"yieartf", "이 얼 쿵후 (GX361 컨버젼)"},
        {"ymcapsul", "유희왕 몬스터 캡슐"},
        {"yokaidko", "요괴도중기 (일본판 구버전)"},
        {"yorijori", "요리 조리 쿡쿡"},
        {"yosakdoa", "요사쿠와 돔베이 (세트2)"},
        {"yosakdon", "요사쿠와 돔베이"},
        {"yosakdona", "요사쿠와 돔베이 (세트2)"},
        {"yosimotm", "마작 요시모토 극장"},
        {"yosimoto", "마작 요시모토 극장"},
        {"youjyudn", "요수전 (일본판)"},
        {"youkaidk", "요괴도중기 (일본판 신버전)"},
        {"youkaidk1", "요괴도중기 (일본판,구버전)(YD1))"},
        {"youkaidk2", "요괴도중기 (일본판,신버전)(YD2,개정판B))"},
        {"youma", "닌자회권/ 요마인법첩 (일본판)"},
        {"youma2", "닌자회권/ 요마인법첩 (일본판,대체)"},
        {"youmab", "닌자회권/ 요마인법첩 (해적판,세트1)"},
        {"youmab2", "닌자회권/ 요마인법첩 (해적판,세트2)"},
        {"yoyoshkn", "요요 수리검"},
        {"yoyospel", "요요 스펠"},
        {"yujan", "유쟝"},
        {"yuka", "유카"},
        {"yukiwo", "유키요 (세계판,시험판)"},
        {"yukon", "유콘"},
        {"yukon1", "유콘 (버전1.0)"},
        {"yumefuda", "유메푸다"},
        {"yutnori", "퍼즐 유토리 (한국판)"},
        {"yuyugogo", "유우유의 퀴즈로 고! 고! (일본판)"},
};

const char *lookup_y(const char *name) {
    if (!name) return NULL;
    for (size_t i = 0; i < sizeof(lookup_table) / sizeof(lookup_table[0]); i++) {
        if (strcmp(lookup_table[i].name, name) == 0) {
            return lookup_table[i].value;
        }
    }
    return NULL;
}

const char *r_lookup_y(const char *value) {
    if (!value) return NULL;
    for (size_t i = 0; i < sizeof(lookup_table) / sizeof(lookup_table[0]); i++) {
        if (strstr(lookup_table[i].value, value)) {
            return lookup_table[i].name;
        }
    }
    return NULL;
}
