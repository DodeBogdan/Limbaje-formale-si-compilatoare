#pragma once
#include <string>
#include <iostream>
#include <vector>
class AFD
{
public:
	void Citire(std::string FileName);
	friend std::ostream& operator<<(std::ostream& out, AFD afd);
	void Verificare(std::string cuvant, bool modAfisare);
	std::string GetStari();
	std::string GetSigma();
	std::vector<std::string> GetDelta();
	std::string GetStareInit();
	std::string GetFinale();
	void SetStari(std::string Stari);
	void SetSigma(std::string Sigma);
	void SetDelta(std::vector<std::string> Delta);
	void SetStareInit(std::string StareInit);
	void SetFinale(std::string Finale);

private:
	//Stari, Sigma, Delta, StareInit, Finale
	std::string m_Stari;
	std::string m_Sigma;
	std::vector<std::string> m_Delta;
	std::string m_StareInit;
	std::string m_Finale;
};

