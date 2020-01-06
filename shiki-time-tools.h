#ifndef SHIKI_TIME_TOOLS_H
#define SHIKI_TIME_TOOLS_H
#include <stdint.h>

static const uint8_t MAX_LEN_DATE_CUSTOM_1 = 30; // example Friday, 20th December 2019
static const uint8_t MAX_LEN_DATE_CUSTOM_2 = 20; // example Friday, 20th December 2019
static const uint8_t MAX_LEN_DATE = 11; // example 04-02-1996
static const uint8_t MAX_LEN_TIME = 9; // example 04:37:20

typedef enum {
    yyyymmdd = 0, // Japanese
    ddmmyyyy = 1, // European
    mmddyyyy = 2, // American
    ddmmyy = 3
} date_format;

typedef enum {
    date_format_custom1_id = 3, // contoh 20 Desember 2019
    date_format_custom2_id = 4, // contoh Jumat, 20 Desember 2019
    date_format_custom1_eng = 5, // example 20th December 2019
    date_format_custom2_eng = 6, // example Friday, 20th December 2019
} custom_date_format;

typedef enum {
    redite = 0, // minggu
    soma = 1, // senin
    anggara = 2, // selasa
    budha = 3, // rabu
    wraspati = 4, // kamis
    sukra = 5, // jumat
    saniscara = 6 // sabtu
} sapta_wara_id;

typedef enum {
    sinta = 0,
    landep = 1,
    ukir = 2,
    kulantir = 3,
    tolu = 4,
    gumbreg = 5,
    wariga = 6,
    warigadean = 7,
    julungwangi = 8,
    sungsang = 9,
    dungulan = 10,
    kuningan = 11,
    langkir = 12,
    medangsia = 13,
    pujut = 14,
    pahang = 15,
    krulut = 16,
    merakih = 17,
    tambir = 18,
    medangkungan = 19,
    matal = 20,
    uye = 21,
    menail = 22,
    prangbakat = 23,
    bala = 24,
    ugu = 25,
    wayang = 26,
    kelawu = 27,
    dukut = 28,
    watugunung = 29
} wuku_id;

struct pawukon_data{
    uint8_t id;
    uint8_t urip;
    char name[13];
};

struct balinese_calendar{
    struct pawukon_data wuku;
    struct pawukon_data eka_wara;
    struct pawukon_data dwi_wara;
    struct pawukon_data tri_wara;
    struct pawukon_data catur_wara;
    struct pawukon_data panca_wara;
    struct pawukon_data sad_wara;
    struct pawukon_data sapta_wara;
    struct pawukon_data asta_wara;
    struct pawukon_data sanga_wara;
    struct pawukon_data dasa_wara;
};

// Global Function
void stim_get_date_custom_auto(char *tim_str, custom_date_format _format);
void stim_get_date_custom_manual(char *tim_str, long time_now, custom_date_format _format);
void stim_get_date_dash_auto(char* tim_str, date_format _format);
void stim_get_date_slash_auto(char* tim_str, date_format _format);
void stim_get_date_colon_auto(char* tim_str, date_format _format);
void stim_get_date_dot_auto(char* tim_str, date_format _format);
void stim_get_date_dash_manual(char* tim_str, long _time, date_format _format);
void stim_get_date_slash_manual(char* tim_str, long _time, date_format _format);
void stim_get_date_colon_manual(char* tim_str, long _time, date_format _format);
void stim_get_date_dot_manual(char* tim_str, long _time, date_format _format);
void stim_get_time_dash_auto(char* tim_str);
void stim_get_time_slash_auto(char* tim_str);
void stim_get_time_colon_auto(char* tim_str);
void stim_get_time_dot_auto(char* tim_str);
void stim_get_time_dash_manual(char* tim_str, long time_now);
void stim_get_time_slash_manual(char* tim_str, long time_now);
void stim_get_time_colon_manual(char* tim_str, long time_now);
void stim_get_time_dot_manual(char* tim_str, long time_now);

uint8_t stim_get_enum_from_str_wuku(char *_str_wuku);
uint8_t stim_get_enum_from_str_sapta_wara(char *_str_sapta_wara);
void stim_get_wariga_from_unix_timestamp(struct balinese_calendar *_wariga, long _time_input);
void stim_get_wariga_from_julian_date(struct balinese_calendar *_wariga, uint8_t _mday_id, uint8_t _month_id, int _year_id);
void stim_get_wariga_from_wuku(struct balinese_calendar *_wariga, wuku_id _wuku_number, sapta_wara_id _sapta_wara_number);
void stim_get_timestamp_from_wuku(long *_time_1, long *_time_2, uint16_t _year_id, wuku_id _wuku_number, sapta_wara_id _sapta_wara_number);
#endif
