#include <iostream>
#include <cmath> // for sqrt()
using namespace std;

class Complex {
private:
    float Re; // Real part
    float Im; // Imaginary part

public:
    // Default constructor
    Complex() {
        Re = 0;
        Im = 0;
    }

    // Parameterized constructor
    Complex(float r, float i) {
        Re = r;
        Im = i;
    }

    // Member function to input values
    void in() {
        cout << "Enter real part: ";
        cin >> Re;
        cout << "Enter imaginary part: ";
        cin >> Im;
    }

    // Member function to print complex number
    void out() const {
        cout << Re;
        if (Im >= 0)
            cout << " + " << Im << "i" << endl;
        else
            cout << " - " << -Im << "i" << endl;
    }

    // Function to calculate modulus
    float modulus() const {
        return sqrt(Re * Re + Im * Im);
    }

    // Friend function to add two Complex numbers
    friend Complex operator+(const Complex& c1, const Complex& c2);

    // Friend function to add float + Complex
    friend Complex operator+(float value, const Complex& c);

    // Friend function to add Complex + float
    friend Complex operator+(const Complex& c, float value);
};

// operator+ to add two complex numbers
Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex(c1.Re + c2.Re, c1.Im + c2.Im);
}

// operator+ to add float + Complex
Complex operator+(float value, const Complex& c) {
    return Complex(c.Re + value, c.Im);
}

// operator+ to add Complex + float
Complex operator+(const Complex& c, float value) {
    return Complex(c.Re + value, c.Im);
}

// Main function
int main() {
    Complex c1, c2(3, 4);

    cout << "Enter first complex number:\n";
    c1.in();

    cout << "\nSecond complex number (predefined): ";
    c2.out();

    Complex sum1 = c1 + c2;
    Complex sum2 = c1 + 5.0;
    Complex sum3 = 5.0 + c1;

    cout << "\nc1 + c2 = ";
    sum1.out();

    cout << "c1 + 5 = ";
    sum2.out();

    cout << "5 + c1 = ";
    sum3.out();

    cout << "Modulus of c1 = " << c1.modulus() << endl;

    return 0;
}
