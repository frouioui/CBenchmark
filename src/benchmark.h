
#if !defined(__BENCHMARK)
#define __BENCHMARK

#include <stdlib.h>
#include <stdio.h>
#include <sys/timeb.h>
#include <time.h>

typedef struct timeb bench_timer_t;

bench_timer_t *bench_start_timers(void);
float bench_get_elapsed_time(bench_timer_t *timers);
void bench_write_report(bench_timer_t *timers, int itteration, char *desc);
void bench_close_timers(bench_timer_t *timers);
void bench_end_timer(bench_timer_t *timers);

#endif // __BENCHMARK
