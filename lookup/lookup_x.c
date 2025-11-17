#include <string.h>
#include "../common/common.h"
#include "lookup.h"

const LookupName lookup_x_table[] = {
    { "x2222", "X2222" },
    { "x2222o", "X2222" },
    { "x5jokers", "엑스 파이브 조커즈" },
    { "x80wc", "X80 - 워 커맨드" },
    { "xday2", "엑스데이 2 (일본판)" },
    { "xeno", "제노 크라이시스" },
    { "xenocrisis", "제노 크라이시스 (HB)" },
    { "xenophob", "제노포브" },
    { "xevi3dg", "제비우스 3D/G" },
    { "xevi3dga", "제비우스 3D/G" },
    { "xevi3dgj", "제비우스 3D/G" },
    { "xevios", "제비우스" },
    { "xevious", "제비우스 (남코)" },
    { "xeviousa", "제비우스 (아타리 세트1)" },
    { "xeviousb", "제비우스 (아타리 세트2)" },
    { "xeviousc", "제비우스 (아타리 세트3)" },
    { "xeviousng", "제비우스 네오지오 컨버전 (HB)" },
    { "xexex", "제젝스 (버전EAA)" },
    { "xexexa", "제젝스 (버전AAA)" },
    { "xexexj", "제젝스 (버전JAA)" },
    { "xfiles", "엑스파일" },
    { "xfilesk", "엑스파일" },
    { "xiaoao", "소오강호" },
    { "xiistag", "XII 스태그" },
    { "xing48", "씽 와이어리스 인터렉티브 TV 게임 와이 TV존 48합 (PAL)" },
    { "xmcota", "엑스맨 - 칠드런 오브 더 아톰 (유럽판)" },
    { "xmcotaa", "엑스맨 - 칠드런 오브 더 아톰 (아시아판)" },
    { "xmcotaar1", "엑스맨 - 칠드런 오브 더 아톰 (아시아판)" },
    { "xmcotaar2", "엑스맨 - 칠드런 오브 더 아톰 (아시아판)" },
    { "xmcotab", "엑스맨 - 칠드런 오브 더 아톰 (브라질판)" },
    { "xmcotabh", "엑스맨 - 칠드런 오브 더 아톰 (보스 핵)" },
    { "xmcotad", "엑스맨 - 칠드런 오브 더 아톰 (유럽판,피닉스에디션)" },
    { "xmcotah", "엑스맨 - 칠드런 오브 더 아톰 (히스패닉판)" },
    { "xmcotahr1", "엑스맨 - 칠드런 오브 더 아톰 (히스패닉판)" },
    { "xmcotaj", "엑스맨 - 칠드런 오브 더 아톰 (일본판)" },
    { "xmcotaj1", "엑스맨 - 칠드런 오브 더 아톰 (일본판)" },
    { "xmcotaj2", "엑스맨 - 칠드런 오브 더 아톰 (일본판)" },
    { "xmcotaj2h", "엑스맨 - 칠드런 오브 더 아톰 (일본판,히든 핵)" },
    { "xmcotaj3", "엑스맨 - 칠드런 오브 더 아톰 (일본판)" },
    { "xmcotajr", "엑스맨 - 칠드런 오브 더 아톰 (일본판,대여용)" },
    { "xmcotar1", "엑스맨 - 칠드런 오브 더 아톰 (유럽판)" },
    { "xmcotar1d", "엑스맨 - 칠드런 오브 더 아톰 (유럽판,피닉스에디션)" },
    { "xmcotau", "엑스맨 - 칠드런 오브 더 아톰 (미국판)" },
    { "xmen", "엑스맨 (4인용 EBA)" },
    { "xmen2p", "엑스맨 (2인용 AAA)" },
    { "xmen2pa", "엑스맨 (2인용 AAA)" },
    { "xmen2pe", "엑스맨 (2인용 EAA)" },
    { "xmen2pj", "엑스맨 (2인용 JAA)" },
    { "xmen2pu", "엑스맨 (2인용 UAB)" },
    { "xmen6p", "엑스맨 (6인용 ECB)" },
    { "xmen6pu", "엑스맨 (6인용 UCB)" },
    { "xmena", "엑스맨 (4인용 AEA)" },
    { "xmenaa", "엑스맨 (4인용 ADA)" },
    { "xmene", "엑스맨 (4인용 EBA)" },
    { "xmenj", "엑스맨 (4인용 JBA)" },
    { "xmenja", "엑스맨 (4인용 JEA)" },
    { "xmenu", "엑스맨 (4인용 UBB)" },
    { "xmenua", "엑스맨 (4인용 UEB)" },
    { "xmultipl", "엑스멀티플라이 (세계판,M81)" },
    { "xmultiplm72", "엑스멀티플라이 (일본판,M72)" },
    { "xmvsf", "엑스맨 vs 스트리트 파이터 (유럽판)" },
    { "xmvsfa", "엑스맨 vs 스트리트 파이터 (아시아판)" },
    { "xmvsfar1", "엑스맨 vs 스트리트 파이터 (아시아판)" },
    { "xmvsfar2", "엑스맨 vs 스트리트 파이터 (아시아판)" },
    { "xmvsfar3", "엑스맨 vs 스트리트 파이터 (아시아판)" },
    { "xmvsfb", "엑스맨 vs 스트리트 파이터 (브라질판)" },
    { "xmvsfcph", "엑스맨 vs 스트리트 파이터 (핵,코옵)" },
    { "xmvsfem", "엑스맨 vs 스트리트 파이터 (핵)" },
    { "xmvsfh", "엑스맨 vs 스트리트 파이터 (히스패닉판)" },
    { "xmvsfj", "엑스맨 vs 스트리트 파이터 (일본판)" },
    { "xmvsfjr1", "엑스맨 vs 스트리트 파이터 (일본판)" },
    { "xmvsfjr2", "엑스맨 vs 스트리트 파이터 (일본판)" },
    { "xmvsfjr3", "엑스맨 vs 스트리트 파이터 (일본판)" },
    { "xmvsfjr4", "엑스맨 vs 스트리트 파이터 (일본판)" },
    { "xmvsfr1", "엑스맨 vs 스트리트 파이터 (유럽판)" },
    { "xmvsfu", "엑스맨 vs 스트리트 파이터 (미국판)" },
    { "xmvsfu1d", "엑스맨 vs 스트리트 파이터 (미국판,피닉스에디션)" },
    { "xmvsfur1", "엑스맨 vs 스트리트 파이터 (미국판)" },
    { "xmvsfur2", "엑스맨 vs 스트리트 파이터 (미국판)" },
    { "xorworld", "Xor 월드 (시제품)" },
    { "xrally", "익스트림 랠리/ 오프 비트 레이서!" },
    { "xsedae", "엑스 세대 퀴즈" },
    { "xsleena", "제인드 슬리나 (세계판)" },
    { "xsleenab", "제인드 슬리나" },
    { "xsleenaba", "제인드 슬리나 (해적판,버그픽스)" },
    { "xsleenabb", "제인드 슬리나 (해적판,세트 2)" },
    { "xsleenaj", "제인드 슬리나 (일본판)" },
    { "xtheball", "엑스 더 볼" },
    { "xtrain", "X 트레인 (버전 1.3)" },
    { "xtrial", "엑스트라이얼 레이싱" },
    { "xtrmhnt2", "익스트림 헌팅 2" },
    { "xtrmhunt", "익스트림 헌팅" },
    { "xxmissio", "XX 미션" },
    { "xybots", "자이보츠 (개정판2)" },
    { "xybots0", "자이보츠 (개정판0)" },
    { "xybots1", "자이보츠 (개정판1)" },
    { "xybotsf", "자이보츠 (프랑스판,개정판3)" },
    { "xybotsg", "자이보츠 (독일판,개정판3)" },
    { "xymg", "행운만관" },
    { "xyonix", "자이오닉스" },
};

