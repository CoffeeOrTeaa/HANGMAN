#pragma once


#include <iostream>
#include <fstream>
#include <ctime>
#include <string>


using namespace std;

//von 10 runterzaehlen -> 10 ist noch nix
void HangPic(int guess) {
	
	switch (guess)
	{
	case 10:
	{
		cout << "                     " << endl;
		cout << "                     " << endl;
		cout << "                     " << endl;
		cout << "                     " << endl;
		cout << "                     " << endl;
		cout << "                     " << endl;
		cout << "                     " << endl;
		break;
	}
	case 9:
	{
		cout << "                     " << endl;
		cout << "                     " << endl;
		cout << "                     " << endl;
		cout << "                     " << endl;
		cout << "                     " << endl;
		cout << "                     " << endl;
		cout << " =================   " << endl;
		break;
	}
	case 8:
	{
		cout << "                     " << endl;
		cout << "|                    " << endl;
		cout << "|                    " << endl;
		cout << "|                    " << endl;
		cout << "|                    " << endl;
		cout << "|                    " << endl;
		cout << "|=================   " << endl;
		break;
	}
	case 7:
	{
		cout << "==================   " << endl;
		cout << "|                    " << endl;
		cout << "|                    " << endl;
		cout << "|                    " << endl;
		cout << "|                    " << endl;
		cout << "|                    " << endl;
		cout << "|=================   " << endl;
		break;
	}
	case 6:
	{
		cout << "==================   " << endl;
		cout << "| /                  " << endl;
		cout << "|/                   " << endl;
		cout << "|                    " << endl;
		cout << "|                    " << endl;
		cout << "|                    " << endl;
		cout << "|=================   " << endl;
		break;
	}
	case 5:
	{
		cout << "==================   " << endl;
		cout << "| /         !        " << endl;
		cout << "|/                   " << endl;
		cout << "|                    " << endl;
		cout << "|                    " << endl;
		cout << "|                    " << endl;
		cout << "|=================   " << endl;
		break;
	}
	case 4:
	{
		cout << "==================   " << endl;
		cout << "| /         !        " << endl;
		cout << "|/          0        " << endl;
		cout << "|                    " << endl;
		cout << "|                    " << endl;
		cout << "|                    " << endl;
		cout << "|=================   " << endl;
		break;
	}
	case 3:
	{
		cout << "==================   " << endl;
		cout << "| /         !        " << endl;
		cout << "|/          0        " << endl;
		cout << "|           |        " << endl;
		cout << "|                    " << endl;
		cout << "|                    " << endl;
		cout << "|=================   " << endl;
		break;
	}
	case 2:
	{
		cout << "==================   " << endl;
		cout << "| /         !        " << endl;
		cout << "|/          0        " << endl;
		cout << "|          /|        " << endl;
		cout << "|                    " << endl;
		cout << "|                    " << endl;
		cout << "|=================   " << endl;
		break;
	}
	case 1:
	{
		cout << "==================   " << endl;
		cout << "| /         !        " << endl;
		cout << "|/          0        " << endl;
		cout << "|          /|\\       " << endl;
		cout << "|                    " << endl;
		cout << "|                    " << endl;
		cout << "|=================   " << endl;
		break;
	}
	case 0:
	{
		cout << "==================   " << endl;
		cout << "| /         !        " << endl;
		cout << "|/          0        " << endl;
		cout << "|          /|\\       " << endl;
		cout << "|          / \\       " << endl;
		cout << "|                    " << endl;
		cout << "|=================   " << endl;
		

		break;
	}
	default:
		cout << "___FEHLER___!!!!!";
	}




}

string RandWord() {

	string rword;
	srand(time(NULL));

	int randnum = rand() % (GetLibraryWordAmount() - 1);
	rword = PrintLibOnlineFast(randnum + 1);

	
	if (rword == "\n") {
		RandWord();
	}
	return rword;
}


bool IsLetterInWord(char input, string word) {

	for (int i = 0; i < word.length(); i++) {
		if (input == word[i])
			return true;

	}

	return false;

}




//spieleranzahl / durchwechseln			--max anzahl ist 10 da es nur so viele zuege gibt

//wort check

//wortauswahl - working on it

//spieler kann wort festlegen

//wiedergabe vim spiel -- buchstaben und zuege koennen in einem array gespeichert werden