#include <iostream>
#include <stdexcept>
#include <string>

// Класс исключения, производный от std::out_of_range
class InvalidPointException : public std::out_of_range {
public:
    InvalidPointException(double x, double y, double z)
        : std::out_of_range("Point coordinates out of range [0, 1]"), x_(x), y_(y), z_(z) {}

    void printDetails() const {
        std::cerr << "InvalidPointException: (" << x_ << ", " << y_ << ", " << z_ << ") are out of range [0, 1]." << std::endl;
    }

private:
    double x_, y_, z_;
};

// Класс Точка в пространстве внутри единичного куба
class Point {
public:
    Point(double x, double y, double z) {
        if (x < 0.0 || x > 1.0 || y < 0.0 || y > 1.0 || z < 0.0 || z > 1.0) {
            throw InvalidPointException(x, y, z);
        }
        x_ = x;
        y_ = y;
        z_ = z;
    }

    void printCoordinates() const {
        std::cout << "Point coordinates: (" << x_ << ", " << y_ << ", " << z_ << ")" << std::endl;
    }

private:
    double x_, y_, z_;
};

int main() {
    try {
        Point p1(0.5, 0.5, 0.5); // Корректные координаты
        p1.printCoordinates();

        Point p2(1.2, 0.5, 0.5); // Некорректные координаты
        p2.printCoordinates();
    } catch (const InvalidPointException& e) {
        std::cerr << e.what() << std::endl;
        e.printDetails();
    }

    try {
        Point p3(0.7, 0.8, 0.9); // Корректные координаты
        p3.printCoordinates();
    } catch (const InvalidPointException& e) {
        std::cerr << e.what() << std::endl;
        e.printDetails();
    }

    return 0;
}
