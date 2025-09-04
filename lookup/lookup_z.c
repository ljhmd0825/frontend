#include <string.h>
#include "../common/common.h"
#include "lookup.h"

typedef struct {
    const char *name;
    const char *value;
} LookupName;

static const LookupName lookup_table[] = {
        {"zaryavos", "자야 보스토카"},
        {"zarzon", "자존"},
        {"zaviga", "자비가"},
        {"zavigaj", "자비가 (일본판)"},
        {"zaxxon", "잭슨 (세트1,개정판D)"},
        {"zaxxon2", "잭슨 (세트2,미확인 개정판)"},
        {"zaxxon3", "잭슨 (세트3,미확인 개정판)"},
        {"zaxxonb", "잭슨"},
        {"zaxxonj", "잭슨 (일본판)"},
        {"zedblade", "제드 블레이드/ 오퍼레이션 라그나로크"},
        {"zektor", "젝터 (개정판B)"},
        {"zero", "제로"},
        {"zero2", "제로"},
        {"zerofxz", "오리엔탈 레전드 제로 (핵)"},
        {"zerogu2", "제로 거너 2"},
        {"zerogun", "제로 건너"},
        {"zeroguna", "제로 건너 (모델 2A)"},
        {"zerogunaj", "제로 건너 (일본판 Model 2A)"},
        {"zerogunj", "제로 건너 (일본판 Model 2B)"},
        {"zerohour", "제로 아워"},
        {"zerohoura", "제로 아워 (세트2)"},
        {"zerohouri", "제로 아워 (인더)"},
        {"zeropnt", "제로 포인트 (세트1)"},
        {"zeropnt2", "제로 포인트 2"},
        {"zeropnta", "제로 포인트 (세트2)"},
        {"zeropntj", "제로 포인트 (일본판)"},
        {"zeroteam", "제로팀 USA (미국판)"},
        {"zeroteama", "제로팀 (일본판,초기판?,세트1)"},
        {"zeroteamb", "제로팀 (일본판?,배터리 없음)"},
        {"zeroteamc", "제로팀 (대만판)"},
        {"zeroteamd", "제로팀 (한국판)"},
        {"zeroteame", "제로팀 (일본판,초기판?,세트2)"},
        {"zeroteams", "제로팀 셀렉션"},
        {"zeroteamsr", "제로팀 슈어사이드 리바이벌 키트"},
        {"zerotime", "제로 타임"},
        {"zerotimea", "제로 타임"},
        {"zerotimeb", "제로 타임"},
        {"zerotimed", "제로 타임 (데이터맷)"},
        {"zerotimemc", "제로 타임"},
        {"zerotm2k", "제로팀 2000"},
        {"zerotrgt", "제로 타겟"},
        {"zerotrgta", "제로 타겟"},
        {"zerowing", "제로 윙 (2인 세트)"},
        {"zerowing1", "제로 윙 (1인 세트)"},
        {"zerowingw", "제로 윙 (2인 세트,윌리엄즈 라이센스)"},
        {"zerozone", "제로 존"},
        {"zhongguo", "중국 츄대D"},
        {"zigzag", "지그 재그"},
        {"zigzag2", "지그 재그 (갤럭시안 하드웨어,세트2)"},
        {"zigzagb", "지그 재그 (갤럭시안 하드웨어,세트1)"},
        {"zigzagb2", "지그 재그 (갤럭시안 하드웨어,세트2)"},
        {"zingzip", "징 징 집"},
        {"zintrckb", "진트릭/ 밀어내기 젠트릭스"},
        {"zintrkcd", "진트릭/ 밀어내기 젠트릭스 (네오 CD 변환)"},
        {"zipzap", "집 & 잽"},
        {"zipzapa", "집 & 잽 (Less Explicit)"},
        {"znpwfv", "전 일본 프로레슬링"},
        {"znpwfvt", "전 일본 프로레슬링 (T 971123 V1.000)"},
        {"zoar", "조어"},
        {"zodiack", "조디악"},
        {"zokumahj", "조쿠 마작 방송국 (일본판)"},
        {"zokuoten", "조쿠 솜씨가 어떤지 좀 봅시다"},
        {"zokuotena", "조쿠 솜씨가 어떤지 좀 봅시다 (V2.03J 2001/02/16 16:00)"},
        {"zolapac", "슈퍼 졸라 팩 갈"},
        {"zombraid", "좀비 레이드 (미국판)"},
        {"zombraidp", "좀비 레이드 (US,시험판 PCB)"},
        {"zombraidpj", "좀비 레이드 (일본판,시험판 PCB)"},
        {"zombrvn", "좀비 리벤지 (개정판A)"},
        {"zombrvne", "좀비 리벤지 (수출)"},
        {"zombrvno", "좀비 리벤지"},
        {"zone7in1", "존 7 in 1 스포츠 (NTSC)"},
        {"zone7in1p", "존 7 in 1 스포츠 (PAL)"},
        {"zoo", "주"},
        {"zookeep", "주 키퍼 (세트1)"},
        {"zookeep2", "주 키퍼 (세트2)"},
        {"zookeep3", "주 키퍼 (세트3)"},
        {"zookeepbl", "주 키퍼"},
        {"zoom909", "벅 로저스/ 줌 909"},
        {"zoomania", "주매니아(버전 10.04)"},
        {"zoomaniaa", "주매니아(버전 10.04)"},
        {"zooo", "주우"},
        {"zteam1v4", "제로 팀 USA (1v4,핵)"},
        {"zteamdr", "제로 팀 USA (프로비던스,핵)"},
        {"zteamdw", "제로 팀 USA (워리어스,핵)"},
        {"zteamem", "제로 팀 USA (나이트메어,핵)"},
        {"zteaml6", "제로팀 USA (캠퍼,핵)"},
        {"zteammm", "제로 팀 USA (인큐버스,핵)"},
        {"zteampls", "제로 팀 USA (플러스,핵)"},
        {"zteamwh", "제로 팀 USA (물음표,핵)"},
        {"zteamwxp", "제로 팀 USA (무한캐논,핵)"},
        {"zteamym", "제로 팀 USA (데빌,핵)"},
        {"zteamymp", "제로팀 USA (데빌플러스,핵)"},
        {"zteamys", "제로 팀 USA (갓,핵)"},
        {"zteamzs", "제로 팀 USA (갓오브워,핵)"},
        {"zunkyou", "준준교의 야망"},
        {"zunkyou", "준준교의 야망"},
        {"zupapa", "주파파!"},
        {"zwackery", "츠왁커리"},
        {"zzyzzyx2", "지직스 (세트2)"},
        {"zzyzzyxx", "지직스 (세트1)"},
        {"zzyzzyxx2", "지직스 (세트2)"},
};

const char *lookup_z(const char *name) {
    if (!name) return NULL;
    for (size_t i = 0; i < A_SIZE(lookup_table); i++) {
        if (strcmp(lookup_table[i].name, name) == 0) {
            return lookup_table[i].value;
        }
    }
    return NULL;
}

const char *r_lookup_z(const char *value) {
    if (!value) return NULL;
    for (size_t i = 0; i < A_SIZE(lookup_table); i++) {
        if (strstr(lookup_table[i].value, value)) {
            return lookup_table[i].name;
        }
    }
    return NULL;
}
