#include <iostream>
#include "Minimizare.h"
#include <Windows.h>

int main()
{
	Minimizare minimizare;
	minimizare.MinimizareAFD("input.txt");
	std::cout << minimizare;
	minimizare.ScriereFisier("out.txt");
	AFD afd;
	afd.Citire("out.txt");
	std::cout << afd;

	std::cout << "Cate cuvinte sa intre in automat?: ";
	int numberOfWords;
	std::cin >> numberOfWords;
	for (int index = 0; index < numberOfWords; index++)
	{
		std::string cuvant;
		std::cout << "Introduceti cuvantul: ";
		std::cin >> cuvant;
		afd.Verificare(cuvant, 0);
	}
	return 0;
}