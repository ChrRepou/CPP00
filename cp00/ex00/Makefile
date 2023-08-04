CC = g++

CFLAGS  = -g -Wall -Wextra -Werror

TARGET = Megaphone

all: $(TARGET)

$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).o

$(TARGET).o: $(TARGET).cpp
	$(CC) $(CFLAGS) -c $(TARGET).cpp

clean:
	$(RM) $(TARGET) $(TARGET).o

fclean:
	make clean

re: fclean all