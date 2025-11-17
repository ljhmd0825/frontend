#include <string.h>
#include "../common/common.h"
#include "lookup.h"

const LookupName lookup_q_table[] = {
    { "qad", "퀴즈 & 드래곤즈 (미국판)" },
    { "qadj", "퀴즈 & 드래곤즈 - 캡콤 퀴즈게임 (일본판)" },
    { "qadjr", "퀴즈 & 드래곤즈 (일본판 재판매)" },
    { "qb3", "큐비 - 3" },
    { "qbeebing", "퀸 비 빙고" },
    { "qbert", "큐*버트 (미국판 세트1)" },
    { "qberta", "큐*버트 (미국판 세트2)" },
    { "qbertj", "큐*버트 (일본판)" },
    { "qbertjp", "큐*버트 (일본판)" },
    { "qbertqub", "큐*버트의 큐브" },
    { "qberttst", "큐*버트 (초기 테스트 버전)" },
    { "qc", "쿼터 호스 클래식" },
    { "qcrayon", "퀴즈 크레용 신쨩 (일본판)" },
    { "qcrayon2", "크레용 신쨩 나랑 놀자 (일본판)" },
    { "qdrmfgp", "퀴즈 도레미파 그랑프리" },
    { "qdrmfgp2", "퀴즈 도레미파 그랑프리2 - 신곡 넣었다고" },
    { "qgakumon", "퀴즈 학문의 진도 (일본판 버전JA2 타입 L)" },
    { "qgh", "퀴즈 고스트 헌터 (일본판,롬 기반)" },
    { "qix", "퀵스 (개정판2)" },
    { "qix2", "퀵스 2 (토너먼트)" },
    { "qixa", "퀵스 (세트2,저용량 롬)" },
    { "qixb", "퀵스 (세트2,대용량 롬)" },
    { "qixo", "퀵스 (세트3,초기)" },
    { "qjinsei", "퀴즈 인생극장 (일본판)" },
    { "qlgs", "각룡고수" },
    { "qmegamis", "퀴즈 오 나의 여신님 (일본판)" },
    { "qmhayaku", "퀴즈 마작 빨리해요" },
    { "qndream", "퀴즈 나나이로 드림스 - 무지개빛 마을의 기적 (일본판)" },
    { "qntoond", "큐인툰" },
    { "qntoondo", "큐인툰 (네덜란드판,게임카드)" },
    { "qos", "스포츠 퀴즈" },
    { "qosa", "스포츠 퀴즈" },
    { "qosb", "스포츠 퀴즈" },
    { "qotn", "퀸 오브 나일" },
    { "qrouka", "퀴즈 복도에 서세요 (일본판,롬 기반)" },
    { "qsangoku", "퀴즈 삼국지 (일본판)" },
    { "qsww", "퀴즈 숙제를 잊어버렸어요 (일본판)" },
    { "qtheater", "퀴즈 시어터 - 3가지 이야기 (버전2.3J)" },
    { "qtono1", "퀴즈 영주의 야망 (일본판)" },
    { "qtono2", "퀴즈 영주의 야망 2 - 전국판" },
    { "qtono2j", "퀴즈 영주의 야망 2 - 전국판 (일본판)" },
    { "qtorimon", "퀴즈 포물첩 (일본판)" },
    { "quaak", "콱 (프로거의 해적판)" },
    { "quake", "퀘이크 아케이드 토너먼트" },
    { "quantum", "퀀텀 (개정판2)" },
    { "quantum1", "퀀텀 (개정판1)" },
    { "quantump", "퀀텀 (시험판)" },
    { "quaquiz2", "쿼드로 퀴즈 2" },
    { "quart2", "쿼텟 2 (비보호)" },
    { "quart21", "쿼텟 2" },
    { "quarterb", "쿼터백" },
    { "quarterba", "쿼터백 (개정판2)" },
    { "quarterbc", "쿼터백 (개정판1,칵테일)" },
    { "quarterha", "쿼터 호스 (세트2,PR-8210)" },
    { "quarterhb", "쿼터 호스 (세트3,LD-V2000)" },
    { "quartet", "쿼텟 (개정판A,불명)" },
    { "quartet1", "쿼텟" },
    { "quartet2", "쿼텟 2" },
    { "quartet2a", "쿼텟 2 (비보호)" },
    { "quarteta", "쿼텟" },
    { "quartetj", "쿼텟 (일본판,불명)" },
    { "quarth", "블록 홀/ 쿼스 (일본판)" },
    { "quartrba", "쿼터백 (세트2)" },
    { "quartt2j", "쿼텟 2 (일본판,불명)" },
    { "quasar", "퀘이사" },
    { "quasara", "퀘이사 (대체)" },
    { "queen", "퀸" },
    { "queenbee", "퀸 비" },
    { "quester", "퀘스터 (일본판)" },
    { "questers", "퀘스터 스페셜 에디션 (일본판)" },
    { "quickjac", "퀵 잭" },
    { "quickp5", "퀵 픽 5" },
    { "quidgrid", "텐 쿼드 그리드" },
    { "quidgrid2", "텐 쿼드 그리드 (v2.4)" },
    { "quidgrid2d", "텐 쿼드 그리드 (v2.4,데이터팩)" },
    { "quidgridd", "텐 쿼드 그리드 (v1.2,데이터팩)" },
    { "quintond", "큐인툰 (영국,데이터팩)" },
    { "quintono", "큐인툰 (영국판,게임 카드)" },
    { "quintoon", "큐인툰" },
    { "quiz", "퀴즈" },
    { "quiz18k", "미야스 논키의 퀴즈 18금 - 닥터 엣찌쨩의 진찰실" },
    { "quiz211", "퀴즈" },
    { "quiz365", "퀴즈 365" },
    { "quiz365t", "퀴즈 365 (홍콩판 & 대만판)" },
    { "quizard", "퀴자드" },
    { "quizard2", "퀴자드 2" },
    { "quizard2_22", "퀴자드 2" },
    { "quizard3", "퀴자드 3" },
    { "quizard3_32", "퀴자드 3" },
    { "quizard3a", "퀴자드 3" },
    { "quizard4", "퀴자드 4 레인보우" },
    { "quizard4_40", "퀴자드 4 레인보우" },
    { "quizard4_41", "퀴자드 4 레인보우" },
    { "quizard4cz", "퀴자드 4 레인보우" },
    { "quizard_10", "퀴자드" },
    { "quizard_12", "퀴자드" },
    { "quizard_17", "퀴자드" },
    { "quizardi", "퀴자드" },
    { "quizardi_12", "퀴자드" },
    { "quizardi_17", "퀴자드" },
    { "quizchq", "퀴즈 채널 퀘스천" },
    { "quizchqk", "퀴즈 채널 퀘스천 (한국판)" },
    { "quizchql", "퀴즈 채널 퀘스천 (버전1.23)(대만판)" },
    { "quizdai2", "퀴즈 미탐정 네오 & 지오 - 퀴즈 대수사선 파트 2" },
    { "quizdais", "퀴즈 대수사선 - 라스트 카운트다운 (J)" },
    { "quizdaisk", "퀴즈 대수사선 - 라스트 카운트다운 (한국판)" },
    { "quizdna", "퀴즈 DNA의 반란" },
    { "quizf1", "퀴즈 F1 1-2 피니시 (일본판)" },
    { "quizhq", "퀴즈 H.Q. (일본판)" },
    { "quizhuhu", "모리구치 히로코의 퀴즈로 휴!휴! (버전2.2J)" },
    { "quizkof", "퀴즈 킹 오브 파이터즈" },
    { "quizkofk", "퀴즈 킹 오브 파이터즈 (한국판)" },
    { "quizmeku", "퀴즈 돌고도는 스토리 (일본판,롬 기반)" },
    { "quizmoon", "퀴즈 미소녀 전사 세일러문 - 지력 체력 시간의 운" },
    { "quizmstr", "퀴즈마스터" },
    { "quizo", "퀴즈 올림픽 (세트1)" },
    { "quizoa", "퀴즈 올림픽 (세트2)" },
    { "quizpani", "퀴즈 파니쿠루 판타지" },
    { "quizpun2", "퀴즈 펀치 2" },
    { "quizqgd", "퀴즈 휴대폰 Q 모드 (GDL-0017)" },
    { "quizrd22", "퀴자드 2.2" },
    { "quizrd32", "퀴자드 3.2" },
    { "quizrr41", "퀴자드 레인보우 4.1" },
    { "quiztou", "열투! 격투! 퀴즈도!! (일본판)" },
    { "quiztvqq", "퀴즈 TV 합중국 Q&Q" },
    { "quizvadr", "퀴즈베이더스" },
    { "quizvid", "비디오 퀴즈" },
    { "qwak", "콰크" },
    { "qwakprot", "콰크 (시험판)" },
    { "qzchikyu", "퀴즈 지구방위군 (일본판)" },
    { "qzkklgy2", "퀴즈 코코로지 2" },
    { "qzkklogy", "퀴즈 코코로지" },
    { "qzquest", "퀴즈 퀘스트 - 공주와 용자의 이야기 (일본판)" },
    { "qzshowby", "퀴즈 세계는 SHOW by 쇼바이!! (일본판)" },
};

