TARGET = Student_Registry.exe
SRC = Student_Registry.c Student_RegistryFINALMAIN.c
OBJ = Student_Registry.o Student_RegistryFINALMAIN.o

all:$(TARGET)

$(TARGET): $(OBJ)
	gcc $(OBJ) -o $(TARGET)

%.o: %.c
	gcc -c $< -o $@

run:all
	./$(TARGET)

clean:
	del /f $(OBJ) $(TARGET)