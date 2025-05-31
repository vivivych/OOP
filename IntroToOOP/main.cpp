#include<iostream>
using namespace std;

//Создавая структуру или класс мы создаем новый тип данных.
//КЛАСС - это тип данных	
//СТРУКТУРА - это тип данных	
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
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//				Methods:
	void print()const
	{
		cout << "X = " << get_x() << "\tY = " << get_y() << endl;
	}
};

//#define STRUCT_POINT
//#define OBJECT_LIFETIME

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	int a;		//Объявление переменной a типа int
	Point A;	//Объявление переменной A типа Point
	//Создание объекта/экземпляра 'A' структуры 'Point' !!
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

	Point A;	//Здесь неявно вызывается конструктор по умолчанию,поскольку мы создаем объект "По умолчанию"
//A.set_x(2);
//A.set_y(3);
//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B = 5;
	//cout << B.get_x() << "\t" << B.get_y() << endl;
	B.print();

	Point C(7, 8);
	C.print();


#ifdef OBJECT_LIFETIME
	for (int i = 0; i < 10; i++)
	{
		cout << i << "\t";
	}
	
	cout << endl;
#endif // OBJECT_LIFETIME

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

}