#pragma once


#include <string>
#include <iostream>
#include <fstream>		 	// source: https://cplusplus.com/reference/fstream/fstream/
         // source: https://cplusplus.com/reference/locale/tolower/

using namespace std;



//Prueft ob eine Zahl im Wort ist, koennen nicht auf ' ' testen, da space auch eine bestaetigung bei cin ist 

//done 08,01
bool IsNotAlph(string word,int wlength) {
	
	
	

	for (int i = 0; i < wlength; i++) {
		
	
		
		


		if (!( 'a' <= word[i] && word[i] <= 'z') && !('A' <= word[i] && word[i] <= 'Z'))
		{

			cerr << " Nummern sind in Woertern nicht erlaubt... Warum tust du das?" << endl << " Dein Wort lautet:" << word << endl;
			
			return true;

		}
	
	
	}

	return false;
};



// working on it																						!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
bool IsExistWord(string word) {


	cout << " Pruefe!" << endl;



	return false;
}


char tolower(char BigL) {

	if (!('a' <= BigL && BigL <= 'z')) {
		BigL = BigL +  ('z' - 'Z');

	}

	return BigL;
}



//Add to Lib //done 08,01
void AddLib() {																													//DONE!
	ofstream lib;



	lib.open("Library.txt", ios_base::app);																						//openmode des Dokuments wirde ueber ios_base definiert. app wurde gewaehlt um nicht immer eine neue Library erzeugen zu muessen, aussserdem kann man so woerter auch direkt ueber die .txt Datei hinzufuegen ohne das sie geloescht werden source: https://cplusplus.com/reference/ios/ios_base/openmode/
	


	if (lib.is_open()) {

		
		string word;
		


		int o=0;
		int i = 0;
		
		
		do {
			
			
			cout << " Tippe das hinzuzufuegende Wort ein. " << endl << " Gebe '!' ein um die eingabe abzubrechen" << endl;

			cin >> word;
			


			if (word == "!") {																									//wenn word ! dann soll die while eingabe abgebrochen werden -> verhindern von dem abspeichern von !, das als abbruchsbedingung gesetzt wurde

				cout << " Beende Eingabe..." << endl;
				break;
			}

				
				
				if (IsNotAlph(word,word.length())==true || IsExistWord(word) == true)                                                                                   //NumTestet auf nummern, und so wird entschieden ob der cin komplett gecleared werden muss oder nur der Buffer entleert. 
				{
					cin.clear(); // macht error flag weg, wenn die Flag auf falschs steh dann funktioniert cin nicht mehr richtig
					cin.ignore((numeric_limits<streamsize>::max)(), '\n'); // macht den buffer frei
					cerr << " Oops Benutze bitte keine Zahlen in diesem Menu. Druecke Enter um fortzufahren..." << endl;
					cin.ignore();
					

					
				}
				else
				{
					//cleared buffer zur sicherheit
					cin.ignore((numeric_limits<streamsize>::max)(), '\n');// macht den buffer frei
					
					for (int j = 0; j < word.length(); j++) {																				//das  Wort soll nur in lower case gespeichert werden. Deshalb wird jeder buchstabe um string durchgegangen um ihn zu testen ung ggbf zu konvertieren

						word[j] = tolower(word[j]);																						//tolower ist eine funktion aus der lib cctype. Man haette es mit ascii code loesen koennen aber das ist eleganter
																																		//source https://cplusplus.com/reference/locale/tolower/

					}
					lib << word << endl;																					//abspeicherung des Wortes 



				}

			
				


			




		



			


		} while (word != "!");																									
		
		
		cout << " Woerter werden hinzugefuegt. Druecke Enter um fortzufahren... " << endl;
		cin.ignore();																											// Kurz stoppen
	
		
		
		
		lib.close();

	}
	else
		cerr << "Datei konnte nicht geoeffnet werden. Breche den Prozess ab... Ooops that shouldnt have happened" << endl;
		
}																											//done!





