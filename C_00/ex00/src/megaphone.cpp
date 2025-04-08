#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		std::string word(argv[i]);
		for (size_t j = 0; j < word.size(); j++)
		{
			std::cout << (char)toupper(word[j]);
		}
	}
	std::cout << "\n";
	return 0;
}
