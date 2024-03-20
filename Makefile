CC = clang
Cflags = -Wall -Wpedantic -Werror -Wextra
LIBFLAGS = -lm

all = sorting

sorting: sorting.o heap.o sorting.o batcher.o shell.o quick.o set.o stats.o
	$(CC) -o $@ $^ $(LIBFLAGS)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $<
	
clean:
	rm -f sorting *.o
	
format:
	clang-format -i -style=file *.o [ch]