const size_t lookup_q_count = A_SIZE(lookup_q_table);

const char *lookup_q(const char *name) {
    if (!name) return NULL;
    for (size_t i = 0; i < lookup_q_count; i++) {
        if (strcmp(lookup_q_table[i].name, name) == 0) {
            return lookup_q_table[i].value;
        }
    }
    return NULL;
}

const char *r_lookup_q(const char *value) {
    if (!value) return NULL;
    for (size_t i = 0; i < lookup_q_count; i++) {
        if (strstr(lookup_q_table[i].value, value)) {
            return lookup_q_table[i].name;
        }
    }
    return NULL;
}

void lookup_q_multi(const char *term, void (*emit)(const char *name, const char *value, void *udata), void *udata) {
    if (!term) return;
    for (size_t i = 0; i < lookup_q_count; i++) {
        if (strcasestr(lookup_q_table[i].name, term))
            emit(lookup_q_table[i].name, lookup_q_table[i].value, udata);
    }
}

void r_lookup_q_multi(const char *term, void (*emit)(const char *name, const char *value, void *udata), void *udata) {
    if (!term) return;
    for (size_t i = 0; i < lookup_q_count; i++) {
        if (strcasestr(lookup_q_table[i].value, term))
            emit(lookup_q_table[i].name, lookup_q_table[i].value, udata);
    }
}
