/*6.	Să se rețină într-un vector de cuvinte și să se afișeze unul sub altul toate prefixele proprii ale unui cuvant citit de la tastatură (prefixele unui cuvânt sunt compuse din minim un caracter și maxim toate caracterele, citite de la stânga la dreapta. Prefix propriu este un prefix, care este diferit de cuvântul dat).
Exemplu: toate prefixele proprii ale cuvântului ANANAS sunt: A, AN, ANA, ANAN, ANANA
*/
#include <iostream>
#include <vector>
#include <string>

//Se afiseaza prefixe din strin-ul introdus.

int main()
{
	std::string str;
	std::vector<std::string> cuvinte;
	
	std::cout << "Input for string: ";
	std::getline(std::cin, str);
	{
		
		std::string temp;

		for (int i = 0; i < str.length() - 1; i++)
		{
			temp.push_back(str[i]);
			cuvinte.push_back(temp);
		}
	}
	std::cout << "\nThe output for your string is: \n";
	for (int i = 0; i < cuvinte.size(); i++)
		std::cout << i + 1 << "." << cuvinte[i] << std::endl;

	return 0;
	
}