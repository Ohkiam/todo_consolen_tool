// Maik Hoffmann
// C++ Basics E228
// * Dieses Tool soll das Alter abfragen und ausgeben können

#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cstring>
#include <cstdio> ///  cstdio.h ist mehr auf c++ angepasst , funzt aber in der IBB nicht, warum auch immer (schlau machen)
#include <fstream>

//#undef WINDOWS
#define WINDOWS

void command_help(){
    std::cout << "Hilfe" << std::endl;
    std::cout << "      tag | Schlagwort erstellen" << std::endl;
    std::cout << "     todo | Aufgabe erstellen" << std::endl;
    std::cout << " list_tag | Sclagwoerter anzeigen" << std::endl;
    std::cout << "list_todo | Aufgaben anzeigen" << std::endl;
    return;
}
void comand_err(){
    std::cout << "Sorry, ich weiss nicht was du willst. Diesen Befehl kenne ich nicht" << std::endl;
    return;
}
void command_tag(){
    std::cout << "Schlagwort erstellen" << std::endl;
    std::fstream f;
	f.open ("test.txt", std::fstream::out | std::fstream::app);
	std::string text;
	std::cin >> text;
	f << text <<"\n";
	f.close();
	return;
}
void command_todo(){
    std::cout << "Aufgabe erstellen" << std::endl;
}
void command_list_tag(){
    std::cout << "Schlagwörter: anzeigen lassen " << std::endl;
    std::ifstream f;  // Datei-Handle
    std::string s;
    f.open("test.txt", std::fstream::in); // Öffne Datei aus Parameter
    while (!f.eof())          // Solange noch Daten vorliegen
    {
        getline(f, s);        // Lese eine Zeile
        std::cout << s << std::endl;    // Zeige sie auf dem Bildschirm

    }
    f.close();                // Datei wieder schließen
}
void command_list_todo(){
    std::cout << "Aufgaben: " << std::endl;
    std::cout << "hier fragen ob mit tag oder alle abgerufen werden sollen, ja für tag eingabe nur enter für auflisten aller aufgaben" << std::endl;
}

#if 0 // 1 ist für anschalten damit der code benutzt wird (0 zum ausschalten)
// Zum testen von Funktionen kann es benutzt werden

void command_list_tag(){
    std::cout << "Schlagwörter: anzeigen lassen " << std::endl;
}

#endif

int main(int argc, char **argv)
{
    if(argc < 2){
        #ifdef WINDOWS

            std::cout << "nur prog.exe in Windows aufgerufen" << std::endl;

        #else

            std::cout << "nur prog in Windows aufgerufen" << std::endl;

        #endif // WINDOWS


        return 0;
    }
    int i;

    for(i=0; i<argc; i++)
	{
		// hier werden die Strings verglichen mit !strcmp
		// wichtig ist das sring.h eingebunden wird

		if(!strcmp( argv[i], "prog.exe" )){
            // hier soll erstmall nix passieren
        }else if(!strcmp( argv[i], "help" )){
            command_help();
            return 0;
        }else if(!strcmp( argv[i], "tag" )){
            command_tag();
            return 0;
        }else if(!strcmp( argv[i], "todo" )){
            command_todo();
            return 0;
        }else if(!strcmp( argv[i], "list_tag" )){
            command_list_tag();
            return 0;
        }else if(!strcmp( argv[i], "list_todo" )){
            command_list_todo();
            return 0;
        }else{
            comand_err();
            //return 0;
        }

    }

return 0;
}





