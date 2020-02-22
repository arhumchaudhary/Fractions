#pragma once
//  fraction_17ac3.h
//  fraction_17ac3
//
//  Created by Arhum Chaudhary on 2019-10-16.
//  NetID: 17ac3
//
//  Copyright � 2019 Arhum Chaudhary. All rights reserved.
//

#ifdef FRACTION_17AC3_EXPORTS
#define FRACTION_17AC3 __declspec(dllexport)
#else
#define FRACTION_17AC3 __declspec(dllimport)
#endif

#include <iostream>
#include <string>

using namespace std;

class FractionException {
public:
	FractionException(const string& msg); // constructor
	string what();
private:
	string errMsg;

};


class Fraction {
private:
	int numer;
	int denom;
public:
	Fraction();
	Fraction(int);
	Fraction(int, int);

	int numerator() const;
	int denominator() const;

	int gcd(int, int);


	//------------- UNARY OPERATORS
	Fraction operator-();
	Fraction& operator++(); // ++ operator (post increment)
	Fraction operator++(int); // ++ operator (pre-increment)


	//------------- BINARY OPERATORS
	friend Fraction operator+(const Fraction& in1, const Fraction& in2);
	friend Fraction operator-(const Fraction& in1, const Fraction& in2);
	friend Fraction operator*(const Fraction& in1, const Fraction& in2);
	friend Fraction operator/(const Fraction& in1, const Fraction& in2);
	Fraction& operator+=(const Fraction& e);


	//------------- LOGIC OPERATORS
	friend bool operator==(const Fraction& in1, const Fraction& in2);
	friend bool operator!=(const Fraction& in1, const Fraction& in2);
	friend bool operator>(const Fraction& in1, const Fraction& in2);
	friend bool operator>=(const Fraction& in1, const Fraction& in2);
	friend bool operator<(const Fraction& in1, const Fraction& in2);
	friend bool operator<=(const Fraction& in1, const Fraction& in2);


	//------------- I/O
	friend ostream& operator<<(ostream& out, const Fraction& input);
	friend istream& operator>>(istream& in, Fraction& fract);
};

/* fraction_17ac3_h */

