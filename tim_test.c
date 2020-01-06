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
    stim_get_date_dash_auto(test_stim, ddmmyy);
    printf("%s\n\n", test_stim);

    stim_get_date_slash_auto(test_stim, yyyymmdd);
    printf("%s\n", test_stim);
    stim_get_date_slash_auto(test_stim, ddmmyyyy);
    printf("%s\n", test_stim);
    stim_get_date_slash_auto(test_stim, mmddyyyy);
    printf("%s\n\n", test_stim);
    stim_get_date_slash_auto(test_stim, ddmmyy);
    printf("%s\n\n", test_stim);

    stim_get_date_colon_auto(test_stim, yyyymmdd);
    printf("%s\n", test_stim);
    stim_get_date_colon_auto(test_stim, ddmmyyyy);
    printf("%s\n", test_stim);
    stim_get_date_colon_auto(test_stim, mmddyyyy);
    printf("%s\n\n", test_stim);
    stim_get_date_colon_auto(test_stim, ddmmyy);
    printf("%s\n\n", test_stim);

    stim_get_date_dot_auto(test_stim, yyyymmdd);
    printf("%s\n", test_stim);
    stim_get_date_dot_auto(test_stim, ddmmyyyy);
    printf("%s\n", test_stim);
    stim_get_date_dot_auto(test_stim, mmddyyyy);
    printf("%s\n\n", test_stim);
    stim_get_date_dot_auto(test_stim, ddmmyy);
    printf("%s\n\n", test_stim);

    stim_get_date_dash_manual(test_stim, time_manual, yyyymmdd);
    printf("%s\n", test_stim);
    stim_get_date_dash_manual(test_stim, time_manual, ddmmyyyy);
    printf("%s\n", test_stim);
    stim_get_date_dash_manual(test_stim, time_manual, mmddyyyy);
    printf("%s\n\n", test_stim);
    stim_get_date_dash_manual(test_stim, time_manual,ddmmyy);
    printf("%s\n\n", test_stim);

    stim_get_date_slash_manual(test_stim, time_manual, yyyymmdd);
    printf("%s\n", test_stim);
    stim_get_date_slash_manual(test_stim, time_manual, ddmmyyyy);
    printf("%s\n", test_stim);
    stim_get_date_slash_manual(test_stim, time_manual, mmddyyyy);
    printf("%s\n\n", test_stim);
    stim_get_date_slash_manual(test_stim, time_manual,ddmmyy);
    printf("%s\n\n", test_stim);

    stim_get_date_colon_manual(test_stim, time_manual, yyyymmdd);
    printf("%s\n", test_stim);
    stim_get_date_colon_manual(test_stim, time_manual, ddmmyyyy);
    printf("%s\n", test_stim);
    stim_get_date_colon_manual(test_stim, time_manual, mmddyyyy);
    printf("%s\n\n", test_stim);
    stim_get_date_colon_manual(test_stim, time_manual,ddmmyy);
    printf("%s\n\n", test_stim);

    stim_get_date_dot_manual(test_stim, time_manual, yyyymmdd);
    printf("%s\n", test_stim);
    stim_get_date_dot_manual(test_stim, time_manual, ddmmyyyy);
    printf("%s\n", test_stim);
    stim_get_date_dot_manual(test_stim, time_manual, mmddyyyy);
    printf("%s\n\n", test_stim);
    stim_get_date_dot_manual(test_stim, time_manual,ddmmyy);
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

    struct balinese_calendar bkl;
    time(&time_manual);
    printf("\n----\n\n");
    stim_get_wariga_from_unix_timestamp(&bkl, time_manual);
    printf("%s %s %s %s %s %s %s %s %s %s %s\n", bkl.wuku.name, bkl.dasa_wara.name, bkl.sanga_wara.name, bkl.asta_wara.name, bkl.sapta_wara.name, bkl.sad_wara.name, bkl.panca_wara.name, bkl.catur_wara.name, bkl.tri_wara.name, bkl.dwi_wara.name, bkl.eka_wara.name);
    printf("%d %d %d %d %d %d %d %d %d %d %d\n", bkl.wuku.urip, bkl.dasa_wara.urip, bkl.sanga_wara.urip, bkl.asta_wara.urip, bkl.sapta_wara.urip, bkl.sad_wara.urip, bkl.panca_wara.urip, bkl.catur_wara.urip, bkl.tri_wara.urip, bkl.dwi_wara.urip, bkl.eka_wara.urip);

    printf("\n----\n\n");
    stim_get_wariga_from_julian_date(&bkl, 14, 4, 2020);
    printf("%s %s %s %s %s %s %s %s %s %s %s\n", bkl.wuku.name, bkl.dasa_wara.name, bkl.sanga_wara.name, bkl.asta_wara.name, bkl.sapta_wara.name, bkl.sad_wara.name, bkl.panca_wara.name, bkl.catur_wara.name, bkl.tri_wara.name, bkl.dwi_wara.name, bkl.eka_wara.name);
    printf("%d %d %d %d %d %d %d %d %d %d %d\n", bkl.wuku.urip, bkl.dasa_wara.urip, bkl.sanga_wara.urip, bkl.asta_wara.urip, bkl.sapta_wara.urip, bkl.sad_wara.urip, bkl.panca_wara.urip, bkl.catur_wara.urip, bkl.tri_wara.urip, bkl.dwi_wara.urip, bkl.eka_wara.urip);
    
    printf("\n----\n\n");
    stim_get_wariga_from_wuku(&bkl, stim_get_enum_from_str_wuku("krulut"), stim_get_enum_from_str_sapta_wara("wra"));
    printf("%s %s %s %s %s %s %s %s %s %s %s\n", bkl.wuku.name, bkl.dasa_wara.name, bkl.sanga_wara.name, bkl.asta_wara.name, bkl.sapta_wara.name, bkl.sad_wara.name, bkl.panca_wara.name, bkl.catur_wara.name, bkl.tri_wara.name, bkl.dwi_wara.name, bkl.eka_wara.name);
    printf("%d %d %d %d %d %d %d %d %d %d %d\n", bkl.wuku.urip, bkl.dasa_wara.urip, bkl.sanga_wara.urip, bkl.asta_wara.urip, bkl.sapta_wara.urip, bkl.sad_wara.urip, bkl.panca_wara.urip, bkl.catur_wara.urip, bkl.tri_wara.urip, bkl.dwi_wara.urip, bkl.eka_wara.urip);

    printf("\n----\n\n");

    long time_manual_2 = 0;
    stim_get_timestamp_from_wuku(&time_manual, &time_manual_2, 1996, krulut, redite);
    stim_get_date_custom_manual(test_stim, time_manual, date_format_custom2_id);
    printf("%s\n", test_stim);
    stim_get_date_custom_manual(test_stim, time_manual_2, date_format_custom2_id);
    printf("%s\n", test_stim);

    printf("size enum date_format: %d\n", (int)sizeof(date_format));
    printf("size enum custom_date_format: %d\n", (int)sizeof(custom_date_format));
    printf("size balinese struct pawukon: %d\n", (int)sizeof(struct pawukon_data));
    printf("size balinese struct wariga: %d\n", (int)sizeof(struct balinese_calendar));

    printf("\ntest dengan inet\n");
    stim_get_date_dash_manual(test_stim, stim_get_net_time("www.google.com", 80), ddmmyyyy);
    printf("%s\n", test_stim);
    stim_get_time_colon_manual(test_stim, stim_get_net_time("www.google.com", 80));
    printf("%s\n", test_stim);

    stim_set_time_from_inet("www.google.com", 80, 7);

}