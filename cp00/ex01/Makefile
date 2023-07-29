CC = g++

CFLAGS  = -g -Wall -Wextra -Werror

TARGET = phonebook

all: $(TARGET)

$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).o

$(TARGET).o: $(TARGET).cpp $(TARGET).hpp
	$(CC) $(CFLAGS) -c $(TARGET).cpp


clean:
	$(RM) $(TARGET) $(TARGET).o

fclean:
	make clean

re: fclean all