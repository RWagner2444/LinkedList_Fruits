#pragma once
#include <cstddef>
#include <iostream>
#include "InfoType.h"
#include "global_config.h"    // configure memory leak detection

class LList
{
public:
    LList() { list = nullptr; }
    ~LList();    // delete all the nodes
    bool IsEmpty() const;
    bool Insert(InfoType* x_ptr);
    bool Delete(const InfoType& x);
    void Display(ostream& out_stream) const;

private:
    struct Node
    {
        Node(InfoType* x, Node* p = nullptr) { infoPtr = x;  next = p; }
        ~Node() { delete infoPtr; }
        InfoType* infoPtr;
        Node* next;
    };

    Node* list;
    LList(const LList& copyFrom);                 // Don't allow!
    LList& operator= (const LList& assignFrom);   // Don't allow!
};