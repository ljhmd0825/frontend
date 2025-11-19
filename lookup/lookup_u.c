#include <string.h>
#include "../common/common.h"
#include "lookup.h"

const LookupName lookup_u_table[] = {
    { "uballoon", "울트라 벌룬" },
    { "uccops", "언더커버 캅스 (세계판)" },
    { "uccopsar", "언더커버 캅스 - 알파 리뉴얼 버전(세계판)" },
    { "uccopsaru", "언더커버 캅스 - 알파 리뉴얼 버전(미국판)" },
    { "uccopsj", "언더커버 캅스 (일본판)" },
    { "uccopsk", "언더커버 캅스 (한글)" },
    { "uccopsu", "언더커버 캅스 (미국판)" },
    { "uchuuai", "마작 우주보다 사랑을 담아" },
    { "ucytokyu", "우주 특급 메달리안" },
    { "uecology", "얼티메이트 이콜로지 (일본판)" },
    { "ufosensb", "UFO 전사 요코쨩 (비암호화)" },
    { "ufosensi", "UFO 전사 요코쨩" },
    { "ufosensib", "UFO 전사 요코쨩 (비암호화)" },
    { "ujlnow", "음 재머 램미 나우!" },
    { "ukiyobox", "우키요 박스" },
    { "ultennis", "얼티메이트 테니스" },
    { "ultennisj", "얼티메이트 테니스 (v 1.4,일본판)" },
    { "ultracin", "두근 두근 울트라맨 레이싱" },
    { "ultrainv", "울트라 인베이더" },
    { "ultraman", "울트라맨 - 공상특촬 시리즈 (일본판)" },
    { "ultramhm", "울트라 극비 마작" },
    { "ultratnk", "울트라 탱크" },
    { "ultrax", "울트라 X 웨폰즈/ 울트라 경비대" },
    { "ultraxg", "울트라 X 웨폰즈/ 울트라 경비대 (리뷰빌드)" },
    { "ultrchmp", "세계 횡단 울트라 챔피언 (한국판)" },
    { "ultrchmph", "칭패세계 - 초시공관군" },
    { "umanclub", "울트라맨 클럽 - 싸워라! 울트라맨 형제!!" },
    { "umipoker", "우미 데 포커/ 마린 파라다이스" },
    { "umipokera", "우미 데 포커/ 마린 파라다이스" },
    { "umk3", "얼티밋 모탈 컴뱃 3 (개정판1.2)" },
    { "umk3p", "얼티밋 모탈 컴뱃 3 플러스 (핵,베타 2)" },
    { "umk3pb1", "얼티밋 모탈 컴뱃 3 플러스 (핵,베타 1)" },
    { "umk3r10", "얼티밋 모탈 컴뱃 3 (개정판1.0)" },
    { "umk3r11", "얼티밋 모탈 컴뱃 3 (개정판1.1)" },
    { "umk3te", "얼티밋 모탈 컴뱃 3 토너먼트 에디션 (핵)" },
    { "umk3uc", "얼티밋 모탈 컴뱃 3 컵 에디션 (핵)" },
    { "umk3uk", "얼티밋 모탈 컴뱃 3 컵 에디션 (핵)" },
    { "unclepoo", "푸 삼촌" },
    { "undefeat", "언더 디피트 (일본판)(GDL-0035)" },
    { "undoukai", "운동회 (일본판)" },
    { "undrfire", "언더 파이어 (세계판)" },
    { "undrfirej", "언더 파이어 (일본판)" },
    { "undrfireu", "언더 파이어 (미국판)" },
    { "undrfirj", "언더 파이어 (일본판)" },
    { "undrfiru", "언더 파이어 (미국판)" },
    { "uniwars", "유니워 S" },
    { "uniwarsa", "유니워 S" },
    { "unk1682", "불명의 VT1682 기반 101합 핸드헬드 (PAL)" },
    { "unkch1", "뉴 체리 골드 99" },
    { "unkch2", "슈퍼 페리 골드" },
    { "unkch3", "뉴 체리 골드 99(세트2)" },
    { "unkch4", "그랜드 채리 마스터" },
    { "unkhorse", "불명의 일본 경마 게임" },
    { "unkitpkr", "불명의 이탈리아 포커 게임" },
    { "unkmeyco", "메이코 게임" },
    { "unkpacg", "무명의 팩맨 도박 게임" },
    { "unkpacga", "무명의 팩맨 겜블링 게임_퍽맨" },
    { "unkpacgb", "무명의 팩맨 겜블링 게임 (세트2)" },
    { "unkpacgc", "코코 루코" },
    { "unkpacgd", "무명의 팩맨 위드 카 겜블링 게임" },
    { "unksig", "무명의 스페이스 인베이더 겜블링 게임 (세트1)" },
    { "unksiga", "무명의 스페이스 인베이더 겜블링 게임 (세트2)" },
    { "unksigb", "무명의 스페이스 인베이더 겜블링 게임 (비암호화)" },
    { "unsquad", "에어리어 88/ U.N. 특수부대 (미국판)" },
    { "untoucha", "언터처블" },
    { "uopoko", "퍼즐 유 포코 (세계판)" },
    { "uopokoj", "퍼즐 유 포코 (일본판)" },
    { "upndown", "업 앤 다운" },
    { "upndownu", "업 앤 다운 (비암호화)" },
    { "upscope", "업 스코프" },
    { "upyoural", "업 유어 앨리" },
    { "urachamu", "우라차차 무대리 (한국판)" },
    { "urashima", "포도마작" },
    { "usagi", "우사기" },
    { "usagiym", "우사기 - 야마시로 마작편 (일본판)(GDL-0022)" },
    { "usagui", "우사기 - 산성 마작편" },
    { "usclssic", "U.S. 클래식" },
    { "usg182", "게임즈 V18.2" },
    { "usg185", "게임즈 V18.5" },
    { "usg187c", "게임즈 V18.7C" },
    { "usg211c", "게임즈 V21.1C" },
    { "usg251", "게임즈 V25.1" },
    { "usg252", "게임즈 V25.4X" },
    { "usg32", "슈퍼 두퍼 카지노 (캘리포니아 v3.2)" },
    { "usg82", "슈퍼 텐 V8.2" },
    { "usg83", "슈퍼 텐 V8.3" },
    { "usg83x", "슈퍼 텐 V8.3X" },
    { "usgames", "게임즈 V25.4X" },
    { "usvsthem", "어스 vs 뎀" },
    { "utoukond", "울트라 투혼전설 (일본판)" },
};

