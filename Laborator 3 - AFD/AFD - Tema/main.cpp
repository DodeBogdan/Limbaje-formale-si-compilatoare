#include "AFD.h"
#include <Windows.h>

int main()
{
	AFD afd;
	afd.Citire();
	std::cout << afd;
	std::cout << "Afisare pasi:\n1.Da\n0.Nu\n:";
	bool modAfisare;
	std::cin >> modAfisare;
	std::cout << "Cate cuvinte sa intre in automat?: ";
	int numberOfWords;
	std::cin >> numberOfWords;
	for (int index = 0; index < numberOfWords; index++)
	{
		std::string cuvant;
		std::cout << "Introduceti cuvantul: ";
		std::cin >> cuvant;
		afd.Verificare(cuvant, modAfisare);
	}
	return 0;
}