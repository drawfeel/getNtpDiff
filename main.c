#include "getNtpDiff.h"
#include <stdio.h>

static int printResult(double diff) {
    struct timeval tv;
    char dateBuf[64] = {0};

    gettimeofday(&tv, NULL);
    //printf("tv_set:\n%s\n", ctime((time_t *) &tv.tv_sec));      //print local system time
    strftime(dateBuf, 64, "%Y-%m-%d %H:%M:%S", localtime((time_t *) &tv.tv_sec));
    printf("before eclipse:\n%s %ld\n", dateBuf, tv.tv_usec);
        printf("tv.sec:%ld\n", tv.tv_sec);

    tv.tv_sec += (int) diff;
    tv.tv_usec += diff - (int) diff;

    //if (settimeofday(&tv, NULL) != 0) { exit(-1);}      //root before

    //printf("tv_set:\n%s\n", ctime((time_t *) &tv.tv_sec));  //print user time after adding offset
    strftime(dateBuf, 64, "%Y-%m-%d %H:%M:%S", localtime((time_t *) &tv.tv_sec));
    printf("after eclipse:\n%s %ld\n", dateBuf, tv.tv_usec);
    return 0;
}

int main(int argc, char *argv[])
{
    int ret = 0;
    pthread_t get_offset_tid;

    const char * serverIp = NTP_SERVER;
    if (2 == argc) {
        serverIp = argv[1];
    }

    pthread_create(&get_offset_tid, NULL, getNtpOffset, (void*)serverIp);
    
    pthread_join(get_offset_tid, (void**)&ret);

    if(ret  < 0 ) {
        printf("get NTP error:%d\n", ret);
        return 0;
    }

    printResult(g_Ntp_Diff);

    return 0;
}
