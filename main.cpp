/*
 * File:        CS112_A2_T3_SectionNum_20230455_20230382_20230603.cpp
 *
 * Purpose:     Fraction Calculator (Summation, Subtraction, Multiplication and Division)
 *
 * Author:      Hady Mohammed Meawad Mohammed           20230455        meawad.hady@gmail.com
 *              Marwan Hussein Mohamed Mohamed          20230382        marawanlabana649@gmail.com
 *              Mahmoud Abdelaziz Mahmoud               20230603        20230603@stud.fci-cu.edu.eg
 *
 * Lab Number:  S19, S20
 * TA:          Eng. Yomna Fathy
 *
 * Emails:      20230455:   meawad.hady@gmail.com
 *              20230382:   marawanlabana649@gmail.com
 *              20230603:   20230603@stud.fci-cu.edu.eg
 *
 * ID1:         20230455 – Input Validation, Program Switch Case, Simplification Function, and Multiplication
 *
 * ID2:         20230382 – Improper Fraction Validation, Subtraction, Summation
 *
 * ID3:         20230603 – Division function, Algorithm and Pseudocode
*/


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
        } else if (c[1] == 1 || c[0] == 0) {
            cout << c[0] * sign << endl;
        } else {
            cout << c[0] * sign << "/" << c[1] << endl;
        }
    }
}


/*
 * Fractions Format Used in Calculations
 * a[0]: first numerator
 * a[1]: first denominator
 * b[0]: second numerator
 * b[1]: second denominator
*/

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
    // Declare variables for two fractions, a symbol, and input strings
    int f1[2], f2[2];
    char symbol;
    string fraction1, fraction2;

    // Display welcome message
    cout << "Welcome to the Fractions Calculator." << endl;

    // Main loop for calculator operations
    while (true) {

        // Prompt user for input fraction format
        cout << "Expressions must be written like this: a/b [-+*/] c/d" << endl;
        cout << "Enter fractions to calculate or exit:";


        cin >> fraction1;
        for (char &x:fraction1){
            x = tolower(x);
        }
        if (fraction1 == "exit") {
            cout << "Thank you for using our Fraction Calculator" << endl;
            break;
        }
        cin >> symbol >> fraction2;


        // Ensure fractions have denominators
        if (fraction1.find('/') == string::npos)
            fraction1 += "/1";
        if (fraction2.find('/') == string::npos)
            fraction2 += "/1";

        // Declaring mathematical Symbols
        string symbols = "+-/*";

        // Using regex check for fraction patterns in each string to Validate the format of input fractions using regular expressions
        if (!regex_match(fraction1, regex("[-+]?[0-9]+/[-+]?[1-9]+"))) {        // Check first fraction format
            cout << "Invalid operation. Try again" << endl;
            continue;
        } else if (!regex_match(fraction2, regex("[-+]?[0-9]+/[-+]?[1-9]+"))) { // Check Second fraction format
            cout << "Invalid operation. Try again" << endl;
            continue;
        } else if (symbols.find(symbol) ==
                   string::npos) {      // if entered symbol isn't valid, Re-prompt user to enter the expression correctly
            cout << "Invalid operand" << endl;
            continue;
        }

        // convert strings to fraction, each fraction in an array, where f1[0] is the nominator and f1[1] is the denominator.
        // Dividing the string based on "/" position
        f1[0] = stoi(fraction1.substr(0, fraction1.find('/')));
        f1[1] = stoi(fraction1.substr(fraction1.find('/') + 1));
        f2[0] = stoi(fraction2.substr(0, fraction2.find('/')));
        f2[1] = stoi(fraction2.substr(fraction2.find('/') + 1));



        // Perform the appropriate calculation based on the operation symbol using a switch statement
        switch (symbol) {
            case '/': {
                divide(f1, f2);
                continue;   // Continue to next iteration
            }
            case '*': {
                multiply(f1, f2);
                continue;   // Continue to next iteration
            }
            case '+': {
                sum(f1, f2);
                continue;   // Continue to next iteration
            }
            case '-': {
                sub(f1, f2);
                continue;   // Continue to next iteration
            }
        }

    }

    return 0;
}
