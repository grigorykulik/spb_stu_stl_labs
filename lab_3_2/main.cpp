//Разработайте программу, которая
//Заполняет list<int> 15 случайными значениями от 1 до 20,
//список может содержать от 0 до 20 значений (обязательно
// проверить на длине списка 0, 1. 2, 3, 4, 5, 7, 14)
//Выводит содержимое списка в следующем порядке: первый 
//элемент, последний элемент, второй элемент, 
//предпоследний элемент, тритий элемент и т.д.
//Например если список содержит:
//1 2 3 4 5 6 7 8
//то вывод будет иметь вид 
//1 8 2 7 3 6 4 5

//2020-12-15
//Grigory Kulik

#include <iostream>
#include <list>

using namespace std;

void fill_list(list<int> &my_list, int size) {
    for (int i=0; i<size; i++){
        my_list.push_back(rand()%20+1);
    }
}

void print_list(list<int> &my_list) {
    list<int>::iterator iter_1;
    list<int>::iterator iter_2;

    iter_1=my_list.begin();
    iter_2=--my_list.end();

    if (my_list.size()%2==0) {

    for (int i=0; i<my_list.size()/2; i++, ++iter_1, --iter_2) {
        cout<<*iter_1<<" ";
        cout<<*iter_2<<" ";
        }
    }

    else {
    for (int i=0; i<my_list.size()/2+1; i++, ++iter_1, --iter_2) {
        cout<<*iter_1<<" ";
        if (iter_1==iter_2) break;
        cout<<*iter_2<<" ";
        }
    }
}

int main() {

    list<int> my_list;
    list<int>::iterator iter;
    int r;

    srand(time(NULL));
    r=rand()%15+0;

    fill_list(my_list, r);
    
    cout<<"List size: "<<r<<endl;

    cout<<"Original list: ";

    for (iter=my_list.begin(); iter!=my_list.end(); iter++) {
        cout<<*iter<<" ";
    }
    cout<<endl;

    cout<<"Modified list: ";
    print_list(my_list);

    return 0;
}