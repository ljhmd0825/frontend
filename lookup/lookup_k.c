#include <string.h>
#include "../common/common.h"
#include "lookup.h"

typedef struct {
    const char *name;
    const char *value;
} LookupName;

static const LookupName lookup_table[] = {
        {"kabukikl",     "Far East of Eden - Kabuki Klash / Tengai Makyou - Shin Den"},
        {"kabukiz",      "Kabuki-Z (World)"},
        {"kabukizj",     "Kabuki-Z (Japan)"},
        {"kageki",       "Kageki (US)"},
        {"kagekih",      "Kageki (hack)"},
        {"kagekij",      "Kageki (Japan)"},
        {"kagekiu",      "Kageki (US)"},
        {"kaguya",       "Mahjong Kaguyahime [BET] (Japan 880521)"},
        {"kaiserkj",     "Kaiser Knuckle (Japan)"},
        {"kaiserkn",     "Kaiser Knuckle (World)"},
        {"kaiserknj",    "Kaiser Knuckle (Ver 2.1J 1994/07/29)"},
        {"kaitei",       "Kaitei Takara Sagashi"},
        {"kaiteids",     "Kaitei Daisensou (Japan)"},
        {"kaitein",      "Kaitei Takara Sagashi (Namco)"},
        {"kaiunqz",      "Kaiun Quiz (Japan, KW1/VER.A)"},
        {"kakumei",      "Mahjong Kakumei"},
        {"kakumei2",     "Mahjong Kakumei 2 - Princess League"},
        {"kamakazi3",    "Kamakazi III (hack of 'Super Galaxians')"},
        {"kamenrid",     "Masked Riders Club Battle Race"},
        {"kamikaze",     "Kamikaze"},
        {"kamikazesp",   "Kamikaze (Euromatic S.A., Spanish bootleg of Scramble)"},
        {"kamikazp",     "Kamikaze (Potomac Games, bootleg of Galaxian)"},
        {"kamikcab",     "Kamikaze Cabbie"},
        {"kanatuen",     "Kanatsuen no Onna [BET] (Japan 880905)"},
        {"kangaroa",     "Kangaroo (Atari)"},
        {"kangarob",     "Kangaroo (bootleg)"},
        {"kangaroo",     "Kangaroo"},
        {"kangarooa",    "Kangaroo (Atari)"},
        {"kangaroob",    "Kangaroo (bootleg)"},
        {"kangarool",    "Kangaroo (Loewen-Automaten)"},
        {"kaos",         "Kaos"},
        {"karatblu",     "Karate Blazers (US)"},
        {"karatblz",     "Karate Blazers (World[Q])"},
        {"karatblza",    "Karate Blazers (World, set 2)"},
        {"karatblzbl",   "Karate Blazers (bootleg with Street Smart sound hardware)"},
        {"karatblzj",    "Toushin Blazers (Japan, Tecmo license)"},
        {"karatblzt",    "Karate Blazers (World, Tecmo license)"},
        {"karatblzu",    "Karate Blazers (US)"},
        {"karateda",     "Karate Dou (Arfyc bootleg)"},
        {"karatedo",     "Karate Dou (Japan)"},
        {"karatevs",     "Taisen Karate Dou (Japan VS version)"},
        {"karatour",     "The Karate Tournament"},
        {"karatourj",    "Chatan Yara Kuushanku - The Karate Tournament (Japan)"},
        {"karianx",      "Karian Cross (Rev. 1.0)"},
        {"karnov",       "Karnov (US)"},
        {"karnova",      "Karnov (US, rev 5)"},
        {"karnovj",      "Karnov (Japan)"},
        {"karnovr",      "Karnov's Revenge / Fighter's History Dynamite"},
        {"karous",       "Karous (Japan) (GDL-0040)"},
        {"kattobas",     "Kattobase Power Pro Kun"},
        {"kazan",        "Ninja Kazan (World)"},
        {"kbash",        "Knuckle Bash"},
        {"kbash2",       "Knuckle Bash 2"},
        {"kbashk",       "Knuckle Bash (Korean PCB)"},
        {"kbashp",       "Knuckle Bash (location test)"},
        {"kbh",          "Keyboardheaven (Korea)"},
        {"kbm",          "Keyboardmania"},
        {"kbm2nd",       "Keyboardmania 2nd Mix"},
        {"kbm3rd",       "Keyboardmania 3rd Mix"},
        {"kchamp",       "Karate Champ (US)"},
        {"kchamp2p",     "Karate Champ (US, 2 players)"},
        {"kchamptec",    "Karate Champ (Tecfri bootleg)"},
        {"kchampvs",     "Karate Champ (US VS version)"},
        {"kchampvs2",    "Karate Champ (US VS version, set 2)"},
        {"kchampvs3",    "Karate Champ (US VS version, set 3)"},
        {"kchampvs4",    "Karate Champ (US VS version, set 4)"},
        {"kdynastg",     "King of Dynast Gear (version 1.8)"},
        {"keith",        "Keith Courage In Alpha Zones (United Amusements PC Engine)"},
        {"keithlcy",     "Dramatic Adventure Quiz Keith and Lucy (Japan)"},
        {"kengo",        "Ken-Go"},
        {"kengoj",       "Ken-Go (Japan)"},
        {"kenseim",      "Ken Sei Mogura: Street Fighter II (Japan 940418, Ver 1.00)"},
        {"keroppi",      "Kero Kero Keroppi's Let's Play Together (USA, Version 2.0)"},
        {"keroppij",     "Kero Kero Keroppi no Isshoni Asobou (Japan)"},
        {"ket",          "Ketsui Kizuna Jigoku Tachi"},
        {"ket1",         "Ketsui: Kizuna Jigoku Tachi (2003/01/01. Master Ver.) (alt rom fill)"},
        {"keta",         "Ketsui Kizuna Jigoku Tachi (older)"},
        {"ketarr",       "Ketsui: Kizuna Jigoku Tachi (2014/07/16 ARRANGE 1.7 VER) (hack)"},
        {"ketarr10",     "Ketsui: Kizuna Jigoku Tachi (2012/04/17 ARRANGE VER) (hack)"},
        {"ketarr15",     "Ketsui: Kizuna Jigoku Tachi (2012/06/26 ARRANGE 1.5 VER) (hack)"},
        {"ketarr151",    "Ketsui: Kizuna Jigoku Tachi (2012/06/26 ARRANGE 1.51 VER) (hack)"},
        {"ketarrf",      "Ketsui: Kizuna Jigoku Tachi (2012/04/17 FAST. VER) (hack)"},
        {"ketarrs15",    "Ketsui: Kizuna Jigoku Tachi (2012/06/27 MR.STOIC 1.5 VER) (hack)"},
        {"ketarrs151",   "Ketsui: Kizuna Jigoku Tachi (2012/06/27 MR.STOIC 1.51 VER) (hack)"},
        {"ketb",         "Ketsui Kizuna Jigoku Tachi (first revision)"},
        {"ketbl",        "Ketsui: Kizuna Jigoku Tachi (2003/01/01. Master Ver., bootleg cartridge conversion)"},
        {"kf10thep",     "The King of Fighters 10th Anniversary Extra Plus (The King of Fighters 2002 bootleg)"},
        {"kf2k2mp",      "The King of Fighters 2002 Magic Plus (bootleg)"},
        {"kf2k2mp2",     "The King of Fighters 2002 Magic Plus II (bootleg)"},
        {"kf2k2pla",     "The King of Fighters 2002 Plus (set 2, bootleg)"},
        {"kf2k2pls",     "The King of Fighters 2002 Plus (set 1, bootleg)"},
        {"kf2k3bl",      "The King of Fighters 2003 (bootleg set 1)"},
        {"kf2k3bla",     "The King of Fighters 2003 (bootleg set 2)"},
        {"kf2k3pcb",     "The King of Fighters 2003 (Japan, JAMMA PCB)"},
        {"kf2k3pl",      "The King of Fighters 2004 Plus / Hero (The King of Fighters 2003 bootleg)"},
        {"kf2k3upl",     "The King of Fighters 2004 Ultra Plus (The King of Fighters 2003 bootleg)"},
        {"kf2k5uni",     "The King of Fighters 10th Anniversary 2005 Unique (The King of Fighters 2002 bootleg)"},
        {"kick",         "Kick (upright)"},
        {"kick4csh",     "Kick '4' Cash (Export)"},
        {"kicka",        "Kick (cocktail)"},
        {"kickball",     "Kick Ball"},
        {"kickboy",      "Kick Boy"},
        {"kickc",        "Kick (cocktail)"},
        {"kicker",       "Kicker"},
        {"kickgoal",     "Kick Goal"},
        {"kickgoala",    "Kick Goal (set 2)"},
        {"kickman",      "Kickman (upright)"},
        {"kicknrun",     "Kick and Run"},
        {"kicknrunu",    "Kick and Run (US)"},
        {"kickoff",      "Kick Off (Japan)"},
        {"kickoffb",     "Kick Off - World Cup (bootleg)"},
        {"kickridr",     "Kick Rider"},
        {"kidniki",      "Kid Niki - Radical Ninja (US)"},
        {"kidnikib",     "Kid Niki (bootleg)"},
        {"kidnikiu",     "Kid Niki - Radical Ninja (US)"},
        {"kikaioh",      "Kikaioh (JAPAN 980914)"},
        {"kikcubic",     "Meikyu Jima (Japan)"},
        {"kikcubicb",    "Kickle Cubele"},
        {"kikikai",      "KiKi KaiKai"},
        {"kikstart",     "Kick Start Wheelie King"},
        {"killbld",      "The Killing Blade (ver. 109, Chinese Board)"},
        {"killcom",      "Killer Comet"},
        {"kingbalj",     "King and Balloon (Japan)"},
        {"kingball",     "King and Balloon (US)"},
        {"kingballj",    "King & Balloon (Japan)"},
        {"kingdmgp",     "Kingdom Grandprix (World)"},
        {"kingofb",      "King of Boxer (English)"},
        {"kingofbj",     "King of Boxer (Japan)"},
        {"kingpin",      "Kingpin"},
        {"kingrt66",     "The King of Route 66 (Rev A)"},
        {"kingrt66p",    "The King of Route 66 (prototype)"},
        {"kinst",        "Killer Instinct (v1.0)"},
        {"kinst2",       "Killer Instinct 2 (v2.1)"},
        {"kinst2uk",     "Killer Instinct 2 (upgrade kit)"},
        {"kinstb",       "Killer Instinct (SNES bootleg)"},
        {"kirameki",     "Kirameki Star Road (Japan)"},
        {"kirarast",     "Ryuusei Janshi Kirara Star"},
        {"kittenk",      "Kitten Kaboodle"},
        {"kiwame",       "Pro Mahjong Kiwame"},
        {"kiwames",      "Pro Mahjong Kiwame S"},
        {"kizuna",       "Kizuna Encounter - Super Tag Battle / Fu'un Super Tag Battle"},
        {"kizuna4p",     "Kizuna Encounter - Super Tag Battle 4 Way Battle Version / Fu'un Super Tag Battle Special Version"},
        {"klax",         "Klax (set 1)"},
        {"klax2",        "Klax (set 2)"},
        {"klax3",        "Klax (set 3)"},
        {"klax4",        "Klax (version 4)"},
        {"klax5",        "Klax (version 5)"},
        {"klax5bl",      "Klax (version 5, bootleg set 1)"},
        {"klax5bl2",     "Klax (version 5, bootleg set 2)"},
        {"klaxd",        "Klax (Germany)"},
        {"klaxd2",       "Klax (Germany, version 2)"},
        {"klaxj",        "Klax (Japan)"},
        {"klaxj3",       "Klax (Japan, version 3)"},
        {"klaxj4",       "Klax (Japan, version 4)"},
        {"klaxp1",       "Klax (prototype set 1)"},
        {"klaxp2",       "Klax (prototype set 2)"},
        {"klondkp",      "KlonDike+"},
        {"knckhead",     "Knuckle Heads (World)"},
        {"knckheadj",    "Knuckle Heads (Japan)"},
        {"knckheadjp",   "Knuckle Heads (Japan, Prototype?)"},
        {"knckhedj",     "Knuckle Heads (Japan)"},
        {"kncljoe",      "Knuckle Joe (set 1)"},
        {"kncljoea",     "Knuckle Joe (set 2)"},
        {"kngtmare",     "Knightmare (prototype)"},
        {"knightb",      "Knight Boy (bootleg of KiKi KaiKai, set 1)"},
        {"knights",      "Knights of the Round (World 911127)"},
        {"knightsb",     "Knights of the Round (bootleg with 2xMSM5205, set 1)"},
        {"knightsb2",    "Knights of the Round (bootleg, World 911127)"},
        {"knightsb3",    "Knights of the Round (bootleg with 2xMSM5205, set 2)"},
        {"knightsj",     "Knights of the Round (Japan 911127)"},
        {"knightsja",    "Knights of the Round (Japan 911127, B-Board 89625B-1)"},
        {"knightsu",     "Knights of the Round (US 911127)"},
        {"knockout",     "Knock Out!!"},
        {"knockoutb",    "Knock Out!! (bootleg, set 2)"},
        {"knockoutc",    "Knock Out!! (bootleg, set 3)"},
        {"knpuzzle",     "Kotoba no Puzzle Mojipittan (Japan, KPM1 Ver.A)"},
        {"kod",          "The King of Dragons (World 910711)"},
        {"kodb",         "The King of Dragons (bootleg)"},
        {"kodj",         "The King of Dragons (Japan 910805)"},
        {"kodja",        "The King of Dragons (Japan 910805, B-Board 89625B-1)"},
        {"kodr1",        "The King of Dragons (World 910711)"},
        {"kodr2",        "The King of Dragons (World 910731)"},
        {"kodu",         "The King of Dragons (US 910910)"},
        {"kodure",       "Kodure Ookami (Japan)"},
        {"kof10th",      "The King of Fighters 10th Anniversary"},
        {"kof2000",      "The King of Fighters 2000"},
        {"kof2000n",     "The King of Fighters 2000 (not encrypted)"},
        {"kof2001",      "The King of Fighters 2001"},
        {"kof2001h",     "The King of Fighters 2001 (set 2)"},
        {"kof2002",      "The King of Fighters 2002"},
        {"kof2002b",     "The King of Fighters 2002 (bootleg)"},
        {"kof2003",      "The King of Fighters 2003 (World / US, MVS)"},
        {"kof2003d",     "The King of Fighters 2003 (Decrypted)"},
        {"kof2003h",     "The King of Fighters 2003 (NGH-2710)"},
        {"kof2k4se",     "The King of Fighters Special Edition 2004 (The King of Fighters 2002 bootleg)"},
        {"kof94",        "The King of Fighters '94"},
        {"kof95",        "The King of Fighters '95 (set 1)"},
        {"kof95a",       "The King of Fighters '95 (set 2)"},
        {"kof95h",       "The King of Fighters '95 (NGH-084)"},
        {"kof96",        "The King of Fighters '96 (set 1)"},
        {"kof96h",       "The King of Fighters '96 (set 2)"},
        {"kof97",        "The King of Fighters '97 (set 1)"},
        {"kof97a",       "The King of Fighters '97 (set 2)"},
        {"kof97h",       "The King of Fighters '97 (NGH-2320)"},
        {"kof97k",       "The King of Fighters '97 (Korean release)"},
        {"kof97oro",     "The King of Fighters '97 Chongchu Jianghu Plus 2003 (bootleg)"},
        {"kof97pls",     "The King of Fighters '97 Plus (bootleg)"},
        {"kof98",        "The King of Fighters '98 - The Slugfest - King of Fighters '98 / Dream Match Never Ends"},
        {"kof98a",       "The King of Fighters '98 - The Slugfest / King of Fighters '98 - Dream Match Never Ends (NGM-2420, alt board)"},
        {"kof98h",       "The King of Fighters '98 - The Slugfest / King of Fighters '98 - Dream Match Never Ends (NGH-2420)"},
        {"kof98k",       "The King of Fighters '98 - The Slugfest / King of Fighters '98 - dream match never ends (Korean board)"},
        {"kof98ka",      "The King of Fighters '98 - The Slugfest / King of Fighters '98 - Dream Match Never Ends (Korean board, set 2)"},
        {"kof98n",       "The King of Fighters '98 - The Slugfest - King of Fighters '98 / Dream Match Never Ends (Decrypted)"},
        {"kof98ult",     "The King of Fighters '98 - The Slugfest / King of Fighters '98 - Dream Match Never Ends (Ultimate Match, Hack)"},
        {"kof98umh",     "The King of Fighters '98: Ultimate Match HERO (China, V100, 09-08-23)"},
        {"kof99",        "The King of Fighters '99 - Millennium Battle (set 1)"},
        {"kof99a",       "The King of Fighters '99 - Millennium Battle (set 2)"},
        {"kof99e",       "The King of Fighters '99 - Millennium Battle (earlier)"},
        {"kof99h",       "The King of Fighters '99 - Millennium Battle (NGH-2510)"},
        {"kof99k",       "The King of Fighters '99 - Millennium Battle (Korean release)"},
        {"kof99ka",      "The King of Fighters '99 - Millennium Battle (Korean release, non-encrypted program)"},
        {"kof99n",       "The King of Fighters '99 - Millennium Battle (not encrypted)"},
        {"kof99p",       "The King of Fighters '99 - Millennium Battle (prototype)"},
        {"kofnw",        "The King of Fighters Neowave"},
        {"kofnwj",       "The King of Fighters Neowave (Japan)"},
        {"kofxi",        "The King of Fighters XI"},
        {"kog",          "King of Gladiator (The King of Fighters '97 bootleg)"},
        {"koikois2",     "Koi Koi Shimasyo 2 - Super Real Hanafuda (Japan)"},
        {"koinomp",      "Mahjong Koi no Magic Potion (Japan)"},
        {"kok",          "Povar / Sobrat' Buran / Agroprom (Arcade multi-game bootleg of ZX Spectrum 'Cookie', 'Jetpac' & 'Pssst')"},
        {"kokoroj",      "Soreike Kokology (Rev A)"},
        {"kokoroj2",     "Soreike Kokology Vol. 2 - Kokoro no Tanteikyoku"},
        {"kokoroja",     "Soreike Kokology"},
        {"komemokos",    "Komemokos (hack of 'Pac-Man (Cirsa, Spanish bootleg)')"},
        {"komocomo",     "Komo Como (Topmar, bootleg?)"},
        {"konami88",     "Konami '88"},
        {"konamigt",     "Konami GT"},
        {"konamigx",     "System GX"},
        {"konek",        "Konek-Gorbunok"},
        {"konotako",     "Kono e Tako (10021 Ver.A)"},
        {"kontest",      "Konami Test Board (GX800, Japan)"},
        {"kopunch",      "KO Punch"},
        {"korinai",      "Mahjong-zukino Korinai Menmen (Japan 880425)"},
        {"korokoro",     "Koro Koro Quest (Japan)"},
        {"koroleva",     "Snezhnaja Koroleva"},
        {"koropens",     "Korokoro Pensuke"},
        {"korosuke",     "Korosuke Roller"},
        {"koshien",      "Ah Eikou no Koshien (Japan)"},
        {"kot",          "Kot-Rybolov (Terminal)"},
        {"kothello",     "Kyuukyoku no Othello"},
        {"kotm",         "King of the Monsters (set 1)"},
        {"kotm2",        "King of the Monsters 2 - The Next Thing"},
        {"kotm2a",       "King of the Monsters 2 - The Next Thing (older)"},
        {"kotm2p",       "King of the Monsters 2 - The Next Thing (prototype)"},
        {"kotmh",        "King of the Monsters (set 2)"},
        {"kouyakyu",     "The Koukouyakyuh"},
        {"kov",          "Knights of Valour - Sangoku Senki (ver. 117)"},
        {"kov115",       "Knights of Valour - Sangoku Senki (ver. 115)"},
        {"kov2nl",       "Knights of Valour 2 New Legend / Sanguo Zhan Ji 2 Guang Sao Yu Jun (V302, Oversea)"},
        {"kov2nl_300",   "Knights of Valour 2 New Legend / Sanguo Zhan Ji 2 Guang Sao Yu Jun (V300, Oversea)"},
        {"kov2nl_300cn", "Sanguo Zhan Ji 2 Gaishi Yingxiong (V300, China)"},
        {"kov2nl_301",   "Knights of Valour 2 New Legend / Sanguo Zhan Ji 2 Guang Sao Yu Jun (V301, Oversea)"},
        {"kov2nl_301cn", "Sanguo Zhan Ji 2 Gaishi Yingxiong (V301, China)"},
        {"kov2nl_302cn", "Sanguo Zhan Ji 2 Gaishi Yingxiong (V302, China)"},
        {"kov3",         "Knights of Valour 3 / Sanguo Zhan Ji 3 (V104, China, Hong Kong, Taiwan)"},
        {"kov3_100",     "Knights of Valour 3 / Sanguo Zhan Ji 3 (V100, China, Hong Kong, Taiwan)"},
        {"kov3_101",     "Knights of Valour 3 / Sanguo Zhan Ji 3 (V101, China, Hong Kong, Taiwan)"},
        {"kov3_102",     "Knights of Valour 3 / Sanguo Zhan Ji 3 (V102, China, Hong Kong, Taiwan)"},
        {"kov7sprt",     "Knights of Valour - The Seven Spirits"},
        {"kovplus",      "Knights of Valour Plus - Sangoku Senki Plus (ver. 119)"},
        {"kovsh",        "Knights of Valour Superheroes - Sangoku Senki Superheroes (ver. 322)"},
        {"kozure",       "Kozure Ookami (Japan)"},
        {"kram",         "Kram (set 1)"},
        {"kram2",        "Kram (set 2)"},
        {"kram3",        "Kram (encrypted)"},
        {"krama",        "Kram"},
        {"kroozr",       "Kozmik Kroozr"},
        {"krull",        "Krull"},
        {"krzybowl",     "Krazy Bowl"},
        {"ksayakyu",     "Kusayakyuu"},
        {"ktiger",       "Kyukyoku Tiger (Japan)"},
        {"ktiger2",      "Kyukyoku Tiger 2 (Japan)"},
        {"ktiger2p",     "Kyukyoku Tiger (Japan, 2 Players)"},
        {"ktigera",      "Kyukyoku Tiger (Japan, 2 player alternate)"},
        {"kuhga",        "Kuhga - Operation Code 'Vapor Trail' (Japan revision 3)"},
        {"kungfub",      "Kung-Fu Master (bootleg set 1)"},
        {"kungfub2",     "Kung-Fu Master (bootleg set 2)"},
        {"kungfub3s",    "Kung-Fu Senjyo (bootleg, Spanish)"},
        {"kungfud",      "Kung-Fu Master (Data East)"},
        {"kungfum",      "Kung-Fu Master"},
        {"kungfumd",     "Kung-Fu Master (US)"},
        {"kungfut",      "Kung-Fu Taikun"},
        {"kungfuta",     "Kung-Fu Taikun (set 2)"},
        {"kuniokub",     "Nekketsu Kouha Kunio-kun (Japan bootleg)"},
        {"kuniokun",     "Nekketsu Kouha Kunio-kun (Japan)"},
        {"kuniokunb",    "Nekketsu Kouha Kunio-kun (Japan bootleg)"},
        {"kurikina",     "Kuri Kinton (World, prototype[Q])"},
        {"kurikinj",     "Kuri Kinton (Japan)"},
        {"kurikint",     "Kuri Kinton (World)"},
        {"kurikinta",    "Kuri Kinton (World, prototype?)"},
        {"kurikintj",    "Kuri Kinton (Japan)"},
        {"kurikintu",    "Kuri Kinton (US)"},
        {"kurikintw",    "Kuri Kinton (US, World Games license)"},
        {"kurikinu",     "Kuri Kinton (US)"},
        {"kurucham",     "Kurukuru Chameleon (Japan) (GDL-0034)"},
        {"kurukuru",     "Kuru Kuru Pyon Pyon (Japan)"},
        {"kuzmich",      "Kuzmich-Egorych"},
        {"kyros",        "Kyros"},
        {"kyrosj",       "Kyros No Yakata (Japan)"},
        {"kyukaidk",     "Kyuukai Douchuuki (Japan new version)"},
        {"kyukaidko",    "Kyuukai Douchuuki (Japan, old version)"},
        {"kyukaido",     "Kyuukai Douchuuki (Japan old version)"},
        {"kyustrkr",     "Last Striker - Kyuukyoku no Striker"},
        {"kzaurus",      "Pittanko Zaurus"},
};

const char *lookup_k(const char *name) {
    if (!name) return NULL;
    for (size_t i = 0; i < A_SIZE(lookup_table); i++) {
        if (strcmp(lookup_table[i].name, name) == 0) {
            return lookup_table[i].value;
        }
    }
    return NULL;
}

const char *r_lookup_k(const char *value) {
    if (!value) return NULL;
    for (size_t i = 0; i < A_SIZE(lookup_table); i++) {
        if (strstr(lookup_table[i].value, value)) {
            return lookup_table[i].name;
        }
    }
    return NULL;
}
