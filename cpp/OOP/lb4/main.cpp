#include "Money.h"
#include <iostream>
using namespace std;

int main() {
    Money m1, m2, res;
    cout << "Enter first money (hrivna coins): ";
    m1.Read();
    cout << "Enter second money (hrivna coins): ";
    m2.Read();

    int choice;
    cout << "Choose operation:\n";
    cout << "1 - Add\n";
    cout << "2 - Subtract\n";
    cout << "3 - Multiply first money by 2.5\n";
    cout << "4 - Divide first money by 3\n";
    cout << "5 - Divide first money by second money\n";
    cout << "6 - Compare\n";
    cout << "Your choice: ";
    cin >> choice;

    //Змінення методів на оператори
    switch (choice) {
    case 1:
        res = m1 + m2;
        cout << "Result of addition: ";
        res.Display();
        break;
    case 2:
        res = m1 - m2;
        cout << "Result of subtraction: ";
        res.Display();
        break;
    case 3:
        res = m1 * 2.5;
        cout << "Result of multiplication by 2.5: ";
        res.Display();
        break;

    case 4:
        res = m1.Divide(3.0);
        cout << "Result of division by 3: ";
        res.Display();
        break;
    case 5: {
        double divRes = m1.Divide(m2);
        cout << "Result of dividing first money by second money: " << divRes << endl;
        break;
    }
    case 6:
        if (m1.IsEqual(m2)) cout << "m1 == m2" << endl;
        else if (m1.IsGreater(m2)) cout << "m1 > m2" << endl;
        else cout << "m1 < m2" << endl;
        break;
    default:
        cout << "Invalid choice" << endl;
    }

    return 0;
}
