#include <vector>
#include <random>
#include <iostream>

double fill_vector()
{
    return rand()%10+1;
}

void print_vector(double const &value)
{
    std::cout<<value<<std::endl;
}

double multiply_by_pi(double const &value)
{
    return value*3.14;
}