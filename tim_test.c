#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "shiki-time-tools.h"

int main(){
    time_t time_manual = 2000000;
    char test_stim[28];

    stim_get_date_custom_auto(test_stim, date_format_custom1_id);
    printf("%s\n", test_stim);
    stim_get_date_custom_auto(test_stim, date_format_custom2_id);
    printf("%s\n", test_stim);
    stim_get_date_custom_auto(test_stim, date_format_custom1_eng);
    printf("%s\n", test_stim);
    stim_get_date_custom_auto(test_stim, date_format_custom2_eng);
    printf("%s\n\n", test_stim);

    stim_get_date_custom_manual(test_stim, time_manual, date_format_custom1_id);
    printf("%s\n", test_stim);
    stim_get_date_custom_manual(test_stim, time_manual, date_format_custom2_id);
    printf("%s\n", test_stim);
    stim_get_date_custom_manual(test_stim, time_manual, date_format_custom1_eng);
    printf("%s\n", test_stim);
    stim_get_date_custom_manual(test_stim, time_manual, date_format_custom2_eng);
    printf("%s\n\n", test_stim);

    stim_get_date_dash_auto(test_stim, yyyymmdd);
    printf("%s\n", test_stim);
    stim_get_date_dash_auto(test_stim, ddmmyyyy);
    printf("%s\n", test_stim);
    stim_get_date_dash_auto(test_stim, mmddyyyy);
    printf("%s\n\n", test_stim);

    stim_get_date_slash_auto(test_stim, yyyymmdd);
    printf("%s\n", test_stim);
    stim_get_date_slash_auto(test_stim, ddmmyyyy);
    printf("%s\n", test_stim);
    stim_get_date_slash_auto(test_stim, mmddyyyy);
    printf("%s\n\n", test_stim);

    stim_get_date_colon_auto(test_stim, yyyymmdd);
    printf("%s\n", test_stim);
    stim_get_date_colon_auto(test_stim, ddmmyyyy);
    printf("%s\n", test_stim);
    stim_get_date_colon_auto(test_stim, mmddyyyy);
    printf("%s\n\n", test_stim);

    stim_get_date_dot_auto(test_stim, yyyymmdd);
    printf("%s\n", test_stim);
    stim_get_date_dot_auto(test_stim, ddmmyyyy);
    printf("%s\n", test_stim);
    stim_get_date_dot_auto(test_stim, mmddyyyy);
    printf("%s\n\n", test_stim);

    stim_get_date_dash_manual(test_stim, time_manual, yyyymmdd);
    printf("%s\n", test_stim);
    stim_get_date_dash_manual(test_stim, time_manual, ddmmyyyy);
    printf("%s\n", test_stim);
    stim_get_date_dash_manual(test_stim, time_manual, mmddyyyy);
    printf("%s\n\n", test_stim);

    stim_get_date_slash_manual(test_stim, time_manual, yyyymmdd);
    printf("%s\n", test_stim);
    stim_get_date_slash_manual(test_stim, time_manual, ddmmyyyy);
    printf("%s\n", test_stim);
    stim_get_date_slash_manual(test_stim, time_manual, mmddyyyy);
    printf("%s\n\n", test_stim);

    stim_get_date_colon_manual(test_stim, time_manual, yyyymmdd);
    printf("%s\n", test_stim);
    stim_get_date_colon_manual(test_stim, time_manual, ddmmyyyy);
    printf("%s\n", test_stim);
    stim_get_date_colon_manual(test_stim, time_manual, mmddyyyy);
    printf("%s\n\n", test_stim);

    stim_get_date_dot_manual(test_stim, time_manual, yyyymmdd);
    printf("%s\n", test_stim);
    stim_get_date_dot_manual(test_stim, time_manual, ddmmyyyy);
    printf("%s\n", test_stim);
    stim_get_date_dot_manual(test_stim, time_manual, mmddyyyy);
    printf("%s\n\n", test_stim);


    stim_get_time_dash_auto(test_stim);
    printf("%s\n", test_stim);
    stim_get_time_slash_auto(test_stim);
    printf("%s\n", test_stim);
    stim_get_time_colon_auto(test_stim);
    printf("%s\n", test_stim);
    stim_get_time_dot_auto(test_stim);
    printf("%s\n\n", test_stim);

    stim_get_time_dash_manual(test_stim, time_manual);
    printf("%s\n", test_stim);
    stim_get_time_slash_manual(test_stim, time_manual);
    printf("%s\n", test_stim);
    stim_get_time_colon_manual(test_stim, time_manual);
    printf("%s\n", test_stim);
    stim_get_time_dot_manual(test_stim, time_manual);
    printf("%s\n\n", test_stim);
    return 0;
}