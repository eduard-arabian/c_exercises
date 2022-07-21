CC = gcc
CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror
CFLAGS += -Wmissing-declarations
CFLAGS += -DUNITY_SUPPORT_64 -DUNITY_OUTPUT_COLOR

ifeq ($(OS), Windows_NT)
	EXECUTABLE = exe
	REMOVE = del
else
	EXECUTABLE = out
	REMOVE = rm -rf
endif

all :: p1 p2

p1 :: integer_checker malloc_with_size void_casting prime_number armstrong_number isotest hamtest gratest

p2 :: test_difference_of_squares test_square_root test_grade_school

rebuild :: clean all

clean ::
	$(REMOVE) *.o *.$(EXECUTABLE)

unity ::
	@$(CC) $(CFLAGS) -c test-framework/unity.c

palindrome_number :: integer
	@$(CC) $(CFLAGS) integer.o palindrome_number.c -o palindrome_number.$(EXECUTABLE)

grade_school ::
	@$(CC) $(CFLAGS) -c grade_school.c

test_grade_school :: unity grade_school
	@$(CC) $(CFLAGS) unity.o grade_school.o test_grade_school.c -o test_grade_school.$(EXECUTABLE)

square_root ::
	@$(CC) $(CFLAGS) -c square_root.c

test_square_root :: unity square_root
	@$(CC) $(CFLAGS) unity.o square_root.o test_square_root.c -o test_square_root.$(EXECUTABLE)

difference_of_squares ::
	@$(CC) $(CFLAGS) -c difference_of_squares.c

test_difference_of_squares :: unity difference_of_squares
	@$(CC) $(CFLAGS) unity.o difference_of_squares.o test_difference_of_squares.c -o test_difference_of_squares.$(EXECUTABLE)

grains ::
	@$(CC) $(CFLAGS) -c grains.c

gratest :: grains
	@$(CC) $(CFLAGS) grains.o gratest.c -o gratest.$(EXECUTABLE)

hamming ::
	@$(CC) $(CFLAGS) -c hamming.c

hamtest :: hamming
	@$(CC) $(CFLAGS) hamming.o hamtest.c -o hamtest.$(EXECUTABLE)

isogram ::
	@$(CC) $(CFLAGS) -c isogram.c

isotest :: isogram
	@$(CC) $(CFLAGS) isogram.o isotest.c -o isotest.$(EXECUTABLE)

integer ::
	@$(CC) $(CFLAGS) -c integer.c

integer_checker :: integer
	@$(CC) $(CFLAGS) integer.o integer_checker.c -o integer_checker.$(EXECUTABLE)

malloc_with_size ::
	@$(CC) $(CFLAGS) malloc_with_size.c -o malloc_with_size.$(EXECUTABLE)

prime_number :: integer
	@$(CC) $(CFLAGS) integer.o prime_number.c -o prime_number.$(EXECUTABLE)

void_casting ::
	@$(CC) $(CFLAGS) void_casting.c -o void_casting.$(EXECUTABLE)

armstrong_number ::
	@$(CC) $(CFLAGS) armstrong_number.c -o armstrong_number.$(EXECUTABLE)

resistor_color ::
	@$(CC) $(CFLAGS) -c resistor_color.c

lint ::
	@python3 ./cpplint.py --extensions=c *.c
	@python3 ./cpplint.py --extensions=h *.h
ifneq ($(OS), Windows_NT)
	@cppcheck --enable=all --inconclusive --suppress=missingIncludeSystem *.c *.h
endif
