#include<iostream>
using namespace std;

#define delimiter "\n------------------------------------\n"

/*
�������� ��������� ��� ����� �� ������� ����� ��� ������. ����� � ��������� ��� ��� ������.
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
	//Point(const Point& other) = delete;	//������� ����������� �����������, � ����� ������� ��������� ����������� ��������.
	Point(const Point& other)
	{
		//this - ���� ������
		//other - ��� ������
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
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);//Square Root, ���������� ������
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
	int a;		//���������� ���������� 'a' ���� 'int'
	Point A;	//���������� ���������� 'A' ���� 'Point'
	//�������� ������� 'A' ��������� 'Point'
	//�������� ���������� 'A' ��������� 'Point'
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
	cout << "���������� �� ����� 'A' �� ����� 'B': " << A.distance(B) << endl;;
	cout << delimiter << endl;
	cout << "���������� �� ����� 'B' �� ����� 'A': " << B.distance(A) << endl;;
	cout << delimiter << endl;
	cout << "���������� ����� ������� 'A' � 'B':   " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "���������� ����� ������� 'B' � 'A':   " << distance(B, A) << endl;
	cout << delimiter << endl;
	cout << sizeof(Point) << endl;

#endif // DISTANCE_CHECK



	/*
	
	������ � ����� ��������
	��� ������� � ����� �������� ����� �������������� �������� ����� ��� �������. 
	( .  )����� - �������� ������� �������. ������������ ��� ��������� ������� � ����� ������� �� ����� �������
	( -> )������� - �������� ���������� �������. ��� ��������� ������� � ����� ������� �� ��� ������.
	
	*/
	 
	/*
	������������ - �������� ������������ ����� �� ��������. ����������� �������������� ������� � get-set ��������. 
������������ ������� :
private:  - �������� ����, �������� ������ ������
public:      - �������� ����, �������� � ����� �����
protected:     - ���������� ����, �������� ������ ������ � �������� �������. ���� ����������� ������������ ������ ��� ������������. 
������������ ������� ��������� � ������ - ��������� ���� �� ��������� �������, � � ������ �� ��������� �������. 

     ���������� � ������������ ������� ������ ��������� � private ������ ������. ���������� � public ��� ��������� ������������. 

	 get-set ������  

	 get - ��������� ������ � ���������� ������ ������ �� ������. (��������� �������� �������� �������� ����������)
	 set - ��������� ������ � �������� ���������� ������ �� ������. (��������� ������ �������� �������� ����������)
	*/

/*Constructor - ��� �����, ������� ������� ������.
	-�� ��������� - ��� �����������, ������� ����� ���� ������ ��� ����������;
	-��� ����������;
	-� �����������;
	-����������� �����������;
	-����������� ��������;
~Destructor - ��� �����, ������� ���������� ������ �� ���������� ��� ������� �����;*/

/*
			Overloading rules
1. ����������� ����� ������ ������������ ���������,
   ������� ����� ��������� ����������:
	+  - �������������;
	++ - �������������;
	%  - �������������;
	%% - �� �������������;

2. ����������� ����� �� ��� ������������ ���������,
   �� �������������:
	?: - Conditional Ternary Operator;
	:: - �������� ���������� ��������� (Scope operator);
	.  - �������� ������� ������� (Point operator);
	.* - Pointer to member selection;
	#  - Preprocessor convert to string;
	## - Preprocessor concatenate;*/
}
