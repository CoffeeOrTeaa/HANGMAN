/*************************************************
* Dateiname: Cos_Programmieren
* Autor: cbu
* Datum:31.10.2022
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Zweck:
* Eingaben:
* Ausgaben:
************************************************/



#include <iostream>

using namespace std;





int main()
{
    cout << "Welcome to" << endl;
    cout << "HANGMAN" << endl;
    cout << "Die Regeln:" << endl;
    cout << " 1. Der Spielleiter sucht sich ein Wort aus und Tippt es ein, waehrend die anderen wegschauen - nicht spicken!"<< endl;
    cout << " 2. Das Raten faengt an, jeder aussser der Spielleiter ist ein/e Rater/-in!" << endl << "    Jeder aussser der Spielleiter ratet einen Buchstaben. Wer ein ganzes Wort erraten will, faengt das Wort mit einem '!' an!" << endl;
    cout << " 3. Erratene Buchstaben werden auf dem Bildschirm angezeigt und koennen nicht mehr vorgeschlagen werden!" << endl << "    Falls das Wort von den Ratern/Raterinnen nicht rechtzeitig erraten wird, dann hat der Spielleiter gewonnen" << endl << "    und die Rater / Raterinnen verloren!"
        << "    Wie viele Versuche die Rater/-innen noch haben wird als Zahl und als Strichmaennchen aufgezeigt!" << endl<< "    - Ist das Strichmaennchen fertig, dann sind die Veruche aus und der Spielleiter hat gewonnen!";
    cin.ignore();
    system("cls");





    return 0;
}


