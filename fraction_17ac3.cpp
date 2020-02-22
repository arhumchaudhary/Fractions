//
//  fraction_17ac3.cpp
//  fraction_17ac3
//
//  Created by Arhum Chaudhary on 2019-10-16.
//  NetID: 17ac3
//
//  Copyright © 2019 Arhum Chaudhary. All rights reserved.
//

#include "pch.h"
#include <stdio.h>
#include "fraction_17ac3.h"


#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>


using namespace std;

// normalizing fraction using greatest common divisor
int Fraction::gcd(int num_1, int num_2) {
	if (num_2 == 0) {
		num_2 = 1;
	}
	{
		if ((num_1 >= num_2) && (num_1 % num_2 == 0)) {
			return num_2;
		}
		else if (num_1 < num_2) {
			return gcd(num_2, num_1);
		}
		else {
			return gcd(num_2, num_1 % num_2);
		}
	}
}

//gets numerator
int Fraction::numerator() const {
	return numer;
}

//gets denominator
int Fraction::denominator() const {
	return denom;
}


//------------- CONSTRUCTORS HOLDING FRACTION VALUES

//default constructor creates a "zero" fraction
Fraction::Fraction() : numer(0), denom(1) {}

//if only one number, goes to numerator
Fraction::Fraction(int input) : numer(input), denom(1) {
}

Fraction::Fraction(int in1, int in2) {
	if (in2 == 0) {
		throw FractionException("ERROR: Denominator is zero.");
	}

	//shifting possible negative number to numerator
	int gcd_num = gcd(abs(in1), abs(in2));
	if (in2 < 0) {
		numer = -(in1 / gcd_num);
		denom = -(in2 / gcd_num);
	}
	else {
		numer = (in1 / gcd_num);
		denom = (in2 / gcd_num);
	}
}


//------------- UNARY OPERATORS

Fraction Fraction :: operator-() {
	return Fraction(-numer, denom);
}

Fraction& Fraction :: operator++() {
	numer += denom;
	return *this;
}

Fraction Fraction :: operator++(int in) {
	Fraction f(numer, denom);
	numer += denom;
	return f;
}


//------------- BINARY OPERATORS

Fraction operator+ (const Fraction& in1, const Fraction& in2) {
	if (in1.denominator() == in2.denominator()) {
		return Fraction((in1.numerator() + in2.numerator()), in1.denominator());
	}
	else {
		return Fraction(((in1.numerator() * in2.denominator()) + (in2.numerator() * in1.denominator())), (in1.denominator() * in2.denominator()));
	}
}

Fraction operator- (const Fraction& in1, const Fraction& in2) {
	if (in1.denominator() == in2.denominator()) {
		return Fraction((in1.numerator() - in2.numerator()), in1.denominator());
	}
	else {
		return Fraction(((in1.numerator() * in2.denominator()) - (in2.numerator() * in1.denominator())), (in1.denominator() * in2.denominator()));
	}
}

Fraction operator* (const Fraction& in1, const Fraction& in2) {
	return Fraction((in1.numerator() * in2.numerator()), (in1.denominator() * in2.denominator()));
}

Fraction operator/ (const Fraction& in1, const Fraction& in2) {
	return Fraction((in1.numerator() * in2.denominator()), (in1.denominator() * in2.numerator()));
}

Fraction& Fraction :: operator+=(const Fraction& in) {
	Fraction frac = Fraction(numer, denom) + Fraction(in);
	numer = frac.numer;
	denom = frac.denom;
	return *this;
}



//------------- LOGIC OPERATORS

bool operator==(const Fraction& in1, const Fraction& in2) {
	return (in1.numerator() == in2.numerator()) && (in1.denominator() == in2.denominator());
}

bool operator!=(const Fraction& in1, const Fraction& in2) {
	return (in1.numerator() != in2.numerator()) || (in1.denominator() != in2.denominator());
}

bool operator>(const Fraction& in1, const Fraction& in2) {
	return (in1.numerator() * in2.denominator()) > (in2.numerator() * in1.denominator());
}

bool operator>=(const Fraction& in1, const Fraction& in2) {
	return (in1.numerator() * in2.denominator()) >= (in2.numerator() * in1.denominator());
}


bool operator<(const Fraction& in1, const Fraction& in2) {
	return (in1.numerator() * in2.denominator()) < (in2.numerator() * in1.denominator());
}
bool operator<=(const Fraction& in1, const Fraction& in2) {
	return (in1.numerator() * in2.denominator()) <= (in2.numerator() * in1.denominator());
}



//------------- I/O

ostream& operator<<(ostream& out, const Fraction& input) {
	out << input.numerator() << "/" << input.denominator();
	return out;
}

istream& operator>>(istream& in, Fraction& fract) {
	int num, den;
	char nxtCh;

	in >> num;

	//make sure next character is less than 10
	if (in.peek() < 10) {

		in >> nxtCh;
		if (nxtCh == '/')
			in >> den;
		else
			fract = Fraction(num, 1);
	}
	else
		fract = Fraction(num);
	return in;
}


//------------- FRACTION EXCEPTIONS

FractionException::FractionException(const string& msg) : errMsg(msg) {
}
string FractionException::what() {
	return errMsg;
}
