// For Paste and Copy for this script
/**
* @description : Beschreibung
*
* @param : Angabe s�mtlicher Parameter
*
* @todo : Was ist noch zu tun?
*
*
* @throws : wirft eine exception (Ausnahme)?
* @error : erzeugt ein Fehler
* @return: Was wird zur�ck gegeben
*/


#include <stdio.h>
#include "header.h"



std::string my_tag = "";
std::string my_todo = "0";
std::string my_file = "todos.txt";
std::string my_tag_file = "tags.txt";





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

void write_file(){
    #if 0
    std::ofstream file(my_tag_file);
    if(!file){
        std::fstream datei(my_tag_file, std::fstream::out | std::fstream::app);
    }
    file.close();
    std::ofstream file1(my_file);
    if(!file1){
        std::fstream datei(my_file, std::fstream::out | std::fstream::app);
    }
    file1.close();
    #endif // 0
    std::string save_file;
    if(my_todo == "0"){
        save_file = my_tag_file;
	}else{
	    save_file = my_file;
	}
    std::fstream f;
	f.open (save_file, std::fstream::out | std::fstream::app);
	//std::string text;
	//std::cin >> text;
	if(my_todo == "0"){
        f << my_tag << " # " <<"\n";
        std::cout << "Das Schlagwort: " << my_tag << " wurde gespeichert!" << std::endl;
	}else{
	    f << my_tag << " # " << my_todo <<"\n";
	    std::cout << "Das Todo: \n" << my_todo << "\n \n wurde gespeichert in " << std::endl;
	}
	f.close();


	return;


}

/**
* @description : Schlagwort (tag) erstellen und in eine txt abspeichern
*
* @param :
*
* @todo : Dateibearbeitung sp�ter in eine eigene Funktion, mit �bergabe des Dateinamen und des eingegebenes Wortes
*         Noch kontrollstruckturen f�r �ffnen, speichern einbauen
*
* @todo : Fortgeschritten -> das Schlagwort als zweiter Parameter eingeben und verarbeiten lassen
* @throws :
* @error :
* @return: string
*/
void command_tag(){
    std::cout << "Schlagwort erstellen" << std::endl;
    getline(std::cin, my_tag);
	write_file();
	return;
}


/**
* @description : ToDos erstellen und in einer markdown datei speichern
*
* @param :
*
* @todo : Dateibearbeitung sp�ter in eine eigene Funktion, mit �bergabe des Dateinamen und des eingegebenes Todos
*         Noch kontrollstruckturen f�r �ffnen, speichern einbauen
*
* @todo : Fortgeschritten -> das DoDo als zweiter Parameter eingeben und verarbeiten lassen
*
* @throws : Ablauf der Abfragen stimmen noch nicht , bool abfrage ???
* @error :
* @return: Was wird zur�ck gegeben
*/
void command_todo(){
    //std::cin >> my_tag;
	std::cout << "Schlagwort ?" << std::endl;
	getline(std::cin, my_tag);

	check_tag();

	std::cout << "Aufgabe erstellen" << std::endl;
	//std::cin >> my_todo;

	getline(std::cin, my_todo);

    write_file();
    return;
}
/**
* @description : Auflisten aller Schlagw�rter (tags)
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
    std::cout << "Schlagw�rter: anzeigen lassen " << std::endl;
    std::ifstream f;  // Datei-Handle
    std::string s;
    f.open(my_tag_file, std::fstream::in); // �ffne Datei aus Parameter
    while (!f.eof())          // Solange noch Daten vorliegen
    {
        getline(f, s);        // Lese eine Zeile
        std::cout << "\t" << s.substr(0, s.size()-2) << std::endl;    // Zeige sie auf dem Bildschirm und nehme das # weg


    }
    f.close();                // Datei wieder schlie�en
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

        /// H����???

        std::string suche;
        std::cin >> suche;
        std::cout << "\n" << std::endl;
        int counter = 1;
        std::string s;
        std::ifstream f;  // Datei-Handle
        f.open(my_file, std::fstream::in); // �ffne Datei aus Parameter
        while (!f.eof())          // Solange noch Daten vorliegen
        {
            getline(f, s);        // Lese eine Zeile
            //std::cout << s << std::endl;
            //std::cout << suche << std::endl;
            /// Hier gibt es zwei m�glichkeiten um zum gesuchten zu kommen
            #if 0 /// Variante eins
            if(s.find(suche) == false){
                //std::cout << s.find("kind") << "    Suchwort: " << suche << " im String " << s << std::endl;
            }
            #endif // 0
            #if 1 /// Variante zwei (mein Favorit)
            if(s.find(suche) != std::string::npos){
                //std::cout << s.find(suche) << "     Suchwort: " << suche << " im String " << s << std::endl;
                std::cout << "\n \t" << counter++ << s.replace(s.find(s[0]), std::string(suche).length()+2 , "") << "\n" << std::endl;
                //s.replace(s.find(s[0]), std::string(suche).length(), "");
            }
            #endif // 1
        }
        f.close();                // Datei wieder schlie�en
    }else{
        std::string s;
        std::ifstream f;  // Datei-Handle
        f.open(my_file, std::fstream::in); // �ffne Datei aus Parameter
        while (!f.eof())          // Solange noch Daten vorliegen
        {
            getline(f, s);        // Lese eine Zeile
            std::cout << s << std::endl;

        }
        f.close();                // Datei wieder schlie�en
    }


/*
    /// Damit tag und # mit "" ersetzen
    string r = "Der Fuchs ist in der Hundeh�tte";
    // Wie? Ersetze Fuchs mit Hund!
    r.replace( r.find( "Fuchs"), strlen("Fuchs"), "Hund");
    */
}
void check_tag(){
    	/// Pr�fung ob das Schlagwort existiert, wenn nicht Schlagwort erstellen (mit R�ckfrage)
	std::ifstream f;  // Datei-Handle
    std::string s;
    bool is_found = false;
    f.open(my_tag_file, std::fstream::in); // �ffne Datei aus Parameter
    while (!f.eof())          // Solange noch Daten vorliegen
    {
        getline(f, s);        // Lese eine Zeile
        if(s.find(my_tag) != std::string::npos){
            is_found = true;
            std::cout << s.find(my_tag) << "   existiert" << std::endl;
        }
    }
    f.close();                // Datei wieder schlie�en
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
            write_file(); /// hier stimmt was nicht, nehme an die "�bergabe" in welcher Datei geschrieben werden soll
        }
    }

}
