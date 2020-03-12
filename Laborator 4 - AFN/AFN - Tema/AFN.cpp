#include "AFN.h"
#include <fstream>
#include <stack>

void AFN::Citire()
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
	for (int index = 0; index < m_Delta.size() - 1; index++)
		m_Delta[index] = m_Delta[index + 1];
	m_Delta.pop_back();
	std::getline(fin, m_StareInit);
	std::getline(fin, m_Finale);
}
int AFN::Verificare(std::string cuvant, std::string stare)
{
	if (cuvant == "")
	{
		for (int index = 0; index < m_Finale.length(); index++)
		{
			if (stare[0] == m_Finale[index])
				return 0;
		}
		return 1;
	}
	bool ok = false;

	for (int index = 0; index < m_Delta.size(); index++)
	{
		if (m_Delta[index][0] == stare[0] && m_Delta[index][1] == cuvant[0]) 
		{
			std::string stareAux;
			stareAux.push_back( m_Delta[index][2]);
			std::string aux = cuvant;
			aux.erase(0, 1);
			bool verificare = Verificare(aux, stareAux);
			if (verificare == 0)
			{
				return 0;
			}
			if (verificare == 1)
			{
				ok = true;
			}
		}
	}

	if (ok == true)
	{
		return 1;
	}
	return -1;
}

std::ostream& operator<<(std::ostream& out, AFN afn)
{
	std::cout << "Starile sunt: ";
	for (int index = 0; index < afn.m_Stari.size(); index ++)
		out << afn.m_Stari[index]<<" ";
	std::cout << std::endl;
	std::cout << "Aflabetul este: ";
	for (int index = 0; index < afn.m_Sigma.size(); index++)
		out << afn.m_Sigma[index] << " ";
	std::cout << std::endl;
	std::cout << "Delta este: ";
	std::cout << std::endl;
	for (int i = 0; i < afn.m_Delta.size(); i++) {
		for(int j = 0; j < afn.m_Delta[i].length(); j++)
			out << afn.m_Delta[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << "Starea initiala este: ";
	out << afn.m_StareInit;
	std::cout << std::endl;
	std::cout << "Starea finala este: ";
	for (int index = 0; index < afn.m_Finale.size(); index++) {
		out << afn.m_Finale[index] << " ";
	}
	std::cout << std::endl;
	out << "\n";
	return out;
}
