#include <iostream>
#include <cctype>
#include <cstring>

//simple program that takes one string argument
//and print it in uppercase

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		for (size_t x=0; x < strlen(argv[1]); x++)
			putchar(toupper(argv[1][x]));
		std::cout << "\n";
	}
	return 0;
}
