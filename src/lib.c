/*
** EPITECH PROJECT, 2018
** lib.c
** File description:
** Contains all the lib functions
*/

#include "benchmark.h"

bench_timer_t *bench_start_timers(void)
{
	bench_timer_t *timers = malloc(sizeof(bench_timer_t) * 2);

	if (timers == NULL) {
		printf("Couldn't use allocate memory.\n");
		exit(1);
	}
	ftime(&timers[0]);
	return (timers);
}

/*
** Return a float corresponding to the number of second elapsed
** between the two given timers.
** Take the array of timers as parameters.
*/
float bench_get_elapsed_time(bench_timer_t *timers)
{
	double diff = 0.0;
	
	diff = (1000.0 * (timers[1].time - timers[0].time) +
			(timers[1].millitm - timers[0].millitm));
	return (diff / 1000);
}

void bench_end_timer(bench_timer_t *timers)
{
	ftime(&timers[1]);
}

float bench_get_average_time(float elapsed, long itteration)
{
	return (elapsed / itteration * 1e+6);
}

void bench_close_timers(bench_timer_t *timers)
{
	free(timers);
}

void bench_write_report(bench_timer_t *timers, int itteration, char *desc)
{
	float elapsed = bench_get_elapsed_time(timers);
	float average = bench_get_average_time(elapsed, itteration);

	bench_close_timers(timers);
	printf("%s: %d loops in %.5f second with an average of %.5f"\
		" microsecond by loop.\n",
		desc, itteration, elapsed, average);
}