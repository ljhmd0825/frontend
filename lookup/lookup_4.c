#include "lookup.h"
#include <string.h>

typedef struct {
    const char *name;
    const char *value;
} LookupName;

static const LookupName lookup_table[] = {
        {"40love",   "Forty-Love"},
        {"40lovebl", "Forty-Love (bootleg)"},
        {"40lovej",  "Forty-Love (Japan)"},
        {"47pie2",   "Idol Janshi Su-Chi-Pie 2 (v1.1)"},
        {"47pie2o",  "Idol Janshi Su-Chi-Pie 2 (v1.0)"},
        {"4dwarrio", "4-D Warriors"},
        {"4enraya",  "4 En Raya"},
        {"4enrayaa", "4 En Raya (set 2)"},
        {"4in1",     "4 Fun in 1"},
        {"4in1boot", "Puzzle King (PacMan 2 with Tetris & HyperMan 2 & Snow Bros"},
};

const char *lookup_4(const char *name) {
    for (size_t i = 0; i < sizeof(lookup_table) / sizeof(lookup_table[0]); i++) {
        if (strcmp(lookup_table[i].name, name) == 0) {
            return lookup_table[i].value;
        }
    }
    return NULL;
}

const char *r_lookup_4(const char *value) {
    for (size_t i = 0; i < sizeof(lookup_table) / sizeof(lookup_table[0]); i++) {
        if (strcmp(lookup_table[i].value, value) == 0) {
            return lookup_table[i].name;
        }
    }
    return NULL;
}