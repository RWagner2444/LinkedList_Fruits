#include "Fruit.h"  // Fruit specification

// Include memory leak detection - configured in global_config.h
#ifdef MEMORY_LEAK_ON
#include "LeakWatcher.h"
#endif

// DO NOT CHANGE THE BEGINNING OF THIS FILE
// YOUR IMPLEMENTATION GOES BELOW HERE

// default constructor
Fruit::Fruit(){
    //assign name to nullptr
    name = nullptr;
}

// The Big3
// destructor
Fruit::~Fruit(){
    //delete name
    delete[] name;
}

// copy constructor
Fruit::Fruit(const Fruit& copyIn){
    //name is already nullptr so no need to copy .name
    //so return there
    if (copyIn.name == nullptr) return;
    
    //copy name from copyIn
    name = new char[MAX_NAME_LEN+1];
    for(int i=0; i<MAX_NAME_LEN+1; i++){
        name[i] = copyIn.name[i];
    }
    //copy code from copyIn
    for(int i=0; i<CODE_LEN; i++){
        code[i] = copyIn.code[i];
    }
}

// assignment operator
Fruit& Fruit::operator=(const Fruit &rhs){
    //name is already nullptr so no need to assign new name
    //so return there
    if (rhs.name == nullptr) return *this;
    
    //initialize name char to length
    name = new char[MAX_NAME_LEN+1];
    //assign name from rhs.name
    for(int i=0; i<MAX_NAME_LEN+1; i++){
        name[i] = rhs.name[i];
    }
    //assign code from rhs.code
    for(int i=0; i<CODE_LEN; i++){
        code[i] = rhs.code[i];
    }
    
    return *this;
}

// Additional operators required
// *****************************
// returns true if name is lexicographically(dictionary order)
// less than the name of the passed Fruit, false otherwise
bool Fruit::operator<(const Fruit& rhs){
    //cast names to string to compare them
    string f1(name);
    string f2(rhs.name);
    int value = f1.compare(f2);

    //check value
    if(value < 0){
        return true;
    }
    return false;
}

// returns true if name is the same as the name of
// the passed Fruit, false otherwise
bool Fruit::operator==(const Fruit& rhs){
    //THE MEMORY LEAK IS FROM THIS METHOD
    //I CAN'T FIGURE OUT WHAT IT IS THOUGH
    
    //cast names to string to compare them
    string f1(name);
    string f2(rhs.name);
    int value = f1.compare(f2);
    
    //check value
    if(value == 0){
        return true;
    }
    return false;
}

// returns true if name is the not the same as the name of
// the passed Fruit, false otherwise(This is a one liner!)
bool Fruit::operator!=(const Fruit& rhs){
    //cast names to string to compare them
    string f1(name);
    string f2(rhs.name);
    int value = f1.compare(f2);

    //check value
    if(value != 0){
        return true;
    }
    return false;
}

// writes the name, left - justified, in a field of
// 30, then a space, then the PLU code.
// The PLU code number is not zero - terminated, so you must
// print it out a character at a time. - 4 if not done.
// To print left justified to the output stream os :
// os << setiosflags(ios::left) << setw(MAX_NAME_LEN) << ...
ostream& operator<<(ostream& out, const Fruit& rhs){
    //if name is null don't output anything and return
    if (rhs.name == nullptr) return out;
    
    //output name to certain format
    out << setiosflags(ios::left) << setw(Fruit::MAX_NAME_LEN) << rhs.name << ' ';
    //output code
    for(int i=0; i<Fruit::CODE_LEN; i++){
        out << rhs.code[i];
    }
    // must always pass back the ostream (cout << "hello" << "this enables chaining" << "just like other operators";)
    return out;
}

// Reads, assuming the nameand PLU code will be strings of
// charactersand they will be separated by white - space.
// Assume that the name is at most 30 characters long,
// with no embedded spaces; however, you must allocate just
// the right amount of space for the name(remember the 0).
// So first read the name into a temporary buffer, then
// allocate memory!The PLU code number is not zero - terminated,
// so you must read it in one character at a time.
istream& operator>>(istream& in, Fruit& rhs){
    //input name and code as strings
    string tempName, tempCode;
    in >> tempName >> tempCode;
    //initialize code to char length
    rhs.name = new char[Fruit::MAX_NAME_LEN+1];
    //assign name char from user input
    for(int i=0; i<tempName.size(); i++){
        rhs.name[i] = tempName[i];
    }
    //assign code char form user input
    rhs.name[tempName.size()] = '\0';
    for(int i=0; i<tempCode.size(); i++){
        rhs.code[i] = tempCode[i];
    }
    return in;
}