#include "batcher.h"
#include "stats.h"
#include <stdio.h>

uint32_t lg(int n);

void comparator(Stats *stats, uint32_t *A, uint32_t x, uint32_t y) {
	if (cmp(stats, A[x], A[y]) == 1) { // Compare
		swap(stats, &A[x], &A[y]); // Swap
	}
}

void batcher_sort(Stats *stats, uint32_t *A, uint32_t n) {
	if (n == 0) {
		return;
	}

	uint32_t t = lg((int) n);
	uint32_t p = 1 << (t - 1);
	
	while (p > 0) {
		uint32_t q = 1 << (t - 1);
		uint32_t r = 0;
		uint32_t d = p;

		while (d > 0) {
			for (uint32_t i = 0; i < (n - d); i++) {
				if ((i & p) == r) {
					comparator(stats, A, i, i + d);
				}
			}

			d = q - p;
			q >>= 1;
			r = p;

		}

		p >>= 1;
	}
}

// BEGIN code from Darrell Long

uint32_t lg(int n) {
	int k = -1;

	while (n > 0) {
		n = n/2;
		k += 1;
	}

	return (uint32_t) k + 1;
}

// END code from Darrell Long
