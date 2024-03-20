#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdlib.h>
#include "shell.h"
#include "heap.h"
#include "quick.h"
#include "batcher.h"
#include "set.h"
#include "stats.h"

#define OPTIONS "Hasbhqn:p:r:"

uint32_t fill_random(uint32_t *Array, uint32_t size, uint32_t seed);

uint32_t print_array(uint32_t *Array, uint32_t size);

int main(int argc, char **argv) {

        uint32_t opt = 0;
        uint32_t size = 100; // Default array size
        uint32_t default_elements = 100; // Default elements to print
	uint32_t seed = 13371453; // Default seed value
	uint32_t *random_array;
	Stats stats;
	
	Set commands = set_empty(); // Creates an empty set

	while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
		switch (opt) {

		case 'a':
			commands = set_insert(commands, 1); // Runs Heap Sort
			commands = set_insert(commands, 2); // Runs Batcher Sort
			commands = set_insert(commands, 3); // Runs Shell Sort
			commands = set_insert(commands, 4); // Runs Quick Sort

			break;
		case 'h': // Heap Sort
			commands = set_insert(commands, 1);

			break;
		case 'b': // Batcher Sort
			commands = set_insert(commands, 2);

			break;
		case 's': // Shell Sort
			commands = set_insert(commands, 3);

			break;
		case 'q': // Quick Sort
			commands = set_insert(commands, 4);

			break;
		case 'r': // Set seed
			seed = strtoul(optarg, NULL, 10);
			
			break;
		case 'n': // Set array size
			size = strtoul(optarg, NULL, 10);

			break;
		case 'p': // Prints out 'elements' number of elements
		        default_elements = atoi(optarg);

			break;
		case 'H': // Prints out program usage
		        printf("SYNOPSIS\n");
                        printf("   A collection of comparison-based sorting algorithms.\n\n");
                        printf("USAGE\n");
                        printf("   ./sorting [-Hasbhqn:p:r:] [-n length] [-p elements] [-r seed]\n\n");
                        printf("OPTIONS\n");
                        printf("   -H              Display program help and usage.\n");
                        printf("   -a              Enable all sorts.\n");
                        printf("   -s              Enable Shell Sort.\n");
                        printf("   -b              Enable Batcher Sort.\n");
                        printf("   -h              Enable Heap Sort.\n");
                        printf("   -q              Enable Quick Sort.\n");
                        printf("   -n length       Specify number of array elements (default: 100).\n");
                        printf("   -p elements     Specify number of elements to print (default: 100).\n");
                        printf("   -r seed         Specify random seed (default: 13371453).\n");
			

			break;
			
		}
	}	

	random_array = malloc(size * sizeof(uint32_t));
	
	if (default_elements > size) {
	        default_elements = size; // prevents out of bounds error
	}
	
	if (set_member(commands, 1)) {
	        fill_random(random_array, size, seed);
		heap_sort(&stats, random_array, size);

		printf("Heap Sort, %d elements, %lu moves, %lu compares", size, stats.moves, stats.compares);
		print_array(random_array, default_elements);
		
		reset(&stats);
	        free(random_array);
	}
	
	if (set_member(commands, 2)) {
		fill_random(random_array, size, seed);
		batcher_sort(&stats, random_array, size);

		printf("Batcher Sort, %d elements, %lu moves, %lu compares", size, stats.moves, stats.compares);
		print_array(random_array, default_elements);
		
		reset(&stats);
	        free(random_array);
	}
	
	if (set_member(commands, 3)) {
		fill_random(random_array, size, seed);
		shell_sort(&stats, random_array, size);

		printf("Shell Sort, %d elements, %lu moves, %lu compares", size, stats.moves, stats.compares);
		print_array(random_array, default_elements);
		
		reset(&stats);
	        free(random_array);
	}
	
	if (set_member(commands, 4)) {
		fill_random(random_array, size, seed);
		quick_sort(&stats, random_array, size);

		printf("Quick Sort, %d elements, %lu moves, %lu compares", size, stats.moves, stats.compares);
		print_array(random_array, default_elements);
		
		reset(&stats);
	        free(random_array);
	}

}

// Functions fill_random() and print_array() given by Darrell Long
// and manipulated to work in the context of sorting.c
	
uint32_t fill_random(uint32_t *Array, uint32_t size, uint32_t seed) {
	srandom(seed);

	for (uint32_t i = 0; i < size; i++) {
		Array[i] = random() & 0x3fffffff;
	}
	return 0;
}

uint32_t print_array(uint32_t *Array, uint32_t default_elements) {

	for (uint32_t i = 0; i < default_elements; i++) {
		if (i % 5 == 0) {
			printf("\n");
		}
		printf("%13" PRIu32, Array[i]);
		if(i == default_elements - 1){
			printf("\n");
		}
	}
	printf("\n");
	return 0;
}
