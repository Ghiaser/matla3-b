#include "Fraction.hpp"

namespace ariel
{

    int findGCD(int num1, int num2)
    {
        /* in the last findGcd code there were sometimes return wrong value */
        return __gcd(num1, num2);
    }

    Fraction floatToFraction(float f) {
        
        int precision = 1000;               // adjust the precision as 3 numbers after decimal point
        int num = round(f * precision);     // multiplying the float by a precision value
        int den = precision;
        int gcdVal = findGCD(num, den);     // reduces the resulting numerator and denominator to their lowest terms using gcd
        num /= gcdVal;
        den /= gcdVal;

        return Fraction(num,den);
    }


    
    Fraction::Fraction(int n,int d){
        int numNegative = 0,denNegative = 0;
        if(d == 0){
            throw invalid_argument("Denominator cannot be zero!");
        }
        if(n < 0){
            numNegative = 1;
        }
        if(d < 0){
            denNegative = 1;
        }
        int gcd = findGCD(abs(n),abs(d));
        if(numNegative == 1 && denNegative == 1){
            this->numerator = abs(n/gcd);
            this->denominator = abs(d/gcd);
        }
        if(numNegative == 1 && denNegative == 0 || numNegative == 0 && denNegative == 1 ){
            this->numerator = (-1) * abs(n/gcd);
            this->denominator = abs(d/gcd);
        }
        if(numNegative == 0 && denNegative == 0){
            this->numerator = abs(n/gcd);
            this->denominator = abs(d/gcd);
        }
    }

    Fraction::Fraction(float number){
        int num = static_cast<int>(number * 1000);
        int den = 1000;
        int gcd = __gcd(num, den);
        num /= gcd;
        den /= gcd;
        numerator = num;
        denominator = den;
    }

    Fraction::Fraction(){}

    /* + */
    Fraction operator+(const Fraction& a, const Fraction& b){

        long int den = a.denominator * b.denominator;
        long int num = ( ((den/a.denominator)*a.numerator) + ((den/b.denominator)*b.numerator) );
        if (num > numeric_limits<int>::max() || num < numeric_limits<int>::min() || den > numeric_limits<int>::max() || den < numeric_limits<int>::min())
        {
            throw overflow_error("Overflow error!");
        }
        int gcdNumDen = findGCD(num, den);
        num /= gcdNumDen;
        den /= gcdNumDen;
        return Fraction(num , den);
    }
    Fraction operator+(const Fraction& a, float b){
    /* convert the flaot number into a fraction and use the above funtion to make the add */
        return (a+(floatToFraction(b)));
    }

    Fraction operator+(float a, const Fraction& b){
    /* same as above */
        return ((floatToFraction(a))+ b);
    }

    /* - */
    Fraction operator-(const Fraction& a, const Fraction& b){
        long int den = a.denominator * b.denominator;
        long int num = ( ((den/a.denominator)*a.numerator) - ((den/b.denominator)*b.numerator) );
        if (num > numeric_limits<int>::max() || num < numeric_limits<int>::min() || den > numeric_limits<int>::max() || den < numeric_limits<int>::min())
        {
            throw overflow_error("Overflow error!");
        }
        int gcdNumDen = findGCD(abs(num), abs(den));
        num /= gcdNumDen;
        den /= gcdNumDen;
        return Fraction(num , den);
    }
    Fraction operator-(const Fraction& a, float b){
        /* convert the flaot number into a fraction and use the above funtion to make the sub */
        return (a - (floatToFraction(b)));
    }
    Fraction operator-(float a, const Fraction& b){
        /* same as above */
        return ((floatToFraction(a)) - b);
    }

    /* * */
    Fraction operator*(const Fraction& a, const Fraction& b){
        if (((long long)a.numerator * b.numerator > numeric_limits<int>::max())
                || ((long long)a.denominator * b.denominator > numeric_limits<int>::max())) {
            throw overflow_error("Overflow error!");
        }
        long long int den = a.denominator * b.denominator;
        long long int num = a.numerator * b.numerator;
        int gcdNumDen = findGCD(abs(num), abs(den));
        num /= gcdNumDen;
        den /= gcdNumDen;

        return Fraction(num , den);
    }
    Fraction operator*(const Fraction& a, float b){
        /* convert the flaot number into a fraction and use the above funtion to make the mul */
        return (a * (floatToFraction(b)));
    }
    Fraction operator*(float a, const Fraction& b){
        /* same as above */
        return ((floatToFraction(a)) * b);
    }

