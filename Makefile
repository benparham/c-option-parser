CC = gcc
AR = ar

CFLAGS = -g -Wall -std=c99
ARFLAGS = ru

OPTION_PARSER = option-parser.a

SRC = option-parser.c
INC = option-parser.h
OBJ = option-parser.o

all: $(OPTION_PARSER)

$(OPTION_PARSER): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^
	ranlib $@

$(OBJ): $(SRC) $(INC)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm $(OBJ)
	@rm $(OPTION_PARSER)