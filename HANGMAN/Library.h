#pragma once


#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>


using namespace std;

void addLib() {
	ofstream lib;
	lib.open("Library.txt");
	if (lib.is_open()) {

		
		string word;
		


		int o=0;
		int i = 0;
		
		
		do {
			cout << " Tippe das hinzuzufuegende Wort ein. " << endl << " Gebe '!' ein um die eingabe abzubrechen" << endl;

			i++;

			cin >> word;																										//einlesen von Word
			if (word == "!") {																									//wenn word ! dann soll die while eingabe abgebrochen werden -> verhindern von dem abspeichern von !, das als abbruchsbedingung gesetzt wurde

				cout << " Beende Eingabe..." << endl;
				break;
			}

			for (int j=0; j < word.length(); j++) {																				//das  Wort soll nur in lower case gespeichert werden. Deshalb wird jeder buchstabe um string durchgegangen um ihn zu testen ung ggbf zu konvertieren
			
				word[j] = tolower(word[j]);																						//tolower ist eine funktion aus der lib cctype. Man haette es mit ascii code loesen koennen aber das ist eleganter
																																//source https://cplusplus.com/reference/locale/tolower/

			}




		
			lib << i <<". " << word << endl;																					//abspeicherung des Wortes mit einer Nummerierung um das auswaehlen des Worts an der Zahl fest machen zu koennen


			


		} while (word != "!");																									
		
		
		cout << " Woerter werden hinzugefuegt... " << endl;
		cin.ignore();																											// Kurz stoppen
	
		

		lib.close();

	}
	else
		cout << "Datei konnte nicht geoeffnet werden. Breche den Prozess ab..." << endl;

}


	





