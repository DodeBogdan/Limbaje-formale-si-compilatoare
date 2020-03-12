#include "AFN.h"

int main()
{
	AFN afn;
	afn.Citire();
	std::string cuvant;
	std::cout << afn;
	do {
		std::cout << "\nPentru verificarea unui cuvant introdu cuvantul.\nPentru iesire din program apasa enter.\n\n";
		std::getline(std::cin, cuvant);
		if (!cuvant.empty())
		{
			
			int index = afn.Verificare(cuvant,"0");
			switch (index)
			{
			case 1:
				std::cout << "Neacceptat\n";
				break;

			case -1:
				std::cout << "Blocaj\n";
				break;

			case 0:
				std::cout << "Acceptat\n";
				break;

			}
			
		}
		
	} while (cuvant.length() != 0);

		return 0;
	}