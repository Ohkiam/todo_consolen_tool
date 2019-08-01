#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>


/// wenn in funktionen.cpp weg sind die Globalen Variablen hier nicht auskommentiert sind, gibt es folgende Fehlermeldungen
/// multiple definition of 'my_tag[abi:cxx11]'
/// first defined here
/// in function 'main'
/*
extern std::string my_tag = "";
extern std::string my_todo = "0";
extern std::string my_file = "todos.txt";
extern std::string my_tag_file = "tags.txt";
*/

void command_help();

void comand_err(std::string a);

void exist_file();

void write_file(std::string todo);

void command_tag();

void command_todo();

void command_list_tag();

void command_list_todo();

void check_tag();
