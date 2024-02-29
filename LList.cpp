#include "LList.h"

// Include memory leak detection - configured in global_config.h
#ifdef MEMORY_LEAK_ON
#include "LeakWatcher.h"
#endif

// DO NOT CHANGE THE BEGINNING OF THIS FILE
// YOUR IMPLEMENTATION GOES BELOW HERE

// delete all the nodes
LList::~LList(){
    //delete all values from linked list
    Node* temp = list;
    while(list != nullptr){
        temp = temp->next;
        delete list;
        list = temp;
    }
    list = nullptr;
}

bool LList::IsEmpty() const{
    //if the first value is null the list is empty
    if(list==nullptr){
        return true;
    }
    //if the first value is not null the list is not empty
    else return false;
}

bool LList::Insert(InfoType* x_ptr){
    //temp is the first value in the linked list
    //last is the previous value of the linked list
    Node* temp = list, *last = nullptr;
    // iterate through linked list to figure out where to insert x_ptr
    while(temp != nullptr){
        if(*x_ptr == *(temp->infoPtr)){
        //if(temp->infoPtr == x_ptr){
            return false;
        }
        if(*x_ptr < *(temp->infoPtr)){
            break;
        }
        last = temp;
        temp = temp->next;
    }
    //insert x_ptr into linked list
    if(last == nullptr){
        list = new Node(x_ptr, temp);
    }
    else{
        last->next = new Node(x_ptr, temp);
    }
    
    return true;
}

bool LList::Delete(const InfoType& x){
    Node* temp = list;
    Node* last = nullptr;
    //iterate through linked list to find x
    while(temp != nullptr){
        if(*temp->infoPtr == x){
            if(last == nullptr){
                list = temp->next;
            }
            else{
                last->next = temp->next;
            }
            delete temp;
            return true;
        }
        last = temp;
        temp = temp->next;
    }
    
    return false;
}

void LList::Display(ostream& out_stream) const{
    Node* temp = list;
    //iterate through list and output every fruit
    while (temp != nullptr){
        out_stream << *temp->infoPtr << "\n";
        temp = temp->next;
    }
}