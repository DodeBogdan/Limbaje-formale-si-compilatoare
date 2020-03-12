/*4.	Determinați numarul de cuvinte dintr-o frază introdusă de  la tastatură, precum și
ce cuvinte sunt în fraza respectivă, sub forma:*/
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <regex>

int main()
{	
	std::string str;
	std::getline(std::cin, str);

	std::vector<std::string> strvec;
	std::string ch = " ?!.,";
	std::string temp;

	for (int i = 0; i < str.length(); i++)
	{
		if (ch.find(str[i]) == -1)
			temp.push_back(str[i]);

		if (ch.find(str[i]) != -1)
		{
			while (ch.find(str[i+1]) != -1) i++;
			strvec.push_back(temp);
			temp.clear();
		}
		
	}
	//verificare pentru cazul in care mai exista un cuvant nepus in vector.
	if(temp.length() != 0)
		strvec.push_back(temp);

	//afisare vector.
	for (int i = 0; i < strvec.size(); i++)
		std::cout <<i+1<<"."<< strvec[i]<<std::endl;
	std::cout << std::endl;
	
	//afisare numar de cuvinte.
	std::cout << strvec.size();

	return 0;
}