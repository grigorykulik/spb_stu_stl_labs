#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

//declare and implement the function to fill an array with random values
void fillRandom(double *array, int size) {
    double max=1;
    double min=-1;

    for (int i=0; i<size; i++) {
        array[i]=((max+(rand()/(RAND_MAX/(min-max)))));
    }
}

//declare and implement the function to sort an array using the bubble sort
void sortArray(double *array, int size) {
     double temp;
     for (int i=0; i<size; i++) {
        for (int j=size-1; j>i; j--) {
            if (array[j-1]>array[j]) {
                temp=array[j-1];
                array[j-1]=array[j];
                array[j]=temp;
            }
        }
    }
}


int main(){
    srand(time(0));
    
    vector<double> vect_5(5);
    vector<double> vect_10(10);
    vector<double> vect_25(25);
    vector<double> vect_50(50);
    vector<double> vect_100(100);

    double *pointer;
    pointer=&vect_5.at(0);
    
    fillRandom(pointer, 5);

    for (int i=0; i<5; i++) {
        cout<<vect_5[i]<<endl;
    }

    cout<<endl;

    sortArray(pointer, 5);
    
    for (int i=0; i<5; i++) {
        cout<<vect_5[i]<<endl;
    }

    return 0;
}