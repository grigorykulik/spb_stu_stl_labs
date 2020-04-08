#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main(){
    vector<int> vect;
    int temp;

    for (int i=0; i<10; i++) {
        vect.push_back(rand());
    }

    for (int i=0; i<10; i++) cout<<vect.at(i)<<endl;

    cout<<endl;

    for (int i=0; i<vect.size(); i++) {
        for (int j=vect.size()-1; j>i; j--) {
            if (vect.at(j-1)>vect.at(j)) {
                temp=vect.at(j-1);
                vect.at(j-1)=vect.at(j);
                vect.at(j)=temp;
            }
        }
    }

    for (int i=0; i<10; i++) cout<<vect.at(i)<<endl;
    
    return 0;
}