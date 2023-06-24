#pragma once

#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>


using namespace std;

namespace ariel
{

class Fraction {                                     // The class

private:                                             //private Access specifier
    int numerator;                                   // Attribute
    int denominator;                                 // Attribute

public:                                              // Access specifier

    Fraction(int numerator,int denominator);     // Constructor with parameters

    Fraction(float num);

    Fraction();                                      // Constructor without parameters

    /* 
        Briefly explain about friend and const :
        
        -> friend used to get access of private variables in "friend mode" functions 
        -> const int* a | int const* a : cannot modify a content 
        -> int* const a : cannot reassign the actual pointer itself
        -> const int* const a : cannot reassign the actual pointer itself and cannot modify the content
        -> const after a method name like that : int getX() const -> means that this method is not going to modify any of the class variables
    */

    /* + */
    friend Fraction operator+(const Fraction& a, const Fraction& b);
    friend Fraction operator+(const Fraction& a, float b);
    friend Fraction operator+(float a, const Fraction& b);

    /* - */
    friend Fraction operator-(const Fraction& a, const Fraction& b);
    friend Fraction operator-(const Fraction& a, float b);
    friend Fraction operator-(float a, const Fraction& b);

    /* * */
    friend Fraction operator*(const Fraction& a, const Fraction& b);
    friend Fraction operator*(const Fraction& a, float b);
    friend Fraction operator*(float a, const Fraction& b);

    /* / */
    friend Fraction operator/(const Fraction& a, const Fraction& b);
    friend Fraction operator/(const Fraction& a, float b);
    friend Fraction operator/(float a, const Fraction& b);
    
    /* > */
    friend bool operator >(const Fraction& a, const Fraction& b);
    friend bool operator >(const Fraction& a, float b);
    friend bool operator >(float a, const Fraction& b);

    /* >= */
    friend bool operator >=(const Fraction& a, const Fraction& b);
    friend bool operator >=(const Fraction& a, float b);
    friend bool operator >=(float a, const Fraction& b);

    /* < */
    friend bool operator <(const Fraction& a, const Fraction& b);
    friend bool operator <(const Fraction& a, float b);
    friend bool operator <(float a, const Fraction& b);

    /* <= */
    friend bool operator <=(const Fraction& a, const Fraction& b);
    friend bool operator <=(const Fraction& a, float b);
    friend bool operator <=(float a, const Fraction& b);
    
    /* == */
    friend bool operator ==(const Fraction& a, const Fraction& b);
    friend bool operator ==(const Fraction& a, float b);
    friend bool operator ==(float a, const Fraction& b);

    // overloaded prefix ++ operator
    Fraction& operator++();

    // overloaded postfix ++ operator
    Fraction operator++(int);

    // overloaded prefix -- operator
    Fraction& operator--();

    // overloaded postfix -- operator
    Fraction operator--(int);

    friend ostream& operator<<(ostream& output, const Fraction& fracture);
    friend istream& operator>>(istream& is, Fraction& fracture);

    int getNumerator() const;       // method that return the numerator of the fraction, method is not going to modify any of the class variables used const
    int getDenominator() const;       // method that return the denominator of the fraction, method is not going to modify any of the class variables used const

};

}
