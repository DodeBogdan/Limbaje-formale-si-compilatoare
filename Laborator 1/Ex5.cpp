/*5.	Scrieți un subprogram care să citească n cuvinte de 
la tastatură și care să le sorteze în ordine crescătoare*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

void metoda()
{
	std::vector<std::string> vec;
	int n;
	std::string str;

	std::cout << "Input for number of elements: ";
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cout << "Input string: ";
		std::cin >> str;
		vec.push_back(str);
	}

	std::sort(vec.begin(), vec.end());

	for (int i = 0; i < n; i++)
	{
		std::cout << i + 1 << "." << vec[i] << std::endl;
	}
}

int main()
{
	metoda();
	return 0;
}