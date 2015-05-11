#include <iostream>
#include "DataStructure.h"
using namespace std;

DataStructure* Traverse(DataStructure* front, int index);
void AddItem(DataStructure* front, int index, int value);
void RemoveItem(DataStructure* front, int index);
void AddValue(DataStructure* front, int index, int value);
void PrintAll(DataStructure* front);
bool Alt(DataStructure* front);
void PrintAlt(DataStructure* front);
void MoveBack(DataStructure* front, int index);

int main() {
    DataStructure *front = NULL;
    int N, Q, i, j, temp, ind, size, val;
    char update;

    cin >> N >> Q;
    front = new DataStructure(N);
    for (i = 0; i < N; i++) {
        cin >> temp;
        AddItem(front, i, temp);
    }
    //PrintAlt(front);

    for (i = 0; i < Q; i++) {
        cin >> update;
        switch (update) {
            case 'M': cin >> ind >> size;
                for (j = 0; j < size; j++) {
                    MoveBack(front, ind - 1);
                }
                //PrintAll(front);
                PrintAlt(front);
                break;
            case 'R': cin >> ind >> size;
                for (j = 0; j < size; j++) {
                    RemoveItem(front, ind);
                    front->AddValue(-1);
                }
                //PrintAll(front);
                PrintAlt(front);
                break;
            case 'A': cin >> ind >> size >> val;
                for (j = 0; j < size; j++) {
                    AddValue(front, ind+j, val);
                }
                //PrintAll(front);
                PrintAlt(front);
                break;
            default: break;

        }
    }


    return 0;
}

DataStructure *Traverse(DataStructure *front, int index) {
    DataStructure *temp = front;
    int i;
    for (i = 0; i < index; i++) {
        if (temp != NULL)
            temp = temp->getnext();
    }
    return temp;
}

void AddItem(DataStructure *front, int index, int value) {

    DataStructure *temp = NULL, *temp2 = NULL, *newitem = NULL, *temp3;
    newitem = new DataStructure(value);
    temp = Traverse(front, index);
    if (temp != NULL)
        temp2 = temp->getnext();
    temp->changenext(newitem);
    temp3 = temp->getnext();
    temp3->changenext(temp2);

}

void RemoveItem(DataStructure* front, int index) {
    DataStructure *temp, *temp2;
    temp = Traverse(front, index - 1);
    temp2 = temp->getnext()->getnext();
    delete temp->getnext();
    temp->changenext(temp2);

}

void AddValue(DataStructure* front, int index, int value) {
    DataStructure *temp;
    temp = Traverse(front, index);
    temp->AddValue(value);

}

void PrintAll(DataStructure* front) {
    DataStructure *temp = front->getnext();
    while (temp != NULL) {
        cout << temp->Value() << " ";
        temp = temp->getnext();
    }
}

bool Alt(DataStructure* front) {
    DataStructure *temp = front->getnext(), *next;
    if (temp == NULL) {
        return true;
    } else {
        next = temp->getnext();
        while (next != NULL) {
            if (temp->Value() > 0) {
                if (next->Value() > 0)
                    return false;
            } else
                if (next->Value() < 0)
                return false;
            temp = temp->getnext();
            next = temp->getnext();
        }
    }
    return true;
}

void PrintAlt(DataStructure* front) {
    if (Alt(front))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

void MoveBack(DataStructure* front, int index) {
    DataStructure *temp, *back;
    temp = Traverse(front, index);
    back = Traverse(front, front->Value());
    back->changenext(temp->getnext());
    back = back->getnext();
    temp->changenext(temp->getnext()->getnext());
    back->changenext(NULL);


}