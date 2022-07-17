CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror
CFLAGS += -Wmissing-declarations
CFLAGS += -DUNITY_SUPPORT_64 -DUNITY_OUTPUT_COLOR

ASANFLAGS  = -fsanitize=address
ASANFLAGS += -fno-common
ASANFLAGS += -fno-omit-frame-pointer

ifeq ($(OS), Windows_NT)
	EXECUTABLE = exe
	REMOVE = del
else
	EXECUTABLE = out
	REMOVE = rm -rf
endif

all :: integer_checker malloc_with_size void_casting prime_number armstrong_number

rebuild :: clean all

clean ::
	$(REMOVE) *.o *.$(EXECUTABLE)

integer ::
	@$(CC) $(ASANFLAGS) $(CFLAGS) -c integer.c

integer_checker :: integer
	@$(CC) $(ASANFLAGS) $(CFLAGS) integer.o integer_checker.c -o integer_checker.out

malloc_with_size ::
	@$(CC) $(ASANFLAGS) $(CFLAGS) malloc_with_size.c -o malloc_with_size.out

prime_number :: integer
	@$(CC) $(ASANFLAGS) $(CFLAGS) integer.o prime_number.c -o prime_number.out

void_casting ::
	@$(CC) $(ASANFLAGS) $(CFLAGS) void_casting.c -o void_casting.out

armstrong_number ::
	@$(CC) $(ASANFLAGS) $(CFLAGS) armstrong_number.c -o armstrong_number.out

resistor_color ::
	@$(CC) $(ASANFLAGS) $(CFLAGS) -c resistor_color.c

lint ::
	@python3 ./cpplint.py --extensions=c *.c
	@python3 ./cpplint.py --extensions=h *.h
ifneq ($(OS), Windows_NT)
	@cppcheck --enable=all --inconclusive --suppress=missingIncludeSystem *.c *.h
endif
