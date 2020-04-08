//1. Ниже приведен интерфейс класса очереди с приоритетами, 
//который функционирует следующим образом.

//В очередь могут быть добавлены элементы, каждому 
//элементу при добавлении присваивается один из трех 
//уровней приоритета (low, normal, high)

//Элементы из очереди извлекаются в соответствии с их 
//приоритетами (сначала извлекаются элементы с приоритетом 
//high, потом normal, потом low), элементы с одинаковыми 
//приоритетами извлекаются из очереди в порядки их поступления. 

//В очереди также может происходить операция 
//акселерации – все элементы с приоритетом low 
//находящиеся в момент акселерации в очереди 
//увеличивают свой приоритет до high и «обгоняют» 
//элементы с приоритетом normal.

/*Ниже приведен интерфейс этого класса:
typedef enum 
{
    LOW, 
    NORMAL,
    HIGH 
} ElementPriority;

typedef struct
{
    string name;
} QueueElement;

class QueueWithPriority
{
    // Конструктор, создает пустую очередь
   QueueWithPriority();

    // Деструктор
   ~QueueWithPriority();

    // Добавить в очередь элемент element с приоритетом priority
    void PutElementToQueue(const QueueElement& element, ElementPriority priority);

    // Получить элемент из очереди
    // метод должен возвращать элемент с наибольшим приоритетом, который был
    // добавлен в очередь раньше других
    QueueElement GetElementFromQueue();

    // Выполнить акселерацию
    void Accelerate();
};

Реализовать этот класс, используя list или 
deque. Объяснить свой выбор. Протестируете программу, 
добавьте отладочный вывод, показывающий, 
что  класс работает правильно.

2020-02-15
Grigory Kulik*/

#include <iostream>
#include "pqueue.h"

using namespace std;

int main(){
    queue_with_priority hospital=queue_with_priority();

//let's create a hospital and populate it with some sick bastards    
    queue_element patient_1;
    patient_1.name="Ушиб";
    hospital.put_element_to_queue(patient_1, low);

    queue_element patient_2;
    patient_2.name="Перелом";
    hospital.put_element_to_queue(patient_2, normal);

    queue_element patient_3;
    patient_3.name="Аппендицит";
    hospital.put_element_to_queue(patient_3, high);

    queue_element patient_4;
    patient_4.name="Коронавирус";
    hospital.put_element_to_queue(patient_4, high);

    queue_element patient_5;
    patient_5.name="Я только спросить";
    hospital.put_element_to_queue(patient_5, low);

//let's see who's in the ward
    cout<<"Высокий приоритет: "<<endl;
    cout<<"*******************"<<endl;
    hospital.print_the_high_priority_queue();
    cout<<endl;

    cout<<"Средний приоритет: "<<endl;
    cout<<"*******************"<<endl;
    hospital.print_the_normal_priority_queue();
    cout<<endl;

    cout<<"Низкий приоритет: "<<endl;
    cout<<"*******************"<<endl;
    hospital.print_the_low_priority_queue();
    cout<<endl;

//let's cure somebody
    queue_element next=hospital.get_element_from_queue();
    cout<<"Начинаем лечение. \"Следующий! На что жалуемся?\" - "<<"\""<<next.name<<"\""<<" - \"На операцию\""<<endl;

//let's see who's in the ward again
    cout<<endl<<"В очереди остаются:"<<endl;
    cout<<"Высокий приоритет: "<<endl;
    cout<<"*******************"<<endl;
    hospital.print_the_high_priority_queue();
    cout<<endl;

    cout<<"Средний приоритет: "<<endl;
    cout<<"*******************"<<endl;
    hospital.print_the_normal_priority_queue();
    cout<<endl;

    cout<<"Низкий приоритет: "<<endl;
    cout<<"*******************"<<endl;
    hospital.print_the_low_priority_queue();
    cout<<endl;



//accelerate low-priority elements
    hospital.accelerate();
    cout<<"Очередь после ускорения: "<<endl;

    cout<<"Высокий приоритет: "<<endl;
    cout<<"*******************"<<endl;
    hospital.print_the_high_priority_queue();
    cout<<endl;

    cout<<"Средний приоритет: "<<endl;
    cout<<"*******************"<<endl;
    hospital.print_the_normal_priority_queue();
    cout<<endl;

    cout<<"Низкий приоритет: "<<endl;
    cout<<"*******************"<<endl;
    hospital.print_the_low_priority_queue();
    cout<<endl;


    return 0;
}