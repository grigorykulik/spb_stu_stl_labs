#include <vector>
#include <random>
#include <iostream>

int number_of_calls=0;
int max, min, num_pos, num_neg, sum_odd, sum_even, first, last, sum;
double avg;

std::vector<int> fill_vector(int size)
{
    std::vector<int> v;

    srand(time(NULL));
    for(int i=0; i<size; i++) v.push_back(rand()%1001-500);
    return v;
}

class stat_collector
{
    public:
        stat_collector() 
        {   
            max=min=num_neg=num_pos=sum_even=sum_odd=first=last=0;
            avg=0.0;
        }
        void operator()(int value)
            {
                if (number_of_calls==0) first=value;
                last=value;
                ++number_of_calls;
                ++sum;
                
                if (value>max) max=value;
                if (value<min) min=value;
                if (value%2==0) sum_even+=value;
                    else sum_odd+=value;
                if (value>0)
                    ++num_pos;
                else ++num_neg;

                avg=sum/number_of_calls;
            }
};

void show_stats()
{
    std::cout<<"Vector stats:"<<std::endl<<"|-------------------|"<<std::endl;
    std::cout<<"Max number: "<<max<<std::endl;
    std::cout<<"Min number: "<<min<<std::endl;
    std::cout<<"Average value: "<<avg<<std::endl;
    std::cout<<"Number of positive elements: "<<num_pos<<std::endl;
    std::cout<<"Number of negative elements: "<<num_neg<<std::endl;
    std::cout<<"Sum of odd elements: "<<sum_odd<<std::endl;
    std::cout<<"Sum of even elements: "<<sum_even<<std::endl;
    if (first==last)
        std::cout<<"The first and the last element are equal."<<std::endl;
    else
        std::cout<<"The first and the last element are not equal."<<std::endl;
}