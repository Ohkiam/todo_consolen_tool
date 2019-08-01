/**
* @autor : Maik Hoffmann
*
* @name : ConsolenToDo
*
* @description : Speichern und Ausgeben von ToDos (Aufgaben) in der Shell
*
* @todos : siehe todo.md im Projektordner
*
*
* @date : 01.08.2019
*/

#pragma once            /** Sorgt dafür das Headerdateien nur einmal eingebunden werden */

/** Bibliotheken */
#include <stdio.h>
#include "header.hpp"

/** Schalter für Windows/Linux */
//#undef WINDOWS
#define WINDOWS



int main(int argc, char **argv)
{
    /**
    * @description : Schalter für den Aufruf der Gui
    *
    * @param : Anzahl der übergebenen Parameter
    *
    * @todo : Diese Funktion muss noch augelagert werden, Problem ist die Übernahme der main Parameter (nochmal schlau machen ob es mit carsten geht)
    *
    * @throws :
    * @error :
    * @return:
    */
    if(argc < 2){
        #ifdef WINDOWS  /// Hier kommt nachher der Aufruf für die Gui rein
            std::cout << "nur prog.exe in Windows aufgerufen" << std::endl;
        #else           /// Hier kommt nachher der Aufruf für die Gui rein
            std::cout << "nur prog in Linux aufgerufen" << std::endl;
        #endif // WINDOWS
        return 0;
    }
    /**
    * @description : Schleife zum Auslesen der übergebenen Parameter beim Programmaufruf und aufruf der entsprechenden Funktionen
    *
    * @param : argc, argv
    *
    * @todo : Diese Funktion muss noch augelagert werden, Problem ist die Übernahme der main Parameter (nochmal schlau machen ob es mit carsten geht)
    *
    * @throws :
    * @error :
    * @return:
    */
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
        if(!strcmp( argv[i], "todo_consolen_tool.exe" )){

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
            comand_err(a);
            return 0;
        }
        #endif // if Spungliste
    }
return 0;
}
