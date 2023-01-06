#pragma once


#include <string>
#include <iostream>
#include <fstream>																												// source: https://cplusplus.com/reference/fstream/fstream/
#include <cctype>																												// source: https://cplusplus.com/reference/locale/tolower/


using namespace std;







//done 
void AddLib() {																													//DONE!
	ofstream lib;



	lib.open("Library.txt", ios_base::app);																						//openmode des Dokuments wirde ueber ios_base definiert. app wurde gewaehlt um nicht immer eine neue Library erzeugen zu muessen, aussserdem kann man so woerter auch direkt ueber die .txt Datei hinzufuegen ohne das sie geloescht werden source: https://cplusplus.com/reference/ios/ios_base/openmode/
	


	if (lib.is_open()) {

		
		string word;
		


		int o=0;
		int i = 0;
		
		
		do {
			cout << " Tippe das hinzuzufuegende Wort ein. " << endl << " Gebe '!' ein um die eingabe abzubrechen" << endl;

			

			cin >> word;																										//einlesen von Word
			if (word == "!") {																									//wenn word ! dann soll die while eingabe abgebrochen werden -> verhindern von dem abspeichern von !, das als abbruchsbedingung gesetzt wurde

				cout << " Beende Eingabe..." << endl;
				break;
			}

			for (int j=0; j < word.length(); j++) {																				//das  Wort soll nur in lower case gespeichert werden. Deshalb wird jeder buchstabe um string durchgegangen um ihn zu testen ung ggbf zu konvertieren
			
				word[j] = tolower(word[j]);																						//tolower ist eine funktion aus der lib cctype. Man haette es mit ascii code loesen koennen aber das ist eleganter
																																//source https://cplusplus.com/reference/locale/tolower/

			}




		
			lib <<  word << endl;																					//abspeicherung des Wortes mit einer Nummerierung um das auswaehlen des Worts an der Zahl fest machen zu koennen


			


		} while (word != "!");																									
		
		
		cout << " Woerter werden hinzugefuegt... " << endl;
		cin.ignore();																											// Kurz stoppen
	
		
		
		cin.ignore();
		lib.close();

	}
	else
		cout << "Datei konnte nicht geoeffnet werden. Breche den Prozess ab... Ooops that shouldnt have happened" << endl;
		
}																											//done!

//working it out
void ReadLib(int num) {
	ifstream is("Library.txt");
	int row = 0;
	int col = 0;
	
	char out;
	char* all = new char[100*100];
	


	while (is.get(out)) {


		all[row*col] = out;


		if (all[row*col] = ' ') {
			col++;
			row = 0;
		}

			//cout << out;
			row++;
	}
	
	
	


	//char c;										//openmode des Dokuments wirde ueber ios_base definiert. Out wurde gewaehlt um nur das lesen moeglich zu machen, um versehentliches schreiben/ueberschreiben zu verhindern.// source: https://cplusplus.com/reference/ios/ios_base/openmode/
	//while (is.get(c))          // loop getting single characters
	//	cout << c;
	
	
	
	
	/*
	istream& get (char* i,  streamsize 100);
	*/
	

}

	





