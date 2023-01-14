#pragma once


#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;



void PlayerVsPC(string randword) {

	char* wrdletter = new char[randword.length()];

	for (int i = 0; i < randword.length(); i++)
		wrdletter[i] = randword[i];


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
	for (int i = 0; i < randword.length(); i++)
		censWord[i] = '*';
	

	char input;
	char usedLtr[26];
	int usenum;
	bool used=false;
	
	while (1 == 1) {
		cin >> input;

		for (int i = 0; i < randword.length(); i++) {
			if (usedLtr[i] == input)
				cout << " Dieser Buchstabe wurde schon benutzt!" << endl;
			used = true;
		}
		
		if (used = false) {


		//wort checken
			for (int i = 0; i < randword.length(); i++) {
				//bei richtig raten
				if (input == wrdletter[i]) {
					censWord[i] = wrdletter[i]; cout << "Du hast richtig geraten!";
				}

				else if (censWord = wrdletter) {
					cout << " Du hast das Wort erraten! \n" << " Das Wort lautete: " << censWord;
				}


				else 
					cout << " Der Buchstabe ist leider nicht enthalten! " << endl;
		}



		}

	}









	 //random player begins
	srand(time(NULL));
	int PlTurn  = rand() % numPLayers;
	
	


	
	

}


