
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>



void command_help();

void comand_err(std::string a);

void write_file(std::string my_file, std::string my_tag, std::string my_todo);

void command_tag();

void command_todo();

void command_list_tag();

void command_list_todo();

void check_tag(std::string my_tag);
