#include "lookup.h"
#include <string.h>

typedef struct {
    const char *name;
    const char *value;
} LookupName;

static const LookupName lookup_table[] = {
        {"valkyrie",      "Valkyrie No Densetsu (Japan)"},
        {"valtric",       "Valtric"},
        {"vamphalf",      "Vamp 1-2"},
        {"vamphalfk",     "Vamp x1/2 (Korea, version 1.1.0908)"},
        {"vamphalfr1",    "Vamf x1/2 (Europe, version 1.0.0903)"},
        {"vampire",       "Vampire (prototype?)"},
        {"vampj",         "Vampire: The Night Warriors (Japan 940705)"},
        {"vampja",        "Vampire: The Night Warriors (Japan 940705 alt)"},
        {"vampjr1",       "Vampire: The Night Warriors (Japan 940630)"},
        {"vandyjal",      "Vandyke (Jaleco, Set 1)"},
        {"vandyke",       "Vandyke (Japan)"},
        {"vandykejal",    "Vandyke (Jaleco, set 1)"},
        {"vandykejal2",   "Vandyke (Jaleco, set 2)"},
        {"vangrd2",       "Vanguard II"},
        {"vangrdce",      "Vanguard (Centuri)"},
        {"vanguard",      "Vanguard (SNK)"},
        {"vanilla",       "Mahjong Vanilla Syndrome (Japan)"},
        {"vanvan",        "Van-Van Car"},
        {"vanvanb",       "Van-Van Car (Karateco set 2)"},
        {"vanvank",       "Van-Van Car (Karateco)"},
        {"vaportra",      "Vapor Trail - Hyper Offence Formation (World revision 1)"},
        {"vaportra3",     "Vapor Trail - Hyper Offence Formation (World revision 3?)"},
        {"vaportrau",     "Vapor Trail - Hyper Offence Formation (US)"},
        {"vaportru",      "Vapor Trail - Hyper Offence Formation (US)"},
        {"vaportrx",      "Vapor TRX (GUTS Jul 2 1998 / MAIN Jul 18 1998)"},
        {"vaportrxp",     "Vapor TRX (GUTS Apr 10 1998 / MAIN Apr 10 1998)"},
        {"varth",         "Varth - Operation Thunderstorm (World 920612)"},
        {"varthb",        "Varth: Operation Thunderstorm (bootleg, set 1)"},
        {"varthb2",       "Varth: Operation Thunderstorm (bootleg, set 2)"},
        {"varthj",        "Varth - Operation Thunderstorm (Japan 920714)"},
        {"varthjr",       "Varth: Operation Thunderstorm (Japan Resale Ver. 920714)"},
        {"varthr1",       "Varth: Operation Thunderstorm (World 920612)"},
        {"varthu",        "Varth - Operation Thunderstorm (US 920612)"},
        {"vasara",        "Vasara"},
        {"vasara2",       "Vasara 2 (set 1)"},
        {"vasara2a",      "Vasara 2 (set 2)"},
        {"vastar",        "Vastar (set 1)"},
        {"vastar2",       "Vastar (set 2)"},
        {"vastar3",       "Vastar (set 3)"},
        {"vastar4",       "Vastar (set 4)"},
        {"vathlete",      "Virtua Athletics / Virtua Athlete (GDS-0019)"},
        {"vathletep",     "Virtua Athletics / Virtua Athlete (prototype)"},
        {"vautour",       "Vautour (Jeutel France)"},
        {"vautourz",      "Vautour (bootleg of Phoenix) (Z80 CPU)"},
        {"vautourza",     "Vautour (bootleg of Phoenix) (Z80 CPU, single PROM)"},
        {"vball",         "U.S. Championship V'ball (set 1)"},
        {"vball2pj",      "U.S. Championship V'ball (Japan)"},
        {"vball2pjb",     "U.S. Championship V'ball (bootleg of Japan set)"},
        {"vballb",        "U.S. Championship V'ball (bootleg of US set)"},
        {"vblokbrk",      "VS Block Breaker (Asia)"},
        {"vbowl",         "Virtua Bowling (World, V101XCM )"},
        {"vbowlhk",       "Virtua Bowling (Hong Kong, V101HJS)"},
        {"vbowlj",        "Virtua Bowling (Japan, V100JCM)"},
        {"vcircle",       "Vicious Circle (prototype)"},
        {"vcop",          "Virtua Cop (Revision B)"},
        {"vcop2",         "Virtua Cop 2"},
        {"vcopa",         "Virtua Cop (Revision A)"},
        {"vendet2p",      "Vendetta (World 2 Players ver. W)"},
        {"vendetao",      "Vendetta (World 4 Players ver. R)"},
        {"vendetas",      "Vendetta (Asia 2 Players ver. U)"},
        {"vendetta",      "Vendetta (World 4 Players ver. T)"},
        {"vendetta2pd",   "Vendetta (Asia, 2 Players, ver. D)"},
        {"vendetta2peba", "Vendetta (World, 2 Players, ver. EB-A?)"},
        {"vendetta2pp",   "Crime Fighters 2 (Japan, 2 Players, ver. P)"},
        {"vendetta2pu",   "Vendetta (Asia, 2 Players, ver. U)"},
        {"vendetta2pun",  "Vendetta (World, 2 Players, ver. ?)"},
        {"vendetta2pw",   "Vendetta (World, 2 Players, ver. W)"},
        {"vendettan",     "Crime Fighters 2 (Japan, 4 Players, ver. N)"},
        {"vendettar",     "Vendetta (US, 4 Players, ver. R)"},
        {"vendettaun",    "Vendetta (World, 4 Players, ver. ?)"},
        {"vendettaz",     "Vendetta (Asia, 4 Players, ver. Z)"},
        {"vendettj",      "Crime Fighters 2 (Japan 2 Players ver. P)"},
        {"vendtaso",      "Vendetta (Asia 2 Players ver. D)"},
        {"venom",         "Venom & Spider-Man - Separation Anxiety (SNES bootleg)"},
        {"venture",       "Venture (version 5 set 1)"},
        {"venture2",      "Venture (version 5 set 2)"},
        {"venture4",      "Venture (version 4)"},
        {"venture5a",     "Venture (version 5 set 2)"},
        {"venture5b",     "Venture (version 5 set 2, bootleg)"},
        {"venus",         "Venus"},
        {"vf",            "Virtua Fighter"},
        {"vf2",           "Virtua Fighter 2 (Version 2.1)"},
        {"vf2a",          "Virtua Fighter 2 (Revision A)"},
        {"vf2b",          "Virtua Fighter 2 (Revision B)"},
        {"vf2o",          "Virtua Fighter 2"},
        {"vf3",           "Virtua Fighter 3 (Japan, Revision D)"},
        {"vf3a",          "Virtua Fighter 3 (Japan, Revision A)"},
        {"vf3c",          "Virtua Fighter 3 (Japan, Revision C)"},
        {"vf3tb",         "Virtua Fighter 3 Team Battle (Japan)"},
        {"vf4",           "Virtua Fighter 4 Version C (GDS-0012C)"},
        {"vf4b",          "Virtua Fighter 4 (Rev B) (GDS-0012B)"},
        {"vf4c",          "Virtua Fighter 4 (Rev C) (GDS-0012C)"},
        {"vf4cart",       "Virtua Fighter 4 (World)"},
        {"vf4evo",        "Virtua Fighter 4: Evolution (Version B) (Japan) (GDS-0024C)"},
        {"vf4evoa",       "Virtua Fighter 4: Evolution (Japan) (GDS-0024A)"},
        {"vf4evob",       "Virtua Fighter 4: Evolution (Version B) (Japan) (GDS-0024B)"},
        {"vf4evoct",      "Virtua Fighter 4: Evolution (World)"},
        {"vf4o",          "Virtua Fighter 4 (GDS-0012)"},
        {"vf4tuned",      "Virtua Fighter 4: Final Tuned (Ver. B) (GDS-0036F)"},
        {"vf4tuneda",     "Virtua Fighter 4: Final Tuned (Rev A) (GDS-0036A)"},
        {"vf4tunedd",     "Virtua Fighter 4: Final Tuned (Ver. A) (GDS-0036D)"},
        {"vfive",         "V-Five (Japan)"},
        {"vfkids",        "Virtua Fighter Kids"},
        {"vformula",      "Virtua Formula"},
        {"vfremix",       "Virtua Fighter Remix"},
        {"vfurlong",      "Net@Select: Horse Racing - Victory Furlong"},
        {"vgoalsca",      "V Goal Soccer (alt)"},
        {"vgoalsoc",      "V Goal Soccer"},
        {"vhunt2",        "Vampire Hunter 2: Darkstalkers Revenge (Japan 970929)"},
        {"vhunt2d",       "Vampire Hunter 2: Darkstalkers Revenge (Japan 970913 Phoenix Edition) (bootleg)"},
        {"vhunt2r1",      "Vampire Hunter 2: Darkstalkers Revenge (Japan 970913)"},
        {"vhuntj",        "Vampire Hunter: Darkstalkers' Revenge (Japan 950316)"},
        {"vhuntjr1",      "Vampire Hunter: Darkstalkers' Revenge (Japan 950307)"},
        {"vhuntjr1s",     "Vampire Hunter: Darkstalkers' Revenge (Japan 950307 stop version)"},
        {"vhuntjr2",      "Vampire Hunter: Darkstalkers' Revenge (Japan 950302)"},
        {"victlap",       "Ace Driver: Victory Lap (World, ADV2 Ver.B)"},
        {"victlapa",      "Ace Driver: Victory Lap (World, ADV2)"},
        {"victlapj",      "Ace Driver: Victory Lap (Japan, ADV1 Ver.C)"},
        {"victlapw",      "Ace Driver - Victory Lap (Rev. ADV2, World)"},
        {"victnine",      "Victorious Nine"},
        {"victorba",      "Victor Banana"},
        {"victory",       "Victory"},
        {"victoryc",      "Victory (Comsoft)"},
        {"victorycb",     "Victory (Comsoft) (bootleg)"},
        {"victroad",      "Victory Road"},
        {"videight",      "Video Eight"},
        {"videopin",      "Video Pinball"},
        {"videopina",     "Video Pinball (4 ROMs version)"},
        {"vidvince",      "Video Vince and the Game Factory (prototype)"},
        {"viewpoin",      "Viewpoint"},
        {"viewpoinp",     "Viewpoint (prototype)"},
        {"vigilant",      "Vigilante (World)"},
        {"vigilanta",     "Vigilante (World, Rev A)"},
        {"vigilantb",     "Vigilante (US, Rev B)"},
        {"vigilantbl",    "Vigilante (bootleg)"},
        {"vigilantc",     "Vigilante (World, Rev C)"},
        {"vigilantd",     "Vigilante (Japan, Rev D)"},
        {"vigilantg",     "Vigilante (US, Rev G)"},
        {"vigilanto",     "Vigilante (US)"},
        {"vigilntj",      "Vigilante (Japan)"},
        {"vigilntu",      "Vigilante (US)"},
        {"vimana",        "Vimana"},
        {"vimana1",       "Vimana (old set)"},
        {"vimanaj",       "Vimana (Japan)"},
        {"vimanan",       "Vimana (Nova Apparate GMBH and Co)"},
        {"vindc2r1",      "Vindicators Part II (rev 1)"},
        {"vindc2r2",      "Vindicators Part II (rev 2)"},
        {"vindctr2",      "Vindicators Part II (rev 3)"},
        {"vindctr2r1",    "Vindicators Part II (rev 1)"},
        {"vindctr2r2",    "Vindicators Part II (rev 2)"},
        {"vindice3",      "Vindicators (Europe, rev 3)"},
        {"vindice4",      "Vindicators (Europe, rev 4)"},
        {"vindict1",      "Vindicators (rev 1)"},
        {"vindict2",      "Vindicators (rev 2)"},
        {"vindict4",      "Vindicators (rev 4)"},
        {"vindicte",      "Vindicators (Europe, rev 5)"},
        {"vindictg",      "Vindicators (German, rev 1)"},
        {"vindictr",      "Vindicators (rev 5)"},
        {"vindictr1",     "Vindicators (rev 1)"},
        {"vindictr2",     "Vindicators (rev 2)"},
        {"vindictr4",     "Vindicators (rev 4)"},
        {"vindictre",     "Vindicators (Europe, rev 5)"},
        {"vindictre3",    "Vindicators (Europe, rev 3)"},
        {"vindictre4",    "Vindicators (Europe, rev 4)"},
        {"vindictrg",     "Vindicators (German, rev 1)"},
        {"viofight",      "Violence Fight (World)"},
        {"viofightj",     "Violence Fight (Japan)"},
        {"viofightu",     "Violence Fight (US)"},
        {"viostorm",      "Violent Storm (Europe ver EAB)"},
        {"viostorma",     "Violent Storm (ver AAC)"},
        {"viostormab",    "Violent Storm (ver AAB)"},
        {"viostormabbl",  "Violent Storm (ver AAB, bootleg)"},
        {"viostormeb",    "Violent Storm (ver EAB)"},
        {"viostormj",     "Violent Storm (ver JAC)"},
        {"viostormu",     "Violent Storm (ver UAC)"},
        {"viostormub",    "Violent Storm (ver UAB)"},
        {"viostormubbl",  "Violent Storm (ver UAB, bootleg)"},
        {"viostrma",      "Violent Storm (Asia ver AAC)"},
        {"viostrmj",      "Violent Storm (Japan ver JAC)"},
        {"viostrmu",      "Violent Storm (US ver UAB)"},
        {"vipclub",       "Vip Club [BET] (Japan 880310)"},
        {"viper",         "Viper"},
        {"viprp1",        "Viper Phase 1 (New Version, World)"},
        {"viprp1h",       "Viper Phase 1 (New Version, Holland)"},
        {"viprp1hk",      "Viper Phase 1 (Hong Kong)"},
        {"viprp1j",       "Viper Phase 1 (New Version, Japan)"},
        {"viprp1k",       "Viper Phase 1 (New Version, Korea)"},
        {"viprp1oj",      "Viper Phase 1 (Japan)"},
        {"viprp1ot",      "Viper Phase 1 (Germany)"},
        {"viprp1pt",      "Viper Phase 1 (New Version, Portugal)"},
        {"viprp1s",       "Viper Phase 1 (New Version, Switzerland)"},
        {"viprp1t",       "Viper Phase 1 (New Version, Germany)"},
        {"viprp1u",       "Viper Phase 1 (New Version, US set 1)"},
        {"viprp1ua",      "Viper Phase 1 (New Version, US set 2)"},
        {"virnba",        "Virtua NBA (USA)"},
        {"virnbao",       "Virtua NBA"},
        {"virnbap",       "Virtua NBA (prototype)"},
        {"virnbapa",      "Virtua NBA (prototype, 15.11)"},
        {"virtpool",      "Virtual Pool"},
        {"vitaminc",      "Mahjong Vitamin C (Japan)"},
        {"vliner",        "V-Liner"},
        {"vmahjong",      "Virtual Mahjong"},
        {"vmetal",        "Varia Metal"},
        {"vmetaln",       "Varia Metal (New Ways Trading Co.)"},
        {"volfied",       "Volfied (World)"},
        {"volfiedj",      "Volfied (Japan)"},
        {"volfiedjo",     "Volfied (Japan)"},
        {"volfiedo",      "Volfied (World)"},
        {"volfiedu",      "Volfied (US)"},
        {"volfieduo",     "Volfied (US)"},
        {"von",           "Cyber Troopers Virtual-On - Twin (Export)"},
        {"von2",          "Virtual On 2: Oratorio Tangram (Japan, Revision B)"},
        {"von254g",       "Virtual On 2: Oratorio Tangram (Japan, ver 5.4g)"},
        {"von2a",         "Virtual On 2: Oratorio Tangram (Japan, Revision A)"},
        {"von2o",         "Virtual On 2: Oratorio Tangram (Japan)"},
        {"vonj",          "Cyber Troopers Virtual-On - Twin (Japan, Revision B)"},
        {"vonot",         "Virtual On Oratorio Tangram M.S.B.S. ver5.66 2000 Edition"},
        {"vonr",          "Cyber Troopers Virtual-On - Relay (Japan)"},
        {"vonu",          "Cyber Troopers Virtual-On - Twin (USA, Revision B)"},
        {"vortex",        "Vortex"},
        {"vpool",         "Video Pool (bootleg on Moon Cresta hardware)"},
        {"vr",            "Virtua Racing"},
        {"vs10yard",      "Vs 10-Yard Fight (World, 11/05/84)"},
        {"vs10yardj",     "Vs 10-Yard Fight (Japan)"},
        {"vs10yardu",     "Vs 10-Yard Fight (US, Taito license)"},
        {"vs2",           "Virtua Striker 2 (Step 2.0, Export, USA)"},
        {"vs2_2k",        "Virtua Striker 2 Ver. 2000 (Rev C)"},
        {"vs2_2ko",       "Virtua Striker 2 Ver. 2000"},
        {"vs215",         "Virtua Striker 2 (Step 1.5, Export, USA)"},
        {"vs215o",        "Virtua Striker 2 (Step 1.5, Japan, test/debug?)"},
        {"vs298",         "Virtua Striker 2 '98 (Step 2.0, Japan)"},
        {"vs29815",       "Virtua Striker 2 '98 (Step 1.5, Japan)"},
        {"vs299",         "Virtua Striker 2 '99 (Export, USA)"},
        {"vs29915",       "Virtua Striker 2 '99.1 (Step 1.5, Export, USA, Revision B)"},
        {"vs29915a",      "Virtua Striker 2 '99 (Step 1.5, Export, USA)"},
        {"vs29915j",      "Virtua Striker 2 '99.1 (Step 1.5, Japan, Revision B)"},
        {"vs299a",        "Virtua Striker 2 '99 (Export, USA, Revision A)"},
        {"vs299b",        "Virtua Striker 2 '99 (Japan, Revision B)"},
        {"vs299j",        "Virtua Striker 2 '99.1 (Japan, Revision B)"},
        {"vs2v991",       "Virtua Striker 2 '99.1 (Export, USA, Revision B)"},
        {"vsav",          "Vampire Savior: The Lord of Vampire (Euro 970519)"},
        {"vsav2",         "Vampire Savior 2: The Lord of Vampire (Japan 970913)"},
        {"vsav2d",        "Vampire Savior 2: The Lord of Vampire (Japan 970913 Phoenix Edition) (bootleg)"},
        {"vsava",         "Vampire Savior: The Lord of Vampire (Asia 970519)"},
        {"vsavb",         "Vampire Savior: The Lord of Vampire (Brazil 970519)"},
        {"vsavd",         "Vampire Savior: The Lord of Vampire (Europe 970519 Phoenix Edition) (bootleg)"},
        {"vsavh",         "Vampire Savior: The Lord of Vampire (Hispanic 970519)"},
        {"vsavj",         "Vampire Savior: The Lord of Vampire (Japan 970519)"},
        {"vsavu",         "Vampire Savior: The Lord of Vampire (USA 970519)"},
        {"vsbbalja",      "Vs. BaseBall (Japan set 2)"},
        {"vsbbaljb",      "Vs. BaseBall (Japan set 3)"},
        {"vsbball",       "Vs. BaseBall"},
        {"vsbballj",      "Vs. BaseBall (Japan set 1)"},
        {"vsbballja",     "Vs. Baseball (Japan, set BA A-2)"},
        {"vsbballjb",     "Vs. Baseball (Japan, set BA A-1)"},
        {"vscaptfl",      "Vs. Super Captain Flag (Japan)"},
        {"vsfdf",         "Vs. Freedom Force"},
        {"vsgongf",       "VS Gong Fight"},
        {"vsgradus",      "Vs. Gradius"},
        {"vsgshoe",       "Vs. Gumshoe"},
        {"vshoot",        "J-League Soccer V-Shoot"},
        {"vsmahjng",      "Vs. Mahjang (Japan)"},
        {"vsnetscr",      "Versus Net Soccer (ver UAB)"},
        {"vspinbal",      "Vs. Pinball"},
        {"vspinbalj",     "Vs. Pinball (Japan, set PN3 B)"},
        {"vspinblj",      "Vs. Pinball (Japan)"},
        {"vsskykid",      "Vs. Super SkyKid"},
        {"vsslalom",      "Vs. Slalom"},
        {"vssoccer",      "Vs. Soccer"},
        {"vssoccera",     "Vs. Soccer (set SC4-3 ?)"},
        {"vstennis",      "Vs. Tennis"},
        {"vstennisa",     "Vs. Tennis (Japan/USA, set 2)"},
        {"vstennisb",     "Vs. Tennis (Japan/USA, set 3)"},
        {"vstetris",      "Vs. Tetris"},
        {"vstrik3",       "Virtua Striker 3 (GDS-0006)"},
        {"vstrik3c",      "Virtua Striker 3 (World, Rev B)"},
        {"vstrik3cb",     "Virtua Striker 3 (USA, EXP, KOR, AUS) (Rev B)"},
        {"vstrik3co",     "Virtua Striker 3 (World)"},
        {"vstriker",      "Virtua Striker (Revision A)"},
        {"vstrikero",     "Virtua Striker"},
        {"vsyard",        "10 Yard Fight (Vs. version World, 11-05-84)"},
        {"vsyard2",       "10 Yard Fight (Vs. version Japan, set 2)"},
        {"vtenis2c",      "Virtua Tennis 2 / Power Smash 2 (Rev A)"},
        {"vtennis",       "Virtua Tennis / Power Smash"},
        {"vtennis2",      "Virtua Tennis 2 / Power Smash 2 (Rev A) (GDS-0015A)"},
        {"vtennisg",      "Virtua Tennis / Power Smash (GDS-0011)"},
        {"vueloesp",      "Vuelo Espacial (Spanish bootleg of UniWar S)"},
        {"vulcan",        "Vulcan Venture"},
        {"vulcana",       "Vulcan Venture (Old)"},
        {"vulcanb",       "Vulcan Venture (Oldest)"},
        {"vulgus",        "Vulgus (set 1)"},
        {"vulgus2",       "Vulgus (set 2)"},
        {"vulgusa",       "Vulgus (set 2)"},
        {"vulgusj",       "Vulgus (Japan[Q])"},
};

const char *lookup_v(const char *name) {
    for (size_t i = 0; i < sizeof(lookup_table) / sizeof(lookup_table[0]); i++) {
        if (strcmp(lookup_table[i].name, name) == 0) {
            return lookup_table[i].value;
        }
    }
    return NULL;
}

const char *r_lookup_v(const char *value) {
    for (size_t i = 0; i < sizeof(lookup_table) / sizeof(lookup_table[0]); i++) {
        if (strcmp(lookup_table[i].value, value) == 0) {
            return lookup_table[i].name;
        }
    }
    return NULL;
}