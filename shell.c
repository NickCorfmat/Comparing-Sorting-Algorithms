#include <stdio.h>
#include "shell.h"
#include "gaps.h"
#include "stats.h"

void shell_sort(Stats *stats, uint32_t *arr, uint32_t length) {
	
	for (uint32_t element = 0; element < GAPS; element++) {
		uint32_t gap = gaps[element]; // For every gap in GAPS
		
		for (uint32_t i = gap; i < length; i++) {
			uint32_t j = i;
			uint32_t temp = move(stats, arr[i]); // Move

			while (j >= gap && cmp(stats, temp, arr[j - gap]) == -1) { // Compare
				arr[j] = move(stats, arr[j - gap]); // Move
				j -= gap;
			}

			arr[j] = move(stats, temp); // Move
		}
	}
}
