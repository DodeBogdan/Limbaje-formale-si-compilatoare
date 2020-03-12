#include "AFD.h"
#include <fstream>

struct Pozitie
{
	int index;
};


void AFD::Citire()
{
	std::fstream fin("input.txt");
	std::getline(fin, m_Stari);
	std::getline(fin, m_Sigma);
	//std::getline(fin, m_Delta);
	int noD;
	fin >> noD;
	for (int i = 0; i < noD + 1; i++)
	{
		std::string temp;
		getline(fin, temp);
		m_Delta.push_back(temp);
	}
	std::getline(fin, m_StareInit);
	std::getline(fin, m_Finale);
}

void AFD::Verificare(std::string cuvant,bool modAfisare)
{
	//1 blocat; -1 Neacceptat; 0 Acceptat.
	int stare = 0;
	int index;
	for (int index = 0; index < cuvant.length(); index++)
		if (m_Sigma.find(cuvant[index]) == std::string::npos) {
			stare = -1;
			break;
		}
	std::string StareActuala = m_StareInit;
	StareActuala.push_back(cuvant[0]);
	if(modAfisare)
		std::cout << "Cuvantul: ";
	if (stare == 0)
		while (!cuvant.empty())
		{
			index = 0;
			while (index < m_Delta.size())
			{
				if (m_Delta[index].find(StareActuala) != std::string::npos)
				{
					break;
				}
				index++;
			}

			if (index == m_Delta.size())
			{
				std::cout << cuvant;
				stare = -1;
				break;
			}
			if (m_Delta[index][2] == '-')
			{
				stare = 1;
				break;
			}
			if (modAfisare)
				std::cout << cuvant << " => ";
			StareActuala.erase();
			cuvant.erase(0, 1);
			StareActuala.push_back(m_Delta[index][2]);
			StareActuala.push_back(cuvant[0]);
		}
	else
		if (modAfisare)
			std::cout << cuvant;
	if (cuvant.empty() &&  m_Finale.find(StareActuala[0]) == std::string::npos)
		stare = -1;

	switch (stare)
	{
	case 1:
		if (modAfisare)
			std::cout << " este blocat.\n";
		else
			std::cout << "Blocat.\n";
		break;
	case -1:
		if (modAfisare)
			std::cout << " este neacceptat.\n";
		else std::cout << "Neacceptat.\n";
		break;
	case 0:
		if (modAfisare)
			std::cout << "empty => este acceptat.\n";
		else std::cout << "Acceptat.\n";
		break;
	}
}

std::ostream& operator<<(std::ostream& out, AFD afd)
{
	//std::cout << "Starile sunt: ";
	//for (int index = 0; index < afd.m_Stari.size(); index ++)
	//	out << afd.m_Stari[index]<<" ";
	//std::cout << std::endl;
	//std::cout << "Aflabetul este: ";
	//for (int index = 0; index < afd.m_Sigma.size(); index++)
	//	out << afd.m_Sigma[index] << " ";
	//std::cout << std::endl;
	//std::cout << "Delta este: ";
	//for (int i = 0; i < afd.m_Delta.size(); i++) {
	//	for(int j = 0; j < afd.m_Delta[i].length(); j++)
	//		out << afd.m_Delta[i][j] << " ";
	//	std::cout << std::endl;
	//}
	//std::cout << "Starea initiala este: ";
	//out << afd.m_StareInit;
	//std::cout << std::endl;
	//std::cout << "Starea finala este: ";
	//out << afd.m_Finale;
	//std::cout << std::endl;
	out << "\tAFD:\n\n";
	out << " " << (char)235 << " ";
	for (int index = 0; index < afd.m_Sigma.length(); index++)
	{
		out << "| " << afd.m_Sigma[index]<<" ";
	}
	for (int index = 1; index < afd.m_Delta.size()-1; index += afd.m_Sigma.length())
	{
		bool okI = 1, okF = 1;
		out << "\n---";
		for (int index = 0; index < afd.m_Sigma.length(); index++)
			out << "|---";
		
		if (afd.m_Delta[index][0] == afd.m_StareInit[0])
		{
			out << "\n->" << afd.m_Delta[index][0];
			for (int index1 = 0; index1 < afd.m_Sigma.length(); index1++)
			{
				out << "| " << afd.m_Delta[index + index1][2] << " ";
			}
		}
		else okI = 0;
		if (afd.m_Finale.find(afd.m_Delta[index][0]) != std::string::npos)
		{
			out << "\nF-" << afd.m_Delta[index][0];
			for (int index1 = 0; index1 < afd.m_Sigma.length(); index1++)
			{
				out << "| " << afd.m_Delta[index + index1][2] << " ";
			}
		}
		else okF = 0;
		if (okI == 0 && okF == 0)
		{
		{
			out << "\n " << afd.m_Delta[index][0]<<" ";
			for (int index1 = 0; index1 < afd.m_Sigma.length(); index1++)
			{
				out << "| " << afd.m_Delta[index + index1][2] << " ";
			}
		}
		}
	}
	out << "\n";
	return out;
}
