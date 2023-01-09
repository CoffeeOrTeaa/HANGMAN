#pragma once


#include <string>
#include <iostream>
#include <fstream>		 	// source: https://cplusplus.com/reference/fstream/fstream/
#include <cctype>           // source: https://cplusplus.com/reference/locale/tolower/
#include <vector>			// source: https://cplusplus.com/reference/vector/vector/

using namespace std;




//Prueft ob eine Zahl im Wort ist, koennen nicht auf ' ' testen, da space auch eine bestaetigung bei cin ist 

//done 08,01
bool IsNotAlph(string word,int wlength) {

	
	

	for (int i = 0; i < wlength; i++) {

	
		if (isalpha(word[i]) == false)
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
			

			for (int j = 0; j < word.length(); j++) {																				//das  Wort soll nur in lower case gespeichert werden. Deshalb wird jeder buchstabe um string durchgegangen um ihn zu testen ung ggbf zu konvertieren

				word[j] = tolower(word[j]);																						//tolower ist eine funktion aus der lib cctype. Man haette es mit ascii code loesen koennen aber das ist eleganter
																																//source https://cplusplus.com/reference/locale/tolower/

			}

			//cout << word;


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
					
					lib << word << endl;																					//abspeicherung des Wortes mit einer Nummerierung um das auswaehlen des Worts an der Zahl fest machen zu koennen



				}

			



			




		



			


		} while (word != "!");																									
		
		
		cout << " Woerter werden hinzugefuegt. Druecke Enter um fortzufahren... " << endl;
		cin.ignore();																											// Kurz stoppen
	
		
		
		
		lib.close();

	}
	else
		cerr << "Datei konnte nicht geoeffnet werden. Breche den Prozess ab... Ooops that shouldnt have happened" << endl;
		
}																											//done!


string SetWordOnlineFast(char* buffer, int size) { //Staffel 2

	char* buf = buffer;
	


	for (int i = 0; i < size; i++) {
		



	}

	
	return string{};

}




//working it out
void ReadLibOnlineFast() { //anspielung auf Netflix serie
	ifstream opLib("Library.txt");
						   
															//source: https://cplusplus.com/reference/vector/vector/
	vector<string> word;	
															//source: https://cplusplus.com/reference/istream/istream/seekg/
															//an das ende der Lib gehen
	opLib.seekg(0, opLib.end);		
															//position des arrays ausgeben -> da wie am ende der lib sind wird die groesse angegeben
	int Libend = opLib.tellg();
	cout << "groessse" << Libend << endl;					//groessse der Lib  ausgeben, fuer debug
	opLib.seekg(0, opLib.beg);									
	word.resize(Libend);									//vector groesse anpassen
	char* buffer = new char[Libend];						//zwisvhenspeicher zur weitergabe d woerter

	opLib.read(buffer, Libend);								//fuellen des zwischenspeichers
	



															//ausgabe der Liste (Debug)
	//for (int i = 0; i < Libend; i++)
		//cout << buffer[i];




	opLib.close();
}








//working on it,? 08,01
void PrintLib() {
	ifstream lib("Library.txt");		//oeffnen von Library
	char word;
	int num=0;


	while (lib.get(word)) {
		
		
		cout <<	word ;

	}


	cout << "Druecke Enter um fortzufahren..." << endl;
	cin.ignore();

	


	 
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
			PrintLib();



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























