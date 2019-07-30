/// Maik Hoffmann
/// C++ Basics E228
/// * Dieses Tool soll das Alter abfragen und ausgeben können

#pragma once  ///* Sorgt dafür das Headerdateien nur einmal eingebunden werden */

#include <stdio.h>
#include "header.h"
#include "funktionen.h"

/// Schalter für Windows/Linux
//#undef WINDOWS
#define WINDOWS


///* Ein und ausgabe von Dateien
// https://www.kompf.de/cplus/artikel/fwords.html



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
            /// Hier kommt nachher der Aufruf für die Gui rein
            std::cout << "nur prog.exe in Windows aufgerufen" << std::endl;
        #else
            /// Hier kommt nachher der Aufruf für die Gui rein
            std::cout << "nur prog in Linux aufgerufen" << std::endl;
        #endif // WINDOWS


        return 0;
    }
    int i;

    for(i=0; i<argc; i++)
	{
        #if 0
		/// https://www.geeksforgeeks.org/friend-class-function-cpp/
		/// geht also mit vererbung, mach ich aber erst später wenn es ans oop geht
		std::string a = argv[i];
		switch(a){
		    /**
		    error: switch quantity not an integer
		    Fehler : Schaltmenge ist keine ganze Zahl
		    */
		    case 'help': std::cout << a << std::endl; break;
		    case 'tag': std::cout << a << std::endl; break;
		    case 'todo': std::cout << a << std::endl; break;
		    default: std::cout << a << std::endl; break;
		}
		#endif // switch case

		#if 1
		// hier werden die Strings verglichen mit !strcmp
		// wichtig ist das sring.h eingebunden wird
        if(!strcmp( argv[i], "main.exe" )){
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
            std::string a = argv[i];
            //std::cout << argv[i] << "haha" << std::endl; /// @todo warum funzt das nicht, warum ruft er bei falschem Befehl zweimal die Funktion command_list_
            comand_err(a);
            //return 0;
        }
        #endif // if Spungliste

    }

return 0;
}





