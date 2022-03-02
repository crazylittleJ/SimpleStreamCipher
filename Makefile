INCDIR =./include
SRCDIR =./src
CC = gcc
CFLAGS = -g -Wall -I$(INCDIR)
SRC_C =$(SRCDIR)/*.c

TARGET = cipher_test
OUTDIR =./bin
LIBDIR =./lib

LIBS=-lm

all: $(TARGET)
 
$(TARGET):
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC_C)
 
clean:
	$(RM) $(TARGET)