    /* / */
    Fraction operator/(const Fraction& a, const Fraction& b){
        if (b.numerator == 0)
        {
            throw runtime_error("Error, Cannot divide by zero");
        }
        Fraction c(b.denominator,b.numerator);
        if (((long long)a.numerator * c.numerator > numeric_limits<int>::max())
                || ((long long)a.denominator * c.denominator > numeric_limits<int>::max())) {
            throw overflow_error("Overflow error!");
        }
        long long int den = a.denominator * b.numerator;
        long long int num = a.numerator * b.denominator;
        int gcdNumDen = findGCD(num, den);
        num /= gcdNumDen;
        den /= gcdNumDen;
        if (num > numeric_limits<int>::max() || num < numeric_limits<int>::min() || den > numeric_limits<int>::max() || den < numeric_limits<int>::min())
        {
            throw overflow_error("Overflow error");
        }
        return Fraction(num , den);
    }
    Fraction operator/(const Fraction& a, float b){
        /* convert the flaot number into a fraction and use the above funtion to make the div */
        return (a / (floatToFraction(b)));
    }
    Fraction operator/(float a, const Fraction& b){
        /* same as above */
        return ((floatToFraction(a)) / b);
    }
    
    bool operator >(const Fraction& a, const Fraction& b){ return ((static_cast<float>(a.numerator)/static_cast<float>(a.denominator)) > ((static_cast<float>(b.numerator)/static_cast<float>(b.denominator))));}
    bool operator >(const Fraction& a, float b){return ((static_cast<float>(a.numerator)/static_cast<float>(a.denominator)) > b);}
    bool operator >(float a, const Fraction& b){return (a > (static_cast<float>(b.numerator)/static_cast<float>(b.denominator)));}

    /* >= */
    bool operator >=(const Fraction& a, const Fraction& b){ return ((static_cast<float>(a.numerator)/static_cast<float>(a.denominator)) >= ((static_cast<float>(b.numerator)/static_cast<float>(b.denominator))));}
    bool operator >=(const Fraction& a, float b){return ((static_cast<float>(a.numerator)/static_cast<float>(a.denominator)) >= b);}
    bool operator >=(float a, const Fraction& b){return (a >= (static_cast<float>(b.numerator)/static_cast<float>(b.denominator)));}

    /* < */
    bool operator <(const Fraction& a, const Fraction& b){ return ((static_cast<float>(a.numerator)/static_cast<float>(a.denominator)) < ((static_cast<float>(b.numerator)/static_cast<float>(b.denominator))));}
    bool operator <(const Fraction& a, float b){return ((static_cast<float>(a.numerator)/static_cast<float>(a.denominator)) < b);}
    bool operator <(float a, const Fraction& b){return (a < (static_cast<float>(b.numerator)/static_cast<float>(b.denominator)));}

    /* <= */
    bool operator <=(const Fraction& a, const Fraction& b){ return ((static_cast<float>(a.numerator)/static_cast<float>(a.denominator)) <= ((static_cast<float>(b.numerator)/static_cast<float>(b.denominator))));}
    bool operator <=(const Fraction& a, float b){return ((static_cast<float>(a.numerator)/static_cast<float>(a.denominator)) <= b);}
    bool operator <=(float a, const Fraction& b){return (a <= (static_cast<float>(b.numerator)/static_cast<float>(b.denominator)));}

    /* == */

    bool operator ==(const Fraction& a, const Fraction& b){
        return ( (static_cast<float>(a.numerator)/static_cast<float>(a.denominator)) == (static_cast<float>(b.numerator)/static_cast<float>(b.denominator)));
    }
    bool operator ==(const Fraction& a, float b){return ((static_cast<float>(a.numerator)/static_cast<float>(a.denominator)) == b);}
    bool operator ==(float a, const Fraction& b){return (a == (static_cast<float>(b.numerator)/static_cast<float>(b.denominator)));}

    // overloaded prefix ++ operator
    Fraction& Fraction::operator++(){
        this->numerator+=this->denominator;
        return *this;
    }

    // overloaded postfix ++ operator
    Fraction Fraction::operator++(int){
        Fraction temp = *this;
        ++*this;
        return temp;
    }

    // overloaded prefix -- operator
    Fraction& Fraction::operator--(){
        this->numerator-=this->denominator;
        return *this;
    }

    // overloaded postfix -- operator
    Fraction Fraction::operator--(int){
        Fraction temp = *this;
        --*this;
        return temp;
    }

    ostream& operator<<(ostream& output, const Fraction& fracture){
        return output << fracture.numerator << "/" << fracture.denominator;
    }
    istream& operator>>(istream& is, Fraction& fracture){
        int num = 0 , den = 0;
        //save numerator and denominator values
        string input;
        is >> num >> den;
        cout << num << " , " << den;
        if(den == 0){
            throw runtime_error("Invalid input!");
        }
        if( (num < 0 && den > 0) || (num >= 0 && den < 0) ){
            fracture.numerator = (-1) * abs(num);
            fracture.denominator = abs(den);
        }else{
            fracture.numerator = num;
            fracture.denominator = den;
        }


        return is;
    }

    int Fraction::getNumerator() const {return numerator;}
    int Fraction::getDenominator() const{return denominator;}

}