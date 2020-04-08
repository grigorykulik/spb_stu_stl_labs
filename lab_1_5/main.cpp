#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main(){
    vector<int> vect;
    vector<int>::iterator iter;
    vector<int>::iterator tmp;
    int temp;
    
//read numbers from the standard input. break if the number equals 0;
    while (temp) {
        cin>>temp;
        if (!temp) break;
        else vect.push_back(temp);
    }

    cout<<endl;
//print the vector
    for (iter=vect.begin(); iter!=vect.end(); iter++) {
        cout<<*iter<<endl;
    }

    cout<<endl;

//check whether the last element equals 1. erase all vector elements that are multiples of two
    if ((!vect.empty()) && vect.back()==1){
        for (iter=vect.begin(); iter!=vect.end(); iter++) {
            if (*iter%2==0) {
                vect.erase(iter);
                iter--;
            }
        }
    }


//TRICKY SONUVABITCH
    else if (vect.back()==2) {
        
        int i=0;
        int counter=0;
        for (i=0; i<vect.size(); ++i) {
            if (vect.at(i)%3==0) {
                counter++;
                tmp=vect.begin()+counter*3;
                vect.insert(tmp, 3, 1);
            }
        }
    }

//print the vector again
    for (iter=vect.begin(); iter!=vect.end(); iter++) {
        cout<<*iter<<endl;
    }

    return 0;
}