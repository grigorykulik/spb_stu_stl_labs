//Написать программа, которая 
//выполняет следующие действия:
//a. Заполняет vector<DataStruct> 
//структурами DataStruct, при этом 
//key1 и key2, генерируются случайным 
//образом в диапазоне от -5 до 5, 
//str заполняется из таблицы (таблица 
//содержит 10 произвольных строк, 
//индекс строки генерируется случайным образом)
//b. Выводит полученный вектор на печать
//c. Сортирует вектор следующим образом:
//i. По возрастанию key1
//ii. Если key1 одинаковые, то по возрастанию key2
//iii. Если key1 и key2 одинаковые, то по возрастанию длинны строки str
//d. Выводит полученный вектор на печать
//DataStruct определена следующим образом:
//typedef struct
//{
//    int       key1;
//    int       key2;
//    string  str;
//} DataStruct;

//2020-02-23
//Grigory Kulik

#include <iostream>
#include <vector>
#include <fstream>
#include "functions.h"

int main() {
    std::vector<data_struct> vect;
    int size;

    srand(time(0));
    size=10;
    fill_vector(vect, size);

    std::cout<<"Unsorted vector"<<std::endl<<"=================="<<std::endl;
    for (int i=0; i<size; i++) 
    {   
        std::cout<<"Element number "<<i<<std::endl;
        std::cout<<vect.at(i).key_1<<std::endl;
        std::cout<<vect.at(i).key_2<<std::endl;
        std::cout<<vect.at(i).str<<std::endl<<std::endl;
    }

    sort(vect);
    
    std::cout<<"Sorted vector"<<std::endl<<"=================="<<std::endl;
    for (int i=0; i<size; i++) 
    {   
        std::cout<<"Element number "<<i<<std::endl;
        std::cout<<vect.at(i).key_1<<std::endl;
        std::cout<<vect.at(i).key_2<<std::endl;
        std::cout<<vect.at(i).str<<std::endl<<std::endl;
    }

}