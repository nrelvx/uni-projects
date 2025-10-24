#pragma once
#include <iostream>

class Fraction {
private:
    int first;   
    int second;  

public:
    bool Init(int f, int s);
    void Read();
    void Display() const;
    int ipart() const;
};
