/*8.Jocul spânzurătoarea: */
#include <iostream>
#include <string>
#include <random>
#include <regex>
#include <fstream>
#include<time.h>
#include <vector>

void game(std::string str, std::string str2, bool &done)
{
	
	int count = 0; // A count to find out if all the letters were used.
	for (int i = 0; i < str.length(); i++)
		if (str2.find(str[i]) != -1)
		{
			count++;
			std::cout << str[i] << " ";
		}
		else
			std::cout << "_ ";
	std::cout << std::endl<<std::endl;

	if (count == str.size())
		done = 1;
}

int main()
{
start:
	{
		std::string str; // Initial string.
		std::string str1; // Result string.
		std::vector<std::string> vecstr; // String vector, the place where the strings are taken.
		std::regex reg("[a-zA-Z]"); // For error checking.

		//Input from the words file.
		std::fstream input("Exercitiul8.cuvinte");
		while (!input.eof())
		{
			std::string temp;
			input >> temp;
			vecstr.push_back(temp);
		}
		input.close();

		//Random word selection.
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> index(0, vecstr.size() - 1);
		//srand(time(NULL));
		//int index = rand() % (vecstr.size()-1);
		str = vecstr[index(rng)];

		//Transformation into uppercase for appearance / input.
		std::transform(str.begin(), str.end(), str.begin(), ::toupper);

		//Variables used for back exit (ENDGAME / WINGAME).
		int mistakes = 6;
		bool done = 0;

		//Display _ _ _ depending on the length of the word.
		std::cout << "The game has the letters: \n";
		game(str, str1, done);

		do {

			std::string ch; //Used for letter input.
			std::cout << "Input a letter: ";
			std::getline(std::cin, ch);
			std::transform(ch.begin(), ch.end(), ch.begin(), ::toupper); //Appearance / input transformation.

			//Input verification + transformation.
			do {
				if (!std::regex_match(ch, reg) || ch.length() != 1) //Check if invalid characters or more than 1 character are entered.
				{
					std::cout << "Input invalid. Reintroduce your character: ";
					std::getline(std::cin, ch);
					std::transform(ch.begin(), ch.end(), ch.begin(), ::toupper);
				}
			} while (!std::regex_match(ch, reg) || ch.length() != 1);

			if (str.find(ch) != -1) //Check if the letter entered is in the word.
			{
				str1.push_back(ch[0]); //It is inserted into the final string
				game(str, str1, done);
			}
			else
			{
				mistakes--;
				std::cout << "The letter was not found. You have " << mistakes << " mistakes available.\n\n";
			}

		} while (done != 1 && mistakes != 0);

		//A message is displayed depending on the result.
		if (mistakes == 0)
			std::cout << "END GAME! The game was: " << str;
		else
			std::cout << "YOU WON!";

	}
	int option;
	std::cout << "\nRetry?\n1.Yes.\n2.No.\n";
	std::cin >> option;

	if (option == 1)
		goto start;
	else
		std::cout << "Thank you for playing!\n";
	return 0;
}