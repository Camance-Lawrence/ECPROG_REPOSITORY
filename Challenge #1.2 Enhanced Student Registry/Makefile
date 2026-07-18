TARGET = TEST.exe
SRC = EnhancedStudentRegistry.c EnhancedStudentRegistryMAIN.c
OBJ = EnhancedStudentRegistry.o EnhancedStudentRegistryMAIN.o

all:$(TARGET)

$(TARGET): $(OBJ)
	gcc $(OBJ) -o $(TARGET)

%.o: %.c
	gcc -c $< -o $@

run:all
	./$(TARGET)

clean:
	del /f $(OBJ) $(TARGET)