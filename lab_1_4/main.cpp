#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    char buffer[80];
    vector<char>::iterator iter;
    char ch;
    int i;

    ifstream file("text.txt");

    i=0;
    while (!file.eof()) {
        file.get(ch);
        buffer[i]=ch;
        i+=1;
    }

    vector<char> vect(buffer, buffer+80);

    for (iter=vect.begin(); iter!=vect.end(); iter++){
    cout<<*iter<<endl;
    }

    return 0;
}