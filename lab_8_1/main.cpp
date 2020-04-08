//Разработать программу, которая, используя 
//только стандартные алгоритмы и функторы, 
//умножает каждый элемент списка чисел 
//с плавающей  точкой на число PI

//2020-02-23
//Grigory Kulik

#include <iostream>
#include <vector>
#include "functions.h"
#include <algorithm>

int main()
{
    std::vector<double> my_vector (10);
    std::vector<double> new_vector (10);
    std::vector<double>::iterator it;

    srand(time(NULL));

    generate(my_vector.begin(), my_vector.end(), fill_vector);
    for_each(my_vector.begin(), my_vector.end(), print_vector);
    transform(my_vector.begin(), my_vector.end(), new_vector.begin(), multiply_by_pi);
    for_each(new_vector.begin(), new_vector.end(), print_vector);

    return 0;
}