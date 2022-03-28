INCDIR =./include
SRCDIR =./src
CC_X64 = gcc
CC_AARCH64 = /usr/bin/aarch64-linux-gnu-gcc
CFLAGS = -g -Wall -I$(INCDIR)
SRC_C =$(SRCDIR)/*.c

TARGET_X64 = cipher_test_x64
TARGET_AARCH64 = cipher_test_aarch64
OUTDIR =./bin
LIBDIR =./lib

LIBS=-lm

all: $(TARGET_X64)

v_aarch64: $(TARGET_AARCH64)
 
$(TARGET_X64):
	$(CC_X64) $(CFLAGS) -o $(TARGET_X64) $(SRC_C)

$(TARGET_AARCH64):
	$(CC_AARCH64) $(CFLAGS) -o $(TARGET_AARCH64) $(SRC_C)
 
clean:
	$(RM) $(TARGET_X64) $(TARGET_AARCH64)