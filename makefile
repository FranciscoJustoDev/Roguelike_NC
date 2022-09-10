CC = gcc
CFLAGS = -lncurses -I$(IDIR)

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c

all: game run clean

game:
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run:
	./game

clean:
	rm game