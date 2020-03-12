#pragma once
#include <string>
#include <vector>
#include <iostream>

class AFN
{
public:
	void Citire();
	friend std::ostream& operator<<(std::ostream& out, AFN afn);
	int Verificare(std::string cuvant, std::string stare);
private:
	std::string m_Stari;
	std::string m_Sigma;
	std::vector<std::string> m_Delta;
	std::string m_StareInit;
	std::string m_Finale;
};

