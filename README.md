Nicolas Corfmat
ncorfmat
1890805
Assignment 3: Sorting - Putting your affairs in order

DESCRIPTION

This program sorts arrays of pseudo-random numbers using the following four algorithms: Shell Sort, Heap Sort, Batcher Sort, and Quicksort. The program simultaneously tracks the number of moves, compares, and swaps performed by each sorting algorithm, and conveniently plots this information on a graph.

BUILD

To build, run 'make' or 'make all" on the terminal command line within the assignment 3 directory. This creates the 'sorting, heap, batcher, shell, quick, stats, and set' executable files which can then be run.

CLEAN

Running 'make clean' will remove all the executable (.o) files, all data files, and previously generated PDF graphs from the assignment 3 directory.

RUNNING

To run, type './sorting' followed by any one of these arguments: -a -h -b -s -q -r -n -p -H. Running '-a' runs all four sorting algorithms with a default array size of 100. '-h, -b, -s, and -q' correspond to Heap Sort, Batcher Sort, Shell Sort, and Quicksort, respectively. To change the seed (which is 13371453 by default), simply run '-r', followed by a number, after specifying your desired sorting algorithm. Similarly, '-n' takes an arugment 'size' which allows the user to specify the desired array size to sort. Running '-p' followed by a number prints out that number of elements from the sorted array. Lastly, '-H' prints out the program usage.