const size_t lookup_x_count = A_SIZE(lookup_x_table);

const char *lookup_x(const char *name) {
    if (!name) return NULL;
    for (size_t i = 0; i < lookup_x_count; i++) {
        if (strcmp(lookup_x_table[i].name, name) == 0) {
            return lookup_x_table[i].value;
        }
    }
    return NULL;
}

const char *r_lookup_x(const char *value) {
    if (!value) return NULL;
    for (size_t i = 0; i < lookup_x_count; i++) {
        if (strstr(lookup_x_table[i].value, value)) {
            return lookup_x_table[i].name;
        }
    }
    return NULL;
}

void lookup_x_multi(const char *term, void (*emit)(const char *name, const char *value, void *udata), void *udata) {
    if (!term) return;
    for (size_t i = 0; i < lookup_x_count; i++) {
        if (strcasestr(lookup_x_table[i].name, term))
            emit(lookup_x_table[i].name, lookup_x_table[i].value, udata);
    }
}

void r_lookup_x_multi(const char *term, void (*emit)(const char *name, const char *value, void *udata), void *udata) {
    if (!term) return;
    for (size_t i = 0; i < lookup_x_count; i++) {
        if (strcasestr(lookup_x_table[i].value, term))
            emit(lookup_x_table[i].name, lookup_x_table[i].value, udata);
    }
}
