CC = g++

CFLAGS  = -g -Wall -Wextra -Werror

TARGET = main
SOURCES = main.cpp Contact.cpp PhoneBook.cpp
OBJ = main.o Contact.o PhoneBook.o

all: exec

exec: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

$(TARGET).o: $(TARGET).cpp PhoneBook.hpp Contact.hpp
	$(CC) $(CFLAGS) -c $(TARGET).cpp

Contact.o: Contact.cpp	PhoneBook.hpp Contact.hpp
	$(CC) $(CFLAGS) -c Contact.cpp

PhoneBook.o: PhoneBook.cpp	PhoneBook.hpp Contact.hpp
	$(CC) $(CFLAGS) -c PhoneBook.cpp

clean:
	$(RM) main $(OBJ)

fclean:
	make clean

re: fclean all