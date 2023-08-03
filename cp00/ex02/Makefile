CC = g++

CFLAGS  = -g -Wall -Wextra -Werror

TARGET = Account
SOURCES = tests.cpp Account.cpp
OBJ = tests.o Account.o

all: main

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

$(TARGET).o: $(TARGET).cpp $(TARGET).hpp
	$(CC) $(CFLAGS) -c $(TARGET).cpp

tests.o: tests.cpp	$(TARGET).hpp
	$(CC) $(CFLAGS) -c tests.cpp

clean:
	$(RM) main $(OBJ)

fclean:
	make clean

re: fclean all