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

all :: integer_checker malloc_with_size void_casting prime_number armstrong_number isotest hamtest gratest

rebuild :: clean all

clean ::
	$(REMOVE) *.o *.$(EXECUTABLE)

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
