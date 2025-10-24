#include "Header.h"
#include <iostream>
using namespace std;

bool Fraction::Init(int f, int s) {
    if (f > 0 && s > 0) {
        first = f;
        second = s;
        return true;
    }
    return false;
}

void Fraction::Read() {
    int f, s;
    do {
        cout << "Enter f: ";
        cin >> f;
        cout << "Enter s: ";
        cin >> s;
    } while (!Init(f, s));
}

void Fraction::Display() const {
    cout << first << "/" << second << endl;
}

int Fraction::ipart() const {
    if (second == 0) {
        cout << "Error, enter another s";
        return 0;
    }
    return first / second;
}

int main() {
    Fraction p;
    p.Read();
    p.Display();
    cout << "Integer part: " << p.ipart() << endl;
    return 0;
}
