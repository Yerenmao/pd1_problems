#include <stdio.h>

int cur_time;

int cal_time(int hr, int min) {
    return 60 * hr + min;
}

int main(void) {
    int hr, min;
    scanf("%d:%d", &hr, &min);
    cur_time = cal_time(hr, min);
    int n; scanf("%d", &n);
    int num, hh, mm, time, dep_time, arr_time, mintime = 60*25, minnum = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d %d:%d %d", &num, &hh, &mm, &time);
        dep_time = cal_time(hh, mm);
        if(dep_time < cur_time) continue;
        arr_time = dep_time + time;
        if(arr_time < mintime) {
            mintime = arr_time;
            minnum = num;
        }
    }
    printf("%d", minnum);
    return 0;
}
