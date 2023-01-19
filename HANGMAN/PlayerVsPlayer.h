#pragma once


#include <iostream>
#include <fstream>
#include <string>
#include <ctime>




using namespace std;


bool IsLetterInWord(char input, string word);
void HangPic(int guess);


 inline void PlayerVsPLayer() {

	 ofstream replay("Replay.txt");


	string word;



	char* wrdletter = new char[word.length()];

	
	//Playercount
	int numPLayers;

	cout << "Wie viele Spieler wollen mitspielen?" << endl;

	cin >> numPLayers;

	

	string* allplayers = new string[numPLayers];

	replay << " Mitspielende Spieler: \n \r ";

	//safe all players in string array
	for (int i = 0; i < numPLayers; i++) {
		cout << " Gebe einen Namen ein:";

		cin >> allplayers[i];

		cout << "\n";

		replay << allplayers[i] << "\r";
	}

	replay << "\n";
	

	



	//random player begins
	srand(time(NULL));
	int PlTurn = rand() % numPLayers;
	
	
	
	int guess = 10;

	cout << allplayers[PlTurn] << " ist der Spielleiter \n" << "Gebe ein Wort ein, die anderen duerfen nicht gucken!!! \n";
	



	cin >> word;

	replay << allplayers[PlTurn] << " ist der Spielleiter geworden und hat das folgende Wort ausgesucht: " << word << "\n";
	
	system("cls");
	for (int i = 0; i < word.length(); i++) {
		wrdletter[i] = word[i];
		wrdletter[i + 1] = '\0';
	}



	int j = 0;
	for (int i = 0; i < numPLayers ; i++) {
		
		if (allplayers[i] != allplayers[PlTurn])
			allplayers[j++] = allplayers[i];



	}

	numPLayers = numPLayers -1;
	PlTurn = rand() % numPLayers;
	
	//cout << word << "\n";

	string input;
	char usedLtr[26] = { '.' };
	int usenum = 0;
	bool used = false;

	//erstelle zensiertes Array das ausgegeben wird
	char* censWord = new char[word.length()];
	for (int i = 0; i < word.length(); i++) {
		censWord[i] = '*';
		censWord[i + 1] = '\0';
	}



	//anfang vom spiel

	while (1 == 1) {

		cout << censWord << "\n";


		if (PlTurn == numPLayers) {
			PlTurn = 0;

		}
		cout << allplayers[PlTurn] << " ist dran! \n";
		replay << allplayers[PlTurn] << " ist dran! \n";


		cout << " Gebe einen Buchstaben oder das Wort ein: ";
		cin >> input;
		for (int i = 0; i < input.length(); i++)
			input[i] = tolower(input[i]);

		replay << allplayers[PlTurn] << " hat den Buchstaben " << input << " ausgesucht!";

		cout << "\n";





		//check ob mehr als 1 buchstabe eingegeben wurde
		if (input.length() > 1) {

			if (input == word) {
				cout << " Du hast das Wort erraten! " << "\n" << " Ich bin stolz auf dich " << allplayers[PlTurn] << "! ... aber jemand anders waere schneller gewesen... \n";
				replay << allplayers[PlTurn] << " \n ist eine lebende Legende, du hast gewonnen! \n \0";

				return;

			}

			else {
				cout << " Das Wort stimmt leider nicht.... Too bad." << "\n";
				guess--;
				replay << " Haha das Wort war falsch. \n";
			}
		}


		else {

			for (int i = 0; i < word.length(); i++) {
				if (usedLtr[i] == input[0]) {
					cout << " Dieser Buchstabe wurde schon benutzt... wow..." << "\n";
					used = true;
					break;
					replay << " Wow.. der Buchstabe war schon dran, streng dich an " << allplayers[PlTurn] << "! \n";

				}


			}



			if (IsLetterInWord(input[0], word) == true && used == false) {
			
				
				cout << " Der Buchstabe ist im Wort!" << "\n";
				usedLtr[usenum++] = input[0];
				for (int i = 0; i < word.length(); i++) {
					if (input[0] == wrdletter[i])
						censWord[i] = wrdletter[i];

					
				}

				replay << allplayers[PlTurn] << "! Dank dir machen wir hier forschritte. \n Der richtige Buchstabe war: " << input << "\n";

			}



			else if (IsLetterInWord(input[0], word) == false && used == false) {
				usedLtr[usenum++] = input[0];
				usedLtr[usenum + 1] = '\n';

				cout << " Der Buchstabe ist NICHT im Wort. Too bad..." << "\n";
				replay << " Hahaha, der Buchstabe ist falsch.\n";
				guess--;



			}



		}

		if (censWord == word)
			cout << " Ach kommt schon leute, es steht doch schon da..." << "\n";
		replay << " Das. Das war einfach nur peinlich.... \n";

		HangPic(guess);
		
		



		if (guess == 0) {

			cout << " Und du hast Sie/Ihn umgebracht.. Na Toll... \n";
			replay << allplayers[PlTurn] << " hat sie/ihn umgebracht... endlich ist es vorbei. \n \0";
			break;
		}
		

			cout << " \n Benutzte Buchstaben: " << usedLtr << "\n";
			replay << "\n Eure falsch geratenen Buchstaben :) " << usedLtr;

			cout << "Versuche: " << guess << "\n" << "__________________________________________________________________________________ \n";

			replay << guess << "\n Versuche habt ihr noch.. \n";





		
			used = false;

			PlTurn++;
		}
	}














