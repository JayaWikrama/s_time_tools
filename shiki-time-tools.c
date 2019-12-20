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