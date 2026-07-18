CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRCS = EnhancedStudentRegistryMAIN.c EnhancedStudentRegistry.c
OBJS = $(SRCS:.c=.o)
HEADERS = EnhancedStudentRegistry.h

ifeq ($(OS),Windows_NT)
    TARGET = EnhancedStudentRegistry.exe
    RM = del /Q
else
    TARGET = EnhancedStudentRegistry
    RM = rm -f
endif

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(TARGET)

run: all
	./$(TARGET)

.PHONY: all clean run