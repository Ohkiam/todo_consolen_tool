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


#include <stdio.h>
#include "header.h"



std::string my_tag = "";
std::string my_todo = "";
std::string my_file = "todos.md";
std::string my_tag_file = "tags.md";





/// hier die Funktionen

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
    getline(std::cin, my_tag);
	write_file(my_tag_file, my_tag);
	return;
}


/**
* @description : ToDos erstellen und in einer markdown datei speichern
*
* @param :
*
* @todo : Dateibearbeitung später in eine eigene Funktion, mit übergabe des Dateinamen und des eingegebenes Todos
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


	check_tag(my_tag);






    write_file(my_file, my_tag, my_todo);
    return;
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
    f.open(my_tag_file, std::fstream::in); // Öffne Datei aus Parameter
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
* @todo : in der Schleife funzt es noch nicht
*
*
* @throws :
* @error :
* @return: strings
*/
void command_list_todo(){
    std::cout << "Aufgaben: " << std::endl;
    std::cout << "Wollen Sie sich die Schlagwoerter anzeigen lassen? \nJa (j) /Nein (n): " << std::endl;
    std::string j_n;
    std::cin >> j_n;
    if(j_n == "j"){
        command_list_tag();
        std::cout << "mit welchem Schlagwort soll gesucht werden: " << std::endl;

        /// Irgendwo hier wird nicht eingelesen und angezeigt

        std::string s;
        std::cin >> s;
        std::ifstream f;  // Datei-Handle
        f.open(my_file, std::fstream::in); // Öffne Datei aus Parameter
        while (!f.eof())          // Solange noch Daten vorliegen
        {
            getline(f, s);        // Lese eine Zeile
            if(s.find(s) == true){
                std::cout << s << std::endl;
            }
        }
        f.close();                // Datei wieder schließen
    }else{
        command_list_todo();
    }


/*
    /// Damit tag und # mit "" ersetzen
    string r = "Der Fuchs ist in der Hundehütte";
    // Wie? Ersetze Fuchs mit Hund!
    r.replace( r.find( "Fuchs"), strlen("Fuchs"), "Hund");
    */
}
void check_tag(std::string my_tag){
    	/// Prüfung ob das Schlagwort existiert, wenn nicht Schlagwort erstellen (mit Rückfrage)
	std::ifstream f;  // Datei-Handle
    std::string s;
    bool is_found = false;
    f.open(my_tag_file, std::fstream::in); // Öffne Datei aus Parameter
    while (!f.eof())          // Solange noch Daten vorliegen
    {
        getline(f, s);        // Lese eine Zeile
        if(s.find(my_tag) == true){
            is_found = true;
        }
    }
    f.close();                // Datei wieder schließen
    if(is_found == true){
        std::cout << my_tag << " Ok, das Schlagwort existiert!" << std::endl;
    }else{
        std::cout << my_tag << " existiert nicht" << std::endl;
        std::cout << "Wollen Sie dieses Schlagwort erstellen? \nJa (j) /Nein (n): " << std::endl;
        std::string j_n;
        std::cin >> j_n;
        if(j_n == "n"){
            command_tag();
        }else{
            write_file(my_tag_file, my_tag);
        }
    }

}
