CC = gcc
AR = ar

CFLAGS = -g -Wall -std=c99 -I .
ARFLAGS = ru

TARGET = liboptions.a

SRC = option-parser.c
INC = option-parser.h
OBJ = option-parser.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^
	ranlib $@

$(OBJ): $(SRC) $(INC)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm $(OBJ)
	@rm $(TARGET)