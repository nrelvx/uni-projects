#include <iostream>
#include "../MoneyDLL/Money.h"

using namespace std;

void fnMoneyApp()
{
    Money m1(10, 50);
    Money m2(5, 75);

    cout << "First money: "; m1.Display();
    cout << "Second money: "; m2.Display();

    Money res;

    res = m1.Add(m2);
    cout << "Addition: "; res.Display();

    res = m1.Subtract(m2);
    cout << "Subtraction: "; res.Display();

    res = m1.Multiply(2.5);
    cout << "Multiplication (first * 2.5): "; res.Display();

    res = m1.Divide(3.0);
    cout << "Division (first / 3): "; res.Display();

    cout << "Division (first / second): " << m1.Divide(m2) << endl;

    cout << "Comparison: ";
    if (m1.IsEqual(m2))
        cout << "m1 == m2" << endl;
    else if (m1.IsGreater(m2))
        cout << "m1 > m2" << endl;
    else
        cout << "m1 < m2" << endl;
}

int main()
{
    fnMoneyApp();

    cout << "\nPress Enter to exit...";
    cin.get();
    cin.get();
    return 0;
}
