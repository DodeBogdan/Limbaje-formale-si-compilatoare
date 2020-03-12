/*3.	Să se inverseze un șir de caractere și apoi să se înlocuiască toate 
aparițiile unui subșir dat s1 cu un alt subșir dat s2.*/
#include <iostream>
#include <string>

int main()
{
	std::string str,s1,s2;

	//citire
	std::getline(std::cin, str);
	reverse(str.begin(), str.end());
	std::cout << str<<std::endl;

	std::getline(std::cin, s1);
	std::getline(std::cin, s2);
	
	int pos = str.find(s1);
	while (pos < str.length())
	{
		str.replace(pos, s1.length(), s2);
		pos = str.find(s1, pos + s2.length());
	}
	std::cout << str;
	return 0;
}