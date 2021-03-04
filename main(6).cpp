#include <iostream>
#include <cmath>

using namespace std;

// базовый класс для фигур
class Shape {
public:
    virtual ~Shape() {}

    // метод square вычисляющий площадь фигуры
    virtual double square() const = 0;

    // метод perim для вычисления периметра
    virtual double perim() const = 0;

    virtual int angles_amount() const = 0;
};

// класс для круга
class Circle : public Shape {
public:

    Circle(const double &r) : r(r) {}

    double square() const {
        return 3.14 * r * r;
    }

    double perim() const {
        return 2 * 3.14 * r;
    }

    int angles_amount() const {
        return 0;
    }

private:
    unsigned int r;
};

// класс прямоугольника
class Rectangle : public Shape {
public:

    Rectangle(const double &w, const double &h) : w(w), h(h) {}

    double square() const {
        return w * h;
    }

    double perim() const {
        return w * 2 + h * 2;
    }

    int angles_amount() const {
        return 4;
    }


private:
    unsigned int w;
    unsigned int h;
};

// класс квадрат
class Square : public Shape {
public:

    Square(const double &a) : a(a) {}

    double square() const {
        return a * a;
    }

    double perim() const {
        return a * 4;
    }

    int angles_amount() const {
        return 4;
    }


private:
    unsigned int a;
};

// класс треугольника
class Triangle : public Shape {
public:

    Triangle(const double &a, const double &b, const double &c) : a(a), b(b), c(c) {}

    double square() const {
        return sqrt((a + b + c) / 2.0 * ((a + b + c) / 2.0 - a) * ((a + b + c) / 2.0 - b) * ((a + b + c) / 2.0 - c));
    }

    double perim() const {
        return a + b + c;
    }

    int angles_amount() const {
        return 3;
    }


private:
    unsigned int a;
    unsigned int b;
    unsigned int c;
};

// класс эллипса
class Ellipse : public Shape {
public:

    Ellipse(const double &a, const double &b) : a(a), b(b) {}

    double square() const {
        return 3.14 * a * b;
    }

    double perim() const {
        return ((3.14 * a * b + (a - b)) / (a + b)) * 4.0;
    }

    int angles_amount() const {
        return 0;
    }


private:
    unsigned int a;
    unsigned int b;
};


int main() {
    Shape *fig = new Circle(3);
    cout << fig->square() << endl;
    cout << fig->perim() << endl;
    cout << fig->angles_amount() << endl;
    delete fig;
}
