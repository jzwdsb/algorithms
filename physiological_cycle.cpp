//
// Created by manout on 17-9-26.
//
#include "common_use.h"

static const int physical_cycle = 23;
static const int emontial_cycle = 28;
static const int intellal_cycle = 33;
int physiological_cycle(int d, int p, int e, int i)
{
	int k = d + 1;
	while ((k - p) % physical_cycle not_eq 0)++k;
	while ((k - e) % emontial_cycle not_eq 0)k += physical_cycle;
	while ((k - i) % intellal_cycle not_eq 0)k += physical_cycle * emontial_cycle;
	return k - d;
}
