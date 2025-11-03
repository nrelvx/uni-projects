#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>
#include <clocale>

using namespace std;

//ВЛАСНІ ВИКЛЮЧЕННЯ 
// 1. Порожній клас
class EmptyTriangleException {};
// 2. Незалежний клас із полями-параметрами функції
class TriangleException {
public:
    double a, b, c;
    string message;
    TriangleException(double sideA, double sideB, double sideC, const string& msg)
        : a(sideA), b(sideB), c(sideC), message(msg) {
    }
};
// 3. Спадкоємець від стандартного виключення з полями
class TriangleLogicError : public logic_error {
public:
    double a, b, c;
    TriangleLogicError(double sideA, double sideB, double sideC, const string& msg)
        : logic_error(msg), a(sideA), b(sideB), c(sideC) {
    }
};

// 4 ВАРІАНТИ ФУНКЦІЙ 
// 1. Без специфікації виключень
double trianglePerimeter1(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        throw invalid_argument("Сторони мають бути додатними числами");
    }
    if (a + b <= c || a + c <= b || b + c <= a) {
        throw invalid_argument("Не можна утворити трикутник з заданими сторонами");
    }
    return a + b + c;
}
// 2. Зі специфікацією throw()
double trianglePerimeter2(double a, double b, double c) throw() {
    if (a <= 0 || b <= 0 || c <= 0) {
        throw invalid_argument("Сторони мають бути додатними числами");
    }
    if (a + b <= c || a + c <= b || b + c <= a) {
        throw invalid_argument("Не можна утворити трикутник з заданими сторонами");
    }
    return a + b + c;
}
// 3. З конкретною специфікацією зі стандартним виключенням
double trianglePerimeter3(double a, double b, double c) throw(invalid_argument, logic_error) {
    if (a <= 0 || b <= 0 || c <= 0) {
        throw invalid_argument("Сторони мають бути додатними числами");
    }
    if (a + b <= c || a + c <= b || b + c <= a) {
        throw logic_error("Не можна утворити трикутник з заданими сторонами");
    }
    return a + b + c;
}
// 4. Зі специфікацією з власним виключенням
double trianglePerimeter4(double a, double b, double c) throw(EmptyTriangleException, TriangleException, TriangleLogicError) {
    if (a <= 0 || b <= 0 || c <= 0) {
        throw TriangleException(a, b, c, "Сторони мають бути додатними числами");
    }
    if (a + b <= c || a + c <= b || b + c <= a) {
        throw TriangleLogicError(a, b, c, "Не можна утворити трикутник з заданими сторонами");
    }
    // Додаткова перевірка для демонстрації порожнього класу
    if (a + b + c > 1000) {
        throw EmptyTriangleException();
    }
    return a + b + c;
}

// ГОЛОВНА ФУНКЦІЯ 
int main() {
    // Різні варіанти спроб локалі
#ifdef _WIN32
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "Ukrainian");
#else
    setlocale(LC_ALL, "uk_UA.UTF-8");
#endif

    // Додаткові спроби
    setlocale(LC_ALL, "");
    setlocale(LC_ALL, "uk_UA");
    setlocale(LC_ALL, "ukr");

    // Тестові дані для перевірки всіх випадків
    double testCases[][3] = {
        {3,4,5},        // правильний трикутник
        {1,1,3},        // неправильний трикутник 
        {-1,2,3},       // від'ємна сторона
        {0,4,5},        // нульова сторона
        {500,300,400},  // великий трикутник (для EmptyTriangleException)
        {5,5,5}         // рівносторонній трикутник
    };

    // Тестування 
    for (int funcType = 1; funcType <= 4; funcType++) {
        cout << "\n Функція " << funcType << endl;
        if (funcType == 1) cout << "Без специфікації виключень:" << endl;
        else if (funcType == 2) cout << "Зі специфікацією throw():" << endl;
        else if (funcType == 3) cout << "З конкретною специфікацією зі стандартним виключенням:" << endl;
        else if (funcType == 4) cout << "Зі специфікацією з власним виключенням:" << endl;

        for (int i = 0; i < 6; i++) {
            double a = testCases[i][0];
            double b = testCases[i][1];
            double c = testCases[i][2];
            cout << "  Сторони (" << a << "," << b << "," << c << "): ";
            try {
                double perimeter;
                // Виклик відповідної функції
                switch (funcType) {
                case 1:
                    perimeter = trianglePerimeter1(a, b, c);
                    break;
                case 2:
                    perimeter = trianglePerimeter2(a, b, c);
                    break;
                case 3:
                    perimeter = trianglePerimeter3(a, b, c);
                    break;
                case 4:
                    perimeter = trianglePerimeter4(a, b, c);
                    break;
                }
                cout << "Периметр = " << perimeter << endl;
            }
            catch (const invalid_argument& e) {
                cout << "invalid_argument: " << e.what() << endl;
            }
            catch (const logic_error& e) {
                cout << "logic_error: " << e.what() << endl;
            }
            catch (const EmptyTriangleException&) {
                cout << "EmptyTriangleException: периметр занадто великий" << endl;
            }
            catch (const TriangleException& e) {
                cout << "TriangleException: " << e.message << endl;
            }
            catch (const TriangleLogicError& e) {
                cout << "TriangleLogicError: " << e.what() << endl;
            }
        }
    }

    // Демонстрація коректної роботи
    cout << "\n Демонстрація коректної роботи " << endl;
    try {
        double a = 7, b = 8, c = 9;
        double perimeter = trianglePerimeter1(a, b, c);
        cout << "Трикутник зі сторонами " << a << "," << b << "," << c
            << " має периметр: " << perimeter << endl;
    }
    catch (const exception& e) {
        cout << "Помилка: " << e.what() << endl;
    }

    return 0;
}