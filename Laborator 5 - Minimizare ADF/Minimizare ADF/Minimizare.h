#pragma once
#include "AFD.h"
#include <fstream>

class Minimizare : AFD
{
public:
	void EliminareStariInaccesibile(AFD other);
	friend std::ostream& operator<<(std::ostream& out, Minimizare minimAFD);
	void MinimizareAFD(std::string FileName);
	void MatriceEchivalenta();
	void AfisareMatriceEchivalenta();
	void SetareStariFinaleDupaMinimizare(AFD other);
	void MarcareFinalSiNefinal();
	bool VerificareStare(std::string stare);
	void MarcareStari(AFD afd);
	void DetectareStariEchivalente(AFD afd);
	void RefacereDelta(AFD afd);
	void RefacereStari();
	void ScriereFisier(std::string FileName);
private:
	std::string m_Stari;
	std::string m_Sigma;
	std::vector<std::string> m_Delta;
	std::string m_StareInit;
	std::string m_Finale;
	std::vector<std::vector<std::string>> m_matriceEchivalenta;
	std::vector<std::vector<int>> m_stariEchivalente;
};

