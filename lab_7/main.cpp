//Разработать функтор, позволяющий собирать статистику
//о последовательности целых чисел (послед может
//содержать числа от -500 до 500). Функтор после 
//обработки последовательности алгоритмом for_each
//должен предоставлять следующую статистику:
//a. Максимальное число в последовательности
//b. Минимальное число в последовательности
//c. Среднее число в последовательности
//d. Количество положительных чисел
//e. Количество отрицательных чисел
//f. Сумму нечетных элементов последовательности
//g. Сумму четных элементов последовательности
//h. Совпадают ли первый и последний элементы последовательности.
//Проверить работу программы на случайно сгенерированных последовательностях.

//2020-02-23
//Grigory Kulik

#include <iostream>
#include <vector>
#include <algorithm>
#include "functions.h"

int main()
{   
    std::vector<int> my_vector;
    std::vector<int>::iterator iter;

    my_vector=fill_vector(100);

    for(iter=my_vector.begin(); iter!=my_vector.end(); iter++) 
    {
        std::cout<<*iter<<std::endl;
    }

    stat_collector collector=stat_collector();
    for_each(my_vector.begin(), my_vector.end(), collector);

    show_stats();

    return 0;
}