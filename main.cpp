/// Maik Hoffmann
/// C++ Basics E228
/// * Dieses Tool soll das Alter abfragen und ausgeben können

// For Paste and Copy for this script
/**
* @description : Beschreibung
*
* @param : Angabe sämtlicher Parameter
*
* @todo : Was ist noch zu tun?
*
*
* @throws : wirft eine exception (Ausnahme)?
* @error : erzeugt ein Fehler
* @return: Was wird zurück gegeben
*/


#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>


/// Schalter für Windows/Linux
//#undef WINDOWS
#define WINDOWS

///* Zeitstempel für die Todos
// http://www.willemer.de/informatik/cpp/timelib.htm


///* Ein und ausgabe von Dateien
// https://www.kompf.de/cplus/artikel/fwords.html

/// Nachher sollen die Todos und schlagwörter in markdowndateien (.md) gespeichert werden

std::string my_tag = "";
std::string my_todo = "";
std::string my_file = "tags.md";

/**
* @description : Anzeigen welche Befehle es gibt
*
* @param : keine
*
* @todo :
*
*
* @throws :
* @error :
* @return: string
*/
void command_help(){
    std::cout <<    "\n Hilfe \n"
                    "      tag | Schlagwort erstellen \n"
                    "     todo | Aufgabe erstellen \n"
                    " list_tag | Sclagwoerter anzeigen \n"
                    "list_todo | Aufgaben anzeigen" << std::endl;
    return;
}
/**
* @description : Meldung das der eingegebene Befehl nicht existiert
*
* @param : string a (Name des falschen Befehl)
*
* @todo :
*
*
* @throws :
* @error :
* @return: string
*/
void comand_err(std::string a){
    std::cout << "Sorry, ich weiss nicht was du willst. Den Befehl "<< a <<" kenne ich nicht" << std::endl;
    return;
}

void write_file(std::string my_file, std::string my_tag, std::string my_todo = "0"){

    std::fstream f;
	f.open (my_file, std::fstream::out | std::fstream::app);
	//std::string text;
	//std::cin >> text;
	if(my_todo == "0"){
        f << my_tag << " # " <<"\n";
	}else{
	    f << my_tag << " # " << my_todo <<"\n";
	}
	f.close();
	std::cout << "Das Schlagwort: " << my_tag << " wurde gespeichert!" << std::endl;
	if(my_todo != "0"){
        std::cout << "Das Todo: \n" << my_todo << "\n \n wurde gespeichert" << std::endl;
	}
	return;


}

/**
* @description : Schlagwort (tag) erstellen und in eine txt abspeichern
*
* @param :
*
* @todo : Dateibearbeitung später in eine eigene Funktion, mit übergabe des Dateinamen und des eingegebenes Wortes
*         Noch kontrollstruckturen für öffnen, speichern einbauen
*
* @todo : Fortgeschritten -> das Schlagwort als zweiter Parameter eingeben und verarbeiten lassen
* @throws :
* @error :
* @return: string
*/
void command_tag(){
    std::cout << "Schlagwort erstellen" << std::endl;
    std::cin >> my_tag;
	write_file(my_file, my_tag);
	return;
}


/**
* @description : ToDos erstellen und in einer txt speichern
*
* @param :
*
* @todo : Schlagwortabfrage -> Kontrollstruktur
*         Dateibearbeitung später in eine eigene Funktion, mit übergabe des Dateinamen und des eingegebenes Todos
*         Noch kontrollstruckturen für öffnen, speichern einbauen
*
* @todo : Fortgeschritten -> das DoDo als zweiter Parameter eingeben und verarbeiten lassen
*
* @throws : Ablauf der Abfragen stimmen noch nicht , bool abfrage ???
* @error :
* @return: Was wird zurück gegeben
*/
void command_todo(){
    std::cout << "Aufgabe erstellen" << std::endl;
	//std::cin >> my_todo;
	getline(std::cin, my_todo);
	std::cout << "welches Schlagwort?" << std::endl;
	//std::cin >> my_tag;
	getline(std::cin, my_tag);

    std::cout << my_todo << std::endl;
	/// Prüfung ob das Schlagwort existiert, wenn nicht Schlagwort erstellen (mit Rückfrage)
	std::ifstream f;  // Datei-Handle
    std::string s;

    //std::string::size_type n;
    bool test;

    f.open(my_file, std::fstream::in); // Öffne Datei aus Parameter
    while (!f.eof())          // Solange noch Daten vorliegen
    {
        getline(f, s);        // Lese eine Zeile
        //n = s.find(my_tag);
        //std::cout << n << std::endl;    // Zeige sie auf dem Bildschirm
        if(s.find(my_tag)){
            test = false;
        }else{
            test = true;

        }
    }

    /// if(tag vorhanden == true) und so weiter
    if(test == false){
        std::cout << my_tag << " existiert nicht" << std::endl;
        std::cout << "Wollen Sie dieses Schlagwort erstellen? \nJa (j) /Nein (n): " << std::endl;
        std::string j_n;
        std::cin >> j_n;
        if(j_n == "j"){
            //write_file(my_file, my_tag, my_todo);
            //f.close();
        }else{
            std::cout << "welches Schlagwort?" << std::endl;
            getline(std::cin, my_tag);
            //f.close();
        }
    }

    write_file(my_file, my_tag, my_todo);


    f.close();                // Datei wieder schließen




	//write_file(my_file, my_tag, my_todo);
}
/**
* @description : Auflisten aller Schlagwörter (tags)
*
* @param :
*
* @todo :
*
*
* @throws :
* @error :
* @return: strings
*/
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
/**
* @description : Auflisten der ToDos
*
* @param :
*
* @todo :
*
*
* @throws :
* @error :
* @return: strings
*/
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





