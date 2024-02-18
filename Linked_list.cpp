//Code made by Nicolas Castaneda 

#include<iostream>

using namespace std;

// The class Node as a ADT that make up the links of the list
class Node{  

public:
    int data;  // the data that will be inserted in the Node 
    Node* next; // This is the link to the next node in the list, In C++ it is referenced using a pointer to a Node type
    
    Node(int value):data(value),next(nullptr){} // Constructor of the type Node 
    ~Node(){                                    // Destructor of the type Node
        cout<<"Node destroyed with value: " << data << endl;
    };
};

class LinkedList{

private:
    Node* head; // Pointer to the first element of the list 
    Node* cursor; //cursor is a pointer to a Node that helps to iterate over the links of the list

    int get_element(){  // gets the data element where the cursor is pointing at
        return cursor->data;
    }

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
        cursor = head; // returns the cursor to the beginning of the list i.e to the new node inserted
     }

    void append(int data){ // Inserting element at the end of the list
        Node* new_node = new Node(data);
        if (head == nullptr){
            head = new_node;
        }else{
            cursor = head; // Cursor is placed at the beginning of the list so that it can start iterating over the list
            while(cursor->next != nullptr){
                cursor = cursor->next;
            }
            cursor->next = new_node;
        }
        cursor = head; // returns the cursor to the beginning of the list
     }
    
    void print_list(){  //Prints  all elements of the list
        cursor = head;
        while(cursor!= nullptr){
            cout<< "->"<<cursor->data;
            cursor = cursor->next;
        } 
        cout << endl;
        cursor = head;   
    }

    void pop_last(){  // removes the last element of the list
        cursor = head;
        if(head == nullptr){
            cout << "List is already empty\n";
        }else if (head->next == nullptr){
            delete head;
            head = nullptr;
            cout << "List is now empty\n";
        }else{
            while (cursor->next->next != nullptr){
                cursor = cursor->next;
            }
            delete cursor->next;
            cursor->next = nullptr; 
        }
        cursor = head;        
        }

    void pop_first(){ // removes the first element of the list
        cursor = head;
        if(head == nullptr){
            cout << " List is already empty\n";
        }else if(head->next == nullptr){
            delete head;
            head == nullptr;
            cout << "List is now empty\n";
        }else{
            Node * old_head = head;
            head = cursor->next;
            delete old_head;
            cursor = head;
        }
    }

    bool is_in_List(int value){ // iterates throughout the list to look if value is in List
        cursor = head;
        if (head == nullptr){
            cout <<"List is empty\n";
            return false;
        }else{
            while(cursor != nullptr){
                if (value == cursor->data){
                    cout << "Value: " << cursor->data << "found in List\n";
                    return true;
                }
                cursor= cursor->next;
            }
            cout << "Value: "<< value<< " not found in List\n";
            return false; 
            cursor = head;
        }
    }

    int get_first_element(){
        cursor = head;
        if (head != nullptr){
            return get_element();
        } else{
            cout << "List is empty\n";
        }  
    }

    int get_last_element(){
        cursor = head;
        if (head == nullptr){
        cout << "List is empty\n";
        }else{
            while(cursor ->next != nullptr){
                cursor = cursor ->next;
            }
            return get_element();
        }
        cursor = head;
    }

    void remove_element(int val){
        cursor = head;
        if(head == nullptr){
            cout << "List is already empty\n";
        }
        if(head->data==val){
            pop_first();
        }else if (cursor->next->data == val){
          Node * following = cursor ->next->next;
          delete cursor->next;
          cursor->next = following;
          cursor = head;  
        }else{
            while(cursor->next->next != nullptr){
                if (cursor->next->data == val){
                    Node * following = cursor->next->next;
                    delete cursor->next;
                    cursor->next = following;
                    cursor = head;
                }
                cursor = cursor->next;
            }
            if(cursor->next->data == val){    // sees if the last one element is val
                delete cursor->next;
                cursor->next = nullptr; 
                cursor = head;
            } 
          cursor = head;
        }   
        cursor = head;              
    }
};

int main(){
   
    LinkedList Mylist;
    Mylist.append(1);
    Mylist.append(2);
    Mylist.append(3);
    Mylist.append(4);
    Mylist.append(5);
    Mylist.print_list();
    Mylist.prepend(0);
    Mylist.print_list();
    Mylist.pop_last();
    Mylist.print_list();
    Mylist.pop_first();
    Mylist.print_list();
    Mylist.remove_element(2);
    Mylist.print_list();  
    Mylist.remove_element(11);
    Mylist.print_list();

    return 0;
}
