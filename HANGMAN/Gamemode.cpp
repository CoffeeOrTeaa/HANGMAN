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
#include "PlayerVsPc.h"
#include "PlayFunc.h"

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





    int replend;
    char* game;
    int replaynum;
    char gamemode;
    do {
        cout << endl << "Bitte waehle den Spielmodus aus" << endl <<
            " 1. Spieler gegen Spieler" << endl <<
            " 2. Spieler gegen PC" << endl <<
            " 3. Greife auf die Wort-Bibliothek zu" << endl <<
            " 4. Auswahl stoppen" << endl;


        cin >> gamemode;
       
    

            switch (gamemode) {

            case '1':
                system("cls");
                PlayerVsPLayer();

                cout << " wollt ihr die wiederholung vom Spiel sehen? \n 1. ja \n 2. nein \n";
                  
                cin >> replaynum;
                    
                if (replaynum == 1) {
                    ifstream replay("Replay.txt");

                    replay.seekg(0, replay.end);

                    replend = replay.tellg();
                    replay.seekg(0, replay.beg);


                    cout << replend;
                    game = new char[replend];

                    replay.read(game, replend);


                    cout << game << endl;
                    replay.close();
                }
                



                //Aufruf von Spieler gegen Spieler cpp
                break;

            case '2':
                system("cls");
                PlayerVsPC(RandWord());
                cout << " wollt ihr die wiederholung vom Spiel sehen? \n 1. ja \n 2. nein \n";
                cin >> replaynum;
                if (replaynum == 1) {
                    ifstream replay("Replay.txt");

                   
                        replay.seekg(0, replay.end);

                    replend = replay.tellg();
                    replay.seekg(0, replay.beg);

                    cout << replend;
                    game = new char[replend];

                    replay.read(game, replend);


                    cout << game << endl;
                    replay.close();

                }
                

                break;

            case '3':
                system("cls");
             
                IntLib();
                  
                    


                break;

            case '4':
                system("cls");
                cout << "Beende Spiel" << endl;  //Beendet das Spiel
                break;



           
           
          
            
            default:
                system("cls");
                cout << "Ungueltige Eingabe, bitte Versuche es erneut" << endl;


                break;
               
            }
            






        } while (gamemode != '4');                                                                            // Beende Programm wenn 4 eingegeben wird


    }
  
