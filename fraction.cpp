#include <iostream>
#include <limits>
using namespace std;

class Fraction {
private:
  int numerator;
  int denominator;

public:
  Fraction(const int numeratorNumber, const int denominatorNumber) : numerator(numeratorNumber),
                                                                     denominator(denominatorNumber) {
  }

  Fraction() {
    numerator = 0;
    denominator = 1;
  }


  friend Fraction operator+(const Fraction &f1, const Fraction &f2) {
    return Fraction(f1.numerator * f2.denominator + f2.numerator * f1.denominator,
                    f1.denominator * f2.denominator);
  }

  friend Fraction operator-(const Fraction &f1, const Fraction &f2) {
    return Fraction(f1.numerator * f2.denominator - f2.numerator * f1.denominator, f1.denominator * f2.denominator);
  }

  friend Fraction operator*(const Fraction &f1, const Fraction &f2) {
    return Fraction(f1.numerator * f2.numerator, f1.denominator * f2.denominator);
  }

  friend Fraction operator/(const Fraction &f1, const Fraction &f2) {
    if (f2.numerator == 0) {
      cout << "Division by zero" << endl;
      return Fraction(0, 1);
    } else {
      return Fraction(f1.numerator * f2.denominator, f1.denominator * f2.numerator);
    }
  }

  friend istream &operator>>(istream &is, Fraction &fraction) {
    cout << "-----READING A FRACtion-----" << endl;
    while (true) {
      cout << "Enter a numerator part: ";
      is >> fraction.numerator;
      if (!is.fail()) break;
      is.clear();
      is.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input! Please enter a number." << endl;
    }

    while (true) {
      cout << "Enter a denumerator part: ";
      is >> fraction.denominator;
      if (!is.fail()) break;
      is.clear();
      is.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input! Please enter a number." << endl;
    }
    cout << "NUMBER WAS READEN SUCCESSFULLY" << endl;
    return is;
  }

  friend ostream &operator<<(ostream &os, const Fraction &fraction) {
    cout << "-----YOUR FRACTION-----" << endl;
    os << fraction.numerator << "/" << fraction.denominator;
    return os;
  }
};

int main() {
  Fraction myFraction;
  cin >> myFraction;
  cout << myFraction << endl;
  Fraction myFriendFraction;
  cin >> myFriendFraction;
  cout << myFraction + myFriendFraction << endl;
  cout << myFraction * myFriendFraction << endl;
  cout << myFraction / myFriendFraction << endl;
  cout << myFraction - myFriendFraction << endl;

  return 0;
}
