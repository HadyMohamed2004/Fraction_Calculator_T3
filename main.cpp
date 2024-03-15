#include <iostream>
#include <string>
#include <regex>

using namespace std;


void multiply(int a[2], int b[2]) {
    int c[2];
    c[0] = a[0] * b[0];
    c[1] = a[1] * b[1];
    cout << "= " << c[0] << "/" << c[1] << endl;
}

void divide(int a[2], int b[2]) {
    int c[2];  // the array of result fraction
    c[1] = a[1] * b[0];
    c[0] = a[0] * b[1];
    cout << "= " << c[0] << "/" << c[1] << endl;
}


int main() {
    int f1[2], f2[2];
    char symbol;
    string fraction1, fraction2;
    while (true) {
        cout<<"enter fractions to calculate: ";
        cin >> fraction1 >> symbol >> fraction2;

        // using regex check for fraction patterns in each string
        if (!regex_match(fraction1, regex("[-+]?[0-9]+/[-+]?[1-9]"))) {
            cout << "failed";
            break;
        } else if (!regex_match(fraction2, regex("[-+]?[0-9]+/[-+]?[1-9]"))) {
            cout << "fraction 2 failed";
            break;
        }


        // convert strings to fraction, each fraction in an array, where f1[0] is the nominator and f1[1] is the denominator.
        f1[0] = stoi(fraction1.substr(0, fraction1.find('/')));
        f1[1] = stoi(fraction1.substr(fraction1.find('/') + 1));
        f2[0] = stoi(fraction2.substr(0, fraction2.find('/')));
        f2[1] = stoi(fraction2.substr(fraction2.find('/') + 1));


        // according to calclulation symbol, switch to function
        switch (symbol) {
            case '/': {
                divide(f1, f2);
                break;
            }
            case '*': {
                multiply(f1, f2);
                break;
            }
        }
        break;
    }


    return 0;
}
