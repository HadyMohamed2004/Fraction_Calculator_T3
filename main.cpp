#include <iostream>
#include <string>
#include <regex>

using namespace std;


void simplify(int c[2]) {
    int sign = (c[0] < 0) ? -1 : 1;

    c[0] *= (c[0] < 0) ? -1 : 1;


    if (c[0] == c[1]) {
        cout << "= " << 1 * sign << endl;
    } else {

        int divisor = (c[0] < c[1]) ? c[0] : c[1];
        for (int i = divisor; i > 0; i--) {
            if (c[0] % i == 0 && c[1] % i == 0) {
                c[0] /= i;
                c[1] /= i;
                break;
            }
        }
        cout << "= ";
        if (c[0] == c[1]) {
            cout << c[0] / c[1] << endl;
        } else if (c[1] == 1) {
            cout << c[0] << endl;
        } else {
            cout << c[0] * sign << "/" << c[1] << endl;
        }
    }


}


void multiply(int a[2], int b[2]) {
    int c[2];
    c[0] = a[0] * b[0];
    c[1] = a[1] * b[1];

    simplify(c);

}

void divide(int a[2], int b[2]) {
    int c[2];  // the array of result fraction
    c[1] = a[1] * b[0];
    c[0] = a[0] * b[1];
    simplify(c);
}

void sum(int a[2], int b[2]) {
    int c[2];
    c[0] = a[0] * b[1] + a[1] * b[0];
    c[1] = a[1] * b[1];
    simplify(c);
}

void sub(int a[2], int b[2]) {
    int c[2];
    c[0] = a[0] * b[1] - a[1] * b[0];
    c[1] = a[1] * b[1];
    simplify(c);
}


int main() {
    int f1[2], f2[2];
    char symbol;
    string fraction1, fraction2;
    string input_, input;
    while (true) {
        cout << "enter fractions to calculate or exit:";
        getline(cin, input_);

        for (char x: input_) {
            input += tolower(x);
        }


        if (input == "exit") {
            cout << "thanks" << endl;
            break;
        }

        int f_space = input.find(" ");
        fraction1 = input.substr(0, f_space);
        f_space = input.find(" ", f_space + 1);
        symbol = input[f_space - 1];
        fraction2 = input.substr(f_space + 1);

        if (fraction1.find('/') == string::npos)
            fraction1 += "/1";
        if (fraction2.find('/') == string::npos)
            fraction2 += "/1";

        // convert strings to fraction, each fraction in an array, where f1[0] is the nominator and f1[1] is the denominator.
        f1[0] = stoi(fraction1.substr(0, fraction1.find('/')));
        f1[1] = stoi(fraction1.substr(fraction1.find('/') + 1));
        f2[0] = stoi(fraction2.substr(0, fraction2.find('/')));
        f2[1] = stoi(fraction2.substr(fraction2.find('/') + 1));



        // using regex check for fraction patterns in each string
        if (!regex_match(fraction1, regex("[-+]?[0-9]+/[-+]?[1-9]+"))) {
            cout << "Invalid operation. Try again";
            break;
        } else if (!regex_match(fraction2, regex("[-+]?[0-9]+/[-+]?[1-9]+"))) {
            cout << "Invalid operation. Try again";
            break;
        }



        // according to calculation symbol, switch to function
        switch (symbol) {
            case '/': {
                divide(f1, f2);
                continue;
            }
            case '*': {
                multiply(f1, f2);
                continue;
            }
            case '+': {
                sum(f1, f2);
                continue;
            }
            case '-': {
                sub(f1, f2);
                continue;
            }
        }

    }


    return 0;
}
