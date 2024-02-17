//Code made by Nicolas Castaneda 

#include<iostream>

using namespace std;

// The class Node as a ADT that make up the links of the list
class Node{  

public:
    int data;  // the data that will be inserted in the Node 
    Node* next; // This is the link to the next node in the list, In C++ it is referenced using a pointer to a Node type
    
    Node(int value):data(value),next(nullptr){} // Constructor of the type Node
};

class LinkedList{

private:
    Node* head; // Pointer to the first element of the list 
    Node* cursor; //cursor is a pointer to a Node that helps to iterate over the links of the list

public:
    LinkedList():head(nullptr),cursor(nullptr){}; // Constructor initializes the pointer to the first element to nullptr
    
    void prepend(int data){   // inserting  element to the head of the list
        Node* new_node = new Node(data);
        if (head == nullptr){
            head = cursor = new_node;
        }else{
            Node* temp = head;
            head = new_node;
            new_node->next = temp;
            
        }
     }

    void append(int data){ // Inserting element at the end of the list
        Node* new_node = new Node(data);
        if (head == nullptr){
            head = new_node;
        }else{
            cursor = head;
            while(cursor->next != nullptr){
                cursor = cursor->next;
            }
            cursor->next = new_node;
        }
     }
    
    void print_list(){
        cursor = head;
        while(cursor!= nullptr){
            cout<< "->"<<cursor->data;
            cursor = cursor->next;
        }
    }

};

int main(){
   
    LinkedList Mylist;
    Mylist.append(1);
    Mylist.append(2);
    Mylist.append(3);
    Mylist.print_list();
    cout << endl;
    Mylist.prepend(0);
    Mylist.print_list();

    return 0;
}
