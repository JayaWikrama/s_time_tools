/*
    lib info    : SHIKI_LIB_GROUP - TIME STRING MANUPULATION
    ver         : 1.01.19.12.20.10
    author      : Jaya Wikrama, S.T.
    e-mail      : jayawikrama89@gmail.com
    Copyright (c) 2019 HANA,. Jaya Wikrama
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "shiki-time-tools.h"

static void stim_get_wday_id(char *_day_str, int8_t _wday){
    if (_wday == 0){
        strcpy(_day_str, "Minggu");
    }
    else if (_wday == 1){
        strcpy(_day_str, "Senin");
    }
    else if (_wday == 2){
        strcpy(_day_str, "Selasa");
    }
    else if (_wday == 3){
        strcpy(_day_str, "Rabu");
    }
    else if (_wday == 4){
        strcpy(_day_str, "Kamis");
    }
    else if (_wday == 5){
        strcpy(_day_str, "Jumat");
    }
    else if (_wday == 6){
        strcpy(_day_str, "Sabtu");
    }
    else {
        strcpy(_day_str, "wrong");
    }
}

static void stim_get_wday_eng(char *_day_str, int8_t _wday){
    if (_wday == 0){
        strcpy(_day_str, "Sunday");
    }
    else if (_wday == 1){
        strcpy(_day_str, "Monday");
    }
    else if (_wday == 2){
        strcpy(_day_str, "Tuesday");
    }
    else if (_wday == 3){
        strcpy(_day_str, "Wednesday");
    }
    else if (_wday == 4){
        strcpy(_day_str, "Thursday");
    }
    else if (_wday == 5){
        strcpy(_day_str, "Friday");
    }
    else if (_wday == 6){
        strcpy(_day_str, "Saturday");
    }
    else {
        strcpy(_day_str, "wrong");
    }
}

static void stim_get_month_id(char *_month_str, int8_t _month){
    if(_month == 0){
        strcpy(_month_str, "Januari");
    }
    else if(_month == 1){
        strcpy(_month_str, "Februari");
    }
    else if(_month == 2){
        strcpy(_month_str, "Maret");
    }
    else if(_month == 3){
        strcpy(_month_str, "April");
    }
    else if(_month == 4){
        strcpy(_month_str, "Mei");
    }
    else if(_month == 5){
        strcpy(_month_str, "Juni");
    }
    else if(_month == 6){
        strcpy(_month_str, "Juli");
    }
    else if(_month == 7){
        strcpy(_month_str, "Agustus");
    }
    else if(_month == 8){
        strcpy(_month_str, "September");
    }
    else if(_month == 9){
        strcpy(_month_str, "Oktober");
    }
    else if(_month == 10){
        strcpy(_month_str, "November");
    }
    else if(_month == 11){
        strcpy(_month_str, "Desember");
    }
    else{
        strcpy(_month_str, "wrong");
    }
}

static void stim_get_month_eng(char *_month_str, int8_t _month){
    if(_month == 0){
        strcpy(_month_str, "January");
    }
    else if(_month == 1){
        strcpy(_month_str, "February");
    }
    else if(_month == 2){
        strcpy(_month_str, "March");
    }
    else if(_month == 3){
        strcpy(_month_str, "April");
    }
    else if(_month == 4){
        strcpy(_month_str, "May");
    }
    else if(_month == 5){
        strcpy(_month_str, "June");
    }
    else if(_month == 6){
        strcpy(_month_str, "July");
    }
    else if(_month == 7){
        strcpy(_month_str, "August");
    }
    else if(_month == 8){
        strcpy(_month_str, "September");
    }
    else if(_month == 9){
        strcpy(_month_str, "October");
    }
    else if(_month == 10){
        strcpy(_month_str, "November");
    }
    else if(_month == 11){
        strcpy(_month_str, "December");
    }
    else{
        strcpy(_month_str, "wrong");
    }
}

void stim_get_date_custom_auto(char *tim_str, custom_date_format _format){
    time_t time_now;
    struct tm *mtm;
    time(&time_now);
    mtm = localtime(&time_now);
    if (_format == date_format_custom1_id){
        char date_str[MAX_LEN_DATE_CUSTOM_1];
        char _month_name[10];
        memset(date_str, 0x00, MAX_LEN_DATE_CUSTOM_1*sizeof(char));
        stim_get_month_id(_month_name, mtm->tm_mon);
        sprintf(date_str, "%02d %s %04d", mtm->tm_mday, _month_name, mtm->tm_year+1900);
        strcpy(tim_str, date_str);
    }
    else if (_format == date_format_custom2_id){
        char date_str[MAX_LEN_DATE_CUSTOM_2];
        char _month_name[10];
        char _wday_name[7];
        memset(date_str, 0x00, MAX_LEN_DATE_CUSTOM_2*sizeof(char));
        stim_get_wday_id(_wday_name, mtm->tm_wday);
        stim_get_month_id(_month_name, mtm->tm_mon);
        sprintf(date_str, "%s, %02d %s %04d", _wday_name, mtm->tm_mday, _month_name, mtm->tm_year+1900);
        strcpy(tim_str, date_str);
    }
    else if (_format == date_format_custom1_eng){
        char date_str[MAX_LEN_DATE_CUSTOM_1];
        char _month_name[10];
        memset(date_str, 0x00, MAX_LEN_DATE_CUSTOM_1*sizeof(char));
        stim_get_month_eng(_month_name, mtm->tm_mon);
        if(mtm->tm_mday == 1){
            sprintf(date_str, "%02dst %s %04d", mtm->tm_mday, _month_name, mtm->tm_year+1900);
        }
        else if(mtm->tm_mday == 2){
            sprintf(date_str, "%02dnd %s %04d", mtm->tm_mday, _month_name, mtm->tm_year+1900);
        }
        else if(mtm->tm_mday == 3){
            sprintf(date_str, "%02drd %s %04d", mtm->tm_mday, _month_name, mtm->tm_year+1900);
        }
        else if(mtm->tm_mday <= 31){
            sprintf(date_str, "%02dth %s %04d", mtm->tm_mday, _month_name, mtm->tm_year+1900);
        }
        strcpy(tim_str, date_str);
    }
    else if (_format == date_format_custom2_eng){
        char date_str[MAX_LEN_DATE_CUSTOM_2];
        char _month_name[10];
        char _wday_name[9];
        stim_get_wday_eng(_wday_name, mtm->tm_wday);
        stim_get_month_eng(_month_name, mtm->tm_mon);
        if(mtm->tm_mday == 1){
            sprintf(date_str, "%s, %02dst %s %04d", _wday_name, mtm->tm_mday, _month_name, mtm->tm_year+1900);
        }
        else if(mtm->tm_mday == 2){
            sprintf(date_str, "%s, %02dnd %s %04d", _wday_name, mtm->tm_mday, _month_name, mtm->tm_year+1900);
        }
        else if(mtm->tm_mday == 3){
            sprintf(date_str, "%s, %02drd %s %04d", _wday_name, mtm->tm_mday, _month_name, mtm->tm_year+1900);
        }
        else if(mtm->tm_mday <= 31){
            sprintf(date_str, "%s, %02dth %s %04d", _wday_name, mtm->tm_mday, _month_name, mtm->tm_year+1900);
        }
        strcpy(tim_str, date_str);
    }
}

void stim_get_date_custom_manual(char *tim_str, long time_now, custom_date_format _format){
    struct tm *mtm;
    mtm = localtime(&time_now);
    if (_format == date_format_custom1_id){
        char date_str[MAX_LEN_DATE_CUSTOM_1];
        char _month_name[10];
        memset(date_str, 0x00, MAX_LEN_DATE_CUSTOM_1*sizeof(char));
        stim_get_month_id(_month_name, mtm->tm_mon);
        sprintf(date_str, "%02d %s %04d", mtm->tm_mday, _month_name, mtm->tm_year+1900);
        strcpy(tim_str, date_str);
    }
    else if (_format == date_format_custom2_id){
        char date_str[MAX_LEN_DATE_CUSTOM_2];
        char _month_name[10];
        char _wday_name[7];
        stim_get_wday_id(_wday_name, mtm->tm_wday);
        stim_get_month_id(_month_name, mtm->tm_mon);
        sprintf(date_str, "%s, %02d %s %04d", _wday_name, mtm->tm_mday, _month_name, mtm->tm_year+1900);
        strcpy(tim_str, date_str);
    }
    else if (_format == date_format_custom1_eng){
        char date_str[MAX_LEN_DATE_CUSTOM_1];
        char _month_name[10];
        memset(date_str, 0x00, MAX_LEN_DATE_CUSTOM_1*sizeof(char));
        stim_get_month_eng(_month_name, mtm->tm_mon);
        if(mtm->tm_mday == 1){
            sprintf(date_str, "%02dst %s %04d", mtm->tm_mday, _month_name, mtm->tm_year+1900);
        }
        else if(mtm->tm_mday == 2){
            sprintf(date_str, "%02dnd %s %04d", mtm->tm_mday, _month_name, mtm->tm_year+1900);
        }
        else if(mtm->tm_mday == 3){
            sprintf(date_str, "%02drd %s %04d", mtm->tm_mday, _month_name, mtm->tm_year+1900);
        }
        else if(mtm->tm_mday <= 31){
            sprintf(date_str, "%02dth %s %04d", mtm->tm_mday, _month_name, mtm->tm_year+1900);
        }
        strcpy(tim_str, date_str);
    }
    else if (_format == date_format_custom2_eng){
        char date_str[MAX_LEN_DATE_CUSTOM_2];
        char _month_name[10];
        char _wday_name[9];
        stim_get_wday_eng(_wday_name, mtm->tm_wday);
        stim_get_month_eng(_month_name, mtm->tm_mon);
        if(mtm->tm_mday == 1){
            sprintf(date_str, "%s, %02dst %s %04d", _wday_name, mtm->tm_mday, _month_name, mtm->tm_year+1900);
        }
        else if(mtm->tm_mday == 2){
            sprintf(date_str, "%s, %02dnd %s %04d", _wday_name, mtm->tm_mday, _month_name, mtm->tm_year+1900);
        }
        else if(mtm->tm_mday == 3){
            sprintf(date_str, "%s, %02drd %s %04d", _wday_name, mtm->tm_mday, _month_name, mtm->tm_year+1900);
        }
        else if(mtm->tm_mday <= 31){
            sprintf(date_str, "%s, %02dth %s %04d", _wday_name, mtm->tm_mday, _month_name, mtm->tm_year+1900);
        }
        strcpy(tim_str, date_str);
    }
}

void stim_get_date_dash_auto(char* tim_str, date_format _format){
    time_t time_now;
    struct tm *mtm;
    char date_str[MAX_LEN_DATE];
    memset(date_str, 0x00, MAX_LEN_DATE*sizeof(char));
    time(&time_now);
    mtm = localtime(&time_now);

    if (_format == yyyymmdd){
        sprintf(date_str, "%04d-%02d-%02d", mtm->tm_year+1900, mtm->tm_mon+1, mtm->tm_mday);
    }
    else if (_format == ddmmyyyy){
        sprintf(date_str, "%02d-%02d-%04d", mtm->tm_mday, mtm->tm_mon+1, mtm->tm_year+1900);
    }
    else if (_format == mmddyyyy){
        sprintf(date_str, "%02d-%02d-%04d", mtm->tm_mon+1, mtm->tm_mday, mtm->tm_year+1900);
    }
    else if (_format == ddmmyy){
        char year_str[5];
        memset(year_str, 0x00, 5*sizeof(char));
        sprintf(year_str, "%04d", mtm->tm_year+1900);
        sprintf(date_str, "%02d-%02d-%c%c", mtm->tm_mon+1, mtm->tm_mday, year_str[2], year_str[3]);
    }
    strcpy(tim_str, date_str); 
}

void stim_get_date_slash_auto(char* tim_str, date_format _format){
    time_t time_now;
    struct tm *mtm;
    char date_str[MAX_LEN_DATE];
    memset(date_str, 0x00, MAX_LEN_DATE*sizeof(char));
    time(&time_now);
    mtm = localtime(&time_now);

    if (_format == yyyymmdd){
        sprintf(date_str, "%04d/%02d/%02d", mtm->tm_year+1900, mtm->tm_mon+1, mtm->tm_mday);
    }
    else if (_format == ddmmyyyy){
        sprintf(date_str, "%02d/%02d/%04d", mtm->tm_mday, mtm->tm_mon+1, mtm->tm_year+1900);
    }
    else if (_format == mmddyyyy){
        sprintf(date_str, "%02d/%02d/%04d", mtm->tm_mon+1, mtm->tm_mday, mtm->tm_year+1900);
    }
    else if (_format == ddmmyy){
        char year_str[5];
        memset(year_str, 0x00, 5*sizeof(char));
        sprintf(year_str, "%04d", mtm->tm_year+1900);
        sprintf(date_str, "%02d/%02d/%c%c", mtm->tm_mon+1, mtm->tm_mday, year_str[2], year_str[3]);
    }
    strcpy(tim_str, date_str);
}

void stim_get_date_colon_auto(char* tim_str, date_format _format){
    time_t time_now;
    struct tm *mtm;
    char date_str[MAX_LEN_DATE];
    memset(date_str, 0x00, MAX_LEN_DATE*sizeof(char));
    time(&time_now);
    mtm = localtime(&time_now);

    if (_format == yyyymmdd){
        sprintf(date_str, "%04d:%02d:%02d", mtm->tm_year+1900, mtm->tm_mon+1, mtm->tm_mday);
    }
    else if (_format == ddmmyyyy){
        sprintf(date_str, "%02d:%02d:%04d", mtm->tm_mday, mtm->tm_mon+1, mtm->tm_year+1900);
    }
    else if (_format == mmddyyyy){
        sprintf(date_str, "%02d:%02d:%04d", mtm->tm_mon+1, mtm->tm_mday, mtm->tm_year+1900);
    }
    else if (_format == ddmmyy){
        char year_str[5];
        memset(year_str, 0x00, 5*sizeof(char));
        sprintf(year_str, "%04d", mtm->tm_year+1900);
        sprintf(date_str, "%02d:%02d:%c%c", mtm->tm_mon+1, mtm->tm_mday, year_str[2], year_str[3]);
    }
    strcpy(tim_str, date_str);   
}

void stim_get_date_dot_auto(char* tim_str, date_format _format){
    time_t time_now;
    struct tm *mtm;
    char date_str[MAX_LEN_DATE];
    memset(date_str, 0x00, MAX_LEN_DATE*sizeof(char));
    time(&time_now);
    mtm = localtime(&time_now);

    if (_format == yyyymmdd){
        sprintf(date_str, "%04d.%02d.%02d", mtm->tm_year+1900, mtm->tm_mon+1, mtm->tm_mday);
    }
    else if (_format == ddmmyyyy){
        sprintf(date_str, "%02d.%02d.%04d", mtm->tm_mday, mtm->tm_mon+1, mtm->tm_year+1900);
    }
    else if (_format == mmddyyyy){
        sprintf(date_str, "%02d.%02d.%04d", mtm->tm_mon+1, mtm->tm_mday, mtm->tm_year+1900);
    }
    else if (_format == ddmmyy){
        char year_str[5];
        memset(year_str, 0x00, 5*sizeof(char));
        sprintf(year_str, "%04d", mtm->tm_year+1900);
        sprintf(date_str, "%02d.%02d.%c%c", mtm->tm_mon+1, mtm->tm_mday, year_str[2], year_str[3]);
    }
    strcpy(tim_str, date_str);   
}

void stim_get_date_dash_manual(char* tim_str, long _time, date_format _format){
    struct tm *mtm;
    char date_str[MAX_LEN_DATE];
    memset(date_str, 0x00, MAX_LEN_DATE*sizeof(char));
    mtm = localtime(&_time);

    if (_format == yyyymmdd){
        sprintf(date_str, "%04d-%02d-%02d", mtm->tm_year+1900, mtm->tm_mon+1, mtm->tm_mday);
    }
    else if (_format == ddmmyyyy){
        sprintf(date_str, "%02d-%02d-%04d", mtm->tm_mday, mtm->tm_mon+1, mtm->tm_year+1900);
    }
    else if (_format == mmddyyyy){
        sprintf(date_str, "%02d-%02d-%04d", mtm->tm_mon+1, mtm->tm_mday, mtm->tm_year+1900);
    }
    else if (_format == ddmmyy){
        char year_str[5];
        memset(year_str, 0x00, 5*sizeof(char));
        sprintf(year_str, "%04d", mtm->tm_year+1900);
        sprintf(date_str, "%02d-%02d-%c%c", mtm->tm_mon+1, mtm->tm_mday, year_str[2], year_str[3]);
    }
    strcpy(tim_str, date_str);
}

void stim_get_date_slash_manual(char* tim_str, long _time, date_format _format){
    struct tm *mtm;
    char date_str[MAX_LEN_DATE];
    memset(date_str, 0x00, MAX_LEN_DATE*sizeof(char));
    mtm = localtime(&_time);

    if (_format == yyyymmdd){
        sprintf(date_str, "%04d/%02d/%02d", mtm->tm_year+1900, mtm->tm_mon+1, mtm->tm_mday);
    }
    else if (_format == ddmmyyyy){
        sprintf(date_str, "%02d/%02d/%04d", mtm->tm_mday, mtm->tm_mon+1, mtm->tm_year+1900);
    }
    else if (_format == mmddyyyy){
        sprintf(date_str, "%02d/%02d/%04d", mtm->tm_mon+1, mtm->tm_mday, mtm->tm_year+1900);
    }
    else if (_format == ddmmyy){
        char year_str[5];
        memset(year_str, 0x00, 5*sizeof(char));
        sprintf(year_str, "%04d", mtm->tm_year+1900);
        sprintf(date_str, "%02d/%02d/%c%c", mtm->tm_mon+1, mtm->tm_mday, year_str[2], year_str[3]);
    }
    strcpy(tim_str, date_str);
}

void stim_get_date_colon_manual(char* tim_str, long _time, date_format _format){
    struct tm *mtm;
    char date_str[MAX_LEN_DATE];
    memset(date_str, 0x00, MAX_LEN_DATE*sizeof(char));
    mtm = localtime(&_time);

    if (_format == yyyymmdd){
        sprintf(date_str, "%04d:%02d:%02d", mtm->tm_year+1900, mtm->tm_mon+1, mtm->tm_mday);
    }
    else if (_format == ddmmyyyy){
        sprintf(date_str, "%02d:%02d:%04d", mtm->tm_mday, mtm->tm_mon+1, mtm->tm_year+1900);
    }
    else if (_format == mmddyyyy){
        sprintf(date_str, "%02d:%02d:%04d", mtm->tm_mon+1, mtm->tm_mday, mtm->tm_year+1900);
    }
    else if (_format == ddmmyy){
        char year_str[5];
        memset(year_str, 0x00, 5*sizeof(char));
        sprintf(year_str, "%04d", mtm->tm_year+1900);
        sprintf(date_str, "%02d:%02d:%c%c", mtm->tm_mon+1, mtm->tm_mday, year_str[2], year_str[3]);
    }
    strcpy(tim_str, date_str);
}

void stim_get_date_dot_manual(char* tim_str, long _time, date_format _format){
    struct tm *mtm;
    char date_str[MAX_LEN_DATE];
    memset(date_str, 0x00, MAX_LEN_DATE*sizeof(char));
    mtm = localtime(&_time);

    if (_format == yyyymmdd){
        sprintf(date_str, "%04d.%02d.%02d", mtm->tm_year+1900, mtm->tm_mon+1, mtm->tm_mday);
    }
    else if (_format == ddmmyyyy){
        sprintf(date_str, "%02d.%02d.%04d", mtm->tm_mday, mtm->tm_mon+1, mtm->tm_year+1900);
    }
    else if (_format == mmddyyyy){
        sprintf(date_str, "%02d.%02d.%04d", mtm->tm_mon+1, mtm->tm_mday, mtm->tm_year+1900);
    }
    else if (_format == ddmmyy){
        char year_str[5];
        memset(year_str, 0x00, 5*sizeof(char));
        sprintf(year_str, "%04d", mtm->tm_year+1900);
        sprintf(date_str, "%02d.%02d.%c%c", mtm->tm_mon+1, mtm->tm_mday, year_str[2], year_str[3]);
    }
    strcpy(tim_str, date_str);
}

void stim_get_time_dash_auto(char* tim_str){
    time_t time_now;
    struct tm *mtm;
    char time_str[MAX_LEN_TIME];
    memset(time_str, 0x00, MAX_LEN_TIME*sizeof(char));
    time(&time_now);
    mtm = localtime(&time_now);

    sprintf(time_str, "%02d-%02d-%02d", mtm->tm_hour, mtm->tm_min, mtm->tm_sec);
    strcpy(tim_str, time_str);
}

void stim_get_time_slash_auto(char* tim_str){
    time_t time_now;
    struct tm *mtm;
    char time_str[MAX_LEN_TIME];
    memset(time_str, 0x00, MAX_LEN_TIME*sizeof(char));
    time(&time_now);
    mtm = localtime(&time_now);

    sprintf(time_str, "%02d/%02d/%02d", mtm->tm_hour, mtm->tm_min, mtm->tm_sec);
    strcpy(tim_str, time_str);
}

void stim_get_time_colon_auto(char* tim_str){
    time_t time_now;
    struct tm *mtm;
    char time_str[MAX_LEN_TIME];
    memset(time_str, 0x00, MAX_LEN_TIME*sizeof(char));
    time(&time_now);
    mtm = localtime(&time_now);

    sprintf(time_str, "%02d:%02d:%02d", mtm->tm_hour, mtm->tm_min, mtm->tm_sec);
    strcpy(tim_str, time_str);
}

void stim_get_time_dot_auto(char* tim_str){
    time_t time_now;
    struct tm *mtm;
    char time_str[MAX_LEN_TIME];
    memset(time_str, 0x00, MAX_LEN_TIME*sizeof(char));
    time(&time_now);
    mtm = localtime(&time_now);

    sprintf(time_str, "%02d.%02d.%02d", mtm->tm_hour, mtm->tm_min, mtm->tm_sec);
    strcpy(tim_str, time_str);
}

void stim_get_time_dash_manual(char* tim_str, long time_now){
    struct tm *mtm;
    char time_str[MAX_LEN_TIME];
    memset(time_str, 0x00, MAX_LEN_TIME*sizeof(char));
    mtm = localtime(&time_now);

    sprintf(time_str, "%02d-%02d-%02d", mtm->tm_hour, mtm->tm_min, mtm->tm_sec);
    strcpy(tim_str, time_str);
}

void stim_get_time_slash_manual(char* tim_str, long time_now){
    struct tm *mtm;
    char time_str[MAX_LEN_TIME];
    memset(time_str, 0x00, MAX_LEN_TIME*sizeof(char));
    mtm = localtime(&time_now);

    sprintf(time_str, "%02d/%02d/%02d", mtm->tm_hour, mtm->tm_min, mtm->tm_sec);
    strcpy(tim_str, time_str);   
}

void stim_get_time_colon_manual(char* tim_str, long time_now){
    struct tm *mtm;
    char time_str[MAX_LEN_TIME];
    memset(time_str, 0x00, MAX_LEN_TIME*sizeof(char));
    mtm = localtime(&time_now);

    sprintf(time_str, "%02d:%02d:%02d", mtm->tm_hour, mtm->tm_min, mtm->tm_sec);
    strcpy(tim_str, time_str);
}

void stim_get_time_dot_manual(char* tim_str, long time_now){
    struct tm *mtm;
    char time_str[MAX_LEN_TIME];
    memset(time_str, 0x00, MAX_LEN_TIME*sizeof(char));
    mtm = localtime(&time_now);

    sprintf(time_str, "%02d.%02d.%02d", mtm->tm_hour, mtm->tm_min, mtm->tm_sec);
    strcpy(tim_str, time_str);
}

// Balinese Calendar
uint8_t stim_get_enum_from_str_wuku(char *_str_wuku){
    static const char *list_wuku[] = {
        "sinta",
        "landep",
        "ukir",
        "kulantir",
        "tolu",
        "gumbreg",
        "wariga",
        "warigadean",
        "julungwangi",
        "sungsang",
        "dungulan",
        "kuningan",
        "langkir",
        "medangsia",
        "pujut",
        "pahang",
        "krulut",
        "merakih",
        "tambir",
        "medangkungan",
        "matal",
        "uye",
        "menail",
        "prangbakat",
        "bala",
        "ugu",
        "wayang",
        "kelawu",
        "dukut",
        "watugunung"
    };
    for (uint8_t i=0; i<30; i++){
        if (strcmp(_str_wuku, list_wuku[i]) == 0) {
            return i;
        }
    }
    return 30;
}

uint8_t stim_get_enum_from_str_sapta_wara(char *_str_sapta_wara){
    static const char *list_sapta_wara[] = {
        "redite",
        "soma",
        "anggara",
        "budha",
        "wraspati",
        "sukra",
        "saniscara"
    };
    for (uint8_t i=0; i<7; i++){
        if (strcmp(_str_sapta_wara, list_sapta_wara[i]) == 0) {
            return i;
        }
    }
    return 7;
}

static void stim_get_balinese_wuku(struct pawukon_data *_w_data){
    if (_w_data->id == 0){
        strcpy(_w_data->name, "sinta");
        _w_data->urip = 7;
    }
    else if (_w_data->id == 1){
        strcpy(_w_data->name, "landep");
        _w_data->urip = 1;
    }
    else if (_w_data->id == 2){
        strcpy(_w_data->name, "ukir");
        _w_data->urip = 4;
    }
    else if (_w_data->id == 3){
        strcpy(_w_data->name, "kulantir");
        _w_data->urip = 6;
    }
    else if (_w_data->id == 4){
        strcpy(_w_data->name, "tolu");
        _w_data->urip = 5;
    }
    else if (_w_data->id == 5){
        strcpy(_w_data->name, "gumbreg");
        _w_data->urip = 8;
    }
    else if (_w_data->id == 6){
        strcpy(_w_data->name, "wariga");
        _w_data->urip = 9;
    }
    else if (_w_data->id == 7){
        strcpy(_w_data->name, "warigadean");
        _w_data->urip = 3;
    }
    else if (_w_data->id == 8){
        strcpy(_w_data->name, "julungwangi");
        _w_data->urip = 7;
    }
    else if (_w_data->id == 9){
        strcpy(_w_data->name, "sungsang");
        _w_data->urip = 1;
    }
    else if (_w_data->id == 10){
        strcpy(_w_data->name, "dungulan");
        _w_data->urip = 4;
    }
    else if (_w_data->id == 11){
        strcpy(_w_data->name, "kuningan");
        _w_data->urip = 6;
    }
    else if (_w_data->id == 12){
        strcpy(_w_data->name, "langkir");
        _w_data->urip = 5;
    }
    else if (_w_data->id == 13){
        strcpy(_w_data->name, "medangsia");
        _w_data->urip = 8;
    }
    else if (_w_data->id == 14){
        strcpy(_w_data->name, "pujut");
        _w_data->urip = 9;
    }
    else if (_w_data->id == 15){
        strcpy(_w_data->name, "pahang");
        _w_data->urip = 3;
    }
    else if (_w_data->id == 16){
        strcpy(_w_data->name, "krulut");
        _w_data->urip = 7;
    }
    else if (_w_data->id == 17){
        strcpy(_w_data->name, "merakih");
        _w_data->urip = 1;
    }
    else if (_w_data->id == 18){
        strcpy(_w_data->name, "tambir");
        _w_data->urip = 4;
    }
    else if (_w_data->id == 19){
        strcpy(_w_data->name, "medangkungan");
        _w_data->urip = 6;
    }
    else if (_w_data->id == 20){
        strcpy(_w_data->name, "matal");
        _w_data->urip = 5;
    }
    else if (_w_data->id == 21){
        strcpy(_w_data->name, "uye");
        _w_data->urip = 8;
    }
    else if (_w_data->id == 22){
        strcpy(_w_data->name, "menail");
        _w_data->urip = 9;
    }
    else if (_w_data->id == 23){
        strcpy(_w_data->name, "prangbakat");
        _w_data->urip = 3;
    }
    else if (_w_data->id == 24){
        strcpy(_w_data->name, "bala");
        _w_data->urip = 7;
    }
    else if (_w_data->id == 25){
        strcpy(_w_data->name, "ugu");
        _w_data->urip = 1;
    }
    else if (_w_data->id == 26){
        strcpy(_w_data->name, "wayang");
        _w_data->urip = 4;
    }
    else if (_w_data->id == 27){
        strcpy(_w_data->name, "kelawu");
        _w_data->urip = 6;
    }
    else if (_w_data->id == 28){
        strcpy(_w_data->name, "dukut");
        _w_data->urip = 5;
    }
    else if (_w_data->id == 29){
        strcpy(_w_data->name, "watugunung");
        _w_data->urip = 8;
    }
    else {
        strcpy(_w_data->name, "failed");
        _w_data->urip = 0;
    }
}

static void stim_get_balinese_eka_wara(struct pawukon_data *_w_data){
    if (_w_data->id == 0){
        strcpy(_w_data->name, "");
        _w_data->urip = 0;
    }
    else if (_w_data->id == 1){
        strcpy(_w_data->name, "luang");
        _w_data->urip = 1;
    }
    else {
        strcpy(_w_data->name, "failed");
        _w_data->urip = 0;
    }
}

static void stim_get_balinese_dwi_wara(struct pawukon_data *_w_data){
    if (_w_data->id == 0){
        strcpy(_w_data->name, "menga");
        _w_data->urip = 5;
    }
    else if (_w_data->id == 1){
        strcpy(_w_data->name, "pepet");
        _w_data->urip = 4;
    }
    else {
        strcpy(_w_data->name, "failed");
        _w_data->urip = 0;
    }
}

static void stim_get_balinese_tri_wara(struct pawukon_data *_w_data){
    if (_w_data->id == 0){
        strcpy(_w_data->name, "pasah");
        _w_data->urip = 9;
    }
    else if (_w_data->id == 1){
        strcpy(_w_data->name, "beteng");
        _w_data->urip = 4;
    }
    else if (_w_data->id == 2){
        strcpy(_w_data->name, "kajeng");
        _w_data->urip = 7;
    }
    else {
        strcpy(_w_data->name, "failed");
        _w_data->urip = 0;
    }
}

static void stim_get_balinese_catur_wara(struct pawukon_data *_w_data){
    if (_w_data->id == 0){
        strcpy(_w_data->name, "sri");
        _w_data->urip = 6;
    }
    else if (_w_data->id == 1){
        strcpy(_w_data->name, "laba");
        _w_data->urip = 5;
    }
    else if (_w_data->id == 2){
        strcpy(_w_data->name, "jaya");
        _w_data->urip = 1;
    }
    else if (_w_data->id == 3){
        strcpy(_w_data->name, "menala");
        _w_data->urip = 8;
    }
    else {
        strcpy(_w_data->name, "failed");
        _w_data->urip = 0;
    }
}

static void stim_get_balinese_panca_wara(struct pawukon_data *_w_data){
    if (_w_data->id == 0){
        strcpy(_w_data->name, "umanis");
        _w_data->urip = 5;
    }
    else if (_w_data->id == 1){
        strcpy(_w_data->name, "pahing");
        _w_data->urip = 9;
    }
    else if (_w_data->id == 2){
        strcpy(_w_data->name, "pon");
        _w_data->urip = 7;
    }
    else if (_w_data->id == 3){
        strcpy(_w_data->name, "wage");
        _w_data->urip = 4;
    }
    else if (_w_data->id == 4){
        strcpy(_w_data->name, "kliwon");
        _w_data->urip = 8;
    }
    else {
        strcpy(_w_data->name, "failed");
        _w_data->urip = 0;
    }
}

static void stim_get_balinese_sad_wara(struct pawukon_data *_w_data){
    if (_w_data->id == 0){
        strcpy(_w_data->name, "tungleh");
        _w_data->urip = 7;
    }
    else if (_w_data->id == 1){
        strcpy(_w_data->name, "aryang");
        _w_data->urip = 6;
    }
    else if (_w_data->id == 2){
        strcpy(_w_data->name, "urukung");
        _w_data->urip = 5;
    }
    else if (_w_data->id == 3){
        strcpy(_w_data->name, "paniron");
        _w_data->urip = 8;
    }
    else if (_w_data->id == 4){
        strcpy(_w_data->name, "was");
        _w_data->urip = 9;
    }
    else if (_w_data->id == 5){
        strcpy(_w_data->name, "maulu");
        _w_data->urip = 3;
    }
    else {
        strcpy(_w_data->name, "failed");
        _w_data->urip = 0;
    }
}

static void stim_get_balinese_sapta_wara(struct pawukon_data *_w_data){
    if (_w_data->id == 0){
        strcpy(_w_data->name, "redite");
        _w_data->urip = 5;
    }
    else if (_w_data->id == 1){
        strcpy(_w_data->name, "soma");
        _w_data->urip = 4;
    }
    else if (_w_data->id == 2){
        strcpy(_w_data->name, "anggara");
        _w_data->urip = 3;
    }
    else if (_w_data->id == 3){
        strcpy(_w_data->name, "budha");
        _w_data->urip = 7;
    }
    else if (_w_data->id == 4){
        strcpy(_w_data->name, "wraspati");
        _w_data->urip = 8;
    }
    else if (_w_data->id == 5){
        strcpy(_w_data->name, "sukra");
        _w_data->urip = 6;
    }
    else if (_w_data->id == 6){
        strcpy(_w_data->name, "saniscara");
        _w_data->urip = 9;
    }
    else {
        strcpy(_w_data->name, "failed");
        _w_data->urip = 0;
    }
}

static void stim_get_balinese_asta_wara(struct pawukon_data *_w_data){
    if (_w_data->id == 0){
        strcpy(_w_data->name, "sri");
        _w_data->urip = 6;
    }
    else if (_w_data->id == 1){
        strcpy(_w_data->name, "indra");
        _w_data->urip = 5;
    }
    else if (_w_data->id == 2){
        strcpy(_w_data->name, "guru");
        _w_data->urip = 8;
    }
    else if (_w_data->id == 3){
        strcpy(_w_data->name, "yama");
        _w_data->urip = 9;
    }
    else if (_w_data->id == 4){
        strcpy(_w_data->name, "ludra");
        _w_data->urip = 3;
    }
    else if (_w_data->id == 5){
        strcpy(_w_data->name, "brahma");
        _w_data->urip = 7;
    }
    else if (_w_data->id == 6){
        strcpy(_w_data->name, "kala");
        _w_data->urip = 1;
    }
    else if (_w_data->id == 7){
        strcpy(_w_data->name, "uma");
        _w_data->urip = 4;
    }
    else {
        strcpy(_w_data->name, "failed");
        _w_data->urip = 0;
    }
}

static void stim_get_balinese_sanga_wara(struct pawukon_data *_w_data){
    if (_w_data->id == 0){
        strcpy(_w_data->name, "dangu");
        _w_data->urip = 5;
    }
    else if (_w_data->id == 1){
        strcpy(_w_data->name, "jangur");
        _w_data->urip = 8;
    }
    else if (_w_data->id == 2){
        strcpy(_w_data->name, "gigis");
        _w_data->urip = 9;
    }
    else if (_w_data->id == 3){
        strcpy(_w_data->name, "nohan");
        _w_data->urip = 3;
    }
    else if (_w_data->id == 4){
        strcpy(_w_data->name, "ogan");
        _w_data->urip = 7;
    }
    else if (_w_data->id == 5){
        strcpy(_w_data->name, "erengan");
        _w_data->urip = 1;
    }
    else if (_w_data->id == 6){
        strcpy(_w_data->name, "urungan");
        _w_data->urip = 4;
    }
    else if (_w_data->id == 7){
        strcpy(_w_data->name, "tulus");
        _w_data->urip = 6;
    }
    else if (_w_data->id == 8){
        strcpy(_w_data->name, "dadi");
        _w_data->urip = 8;
    }
    else {
        strcpy(_w_data->name, "failed");
        _w_data->urip = 0;
    }
}

static void stim_get_balinese_dasa_wara(struct pawukon_data *_w_data){
    if (_w_data->id == 0){
        strcpy(_w_data->name, "pandita");
        _w_data->urip = 5;
    }
    else if (_w_data->id == 1){
        strcpy(_w_data->name, "pati");
        _w_data->urip = 8;
    }
    else if (_w_data->id == 2){
        strcpy(_w_data->name, "suka");
        _w_data->urip = 9;
    }
    else if (_w_data->id == 3){
        strcpy(_w_data->name, "duka");
        _w_data->urip = 3;
    }
    else if (_w_data->id == 4){
        strcpy(_w_data->name, "sri");
        _w_data->urip = 7;
    }
    else if (_w_data->id == 5){
        strcpy(_w_data->name, "manuh");
        _w_data->urip = 1;
    }
    else if (_w_data->id == 6){
        strcpy(_w_data->name, "manusa");
        _w_data->urip = 4;
    }
    else if (_w_data->id == 7){
        strcpy(_w_data->name, "raja");
        _w_data->urip = 6;
    }
    else if (_w_data->id == 8){
        strcpy(_w_data->name, "dewa");
        _w_data->urip = 8;
    }
    else if (_w_data->id == 9){
        strcpy(_w_data->name, "raksasa");
        _w_data->urip = 8;
    }
    else {
        strcpy(_w_data->name, "failed");
        _w_data->urip = 0;
    }
}

static void stim_get_wariga_from_pawukon_timestamp(struct balinese_calendar *_wariga, uint8_t time_in_wuku){
    _wariga->wuku.id = time_in_wuku / 7;
    _wariga->tri_wara.id = time_in_wuku % 3;
    if (time_in_wuku <= 70){
        _wariga->catur_wara.id = time_in_wuku % 4;
    }
    else if (time_in_wuku <= 73){
        _wariga->catur_wara.id = 2;
    }
    else {
        _wariga->catur_wara.id = (time_in_wuku - 2) % 4;
    }
    _wariga->panca_wara.id = (time_in_wuku + 1) % 5;
    _wariga->sad_wara.id = time_in_wuku % 6;
    _wariga->sapta_wara.id = time_in_wuku % 7;
    if (time_in_wuku <= 70){
        _wariga->asta_wara.id = time_in_wuku % 8;
    }
    else if (time_in_wuku <= 73){
        _wariga->asta_wara.id = 6;
    }
    else {
        _wariga->asta_wara.id = (time_in_wuku - 2) % 8;
    }
    if (time_in_wuku < 3){
        _wariga->sanga_wara.id = 0;
    }
    else {
        _wariga->sanga_wara.id = (time_in_wuku - 3) % 9;
    }
    stim_get_balinese_wuku(&_wariga->wuku);
    stim_get_balinese_tri_wara(&_wariga->tri_wara);
    stim_get_balinese_catur_wara(&_wariga->catur_wara);
    stim_get_balinese_panca_wara(&_wariga->panca_wara);
    stim_get_balinese_sad_wara(&_wariga->sad_wara);
    stim_get_balinese_sapta_wara(&_wariga->sapta_wara);
    stim_get_balinese_asta_wara(&_wariga->asta_wara);
    stim_get_balinese_sanga_wara(&_wariga->sanga_wara);

    _wariga->eka_wara.id = (_wariga->panca_wara.urip + _wariga->sapta_wara.urip) % 2;
    _wariga->dwi_wara.id = (_wariga->panca_wara.urip + _wariga->sapta_wara.urip) % 2;
    _wariga->dasa_wara.id = (_wariga->panca_wara.urip + _wariga->sapta_wara.urip) % 10;
    stim_get_balinese_eka_wara(&_wariga->eka_wara);
    stim_get_balinese_dwi_wara(&_wariga->dwi_wara);
    stim_get_balinese_dasa_wara(&_wariga->dasa_wara);
}

void stim_get_wariga_from_unix_timestamp(struct balinese_calendar *_wariga, long _time_input){
    long start_time_balinese_calender = 0;
    struct tm *btm = localtime(&start_time_balinese_calender);
    btm->tm_mday = 6;
    btm->tm_mon = 4;
    btm->tm_year = 0;

    btm->tm_hour = 4;
    btm->tm_min = 30;
    btm->tm_sec = 0;

    start_time_balinese_calender = mktime(btm);
    uint8_t time_in_wuku = (uint8_t)(((_time_input - start_time_balinese_calender)/(3600*24)) % 210);

    stim_get_wariga_from_pawukon_timestamp(_wariga, time_in_wuku);
}

void stim_get_wariga_from_julian_date(struct balinese_calendar *_wariga, uint8_t _mday_id, uint8_t _month_id, int _year_id){
    long _time_input = 0;
    struct tm *btm = localtime(&_time_input);
    btm->tm_mday = _mday_id;
    btm->tm_mon = _month_id - 1;
    btm->tm_year = _year_id - 1900;

    btm->tm_hour = 4;
    btm->tm_min = 30;
    btm->tm_sec = 0;

    _time_input = mktime(btm);

    stim_get_wariga_from_unix_timestamp(_wariga, _time_input);
}

void stim_get_wariga_from_wuku(struct balinese_calendar *_wariga, wuku_id _wuku_number, sapta_wara_id _sapta_wara_number){
    memset(_wariga, 0x00, sizeof(struct balinese_calendar));
    if (_wuku_number == 30 || _sapta_wara_number == 7){
        printf("%s: unrecognized input\n", __func__);
    }
    else{
        uint8_t time_in_wuku = (_wuku_number*7) + _sapta_wara_number;
        stim_get_wariga_from_pawukon_timestamp(_wariga, time_in_wuku);
    }
}

void stim_get_timestamp_from_wuku(long *_time_1, long *_time_2, uint16_t _year_id, wuku_id _wuku_number, sapta_wara_id _sapta_wara_number){
    long start_time_balinese_calender = 0;
    long time_now;
    struct tm *btm = localtime(&start_time_balinese_calender);
    btm->tm_mday = 6;
    btm->tm_mon = 4;
    btm->tm_year = 0;

    btm->tm_hour = 4;
    btm->tm_min = 30;
    btm->tm_sec = 0;

    start_time_balinese_calender = mktime(btm);
    
    time(&time_now);
    btm = localtime(&time_now);
    btm->tm_mday = 1;
    btm->tm_mon = 0;
    btm->tm_year = _year_id - 1900;

    btm->tm_hour = 4;
    btm->tm_min = 30;
    btm->tm_sec = 0;

    time_now = mktime(btm);

    uint8_t time_in_wuku = (uint8_t)(((time_now - start_time_balinese_calender)/(3600*24)) % 210);
    uint8_t wuku_number = time_in_wuku / 7;
    uint8_t sapta_wara_number = time_in_wuku % 7;
    long time_elapsed = 0;
    if (_wuku_number >= wuku_number){
        if (_sapta_wara_number >= sapta_wara_number){
            time_elapsed = (_wuku_number - wuku_number) * 7 + _sapta_wara_number - sapta_wara_number;
        }
        else {
            time_elapsed = (_wuku_number - wuku_number - 1) * 7 + (_sapta_wara_number + 7) - sapta_wara_number;
        }
    } else {
        if (_sapta_wara_number >= sapta_wara_number){
            time_elapsed = 210 - (wuku_number - _wuku_number) * 7 + _sapta_wara_number - sapta_wara_number;
        }
        else {
            time_elapsed = 210 - (wuku_number - (_wuku_number - 1)) * 7 + (_sapta_wara_number + 7) - sapta_wara_number;
        }
    }
    *_time_1 = time_now + (time_elapsed * 24 * 3600);
    *_time_2 = time_now + ((time_elapsed + 210) * 24 * 3600);
}