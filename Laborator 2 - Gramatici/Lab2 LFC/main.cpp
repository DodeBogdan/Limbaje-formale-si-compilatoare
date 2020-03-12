#include <iostream>	
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include <windows.h>

struct Productii
{
	std::vector<std::string> VS;
	std::vector<std::string> VD;
};
class Gramatica
{
public:
	void citire()
	{
		std::ifstream fin("Gramatica.txt");
		fin >> m_VN;
		fin >> m_VT;
		fin >> m_S;
		while (!fin.eof())
		{
			std::string temp;
			fin >> temp;
			m_p.VS.push_back(temp);
			fin >> temp;
			m_p.VD.push_back(temp);
		}
		fin.close();
	}
	void verificare(bool &ok)
	{
		{
			for (int i = 0; i < m_VN.length(); i++)
				if (m_VT.find(m_VN[i]) < m_VT.length())
				{
					std::cout << "S-a gasit o eroare la neterminale / terminale.\n";
					ok = 0;
					return;
				}
			std::cout << "Nu exista intersectie intre VN si VT.\n";
		}
		{
			if (m_VN.find("S") > m_VN.length())
			{
				std::cout << "S nu este in neterminale. \n";
				ok = 0;
				return;
			}
			std::cout << "S se afla in VN.\n";
		}
		{
			for (int i = 0; i < m_p.VS.size(); i++)
				for(int j = 0; j < m_VN.length(); j++)
					if (m_p.VS[i].find(m_VN[j]) != std::string::npos)
					{
						break;
					}
					else
					{
						if (j == m_VN.length() - 1) {
							std::cout << "S-a gasit o productie ce nu contine un neterminal.\n" << m_p.VS[i] << std::endl;
							ok = 0;
							return;
						}
					}
			std::cout << "Pentru fiecare regula membrul stang contine cel putin un neterminal.\n";
		}
		{
			std::string temp;
			for (int i = 0; i < m_p.VS.size(); i++)
			{
				std::string temp1 = m_p.VS[i];
				for(int j = 0; j < temp1.length(); j++)
					temp.push_back(temp1[j]);
				temp1 = m_p.VD[i];
				for(int j = 0; j < temp1.length(); j++)
					temp.push_back(temp1[j]);
			}
			for(int i = 0; i < temp.length(); i++)
				if(m_VN.find(temp[i]) > m_VN.length())
					if (m_VT.find(temp[i]) > temp.length())
					{
						std::cout << "S-au gasit elemente ce nu apartin de VT sau VN.\n";
						ok = 0;
						return;
					}
			std::cout << "Fiecare productie contine doar elemente din VN si VT.\n";
		}
		{
			for (int i = 0; i < m_p.VS.size(); i++)
				if (m_p.VS[i].find("S") < m_p.VS[i].length())
				{
					std::cout << "S-a gasit cel putin o productie ce are doar S.\n";
					return;
				}
			ok = 0;
		}
	}
	void afisare()
	{
		{
			std::cout << "VN: ";
			for (int i = 0; i < m_VN.length(); i++)
				if (i < m_VN.length() - 1)
					std::cout << m_VN[i] << ", ";
				else
					std::cout << m_VN[i] << ";";
			std::cout << std::endl;
		}
		{
			std::cout << "VT: ";
			for (int i = 0; i < m_VT.length(); i++)
				if (i < m_VT.length() - 1)
					std::cout << m_VT[i] << ", ";
				else
					std::cout << m_VT[i]<<";";
			std::cout << std::endl;
		}
		{
			std::cout << "S: "<<m_S<<std::endl;
		}
		{
			std::cout << "Productii: \n";
			for (int i = 0; i < m_p.VS.size();i++)
			{
				if(i < m_p.VS.size()-1)
				std::cout << m_p.VS[i] << " => " << m_p.VD[i]<<std::endl;
			}
		}
	}
	void generare(bool optiune)
	{
		if (optiune == 1)
		{
			std::cout << m_S;
			bool ok = 1;
			while (ok)
			{
				ok = 1;
				std::vector<std::string> tempvs,tempvd;
				for (int i = 0; i < m_p.VS.size(); i++)
				{
					if(m_S.find(m_p.VS[i]) != std::string::npos)
						{
							tempvs.push_back(m_p.VS[i]);
							tempvd.push_back(m_p.VD[i]);
						}
				}
				if (tempvs.size() == 0)
				{
					for (int i = 0; i < m_S.length(); i++)
						if (m_VT.find(m_S[i]) > m_VN.length())
						{
							std::cout << "Eroare, cuvantul este format si din neterminale.";
							break;
						}
					m_S = 'S';
					return;
				}
				else
					std::cout << "=>";
				std::random_device dev;
				std::mt19937 rng(dev());
				std::uniform_int_distribution<std::mt19937::result_type> index(0, tempvs.size() - 1);
				int rand = index(rng);
				int pos = m_S.find(tempvs[rand]);
				m_S.replace(pos, tempvs[rand].length(), tempvd[rand]);
				std::cout<< m_S;
			}
		}
		else
		{
			std::cout << m_S;
			bool ok = 1;
			while (ok)
			{
				ok = 1;
				std::vector<std::string> tempvs, tempvd;
				for (int i = 0; i < m_p.VS.size(); i++)
				{
					if (m_S.find(m_p.VS[i]) != std::string::npos)
					{
						tempvs.push_back(m_p.VS[i]);
						tempvd.push_back(m_p.VD[i]);
					}
				}
				if (tempvs.size() == 0)
				{
					for (int i = 0; i < m_S.length(); i++)
						if (m_VT.find(m_S[i]) > m_VN.length())
						{
							std::cout << "Eroare, cuvantul este format si din neterminale.";
							break;
						}
					std::cout <<"=>"<< m_S;
					m_S = 'S';
					return;
				}
				std::random_device dev;
				std::mt19937 rng(dev());
				std::uniform_int_distribution<std::mt19937::result_type> index(0, tempvs.size() - 1);
				int rand = index(rng);
				int pos = m_S.find(tempvs[rand]);
				m_S.replace(pos, tempvs[rand].length(), tempvd[rand]);
				
			}
			
		}
	}

private:
	std::string m_VN;
	std::string m_VT;
	std::string m_S;
	Productii m_p;
};

int main()
{

	Gramatica gramatica;
	gramatica.citire();
	bool ok = 1;
	gramatica.verificare(ok);
	if (ok) {
		gramatica.afisare();
		bool optiune;
		std::cout << "Introdu optiunea: \n0.Doar cuvantul final.\n1.Afisare pasi pana la generare finala.\n";
		std::cin >> optiune;
		std::cout << "Alege cate cuvinte sa fie generate: ";
		int n;
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cout << "Cuvantul " << i+1 << " generat este: ";
			gramatica.generare(optiune);
			std::cout << std::endl;
			Sleep(1000);
		}
	}
	else
		std::cout << "Exista erori in fisier!.";
	return 0;
}