//working it out
string ReadLibOnlineFast(int num) { //anspielung auf Netflix serie
	ifstream opLib("Library.txt");
						   
															//an das ende der Lib gehen
	opLib.seekg(0, opLib.end);		
															//position des arrays ausgeben -> da wie am ende der lib sind wird die groesse angegeben
	int Libend = opLib.tellg();
	
	//cout << "groessse" << Libend << endl;					//groessse der Lib  ausgeben, fuer debug
	opLib.seekg(0, opLib.beg);		
	
	char* word = new char[Libend];							//source: https://cplusplus.com/reference/istream/istream/seekg/

	char* buffer = new char[Libend];						//zwisvhenspeicher zur weitergabe d woerter

	opLib.read(buffer, Libend);								//fuellen des zwischenspeichers
	

	int i = 0;
	int row=0;
	
	while (buffer[i] != NULL) {
		if (buffer[i] == '\n')
			row++;
		i++;

	}
	//cout <<endl << row; //Anzahl der Woerter
	 
	
	string* allwords = new string [row];		//string array mit der groessse von der anzahl der reihen
	
	
	

	int placeInDoc = 0;//Platz im Dokument
	int sizeOfWord=0;//laenge des Wortes
	
	int allnum = 0;
	do {//pruefen bis wohin noch char ausgegeben werden
		
		if (buffer[placeInDoc] == '\n') {
			

			
			
			char* _buffer = new char[sizeOfWord];				//groessse vom Wort zwischenspeicher anpassen auf wort laenge


			for (int x = 0; x < sizeOfWord; x++) {
				_buffer[x] = buffer[placeInDoc - sizeOfWord + x];
			}

			_buffer[sizeOfWord] = NULL;

			allwords[allnum] = string{ _buffer };				//Speicher alle chars im _buffer als String in allwords ab.
			sizeOfWord = -1;											// zurueck setzen der Wortlaenge, um von vorne wieder hochzaehlen zu koennen

			//cout <<allwords[allnum] << endl; //moegliche ausgabe des gerade gespeicherten wortes
			allnum++;
			
		}
		
		    sizeOfWord++;		//hochzaehlen der groesse der Woerter			
			placeInDoc++;	//naechster platz im dokument
			//cout << endl << size;
	} while (buffer[placeInDoc] != NULL);
;
		//ausgabe der Liste (Debug)
	/*for (int i = 0; i < Libend; i++)
		cout << buffer[i];*/

	


	opLib.close();
	return allwords[num];
}










	//Interface Lib
void IntLib() {

	int mode;


	do {
		cout << " Waehlen sie ihre Option aus: " << endl
			<< "  1. Wort-Bibliothek anzeigen" << endl
			<< "  2. Wort hinzufuegen" << endl
			<< "  3. Wort loeschen" << endl
			<< "4 zum zum vorherigen Menu zurueck" << endl;




		cin >> mode;




		if (!cin)                                                                                   //wenn invalid input, dann clear cin buffer clearen / zwischengespeicherte Inputs
		{
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			cerr << " Oops Benutze bitte nur korrespondierende Zahlen in diesem Menu" << endl;
		}
		else
		{
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');                                  //cleared buffer zur sicherheit
		}


		switch (mode) {

		case 1://Lib Anzeigen
			system("cls"); //wort lib
			//cout << "1 debug" << endl;
			//cin.ignore();
			ReadLibOnlineFast(4);



			break;

		case 2://WORT HINZU
			system("cls");
			AddLib();

			//cout << "2 funyt" << endl;
			
			break;

		case 3:
			system("cls");


		             


			break;

		



		default:
			system("cls");
			cout << "Ungueltige Eingabe, bitte Versuche es erneut" << endl;


			break;

		}







	} while (mode != 4);                                                                            // Beende Programm wenn 4 eingegeben wird


}























