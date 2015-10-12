#ifndef A_h__
#define A_h__

class A
{
	int mA;
public:
	A(int a);
	A(const A &Right);
	~A();

	const A operator+(const A &Right) const;		// перегрузка оператора +
	A operator-(const A &Right);
	A operator*(const A &Right);
	A operator/(const A &Right);

	friend ostream &operator<<(ostream & out, const A &Right);
	friend istream &operator>>(istream & in, A &Right);
};
#endif // A_h__