const size_t lookup_u_count = A_SIZE(lookup_u_table);

const char *lookup_u(const char *name) {
    if (!name) return NULL;
    for (size_t i = 0; i < lookup_u_count; i++) {
        if (strcmp(lookup_u_table[i].name, name) == 0) {
            return lookup_u_table[i].value;
        }
    }
    return NULL;
}

const char *r_lookup_u(const char *value) {
    if (!value) return NULL;
    for (size_t i = 0; i < lookup_u_count; i++) {
        if (strstr(lookup_u_table[i].value, value)) {
            return lookup_u_table[i].name;
        }
    }
    return NULL;
}

void lookup_u_multi(const char *term, void (*emit)(const char *name, const char *value, void *udata), void *udata) {
    if (!term) return;
    for (size_t i = 0; i < lookup_u_count; i++) {
        if (strcasestr(lookup_u_table[i].name, term))
            emit(lookup_u_table[i].name, lookup_u_table[i].value, udata);
    }
}

void r_lookup_u_multi(const char *term, void (*emit)(const char *name, const char *value, void *udata), void *udata) {
    if (!term) return;
    for (size_t i = 0; i < lookup_u_count; i++) {
        if (strcasestr(lookup_u_table[i].value, term))
            emit(lookup_u_table[i].name, lookup_u_table[i].value, udata);
    }
}
