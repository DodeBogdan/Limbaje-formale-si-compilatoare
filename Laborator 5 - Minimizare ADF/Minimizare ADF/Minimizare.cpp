#include "Minimizare.h"
#include <algorithm>

void Minimizare::EliminareStariInaccesibile(AFD other)
{
	m_StareInit = other.GetStareInit();
	std::string stari;
	std::vector<std::string> Delta = other.GetDelta();
	std::string StariAFD = other.GetStari();

	for (int index = 0; index < StariAFD.size(); index++)
	{
		if (m_StareInit[0] == StariAFD[index])
			stari.push_back(StariAFD[index]);
		else
		{
			for (int index1 = 0; index1 < Delta.size(); index1++)
			{
				if(Delta[index1].size() != 0)
				if (StariAFD[index] == Delta[index1][2])
					{
						stari.push_back(StariAFD[index]);
						break;
					}
			}
		}
	}
	m_Stari = stari;
}

void Minimizare::MinimizareAFD(std::string FileName)
{
	AFD afd;
	afd.Citire(FileName);
	std::cout << afd;

	m_StareInit = afd.GetStareInit();
	m_Sigma = afd.GetSigma();

	EliminareStariInaccesibile(afd);
	SetareStariFinaleDupaMinimizare(afd);
	MatriceEchivalenta();
	AfisareMatriceEchivalenta();
	MarcareFinalSiNefinal();
	AfisareMatriceEchivalenta();
	MarcareStari(afd);
	DetectareStariEchivalente(afd);
	RefacereStari();
	RefacereDelta(afd);
}

void Minimizare::MatriceEchivalenta()
{
	int numarIteratii = 0;
	for (int index = 0; index < m_Stari.length(); index++)
	{
		std::vector<std::string> vectorAuxiliar;
		for (int index1 = 0; index1 < numarIteratii; index1++)
		{
			vectorAuxiliar.push_back("_");
		}
		++numarIteratii;
		std::string temp;
		temp.push_back(m_Stari[index]);
		vectorAuxiliar.push_back(temp);
		m_matriceEchivalenta.push_back(vectorAuxiliar);
	}
}

void Minimizare::AfisareMatriceEchivalenta()
{
	for (int index = 0; index < m_matriceEchivalenta.size(); index++)
	{
		for (int index1 = 0; index1 < m_matriceEchivalenta[index].size(); index1++)
			std::cout << m_matriceEchivalenta[index][index1] << " ";
		std::cout << std::endl;
	}
}

