#include <string.h>
#include "../common/common.h"
#include "lookup.h"

const LookupName lookup_1_table[] = {
    { "10yard", "10 야드 파이트 (세계판,세트1)" },
    { "10yard85", "10 야드 파이트 85 (미국판,타이토 라이센스)" },
    { "10yardj", "10 야드 파이트 (일본판)" },
    { "110dance", "레트로 댄스 매트 (110 곡 슈퍼 스텝매니아 + 9합 게임,PAL)" },
    { "119", "119 (해적판?)" },
    { "11beat", "일레븐 비트" },
    { "18wheelr", "18 휠러: 아메리칸 프로 트럭커 (디럭스,개정판A)" },
    { "18wheelro", "18 휠러: 아메리칸 프로 트럭커 (디럭스)" },
    { "18wheelrt", "18 휠러: 아메리칸 프로 트럭커 (디럭스,개정판T)" },
    { "18wheels", "18 휠러: 아메리칸 프로 트럭커 (스탠다드)" },
    { "18wheelu", "18 휠러: 아메리칸 프로 트럭커 (입식)" },
    { "1941", "1941 - 카운터 어택 (세계판)" },
    { "1941j", "1941 - 카운터 어택 (일본판)" },
    { "1941r1", "1941 - 카운터 어택 (세계판)" },
    { "1941u", "1941 - 카운터 어택 (미국판)" },
    { "1942", "1942 (개정판B)" },
    { "1942a", "1942 (개정판A)" },
    { "1942abl", "1942 (개정판A,해적판)" },
    { "1942b", "1942 (초판)" },
    { "1942c64", "1942 (C64 음악)" },
    { "1942h", "1942 /슈퍼차저 1942" },
    { "1942iti", "1942 (이티사 해적판)" },
    { "1942p", "1942 (테크프라이 PCB,해적판?)" },
    { "1942w", "1942 (윌리엄즈 일레트로닉스 라이센스)" },
    { "1943", "1943 - 미드웨이의 전투 (유럽판)" },
    { "1943b", "1943 - 미드웨이 해전 (해적판 세트1)" },
    { "1943b2", "1943 - 미드웨이 해전 (해적판 세트2)" },
    { "1943bj", "1943 - 미드웨이 해전 (해적판)" },
    { "1943j", "1943 - 미드웨이 해전 (일본판,개정판B)" },
    { "1943ja", "1943 - 미드웨이 해전 (일본판)" },
    { "1943jah", "1943 - 미드웨이 해전 (일본판,비보호 핵)" },
    { "1943jaha", "1943 - 미드웨이 해전 (일본판,비보호 핵, 대체)" },
    { "1943kai", "1943 카이 - 미드웨이 해전 (일본판)" },
    { "1943mii", "1943 - 미드웨이의 전투 마크 II (미국판)" },
    { "1943u", "1943 - 미드웨이 해전 (미국판,개정판C)" },
    { "1943ua", "1943 - 미드웨이 해전 (미국판)" },
    { "1944", "1944 - 더 루프 마스터 (유럽판)" },
    { "1944ad", "1944 - 루프 마스터 (미국판,피닉스에디션,대체)" },
    { "1944d", "1944 - 루프 마스터 (미국판,피닉스에디션)" },
    { "1944j", "1944 - 더 루프 마스터 (일본판)" },
    { "1944u", "1944 - 더 루프 마스터 (미국판)" },
    { "1945kiii", "1945k III (신형,OPCX2 PCB)" },
    { "1945kiiin", "1945k III (신형,OPCX1 PCB)" },
    { "1945kiiio", "1945k III (구형,OPCX1 PCB)" },
    { "1945kiiipt", "1945k III (OPCX1 PCB)" },
    { "19xx", "19XX - 운명과의 전쟁 (유럽판)" },
    { "19xxa", "19XX - 운명과의 전쟁 (아시아판)" },
    { "19xxar1", "19XX - 운명과의 전쟁 (아시아판)" },
    { "19xxb", "19XX - 운명과의 전쟁 (브라질판)" },
    { "19xxd", "19XX - 운명과의 전쟁 (미국판,피닉스에디션)" },
    { "19xxh", "19XX - 운명과의 전쟁 (히스패닉판)" },
    { "19xxj", "19XX - 운명과의 전쟁 (일본판,노란 케이스)" },
    { "19xxjr1", "19XX - 운명과의 전쟁 (일본판)" },
    { "19xxjr2", "19XX - 운명과의 전쟁 (일본판)" },
    { "19xxu", "19XX - 운명과의 전쟁 (미국판)" },
    { "19yy", "19YY (네오CD 컨버전,ADK월드)" },
    { "19yyo", "19YY (네오CD 컨버전,ADK월드)(오리지널)" },
    { "1on1gov", "1 대 1 거버먼트" },
};

const size_t lookup_1_count = A_SIZE(lookup_1_table);

const char *lookup_1(const char *name) {
    if (!name) return NULL;
    for (size_t i = 0; i < lookup_1_count; i++) {
        if (strcmp(lookup_1_table[i].name, name) == 0) {
            return lookup_1_table[i].value;
        }
    }
    return NULL;
}

const char *r_lookup_1(const char *value) {
    if (!value) return NULL;
    for (size_t i = 0; i < lookup_1_count; i++) {
        if (strstr(lookup_1_table[i].value, value)) {
            return lookup_1_table[i].name;
        }
    }
    return NULL;
}

void lookup_1_multi(const char *term, void (*emit)(const char *name, const char *value, void *udata), void *udata) {
    if (!term) return;
    for (size_t i = 0; i < lookup_1_count; i++) {
        if (strcasestr(lookup_1_table[i].name, term))
            emit(lookup_1_table[i].name, lookup_1_table[i].value, udata);
    }
}

void r_lookup_1_multi(const char *term, void (*emit)(const char *name, const char *value, void *udata), void *udata) {
    if (!term) return;
    for (size_t i = 0; i < lookup_1_count; i++) {
        if (strcasestr(lookup_1_table[i].value, term))
            emit(lookup_1_table[i].name, lookup_1_table[i].value, udata);
    }
}
