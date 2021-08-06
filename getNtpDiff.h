#ifndef GET_NTP_DIFF_H
#define GET_NTP_DIFF_H
#include <pthread.h>
#include <sys/time.h>

//#define NTP_SERVER "time1.aliyun.com"
//#define NTP_SERVER "time2.aliyun.com"
//#define NTP_SERVER "time3.aliyun.com"
//#define NTP_SERVER "time4.aliyun.com"
#define NTP_SERVER "time5.aliyun.com"
//#define NTP_SERVER "time6.aliyun.com"
//#define NTP_SERVER "time7.aliyun.com"
//#define NTP_SERVER "clock.fmt.he.net"
//#define NTP_SERVER "clock.nyc.he.net"
//#define NTP_SERVER "clock.sjc.he.net"
//#define NTP_SERVER "ntp1.tummy.com"
//#define NTP_SERVER "time.nist.gov"
//#define NTP_SERVER "time-a.nist.gov"
//#define NTP_SERVER "time-b.nist.gov"

#define NTP_SERVER "time5.aliyun.com"
extern double g_Ntp_Diff;

extern void* getNtpOffset (void* serverIp);
#endif //GET_NTP_DIFF_H
