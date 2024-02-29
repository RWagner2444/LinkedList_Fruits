#pragma once
#include <iostream> // cout, cin, stream definitions, etc.
#include <cstddef>  // nullptr defined
#include <iomanip>  // std::setiosflags
#include <string>   // for working with strings
#include "global_config.h"    // determines whether memory leak detection is on
using namespace std;

class Fruit
{
private:
    // static constant members of class Fruit
    static const int CODE_LEN = 4;
    static const int MAX_NAME_LEN = 30;

    char* name;              // allocate memory (use new) - zero-terminated
    char code[CODE_LEN];     // NOT zero-terminated (be careful!)

public:
    // default constructor
    Fruit();

    // The Big3
    ~Fruit();                            // destructor
    Fruit(const Fruit& copyIn);            // copy constructor
    Fruit& operator=(const Fruit &rhs);    // assignment operator

    // Additional operators required
    // *****************************
    // returns true if name is lexicographically(dictionary order)
    // less than the name of the passed Fruit, false otherwise
    bool operator<(const Fruit& rhs);

    // returns true if name is the same as the name of
    // the passed Fruit, false otherwise
    bool operator==(const Fruit& rhs);

    // returns true if name is the not the same as the name of
    // the passed Fruit, false otherwise(This is a one liner!)
    bool operator!=(const Fruit& rhs);

    // writes the name, left - justified, in a field of
    // 30, then a space, then the PLU code.
    // The PLU code number is not zero - terminated, so you must
    // print it out a character at a time. - 4 if not done.
    // To print left justified to the output stream os :
    // os << setiosflags(ios::left) << setw(MAX_NAME_LEN) << ...
    friend ostream& operator<<(ostream& out, const Fruit& rhs);

    // Reads, assuming the nameand PLU code will be strings of
    // charactersand they will be separated by white - space.
    // Assume that the name is at most 30 characters long,
    // with no embedded spaces; however, you must allocate just
    // the right amount of space for the name(remember the 0).
    // So first read the name into a temporary buffer, then
    // allocate memory!The PLU code number is not zero - terminated,
    // so you must read it in one character at a time.
    friend istream& operator>>(istream& in, Fruit& rhs);
};