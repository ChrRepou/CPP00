#include <iostream>
#include <cctype>
#include <cstring>

//simple program that takes one string argument
//and print it in uppercase

int main(int argc, char *argv[])
{
	int	i;
	if (argc == 1 || strlen(argv[1]) == 0)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	if (argc == 2)
	{
		for (size_t x=0; x < strlen(argv[1]); x++)
			putchar(toupper(argv[1][x]));
		std::cout << "\n";
	}
	else
	{
		i = 1;
		while(argv[i])
		{
			for (size_t x=0; x < strlen(argv[i]); x++)
				putchar(toupper(argv[i][x]));
			i++;
		}
		std::cout << "\n";
	}
	return 0;
}
