#include<iostream>
using namespace std;

#define delimiter "\n------------------------------------\n"

/*
Создавая структуру или класс мы создаем новый тип данных. Класс и структура это тип данных.
*/
class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//					Constructors:
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(int x)
	{
		this->x = x;
		this->y = 0;
		cout << "Constructor:\t\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	//Point(const Point& other) = delete;	//Удаляем конструктор копирования, и таким образом запрещаем копирование объектов.
	Point(const Point& other)
	{
		//this - этот объект
		//other - тот объект
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//					Operators:
	void operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
	}

	Point& operator++()
	{
		this->x++;
		this->y++;
		return *this;
	}

	//					Methods:
	double distance(const Point& other)const
	{
		//other.x *= 100;
		//this->x *= 100;
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);//Square Root, квадратный корень
		return distance;
	}
	void print()const
	{
		cout << "X = " << get_x() << "\tY = " << get_y() << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	//B.set_y(B.get_y() * 200);
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
}
Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

//#define STRUCT_POINT
#define DISTANCE_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	int a;		//Объявление переменной 'a' типа 'int'
	Point A;	//Объявление переменной 'A' типа 'Point'
	//Создание объекта 'A' структуры 'Point'
	//Создание экземпляра 'A' структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT


#ifdef DISTANCE_CHECK
	Point A(2, 3);
	Point B(7, 8);
	A.print();
	B.print();

	cout << delimiter << endl;
	cout << "Расстояние от точки 'A' до точки 'B': " << A.distance(B) << endl;;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'B' до точки 'A': " << B.distance(A) << endl;;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'A' и 'B':   " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'B' и 'A':   " << distance(B, A) << endl;
	cout << delimiter << endl;
	cout << sizeof(Point) << endl;

#endif // DISTANCE_CHECK



	/*
	
	Доступ к полям объектов
	Для доступа к полям объектов может использоваться оператор точка или стрелка. 
	( .  )Точка - оператор прямого доступа. Используется для получения доступа к полям объекта по имени объекта
	( -> )Стрелка - оператор косвенного доступа. Для получения доступа к полям объекта по его адресу.
	
	*/
	 
	/*
	Инкапсуляция - сокрытие определенной части от внешнего. Реализуется модификаторами доступа и get-set методами. 
Модификаторы доступа :
private:  - закрытые поля, доступны внутри класса
public:      - открытые поля, доступны в любом месте
protected:     - защищенные поля, доступны внутри класса и дочерних классов. Этот модификатор используется только при наследовании. 
Единственное ОТЛИЧИЕ структуры и класса - структуры поля по умолчанию открыты, а у класса по умолчанию закрыты. 

     Переменные в обязательном порядке должны находится в private сессии класса. Переменная в public это нарушение инкапсуляции. 

	 get-set методы  

	 get - открывает доступ к переменным членам класса на ЧТЕНИЕ. (Позволяет получить значение закрытых переменных)
	 set - открывает доступ к закрытым переменным класса на ЗАПИСЬ. (Позволяет задать значение закрытых переменных)
	*/

/*Constructor - это метод, который создает объект.
	-По умолчанию - это конструктор, который может быть вызван без параметров;
	-Без параметров;
	-С параметрами;
	-Конструктор копирования;
	-Конструктор переноса;
~Destructor - это метод, который уничтожает объект по завершении его времени жизни;*/

/*
			Overloading rules
1. Перегрузить можно только существующие операторы,
   создать новые операторы невозможно:
	+  - перегружается;
	++ - перегружается;
	%  - перегружается;
	%% - НЕ перегружается;

2. Перегружить можно НЕ все сущкствующие операторы,
   НЕ перегружаются:
	?: - Conditional Ternary Operator;
	:: - Оператор разрешения видимости (Scope operator);
	.  - Оператор прямого доступа (Point operator);
	.* - Pointer to member selection;
	#  - Preprocessor convert to string;
	## - Preprocessor concatenate;*/
}
