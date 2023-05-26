#include <iostream>
#include <string>

class Figure;
void getInfo(Figure&);

class Figure {
protected:
    std::string figureName{};

public:
    Figure() {
        this->figureName = "Фигура";
    }

    Figure(std::string figureName) {
        this->figureName = figureName;
    }

    std::string getFigureName() {
        return figureName;
    }

    virtual std::string Info() = 0{}
};

class Triangle : public Figure {
protected:
    int a{}, b{}, c{}, A{}, B{}, C{};

public:
    Triangle(int a, int b, int c, int A, int B, int C, std::string name) : Figure(name) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }

    Triangle(int a, int b, int c, int A, int B, int C) : Figure("Треугольник") {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }

    std::string Info() override {
        return figureName + ":\n" + "Стороны: a=" + std::to_string(a) + " b=" + std::to_string(b) + " c=" + std::to_string(c) + "\n"
            + "Углы: A=" + std::to_string(A) + " B=" + std::to_string(B) + " C=" + std::to_string(C) + "\n\n";
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90, "Прямоугольный треугольник") {}
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A, "Равнобедренный треугольник") {}
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60, "Равносторонний треугольник") {}
};

class Quadrangle : public Figure {
protected:
    int a{}, b{}, c{}, d{}, A{}, B{}, C{}, D{};
public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure("Четырёхугольник") {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }

    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D, std::string name) : Figure(name) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }

    std::string Info() override {
        return figureName + ":\n" + "Стороны: a=" + std::to_string(a) + " b=" + std::to_string(b) + " c=" + std::to_string(c) + " d=" + std::to_string(d) + "\n"
            + "Углы: A=" + std::to_string(A) + " B=" + std::to_string(B) + " C=" + std::to_string(C) + " D=" + std::to_string(D) + "\n\n";
    }

};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B, "Параллелограмм") {}
    Parallelogram(int a, int b, int A, int B, std::string name) : Quadrangle(a, b, a, b, A, B, A, B, name) {}
};

class Rectangle : public Parallelogram {
public:
    Rectangle(int a, int b) : Parallelogram(a, b, 90, 90, "Прямоугольник") {}
    Rectangle(int a, int b, std::string name) : Parallelogram(a, b, 90, 90, name) {}
};

class Rhomb : public Parallelogram {
public:
    Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B, "Ромб") {}
};

class Square : public Rectangle {
public:
    Square(int a) : Rectangle(a, a, "Квадрат") {}
};

int main()
{
    setlocale(LC_ALL, "Russian");
    
    Triangle triangleClass(10, 20, 30, 40, 50, 60);
    getInfo(triangleClass);

    RightTriangle right(10, 20, 30, 50, 60);
    getInfo(right);

    IsoscelesTriangle isoscele(10, 20, 30, 40);
    getInfo(isoscele);

    EquilateralTriangle equilateral(50);
    getInfo(equilateral);

    Quadrangle quadrangleObj(10, 20, 30, 40, 50, 60, 70, 80);
    getInfo(quadrangleObj);

    Parallelogram parallelogram(20, 30, 30, 40);
    getInfo(parallelogram);

    Rhomb rhomb(30, 40, 30);
    getInfo(rhomb);

    Square square(10);
    getInfo(square);

    Rectangle rectangle(10, 20);
    getInfo(rectangle);
}

void getInfo(Figure& info) {
    std::cout << info.Info();
}