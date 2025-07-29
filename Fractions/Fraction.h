#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
using std::cout;

#define delimiter "\n------------------------------------------------\n"

// CLASS DECLARATION

class Fraction;
Fraction operator* (Fraction left, Fraction right);
Fraction operator/ (const Fraction left, const Fraction right);
Fraction operator+ (Fraction left, Fraction right);
Fraction operator- (const Fraction left, const Fraction right);
bool operator== (Fraction left, Fraction right);
bool operator!= (const Fraction left, const Fraction right);
bool operator> (Fraction left, Fraction right);
bool operator< (Fraction left, Fraction right);
std::ostream& operator<< (std::ostream& os, Fraction& obj);
std::istream& operator>> (std::istream& is, Fraction& obj);


class Fraction
{
	int integer;
	int numerator;
	int denominator;

public:
	int get_integer() const;
	int get_numerator() const;
	int get_denominator() const;

	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	//				contructions
	Fraction();
	Fraction(int integer, int numerator, int denominator);
	Fraction(int numerator, int denominator);
	Fraction(int integer);
	Fraction(double decimal);
	Fraction(const Fraction& other);
	~Fraction();

	//				Operators
	Fraction& operator= (const Fraction& other);
	Fraction& operator*= (const Fraction other);
	Fraction& operator/= (const Fraction other);
	Fraction& operator+= (const Fraction other);
	Fraction& operator-= (const Fraction other);

	//			Icrement/Decrement
	Fraction& operator++();
	Fraction operator++ (int);
	Fraction& operator--();
	Fraction operator-- (int);

	//Type-cast operastors
	operator int() const;
	operator double() const;

	//				Methods
	Fraction& to_improper(); 
	Fraction& Reduce(); 
	Fraction& to_proper(); 
	Fraction invert()const;
	void print()const;
};