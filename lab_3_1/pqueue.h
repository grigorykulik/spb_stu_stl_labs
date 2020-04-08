//2020-02-15
//Copyright Grigory Kulik


#include <iostream>
#include <deque>
using namespace std;

typedef enum {
    low,
    normal,
    high
} element_priority;

typedef struct {
    string name;
} queue_element;

class queue_with_priority {
    public:
    deque<queue_element> low_priority;
    deque<queue_element> normal_priority;
    deque<queue_element> high_priority;


    // queue_with_priority();
    // ~queue_with_priority();


//show the low, normal, and high priority queues
    void print_the_low_priority_queue(){
        for (int i=0; i<low_priority.size(); i++) {
            cout<<low_priority.at(i).name<<endl;
        }
    }

    void print_the_normal_priority_queue(){
        for (int i=0; i<normal_priority.size(); i++) {
            cout<<normal_priority.at(i).name<<endl;
        }
    }

    void print_the_high_priority_queue(){
        for (int i=0; i<high_priority.size(); i++) {
            cout<<high_priority.at(i).name<<endl;
        }
    }


//move all elements from the low to high priority queue
    void accelerate(){
        int size=low_priority.size();
        for (int i=0; i<size; i++){
            high_priority.push_back(low_priority.front());
            low_priority.pop_front();
        }
    };

//add an element to the que
    void put_element_to_queue(const queue_element& element, element_priority priority){
        if (priority==low) {
            low_priority.push_back(element);
        }

        else if (priority==normal) {
            normal_priority.push_back(element);
        }

        else if (priority==high){
            high_priority.push_back(element);
        }
    }

//get element from the queue
    queue_element get_element_from_queue() {
        if (!high_priority.empty()) {
            queue_element return_value;
            return_value=high_priority.front();
            high_priority.pop_front();
            return return_value;
        }

        if (!normal_priority.empty()) {
            queue_element return_value;
            return_value=normal_priority.front();
            normal_priority.pop_front();
            return return_value;
        }

        if (!low_priority.empty()) {
            queue_element return_value;
            return_value=low_priority.front();
            low_priority.pop_front();
            return return_value;
        }

        else {
            cout<<"The queue is empty"<<endl;
        }

    }

};