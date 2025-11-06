#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// Базовий клас Liquid (рідина)
class Liquid {
protected:
    string name;        // назва рідини
    double density;     // щільність
public:
    Liquid(string n = "Невідома", double d = 1.0) : name(n), density(d) {}

    // Методи перепризначення
    void setName(string newName) { name = newName; }
    void setDensity(double newDensity) {
        if (newDensity > 0) density = newDensity;
    }

    // Методи отримання значень
    string getName() const { return name; }
    double getDensity() const { return density; }

    virtual void display() const {
        cout << "Рідина: " << name << ", Щільність: " << density << " г/см^3" << endl;
    }

    virtual ~Liquid() {}
};

// Похідний клас Alcohol (спирт)
class Alcohol : public Liquid {
private:
    double strength;    // міцність (%)
public:
    Alcohol(string n = "Спирт", double d = 0.79, double s = 40.0)
        : Liquid(n, d), strength(s) {
    }

    // Методи для роботи з міцністю
    void setStrength(double newStrength) {
        if (newStrength >= 0 && newStrength <= 100) strength = newStrength;
    }
    void changeStrength(double delta) {
        // Зміна міцності
        double newStrength = strength + delta;
        if (newStrength >= 0 && newStrength <= 100) strength = newStrength;
    }

    double getStrength() const { return strength; }

    void display() const override {
        cout << "Спирт: " << name << ", Щільність: " << density
            << " г/см³, Міцність: " << strength << "%" << endl;
    }
};

// Функція, що отримує та повертає об'єкт базового класу
Liquid processLiquid(const Liquid& liquid) {
    cout << "Обробка в функції: ";
    liquid.display();
    return liquid;
}

int main() {
    
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Тестування базового класу
    Liquid water("Вода", 1.0);
    water.display();
    water.setDensity(0.998);
    cout << "Після зміни щільності: ";
    water.display();
    cout << endl;

    // Тестування похідного класу
    Alcohol vodka("Горілка", 0.94, 40.0);
    vodka.display();
    vodka.setStrength(45.0);
    vodka.changeStrength(-3.0);
    cout << "Після змін міцності: ";
    vodka.display();
    cout << endl;

    // Демонстрація принципу підстановки
    cout << "Принцип підстановки" << endl;
    Liquid* liquidPtr = &vodka;  // Вказівник базового класу на похідний
    liquidPtr->display();        // Виклик методу похідного класу

    // Функція працює з базовим класом
    processLiquid(water);
    processLiquid(vodka);        // Може приймати похідний клас

    return 0;
}