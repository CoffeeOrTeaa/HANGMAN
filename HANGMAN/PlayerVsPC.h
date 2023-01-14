#pragma once


#include <iostream>
#include <fstream>
#include <string>
#include <ctime>


using namespace std;

char tolower2(char BigL) {

	if (!('a' <= BigL && BigL <= 'z')) {
		BigL = BigL + ('z' - 'Z');

	}

	return BigL;
}


void PlayerVsPC(string randword) {

	char* wrdletter = new char[randword.length()];

	for (int i = 0; i < randword.length(); i++) {
		wrdletter[i] = randword[i];
		wrdletter[i + 1] = '\0';
	}

	//Playercount
	int numPLayers;

	cout << "Wie viele Spieler wollen mitspielen?" << endl;

	cin >> numPLayers;


	string* allplayers = new string[numPLayers];


	//safe all players in string array
	for (int i = 0; i < numPLayers; i++) {
		cout << " Gebe einen Namen ein:";

		cin >> allplayers[i];

		cout << "\n";
	}


	//erstelle zensiertes Array das ausgegeben wird
	char* censWord = new char[randword.length()];
	for (int i = 0; i < randword.length(); i++) {
		censWord[i] = '*';
		censWord[i + 1] = '\0';
	}




	string input;
	char usedLtr[26] = {'.'};
	int usenum = 0;
	bool used = false;


	cout << randword << "\n";



	//random player begins
	srand(time(NULL));
	int PlTurn = rand() % numPLayers;
	int guess = 9;





	//anfang vom spiel

	while (1 == 1) {

		cout << censWord << "\n";


		if (PlTurn == numPLayers) {
			PlTurn = 0;
			
		}
		cout << allplayers[PlTurn] << " ist dran! \n";



		cout << " Gebe einen Buchstaben oder das Wort ein: ";
		cin >> input;
		for (int i = 0; i < input.length(); i++) 
			input[i] = tolower2(input[i]);


		cout << "\n";





		//check ob mehr als 1 buchstabe eingegeben wurde
		if (input.length() > 1) {

			if (input == randword) {
				cout << " Du hast das Wort erraten! " << "\n" << " Ich bin stolz auf dich " << allplayers[PlTurn] << "! ... aber jemand anders waere schneller gewesen... \n";
				
				return;

			}

			else
				cout << " Das Wort stimmt leider nicht.... Too bad." << "\n";
		}


		else {

			for (int i = 0; i < randword.length(); i++) {
				if (usedLtr[i] == input[0]) {
					cout << " Dieser Buchstabe wurde schon benutzt... wow..." << "\n";
					used = true;
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
			

			}

			

			else if (IsLetterInWord(input[0], randword) == false && used == false) {
				usedLtr[usenum++] = input[0];
				usedLtr[usenum + 1] = '\n';
				
				cout << " Der Buchstabe ist NICHT im Wort. Too bad..." << "\n";

				guess--;
				


			}


			
		}

		if (censWord == randword) {
			cout << "Ach kommt schon leute, es steht doch schon da..." << "\n";
		}

		HangPic(guess);

		
		cout << " \n Benutzte Buchstaben: "<< usedLtr << "\n";
		

		cout << "Versuche: " << 10-guess << "\n"<<  "__________________________________________________________________________________ \n";



		

	

		if (guess == -1) {
			
			cout << " Und du hast Sie/Ihn umgebracht.. Na Toll... \n";
			break;
		}
		used = false;

		PlTurn++;
	}
}






	

	
	




