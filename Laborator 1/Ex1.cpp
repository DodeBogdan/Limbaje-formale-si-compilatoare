/*1.	Să se determine de câte ori apare un anumit caracter într-un șir de caractere dat. */
#include <iostream>
#include <string>

int main()
{
	std::string string, character;
	int count = 0;

	std::cout << "Enter the string: ";
	std::getline(std::cin, string);

	std::cout << "Enter the character: ";
	std::cin >> character;

	for (int i = 0; i < string.length(); ++i)
	{
		if (string[i] == character[0])
			count++;
	}
	
	std::cout << "The string is: ";
	std::cout << string;
	std::cout << "\nThe number of character aparition is: " << count<<std::endl;
	return 0;
}