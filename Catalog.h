#pragma once
#include <iostream>
#include "LList.h"            // LList specification
#include "InfoType.h"        // Catalog Items (Fruit.h and ItemType defined)
#include "global_config.h"    // determines whether memory leak detection is on
using namespace std;

class Catalog
{
private:
    LList InfoTypeCatalog;
    void Insert(InfoType *);
    void Delete(const InfoType& x);
    void DisplayList();

public:
    // I do not need the constructor or destructor for my Catalog implementation
    // So, you may leave these methods commented and un-implemented
    //Catalog();    // default constructor
    //~Catalog();    // destructor

    // primary method launched by Prog2.cpp
    void Run();
};