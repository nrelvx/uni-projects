#include "Money.h"
#include <iostream>
#include <sstream>
using namespace std;


// ����������� �� �������������
Money::Money() : hrivna(0), coins(0) {
   // std::cout << "Default constructor called";
}

// ����������� � �����������
Money::Money(long h, unsigned char c) {
    Init(h, c);
   // std::cout << "Parameterized constructor called";
}

// ����������� ���������
Money::Money(const Money& other) {
    hrivna = other.hrivna;
    coins = other.coins;
   // std::cout << "Copy constructor called";
}

// ����������
Money::~Money() {
   // std::cout << "Destructor called for " << hrivna << "," << (int)coins << std::endl;
}

bool Money::Init(long h, unsigned char c)
{
    if (h >= 0 && c < 100) {
        hrivna = h;
        coins = c;
        return true;
    }
    return false;
}

void Money::Read()
{
    long h;
    unsigned int c;
    cout << "Enter hrivna and coins: ";
    cin >> h >> c;
    hrivna = h + c / 100;
    coins = c % 100;
}

void Money::Display() const
{
    cout << hrivna << "," << (int)coins << endl;
}

string Money::toString() const
{
    ostringstream ss;
    ss << hrivna << "," << (int)coins;
    return ss.str();
}

Money Money::Add(const Money& other) const
{
    long totalCoins = coins + other.coins;
    long h = hrivna + other.hrivna + totalCoins / 100;
    unsigned char c = totalCoins % 100;
    Money res;
    res.Init(h, c);
    return res;
}

Money Money::Subtract(const Money& other) const
{
    long total1 = hrivna * 100 + coins;
    long total2 = other.hrivna * 100 + other.coins;
    long diff = total1 - total2;
    if (diff < 0) diff = 0;
    Money res;
    res.Init(diff / 100, diff % 100);
    return res;
}

Money Money::Multiply(double factor) const
{
    long total = static_cast<long>((hrivna * 100 + coins) * factor);
    Money res;
    res.Init(total / 100, total % 100);
    return res;
}

Money Money::Divide(double factor) const
{
    if (factor == 0) factor = 1;
    long total = static_cast<long>((hrivna * 100 + coins) / factor);
    Money res;
    res.Init(total / 100, total % 100);
    return res;
}

double Money::Divide(const Money& other) const
{
    long total1 = hrivna * 100 + coins;
    long total2 = other.hrivna * 100 + other.coins;
    if (total2 == 0) total2 = 1;
    return static_cast<double>(total1) / total2;
}

bool Money::IsEqual(const Money& other) const
{
    return hrivna == other.hrivna && coins == other.coins;
}

bool Money::IsGreater(const Money& other) const
{
    return hrivna > other.hrivna || (hrivna == other.hrivna && coins > other.coins);
}

bool Money::IsLess(const Money& other) const
{
    return hrivna < other.hrivna || (hrivna == other.hrivna && coins < other.coins);
}
//��������� ��������
Money Money::operator+(const Money& other) const {
    return Add(other);
}

Money Money::operator-(const Money& other) const {
    return Subtract(other);
}

Money Money::operator*(double factor) const {
    return Multiply(factor);
}