void Minimizare::SetareStariFinaleDupaMinimizare(AFD other)
{
	std::string TempFinale = other.GetFinale();
	for (int index = 0; index < m_Stari.length(); index++)
		for (int index1 = 0; index1 < TempFinale.length(); index1++)
			if (m_Stari[index] == TempFinale[index1]) 
			{
				m_Finale.push_back(m_Stari[index]);
				break;
			}
}
bool Minimizare::VerificareStare(std::string stare)
{
	for (int index = 0; index < m_Finale.length(); index++)
		if (stare[0] == m_Finale[index])
			return true;
	return false;
}
void Minimizare::MarcareFinalSiNefinal()
{
	for (int linie = 0; linie < m_Stari.length(); linie++)
	{
		std::string stare;
		stare.push_back(m_Stari[linie]);
		for (int coloana = 0; coloana < linie; coloana++)
		{
			std::string pereche;
			pereche.push_back(m_Stari[coloana]);
			if (pereche != stare && ((VerificareStare(pereche) == true && VerificareStare(stare) == false))
				|| ((VerificareStare(pereche) == false && VerificareStare(stare) == true)))
				m_matriceEchivalenta[linie][coloana] = "x";
		}
	}
}
bool existaStare(std::string string, char element)
{
	for (int index = 0; index < string.length(); index++)
		if (string[index] == element)
			return true;
	return false;
}
void Minimizare::MarcareStari(AFD afd)
{
	bool ok = false;
	do
	{
		ok = false;
		for (int linie = 1; linie < m_Stari.length(); linie++)
		{
			for (int coloana = 0; coloana < linie; coloana++)
			{
				if (m_matriceEchivalenta[linie][coloana] == "_")
				{
					std::vector<std::string> Delta = afd.GetDelta();
					for (int index = 0; index < m_Sigma.length(); index++)
					{
						int first = 0;
						int second = 0;
						int linieNoua;

						linieNoua = m_matriceEchivalenta[linie][m_matriceEchivalenta[linie].size() - 1][0] - '0';

						for (int index1 = 0; index1 < Delta.size(); index1++)
						{
							if (Delta[index1][0] == (linieNoua + '0') && Delta[index1][1] == m_Sigma[index])
							{
								first = Delta[index1][2] - '0';
							}
							if (Delta[index1][0] == (coloana + '0') && Delta[index1][1] == m_Sigma[index])
							{
								second = Delta[index1][2] - '0';
							}
						}
						
						for (int i = 0; i < m_matriceEchivalenta.size(); i++)
							for (int j = 0; j < m_matriceEchivalenta[i].size(); j++)
							{
								if (first == m_matriceEchivalenta[i][j][0] - '0')
									first = i;
								if (second == m_matriceEchivalenta[i][j][0] - '0')
									second = i;
							}	

						if (first < second)
							std::swap(first, second);
						if (m_matriceEchivalenta[first][second] == "x")
						{
							m_matriceEchivalenta[linie][coloana] = "x";
							ok = true;
						}
					}
				}
			}
		}
		AfisareMatriceEchivalenta();
	} while (ok == true);


}
void afisareMatrice(std::vector<std::vector<int>> stariEchivalente)
{
	for (int index = 0; index < stariEchivalente.size(); index++)
	{
		std::cout << "Index: " << index << " : ";
		for (int index1 = 0; index1 < stariEchivalente[index].size(); index1++)
			std::cout << stariEchivalente[index][index1];
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool exista(std::vector<int> vector, int element)
{
	for (int index = 0; index < vector.size(); index++)
		if (vector[index] == element)
			return true;
	return false;
}
bool existaMat(std::vector < std::vector<int>> mat, int element)
{
	for (int index = 0; index < mat.size(); index++)
		for (int index1 = 0; index1 < mat[index].size(); index1++)
			if (mat[index][index1] == element)
				return true;
	return false;
}
void Minimizare::DetectareStariEchivalente(AFD afd)
{

	m_stariEchivalente.resize(afd.GetStari().length());
	for (int index = 0; index < afd.GetStari().length(); index++)
		m_stariEchivalente[index].resize(afd.GetStari().length());

	for (int linie = 0; linie < m_matriceEchivalenta.size(); linie++)
	{
		std::vector<int> temp;
		for (int coloana = 0; coloana < linie; coloana++)
		{
			if (m_matriceEchivalenta[linie][coloana] == "_")
				m_stariEchivalente[coloana][linie] = m_matriceEchivalenta[linie][m_matriceEchivalenta[linie].size()-1][0] - '0';
		}
	}
	std::vector<std::vector<int>> temp;
	for (int index = 0; index < m_stariEchivalente.size(); index++)
	{
		std::vector<int> vtemp;
		for (int index1 = 0; index1 < m_stariEchivalente.size(); index1++)
			if (m_stariEchivalente[index][index1] != 0)
				vtemp.push_back(m_stariEchivalente[index][index1]);
		temp.push_back(vtemp);
	}

	std::vector<std::vector<int>> stariEchivalente;
	std::vector<int> vTemp;
	for (int index = 0; index < m_Stari.length(); index++)
		vTemp.push_back(m_Stari[index] - '0');
	for (int index = 0; index < temp.size(); index++)
	{
		std::vector<int> vtemp;
		if (exista(vTemp, index) && !existaMat(stariEchivalente,index))
			vtemp.push_back(index);
		for (int index1 = 0; index1 < temp[index].size(); index1++)
		{
			if (!existaMat(stariEchivalente, temp[index][index1]));
				vtemp.push_back(temp[index][index1]);
		}
		stariEchivalente.push_back(vtemp);

	}

	
	temp.clear();
	for (int index = 0; index < stariEchivalente.size(); index++)
	{
		std::vector<int> tempo = stariEchivalente[index];
		if (tempo.size() != 0 && !existaMat(temp,stariEchivalente[index][0]))
			temp.push_back(tempo);
	}
	std::cout << std::endl;
	afisareMatrice(temp);
	m_stariEchivalente = temp;

}

void Minimizare::RefacereDelta(AFD afd)
{

	std::vector<std::string> Delta = afd.GetDelta();

	for (int index = 0; index < Delta.size(); index++)
	{
		bool ok = true;
		std::string temp;
		if (Delta[index].size() != 0)
		{

			if (!existaStare(m_Stari, Delta[index][0]))
			{
				ok = false;
			}
				
			if(ok)
			{
				temp.push_back(Delta[index][0]);
				temp.push_back(Delta[index][1]);


				if (!existaStare(m_Stari, Delta[index][2]))
				{
					for (int linie = 0; linie < m_stariEchivalente.size(); linie++)
						for (int coloana = 0; coloana < m_stariEchivalente[linie].size(); coloana++)
							if (m_stariEchivalente[linie][coloana] + '0' == Delta[index][2])
							{
								temp.push_back(m_stariEchivalente[linie][0] + '0');
								break;
							}
				}
				else
					temp.push_back(Delta[index][2]);
			}

		}
		if(ok)
		m_Delta.push_back(temp);
	}


}
bool apartine(std::string vector1, std::string vector2)
{
	for (int index = 0; index < vector1.size(); index++)
		for (int index2 = 0; index2 < vector2.size(); index2++)
			if (vector1[index] == vector2[index2])
				return true;
	return false;
}
void Minimizare::RefacereStari()
{
	std::string temp;
	for (int index = 0; index < m_stariEchivalente.size(); index++)
	{
		temp.push_back(m_stariEchivalente[index][0] + '0');
	}
	m_Stari = temp;
	temp.clear();
	for (int index = 0; index < m_Finale.length(); index++)
		for (int index1 = 0; index1 < m_Stari.length(); index1++)
			if (m_Finale[index] == m_Stari[index1])
				temp.push_back(m_Stari[index1]);
	m_Finale = temp;
}

void Minimizare::ScriereFisier(std::string FileName)
{
	std::ofstream fout(FileName);
	for (int index = 0; index < m_Stari.length(); index++)
	{
		char temp = m_Stari[index];
		fout << temp;
	}
	fout << std::endl;
	for (int index = 0; index < m_Sigma.length(); index++)
		fout << m_Sigma[index];
	fout << std::endl;
	fout << m_Delta.size() - 1;
	for (int index = 0; index < m_Delta.size(); index++)
	{
		for (int index1 = 0; index1 < m_Delta[index].size(); index1++)
		{
			char temp;
			if (index1 != 1)
				 temp = m_Delta[index][index1];
			else
				temp = m_Delta[index][index1];
			fout << temp;
		}
		fout << std::endl;
	}
	fout << m_StareInit;
	fout << std::endl;
	fout << m_Finale;

	fout.close();
}

std::ostream& operator<<(std::ostream& out, Minimizare minimAFD)
{
	out << "\AFD Minimizat:\n\n";
	out << " " << (char)235 << " ";
	for (int index = 0; index < minimAFD.m_Sigma.length(); index++)
	{
		out << "| " << minimAFD.m_Sigma[index] << " ";
	}
	for (int index = 1; index < minimAFD.m_Delta.size() - 1; index += minimAFD.m_Sigma.length())
	{
		bool okI = 1, okF = 1;
		out << "\n---";
		for (int index = 0; index < minimAFD.m_Sigma.length(); index++)
			out << "|---";

		if (minimAFD.m_Delta[index][0] == minimAFD.m_StareInit[0])
		{
			out << "\n->" << minimAFD.m_Delta[index][0];
			for (int index1 = 0; index1 < minimAFD.m_Sigma.length(); index1++)
			{
				out << "| " << minimAFD.m_Delta[index + index1][2] << " ";
			}
		}
		else okI = 0;
		if (minimAFD.m_Finale.find(minimAFD.m_Delta[index][0]) != std::string::npos)
		{
			out << "\nF-" << minimAFD.m_Delta[index][0];
			for (int index1 = 0; index1 < minimAFD.m_Sigma.length(); index1++)
			{
				out << "| " << minimAFD.m_Delta[index + index1][2] << " ";
			}
		}
		else okF = 0;
		if (okI == 0 && okF == 0)
		{
			{
				out << "\n " << minimAFD.m_Delta[index][0] << " ";
				for (int index1 = 0; index1 < minimAFD.m_Sigma.length(); index1++)
				{
					out << "| " << minimAFD.m_Delta[index + index1][2] << " ";
				}
			}
		}
	}
	out << "\n";
	return out;
}
