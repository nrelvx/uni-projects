#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

// Абстрактний клас "Геометрична фігура"
class GeometricShape {
protected:
    double centerX, centerY; // координати центра
    double rotationAngle;    // кут повороту в градусах
    double scaleFactor;      // масштабний фактор
    bool isVisible;          // чи видима фігура

public:
    GeometricShape(double x, double y, double angle = 0, double scale = 1)
        : centerX(x), centerY(y), rotationAngle(angle), scaleFactor(scale), isVisible(false) {
    }

    // Віртуальні функції
    virtual void show() = 0;
    virtual void hide() = 0;
    virtual void rotate(double angle) = 0;
    virtual void move(double dx, double dy) = 0;

    // Деструктор
    virtual ~GeometricShape() {}
};

// Похідний клас "Пряма"
class Line : public GeometricShape {
private:
    double x2, y2; // координати кінцевої точки

public:
    Line(double x1, double y1, double x2, double y2, double angle = 0, double scale = 1)
        : GeometricShape(x1, y1, angle, scale), x2(x2), y2(y2) {
    }

    void show() override {
        if (!isVisible) {
            cout << "Пряма показана (" << centerX << ", " << centerY << ") -> (" << x2 << ", " << y2 << ")" << endl;
            isVisible = true;
        }
    }

    void hide() override {
        if (isVisible) {
            cout << "Пряма прихована" << endl;
            isVisible = false;
        }
    }

    void rotate(double angle) override {
        rotationAngle += angle;
        cout << "Пряму повернуто на кут " << angle << " градусів. Новий кут: " << rotationAngle << endl;
    }

    void move(double dx, double dy) override {
        centerX += dx;
        centerY += dy;
        x2 += dx;
        y2 += dy;
        cout << "Пряму переміщено на вектор (" << dx << ", " << dy << "). Нові координати: ("
            << centerX << ", " << centerY << ") -> (" << x2 << ", " << y2 << ")" << endl;
    }
};

// Демонстраційна функція
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Line line(0, 0, 10, 10); // Створення прямої від (0,0) до (10,10)

    line.show();
    line.rotate(45);
    line.move(5, 5);
    line.hide();

    return 0;
}
