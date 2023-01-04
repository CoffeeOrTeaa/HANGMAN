#pragma once


#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void add() {
	ofstream lib;
	lib.open("Library.txt");
	if (lib.is_open()) {
		
		string word;
		
		cin >> word;
		
		lib << word << endl << "wtf";


		lib.close();

	}


}


	





