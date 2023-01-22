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

			cout	 << " Nummern sind in Woertern nicht erlaubt... Warum tust du das?" << endl << " Dein Wort lautet:" << word << endl;
			
			return true;

		}
	
	
	}

	return false;
};


char tolower(char BigL) {

	if (!('a' <= BigL && BigL <= 'z')) {
		BigL = BigL +  ('z' - 'Z');

	}

	return BigL;
}


int GetLibraryWordAmount() {
	ifstream opLib("Library.txt");

	//an das ende der Lib gehen
	opLib.seekg(0, opLib.end);
	//position des arrays ausgeben -> da wie am ende der lib sind wird die groesse angegeben
	int Libend = opLib.tellg();

	//cout << "groessse" << Libend << endl;					//groessse der Lib  ausgeben, fuer debug
	opLib.seekg(0, opLib.beg);

	

	char* buffer = new char[Libend];						//zwisvhenspeicher zur weitergabe d woerter

	opLib.read(buffer, Libend);								//fuellen des zwischenspeichers


	int i = 0;
	int row = 0;

	//zaehlt anzahl der Woerter
	while (buffer[i] != NULL) {
		if (buffer[i] == '\n')
			row++;
		i++;

	}
	//cout <<endl << row; //Anzahl der Woerter
	
	opLib.close();
	delete []buffer;
	return row;
}








//Done 12.01
string PrintLibFast(int num) { //anspielung auf Netflix serie
	ifstream opLib("Library.txt");

	//an das ende der Lib gehen
	opLib.seekg(0, opLib.end);
	//position des arrays ausgeben -> da wie am ende der lib sind wird die groesse angegeben
	int Libend = opLib.tellg();

	//cout << "groessse" << Libend << endl;					//groessse der Lib  ausgeben, fuer debug
	opLib.seekg(0, opLib.beg);


	char* buffer = new char[Libend];						//zwisvhenspeicher zur weitergabe d woerter

	opLib.read(buffer, Libend);								//fuellen des zwischenspeichers

	
															//gibt anzahl der Woerter aus
	int row = GetLibraryWordAmount();
	

	

	

	string* allwords = new string[row];		//string array mit der groessse von der anzahl der reihen




	int placeInDoc = 0;//Platz im Dokument
	int sizeOfWord = 0;//laenge des Wortes

	int allnum = 0;
	do {//pruefen bis wohin noch char ausgegeben werden

		if (buffer[placeInDoc] == '\n') {




			char* _buffer = new char[sizeOfWord];				//groessse vom Wort zwischenspeicher anpassen auf wort laenge


			for (int x = 0; x < sizeOfWord; x++) {
				_buffer[x] = buffer[placeInDoc - sizeOfWord + x];
			}

			_buffer[sizeOfWord] = NULL;

			allwords[allnum] = string{ _buffer };	
						//Speicher alle chars im _buffer als String in allwords ab.
			sizeOfWord = -1;											// zurueck setzen der Wortlaenge, um von vorne wieder hochzaehlen zu koennen

			//cout <<allwords[allnum] << endl; //moegliche ausgabe des gerade gespeicherten wortes
			allnum++;

		}

		sizeOfWord++;		//hochzaehlen der groesse der Woerter			
		placeInDoc++;	//naechster platz im dokument
	
	} while (buffer[placeInDoc] != NULL);
	
	


	
	delete[]buffer;
	

	opLib.close();
	return allwords[num];
}






// done 12.09																					!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
bool IsExistWord(string word) {


	int sizeLib = GetLibraryWordAmount();
	string* allw = new string[sizeLib];
	

	//fuelle ein array mit allen woertern
	for (int i = 0; i < sizeLib; i++)
		allw[i] = PrintLibFast(i);



	for (int i = 0; i < sizeLib; i++) {
		if (word == allw[i]) {
			return true;
		}
		
	}

	

	return false;
}


//Add to Lib //done 08,01
void AddToLib() {																													//DONE!
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
					cerr << " Oops Benutze bitte keine Zahlen in diesem Menu. Druecke Enter um fortzufahren..." << endl;
					cin.ignore();
					

					
				}
				else
				{
					
					
					for (int j = 0; j < word.length(); j++) {																				//das  Wort soll nur in lower case gespeichert werden. Deshalb wird jeder buchstabe um string durchgegangen um ihn zu testen ung ggbf zu konvertieren

						word[j] = tolower(word[j]);		
						
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

void deleteWord( ) {
	string wdel; //das zu loeschende Wort
	

	int _sizeLib = GetLibraryWordAmount();
	

	string* allw = new string[_sizeLib];


	for (int i = 0; i < _sizeLib; i++) {
		allw[i] = PrintLibFast(i);
		//cout << allw[i];
	}
	
	
	cout << "Gebe das zu loeschende Wort ein: " << endl;
	cin >> wdel;
	
	//wdel in lowercase aendern

	for(int i =0 ; i < wdel.length() ; i++)
		wdel[i] = tolower(wdel[i]);


	//erst pruefen ob das Wort existiert
	if (IsExistWord(wdel) == true) {

		//buffer mit der Groesse der Wortanzahl erstellen
		string* buffer = new string[_sizeLib];
		int j=0;

		for (int i = 0; i < _sizeLib; i++) {

			//alle woerter durchgehen bis uebereinstimmung gefunden ist
			if (wdel != allw[i]) {

				buffer[j] = allw[i];
				j++;
			}

		

		}
		
		

			ofstream opLib("Library.txt");
			for (int i = 0; i < _sizeLib; i++)
				opLib << buffer[i] << endl;
		
			opLib.close();
			
			
	}
	

	else
		cout << " Dieses Wort ist nicht in der Wort Library..." << endl;
		
}












	//Interface Lib
void IntLib() {

	char mode;

	int sizeLib;
	string* allwords;
	

	do {
		cout << " Waehlen sie ihre Option aus: " << endl
			<< "  1. Wort-Bibliothek anzeigen" << endl
			<< "  2. Wort hinzufuegen" << endl
			<< "  3. Wort loeschen" << endl
			<< "4 zum zum vorherigen Menu zurueck" << endl;




		cin >> mode;





		switch (mode) {

		case '1'://Lib Anzeigen
			
			sizeLib = GetLibraryWordAmount();
			allwords = new string[sizeLib];
		
			for (int i = 0; i < sizeLib; i++)
				allwords[i] = PrintLibFast(i);

			system("cls"); 

			cout << "Zeige Inhalt der Wort-Bibliothek" << endl << endl;

			for(int i =0; i< sizeLib; i++)
				cout << i << ". "<< allwords[i] << endl;
			
			
			cout << " Druecke Enter zum Fortzufahren.." << endl;
			cin.ignore();


			break;

		case '2'://WortHinzufuegen
			system("cls");
			AddToLib();

			//cout << "2 funyt" << endl;
			
			break;

		case '3':// wort entfernen
			system("cls");
			deleteWord();


		             


			break;

		



		default:
			system("cls");
			cout << "Ungueltige Eingabe, bitte Versuche es erneut" << endl;


			break;

		}







	} while (mode != '4');                                                                            // Beende Programm wenn 4 eingegeben wird


}























