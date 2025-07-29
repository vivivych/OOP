﻿#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-------------------------------------\n"

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);

class Fraction
{
	int integer;		//Целая часть
	int numerator;		//Числитель
	int denominator;	///Значенатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//				Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgConstructor:\t" << this << endl;
	}
	Fraction(double decimal)
	{
		//decimal - десятичный
		decimal += 1e-10;
		integer = decimal;	//неявное преобразование типов из 'double' в 'int'
		decimal -= integer;
		denominator = 1e+9;	//Максимально возможное значение числителя (9 десятичных разрядов)
		//e - Exponent (оснвание системы счисления)
		numerator = decimal * denominator;
		reduce();
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//				Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	//				Increment/Decrement:
	Fraction& operator++()	//Prefix increment
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)//Postfix increment
	{
		Fraction old = *this;
		integer++;
		return old;
	}

	//				Type-cast operators:
	operator int()const
	{
		return integer + numerator / denominator;
	}
	operator double()const
	{
		return integer + (double)numerator / denominator;
	}

	//					Methods:
	Fraction& reduce()
	{

		int more, less, rest;
		if (numerator < denominator)
		{
			less = numerator;
			more = denominator;
		}
		else
		{
			more = numerator;
			less = denominator;
		}
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;	//GCD - Greatest Common Divisor
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	Fraction& to_improper()
	{
		//Переводит дробь в неправильную (Целую часть интегрирует в числитель)
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());*/
	/*Fraction result
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
	return result;*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}

//					Comparison operators:
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() ==
		right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
	//return left > right || left == right;
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
	//return left < right || left == right;
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	//os - Output Stream
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
std::istream& operator>>(std::istream& cin, Fraction& obj)
{
	
	const int SIZE = 32;
	char sz_input[SIZE] = {};	//sz_ - String Zero (Строка, заканчивающаяся нулем)
	//is >> sz_input;
	cin.getline(sz_input, SIZE);	//Ввод строки с пробелами
	//cout << sz_input << endl;
	const char delimiters[] = { '(', '/', ')', ' ', '.', ',', 0 };
	int numbers[3] = {};
	int n = 0;

	/*
	---------------------------
	Функция strtok() разбивает строку на токены;
	Разделители (delimiters) - это символы, по которым нужно делить строку;
	Токены (tokens) - это элементы, которые нужно достать из строки (это все что НЕ разделители);
	Функция strtok() возвращает указатель на найденный токен, если токен не найден,
	то функция возвращает 'nullptr';
	pch - Pointer to Character, содержит указатель на первый символ токена.
	---------------------------
	*/
	for (char* pch = strtok(sz_input, delimiters); pch && n < 3; pch = strtok(NULL, delimiters))
		numbers[n++] = atoi(pch);	
	/*
	---------------------------
	Функция atoi() ASCII to Integer, принимает строку ASCII-сиволов, и возвращает целое число,
	соответствуюзее этой строке.
	---------------------------
	*/

	//for (int i = 0; i < n; i++)cout << numbers[i] << "\t"; cout << endl;

	switch (n)
	{
	case 1:obj = Fraction(numbers[0]); break;
	case 2:obj = Fraction(numbers[0], numbers[1]); break;
	case 3:obj = Fraction(numbers[0], numbers[1], numbers[2]); break;
	}

	return cin;
}

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETICAL_OPERATORS
//#define INCREMENT_DECREMENT
//#define COMPARISON_OPERATORS
//#define ISTREAM_OPERATOR
//#define CONVERSIONS_BASICS
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSIONS_FROM_CLASS_TO_OTHER

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;			//Default constructor
	A.print();

	Fraction B = 5;		//Single-argument constructor (Конструктор с одним параметром)
	B.print();

	Fraction C(1, 2);	//Constructor
	C.print();

	Fraction D(2, 3, 4);//Constructor
	D.print();

	Fraction E = D;		//Copy constructor
	E.print();

	Fraction F;
	F = E;				//Copy assignment
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	int a, b, c;

	a = b = c = 0;

	cout << a << "\t" << b << "\t" << c << endl;

	Fraction A, B, C;
	cout << delimiter << endl;
	A = B = C = Fraction(2, 3, 4);
	//Fraction(2, 3, 4); // Явный вызов конструктора, который создает временный безымянный объект.
	//Временные безымянные объекты существуют в пределах одного выражения
	cout << delimiter << endl;
#endif // ASSIGNMENT_CHECK

#ifdef ARITHMETICAL_OPERATORS
	Fraction A(1, 2);
	Fraction B(2, 3, 4);
	Fraction C = A / B;
	A.print();
	B.print();
	C.print();
	cout << delimiter << endl;
	A /= B;
	A.print();
	B.print();
#endif // ARITHMETICAL_OPERATORS

#ifdef INCREMENT_DECREMENT
	Fraction A(1, 2);
	Fraction B = A++;
	A.print();
	B.print();
#endif // INCREMENT_DECREMENT

#ifdef COMPARISON_OPERATORS
	cout << (Fraction(1, 3) <= Fraction(5, 11)) << endl;
#endif // COMPARISON_OPERATORS

	//Fraction A(1, 2, 3);
	//Fraction B(2, 3, 4);

#ifdef ISTREAM_OPERATOR
	Fraction A;
	cout << "Введите простую дробь: "; cin >> A;
	cout << delimiter << endl;
	cout << A << endl;
	cout << delimiter << endl;
#endif // ISTREAM_OPERATOR

#ifdef CONVERSIONS_BASICS
	//(type)value;	//C-like notation
//type(value);	//Functional notation
//C4244: ... possible loss of data

	int a = 2;		//No conversions
	double b = 3;	//Implicit conversion from less to more ('int' to 'double')
	int c = b;		//Implicit conversion from more to less without data loss
	int d = 4.5;	//Implicit conversion from more to less with data loss  
#endif // CONVERSIONS_BASICS

	/*
	------------------------------
	1. From other to Class:
		1.1. SingleArgumentConstrictor;
		1.2. Assignment operator (Copy assignment);
	2. From Class to other;
	------------------------------
	*/

#ifdef CONVERSION_FROM_OTHER_TO_CLASS
	Fraction A = (Fraction)5;		//Conversion from less to more
	cout << A << endl;

	Fraction B;
	cout << delimiter << endl;
	B = Fraction(8);
	cout << delimiter << endl;
	cout << B << endl;
#endif // CONVERSION_FROM_OTHER_TO_CLASS

#ifdef CONVERSIONS_FROM_CLASS_TO_OTHER
	/*operator type()
{
	....;
	....;
	....;
}*/

	Fraction A(2, 3, 4);
	cout << A << endl;

	int a = A;
	cout << a << endl;
	double b = A;
	cout << b << endl;
#endif // CONVERSIONS_FROM_CLASS_TO_OTHER

	/*int i = 0;
	i += 1;*/

	Fraction A = 2.76;
	cout << A << endl;

}
//Возврат объектов из функции.
/*
Как функция возвращает значение.
Значение из функции также можно вернуть по значению, по указателю или по ссылке.
И при возврате значения по значению оно копируется на место вызова. Если возвращаемое значение является объектом то для него вызывается конструктор копирования.
Если функция возвращает значение по значению то на месте вызова функции остается временный безымянный объект.
Для того чтобы возвращаемое значение не копировалось на место вызова, его нужно вернуть по ссылке.

Но по ссылке никогда нельзя возвращать локальные переменные, объявленные в теле функции..

*/