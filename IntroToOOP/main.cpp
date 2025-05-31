#include<iostream>
using namespace std;

//�������� ��������� ��� ����� �� ������� ����� ��� ������.
//����� - ��� ��� ������	
//��������� - ��� ��� ������	
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
	int a;		//���������� ���������� a ���� int
	Point A;	//���������� ���������� A ���� Point
	//�������� �������/���������� 'A' ��������� 'Point' !!
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

	Point A;	//����� ������ ���������� ����������� �� ���������,��������� �� ������� ������ "�� ���������"
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

}