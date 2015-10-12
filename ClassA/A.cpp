#include "stdafx.h"
#include "A.h"

A::A( int a ) : mA(a)
{
	cout << "Конструктор A " << this << endl; 
}

A::A( const A &Right ):mA(Right.mA)
{
	cout << "Конструктор копирования A " << this << " from " << &Right << endl; 
}

A::~A()
{
	cout << "Деструктор A " << this << endl; 
}

const A A::operator+( const A &Right ) const
{
	A Temp(mA + Right.mA);

	cout << "A::operator+ " << this << " + " << &Right << " " << mA << '+' << Right.mA << endl;
	return Temp;
}

A A::operator-(const A &Right)
{
	A Temp(mA - Right.mA);

	cout << "A::operator- " << this << " - " << &Right << " " << mA << '-' << Right.mA << endl;
	return Temp;
}

A A::operator*( const A &Right )
{
	A Temp(mA * Right.mA);

	cout << "A::operator* " << this << " * " << &Right << " " << mA << '*' << Right.mA << endl;
	return Temp;
}

A A::operator/( const A &Right )
{
	A Temp(mA);
	if (Right.mA != 0)
		Temp.mA = this->mA/Right.mA;
	else
		cout << "Devision by zero!\n";

	cout << "A::operator/ " << this << " / " << &Right << " " << mA << '/' << Right.mA << endl;
	return Temp;
}

ostream& operator<<(ostream & out, const A &Right)
{
	out << Right.mA;
	return out;
};

istream &operator>>(istream & in,  A &Right) 
{
	in >> Right.mA;
	return in;
};