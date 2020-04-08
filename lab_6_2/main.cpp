// Написать программу, которая выполняет следующие действия 
//(все операции должны выполняться с помощью стандартных алгоритмов):
// a. Заполняет вектор геометрическими фигурами. 
//Геометрическая фигура может быть треугольником, квадратом, 
//прямоугольником или пяти угольником. Структура описывающая 
//геометрическую фигуру  определена ниже, 
//b. Подсчитывает общее количество вершин всех фигур 
//содержащихся в векторе (так треугольник добавляет 
//к общему числу 3, квадрат 4 и т.д.)
//c. Подсчитывает количество треугольников, квадратов 
//и прямоугольников в векторе
//d. Удаляет все пятиугольники 
//e. На основании этого вектора создает vector<Point>, 
//который содержит координаты одной из вершин (любой) 
//каждой фигуры, т.е. первый элемент этого вектора 
//содержит координаты одной из вершину первой фигуры, 
//второй элемент этого вектора содержит координаты 
//одной из вершину второй фигуры и т.д.
//f. Изменяет вектор так, чтобы он содержал в начале 
//все треугольники, потом все квадраты, а потом прямоугольники.
//g. Распечатывает вектор после каждого этапа работы

//2020-02-23
//Grigory Kulik

#include <vector>
#include <iostream>
#include <algorithm>
#include "functions.h"

int main()
{   
    std::vector<shape> shapes(10);
    std::vector<point> points(10);
    std::vector<shape>::iterator iter;

    srand(time(NULL));
    generate(shapes.begin(), shapes.end(), generate_shape);
    print_vector(shapes);

    for_each(shapes.begin(), shapes.end(), get_overall_number_of_vertices);
    std::cout<<"Overall number of vertices in the vector is "<<overall_number_of_vertices<<std::endl;

    count_shapes(shapes);

    std::cout<<"Pentagons removed "<<std::endl;
    erase_pentagons(shapes);
    print_vector(shapes);

    transform(shapes.begin(), shapes.end(), points.begin(), get_random_point);
    
    sort(shapes);
    std::cout<<std::endl<<"After sorting:"<<std::endl;
    print_vector(shapes);

    return 0;
}
