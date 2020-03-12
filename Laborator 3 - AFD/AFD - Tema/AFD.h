#pragma once
#include <string>
#include <iostream>
#include <vector>
class AFD
{
public:
	void Citire();
	friend std::ostream& operator<<(std::ostream& out, AFD afd);
	void Verificare(std::string cuvant, bool modAfisare);

private:
	//Stari, Sigma, Delta, StareInit, Finale
	std::string m_Stari;
	std::string m_Sigma;
	std::vector<std::string> m_Delta;
	std::string m_StareInit;
	std::string m_Finale;
};

