/*************************************************
* Dateiname: HANGMAN
* Autor: CoffeeOrTeaa
* Datum:21.12.2022
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Zweck:        Hangman
* Eingaben:
* Ausgaben:
************************************************/



#include <iostream>
#include <windows.h>
#include "Library.h"
#include "PlayerVsPlayer.h"
using namespace std;





int main()
{
    system("color F0");                 //macht den Hintergrund weiss und schrift schwarz 

    HWND console = GetConsoleWindow();   //passt die Fenstergroesse an
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.top, r.left, 1200, 900, TRUE);


    cout << "Welcome to" << endl;       //Regeln etc
    cout << "HANGMAN" << endl;
    cout << "Die Regeln:" << endl;
    cout << " 1. Der Spielleiter sucht sich ein Wort aus und Tippt es ein, waehrend die anderen wegschauen - nicht spicken!" << endl;
    cout << " 2. Das Raten faengt an, jeder aussser der Spielleiter ist ein/e Rater/-in!" << endl << "    Jeder aussser der Spielleiter ratet einen Buchstaben. Wer ein ganzes Wort erraten will, faengt das Wort mit einem '!' an!" << endl;
    cout << " 3. Erratene Buchstaben werden auf dem Bildschirm angezeigt und koennen nicht mehr vorgeschlagen werden!" << endl << "    Falls das Wort von den Ratern/Raterinnen nicht rechtzeitig erraten wird, dann hat der Spielleiter gewonnen" << endl << "    und die Rater / Raterinnen verloren!"
        << "    Wie viele Versuche die Rater/-innen noch haben wird als Zahl und als Strichmaennchen aufgezeigt!" << endl << "    - Ist das Strichmaennchen fertig, dann sind die Veruche aus und der Spielleiter hat gewonnen!" << endl << "Druecke Enter um Fortzufahren" << endl;
    cin.ignore();


    system("cls");                      //cleared den Screen

    string tstwrd;

    int gamemode;

    do {
        cout << "Bitte waehle den Spielmodus aus" << endl <<
            " 1. Spieler gegen Spieler" << endl <<
            " 2. Spieler gegen PC" << endl <<
            " 3. Fuege Woerter der Wort-Bibliothek hinzu" << endl <<
            " 4. Auswahl stoppen" << endl;


        cin >> gamemode;
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
    

            switch (gamemode) {

            case 1:
                system("cls");
                cout << "1 debug" << endl;
                






                //Aufruf von Spieler gegen Spieler cpp
                break;

            case 2:
                system("cls");
                 cout << "2 funyt" << endl;
                //Aufruf der cpp von Spieler gegen PC
                break;

            case 3:
                system("cls");
             
                IntLib();
                  
                    


                break;

            case 4:
                system("cls");
                cout << "Beende Spiel" << endl;  //Beendet das Spiel
                break;



           
            //case um funktionen zu testen
           case 6:
                cout << "hier wird getestet" << endl;

               
                tstwrd = "@";

               if(AlphTest(tstwrd,tstwrd.length())== true)
                cout << "zahl enthalten" << endl;
               else
                cout << "Zahl nicht enthalten" << endl;
                
               
               
               break;
            
            
            default:
                system("cls");
                cout << "Ungueltige Eingabe, bitte Versuche es erneut" << endl;


                break;

            }
            






        } while (gamemode != 4);                                                                            // Beende Programm wenn 4 eingegeben wird


    }
  
