#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main(){
    vector<int> vect;
    vector<int>::iterator iter;
    vector<int>::iterator iter_2;
    int temp, temp_2;

    for (int i=0; i<10; i++) {
        vect.push_back(rand());
    }

    for (iter=vect.begin(); iter!=vect.end(); iter++) {
        cout<<*iter<<endl;
    }

    cout<<endl;

    for (iter=vect.begin(); iter!=vect.end(); iter++) {
        for (iter_2=vect.end()-1; iter_2>iter; iter_2--) {
            if (*(iter_2-1)>*iter_2) {
                temp=*(iter_2-1);
                temp_2=*iter_2;

                *(iter_2-1)=temp_2;
                *iter_2=temp;
            }
        }
    }

    for (iter=vect.begin(); iter!=vect.end(); iter++) cout<<*iter<<endl;
    
    return 0;
}