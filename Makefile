CC = gcc
CFLAGS = -Wall -Werror -Wextra

all :: integer_checker malloc_with_size void_casting prime_number armstrong_number

rebuild :: clean all

clean ::
	rm *.o integer_checker malloc_with_size prime_number void_casting
	rm armstrong_number

integer ::
	$(CC) $(CFLAGS) -c integer.c

integer_checker :: integer
	$(CC) $(CFLAGS) integer.o integer_checker.c -o integer_checker

malloc_with_size ::
	$(CC) $(CFLAGS) malloc_with_size.c -o malloc_with_size

prime_number :: integer
	$(CC) $(CFLAGS) integer.o prime_number.c -o prime_number

void_casting ::
	$(CC) $(CFLAGS) void_casting.c -o void_casting

armstrong_number ::
	$(CC) $(CFLAGS) armstrong_number.c -o armstrong_number

lint ::
	@python3 ./cpplint.py --extensions=c *.c
	@python3 ./cpplint.py --extensions=h *.h
	@cppcheck --enable=all --inconclusive --suppress=missingIncludeSystem *.c *.h
