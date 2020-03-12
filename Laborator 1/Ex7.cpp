/*7.	Se dă un vector de cuvinte v și un subșir de caractere s1. Să se rețină într-un alt vector, toate cuvintele din v, care conțin subșirul s1.  */
#include <iostream>
#include <vector>
#include <string>
//Dintr-un vector de cuvinte se afiseaza cuvintele ce contin un anumit string.
int main()
{
	std::vector<std::string> vecInit;
	std::vector<std::string> vecFin;
	int dimv;

	std::cout << "Input for vector dimension: ";
	std::cin >> dimv;

	for (int i = 0; i < dimv; i++)
	{
		std::string s1;
		std::cout << "Input string: ";
		std::cin >> s1;
		vecInit.push_back(s1);
	}

	std::string s1;

	std::cout << "Input for searching string: ";
	std::cin >> s1;

	for (int i = 0; i < vecInit.size(); i++)
	{
		if (vecInit[i].find(s1) != -1)
			vecFin.push_back(vecInit[i]);
	}

	for (int i = 0; i < vecFin.size(); i++)
		std::cout << i + 1 << "." << vecFin[i] << std::endl;

	return 0;
}