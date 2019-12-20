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
} date_format;

typedef enum {
    date_format_custom1_id = 3, // contoh 20 Desember 2019
    date_format_custom2_id = 4, // contoh Jumat, 20 Desember 2019
    date_format_custom1_eng = 5, // example 20th December 2019
    date_format_custom2_eng = 6, // example Friday, 20th December 2019
} custom_date_format;

//Global Function
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
#endif
