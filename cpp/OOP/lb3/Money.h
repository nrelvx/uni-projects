#pragma once
#include <string>

class Money
{
    long hrivna;
    unsigned char coins;
public:
    // ������������
    Money();
    Money(long h, unsigned char c);
    Money(const Money& other);

    // ����������
    ~Money();

    bool Init(long h, unsigned char c);
    void Read();
    void Display() const;
    std::string toString() const;

    Money Add(const Money& other) const;
    Money Subtract(const Money& other) const;
    Money Multiply(double factor) const;
    Money Divide(double factor) const;
    double Divide(const Money& other) const;

    bool IsEqual(const Money& other) const;
    bool IsGreater(const Money& other) const;
    bool IsLess(const Money& other) const;
};
