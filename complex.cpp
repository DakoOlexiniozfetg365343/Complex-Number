#include <iostream>
#include <cmath>
using namespace std;


class Complex {
private:
    double real = 0;
    double imaginary = 0;

public:
    Complex(const double realNumber, const double imaginaryNumber): real(realNumber), imaginary(imaginaryNumber) {
    }

    Complex(const double realNumber): real(realNumber), imaginary(0) {
    }

    Complex() {
        this->real = 0;
        this->imaginary = 0;
    }

    friend ostream &operator<<(ostream &os, const Complex &complex) {
        cout << "YOUR COMPLEX NUMBER: " << endl;
        if (complex.imaginary >= 0) {
            os << "(" << complex.real << " + " << complex.imaginary << "i)";
        } else {
            os << "(" << complex.real << "" << complex.imaginary << "i)";
        }
        return os;
    }

    friend istream &operator>>(istream &is, Complex &complex) {
        cout << "-----READING A COMPLEX NUMBER-----" << endl;
        while (true) {
            cout << "Enter real part: ";
            is >> complex.real;
            if (!is.fail()) break;
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
        }

        while (true) {
            cout << "Enter imaginary part: ";
            is >> complex.imaginary;
            if (!is.fail()) break;
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
        }
        cout << "NUMBER WAS READEN SUCCESSFULLY" << endl;
        return is;
    }

    friend Complex operator+(const Complex &firstComplex, const Complex &secondComplex) {
        return Complex(firstComplex.real + secondComplex.real, firstComplex.imaginary + secondComplex.imaginary);
    }

    friend Complex operator-(const Complex &firstComplex, const Complex &secondComplex) {
        return Complex(firstComplex.real - secondComplex.real, firstComplex.imaginary - secondComplex.imaginary);
    }

    friend Complex operator*(const Complex &c1, const Complex &c2) {
        double realPart = (c1.real * c2.real) - (c1.imaginary * c2.imaginary);
        double imaginaryPart = (c1.real * c2.imaginary) + (c1.imaginary * c2.real);
        return Complex(realPart, imaginaryPart);
    }

    friend Complex operator/(const Complex &c1, const Complex &c2) {
        if (c2.real == 0 && c2.imaginary == 0) {
            cout << "Division by 0" << endl;
            return Complex(0, 0);
        }
        double denominator = (c2.real * c2.real + c2.imaginary * c2.imaginary);
        double realPart = (c1.real * c2.real + c1.imaginary * c2.imaginary) / denominator;
        double imaginaryPart = (c1.imaginary * c2.real - c1.real * c2.imaginary) / denominator;
        return Complex(realPart, imaginaryPart);
    }


    void displayDetails(const Complex &complex) {
        cout << "-----DETAILS ABOUT COMPLEX NUMBER-----" << endl;
        cout << "Real: " << complex.real << endl;
        cout << "Imaginary: " << complex.imaginary << endl;
        if (complex.imaginary >= 0) {
            cout << "Full: " << complex.real << " + " << complex.imaginary << "i" << endl;
        } else {
            cout << "Full: " << complex.real << " " << complex.imaginary << "i" << endl;
        }
    }

    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

    double magnitude() const { return sqrt((real * real) + (imaginary * imaginary)); }
};


int main() {
    Complex myComplex(3, 5);
    Complex myComplex2(3, 4);
    cout << myComplex + myComplex2 << endl;
    cout << myComplex - myComplex2 << endl;
    cout << myComplex * myComplex2 << endl;
    cout << myComplex / myComplex2 << endl;
    Complex myComplex3;
    cin >> myComplex3;
    cout << myComplex3;
}

