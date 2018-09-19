/*
** EPITECH PROJECT, 2018
** Benchmark
** File description:
** main file of the benchmarks
*/

#include "benchmark.h"

static void bench_check_args(void)
{
	long long int itteration = 123456;
	int i = 0;
	bench_timer_t *timers = bench_start_timers();

	while (i < itteration) {
		check_args(1);
		i++;
	}
	bench_end_timer(timers);
	bench_write_report(timers, i, "check args valid");
}

int main(void)
{
	bench_check_args();
	return (0);
}
