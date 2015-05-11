#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

class DataStructure {
private:
    int _value;
    DataStructure* _next;
public:
    DataStructure(int value);
    DataStructure* getnext();
    void changenext(DataStructure* next);
    void AddValue(int value);
    int Value();
};

#endif
