#include "DataStructure.h"

DataStructure::DataStructure(int value) {
    _value = value;
    _next = NULL;
}

DataStructure* DataStructure::getnext() {
    return _next;
}

void DataStructure::changenext(DataStructure* next) {
    _next = next;
}

void DataStructure::AddValue(int value) {

    _value += value;

}

int DataStructure::Value() {

    return _value;
}