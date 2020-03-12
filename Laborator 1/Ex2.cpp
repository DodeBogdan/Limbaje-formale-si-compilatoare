/*2.	Să se determine dacă un șir de caractere este un numar natural, întreg sau real.
Exemplu: 
•	23 este număr natural (evident că și întreg sau real), 23.04 este număr real, -14 este număr întreg, 24.345E-10 este număr real în formă exponențială, 
•	2a37 NU este număr, 23.4.5 NU este număr, 34E Nu este număr, 34-E NU este număr
*/
#include <iostream>
#include <string>
#include <regex>

int main()

{
	std::string str;
	std::getline(std::cin, str);
	std::regex regnatural("[\\[0]|([1-9]+[0-9]*)?"); // numere naturale.
	std::regex regint("(\\+|-)?[1-9]+[0-9]*?"); // numere intregi, practic naturale + minus ^_^
	std::regex regfloat("(\\+|-)?(0[\.][0-9]+)|(([1-9]+[0-9]*[\.][0-9]+)([E][-+]?[0-9]+)?)"); // numere float + stiintific.

	//verific prima data pentru naturale
	if (std::regex_match(str, regnatural))
		std::cout <<"Number: "<<str<<" is natural" << std::endl;
	
	//verificare pentru intregi
	else if (std::regex_match(str, regint))
		std::cout << "Number: " << str << " is integer" << std::endl;

	//verificare pentru float
	else if (std::regex_match(str, regfloat))
		std::cout << "Number: " << str << " is float" << std::endl;
	else
	{
		std::cout << "Number: " << str << " is not a number" << std::endl;
	}
	return 0;
}