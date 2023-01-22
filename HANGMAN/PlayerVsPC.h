#pragma once



#include <fstream>
#include <string>
#include <ctime>
//#include "Library.h"




using namespace std;




void PlayerVsPC(string randword) {
	ofstream replay("Replay.txt");

	char* wrdletter = new char[randword.length()]; //char array mit groessse von weitergegebenen string

	for (int i = 0; i < randword.length(); i++) {
		wrdletter[i] = randword[i];
		wrdletter[i + 1] = '\0';
	}


	//erstelle zensiertes Array das ausgegeben wird
	char* censWord = new char[randword.length()];
	for (int i = 0; i < randword.length(); i++) {
		censWord[i] = '*';
		censWord[i + 1] = '\0';
	}


	//Playercount
	int numPLayers;

	cout << "Wie viele Spieler wollen mitspielen?" << endl;

	cin >> numPLayers;
	

	string* allplayers = new string[numPLayers];



	replay << " Mitspielende Spieler: \n \r " << endl;
	//safe all players in string array
	for (int i = 0; i < numPLayers; i++) {
		cout << " Gebe einen Namen ein:";

		cin >> allplayers[i];
		replay << allplayers[i] << "\r" << endl;
		cout << "\n";
	}

	replay << endl;
	




	string input;
	char usedLtr[26] = { '.' };
	int usenum = 0;
	bool used = false;


	//cout << randword << "\n";



	//random player begins
	srand(time(NULL));
	int PlTurn = rand() % numPLayers; 
	int guess = 10;





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

		replay << allplayers[PlTurn] << " hat den Buchstaben " << input << " ausgesucht!" << endl;
		cout << "\n";





		//check ob mehr als 1 buchstabe eingegeben wurde
		if (input.length() > 1) {

			if (input == randword) {
				cout << " Du hast das Wort erraten! " << "\n" << " Ich bin stolz auf dich " << allplayers[PlTurn] << "! ... aber jemand anders waere schneller gewesen... \n";
				replay << "  \n" << allplayers[PlTurn] << " ist eine lebende Legende, du hast gewonnen!" << NULL;
				replay.close();
				return;

			}

			else {
				cout << " Das Wort stimmt leider nicht.... Too bad." << "\n";
				replay << " Haha das Wort war falsch." << endl; 
				guess--;
			}
		}


		else {

			for (int i = 0; i < randword.length(); i++) {
				if (usedLtr[i] == input[0]) {
					cout << " Dieser Buchstabe wurde schon benutzt... wow..." << "\n";
					used = true;
					replay << " Wow.. der Buchstabe war schon dran, streng dich an " << allplayers[PlTurn] << "!" << endl;
					break;

				}


			}



			if (IsLetterInWord(input[0], randword) == true && used == false) {
				cout << " Der Buchstabe ist im Wort!" << "\n";
				usedLtr[usenum++] = input[0];
				for (int i = 0; i < randword.length(); i++) {
					if (input[0] == wrdletter[i])
						censWord[i] = wrdletter[i];


				}

				replay << allplayers[PlTurn] << "! Dank dir machen wir hier forschritte. \n Der richtige Buchstabe war: " << input << endl;

			}



			else if (IsLetterInWord(input[0], randword) == false && used == false) {
				usedLtr[usenum++] = input[0];
				usedLtr[usenum + 1] = '\n';

				cout << " Der Buchstabe ist NICHT im Wort. Too bad..." << "\n";

				replay << " Hahaha, der Buchstabe ist falsch." << endl;
				guess--;



			}



		}

		if (censWord == randword) {
			cout << "Ach kommt schon leute, es steht doch schon da..." << "\n";
		}

		HangPic(guess);


		cout << " \n Benutzte Buchstaben: " << usedLtr << "\n";


		cout << "Versuche: " << guess << "\n" << "__________________________________________________________________________________ \n";







		if (guess == 0) {

			replay << allplayers[PlTurn] << " hat sie/ihn umgebracht... endlich ist es vorbei. \n \0" << endl;
			cout << " Und du hast Sie/Ihn umgebracht.. Na Toll... \n Das Wort war: " << randword << "\n";
			replay.close();
			break;
		}

		replay << guess << "\n Versuche habt ihr noch.. \n" << endl;

		used = false;

		PlTurn++;
	}
}














