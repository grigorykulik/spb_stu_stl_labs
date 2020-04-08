//Написать программу, которая выполняет следующие действия:
//a. Читает содержимое текстового файла
//b. Выделяет слова, словом считаются последовательность 
//символов разделенных пробелами и/или знаками табуляции 
//и/или символами новой строки
//c. Вывести список слов присутствующий в тексте без повторений
//(имеется в виду, что одно и то же слово может присутствовать в списке только один раз)

//2020-02-23
//Copyright by Grigory Kulik

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include "functions.h"

int main()
{   
    std::vector<std::string> words;
    std::vector<std::string>::iterator iter;
    std::vector<std::string>::iterator new_vector_end;
    std::string string_to_process;

    std::ifstream file("text");

    if (!file) 
    {
        std::cout<<"Cannot open the file. Make sure the file exists or has the correct format."<<std::endl;
        exit(EXIT_FAILURE);
    }

    getline(file, string_to_process, '\0');
    words=get_words(string_to_process);

    std::cout<<"Unsorted: "<<std::endl<<"------------------"<<std::endl;
    for (iter=words.begin(); iter!=words.end(); iter++)
    {
        std::cout<<*iter<<std::endl;
    }

    std::sort(words.begin(), words.end());
    std::cout<<"Sorted: "<<std::endl<<"------------------"<<std::endl;
    for (iter=words.begin(); iter!=words.end(); iter++)
    {
        std::cout<<*iter<<std::endl;
    }

    words.erase(std::unique(words.begin(), words.end()), words.end());

    std::cout<<"Filtered: "<<std::endl<<"------------------"<<std::endl;
    for (iter=words.begin(); iter!=words.end(); iter++)
    {
        std::cout<<*iter<<std::endl;
    }

}