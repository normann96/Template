// ClassA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "A.h"

int Sum(int a, int b)
{
	return a + b;
};

int Mult(int a, int b)
{
	return a * b;
};

void Sort(int * pAr, int nSize, bool (*pFn)(int, int))
{
	int iMinInd, nMin;
	for(int i = 0; i < nSize; ++i)
	{
		iMinInd = i;
		nMin = pAr[i];
		for(int j = i +1; j < nSize; ++j)
		{
			if(pFn(pAr[j], nMin)) 
			{	
				nMin = pAr[j];
				iMinInd = j;
			}
		}
		pAr[iMinInd] = pAr[i];
		pAr[i] = nMin;
	}
};

bool SortByAx(int a, int b)
{
	return a > b;
}

template<typename T>
void SortTemp(T * pAr, int nSize, bool (*pFn)(T, T))
{
	int iMinInd;
	T nMin;
	for(int i = 0; i < nSize; ++i)
	{
		iMinInd = i;
		nMin = pAr[i];
		for(int j = i +1; j < nSize; ++j)
		{
			if(pFn(pAr[j], nMin)) 
			{	
				nMin = pAr[j];
				iMinInd = j;
			}
		}
		pAr[iMinInd] = pAr[i];
		pAr[i] = nMin;
	}
};

template<typename T>
bool Ax(T a, T b)
{
	return a < b;
};

template<typename T>
bool Dex(T a, T b)
{
	return a > b;
};

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(0, "");

	{
// 		A a(2);
// 		cout << a << endl;
// 		cin >> a;
// 		cout << a << endl;
		

 	}
/*
	int (*pFn)(int, int);		// шаблон указателя на функцию

	pFn = Sum;
	int nRes = pFn(5,6);
	cout << nRes << endl;
	pFn = Mult;
	nRes = pFn(5,6);
	cout << nRes << endl;

	int nSize = 10;
	double *pAr = new double[nSize];
	for(int i = 0; i < nSize; i++)
		pAr[i] = (10 + rand() % 89)*0.2;
	
	for(int i = 0; i < nSize; i++)
	cout << pAr[i] << " ";
	cout << endl;
	
	SortTemp(pAr, nSize, Ax<double>);
	for(int i = 0; i < nSize; i++)
	cout << pAr[i] << " ";
	cout << endl;
	
	SortTemp(pAr, nSize, Dex<double>);
	for(int i = 0; i < nSize; i++)
		cout << pAr[i] << " ";
	cout << endl;

	delete [] pAr;
*/
	int *pArr = new int[10];
	for(int i = 0; i < 10; i++)
		pArr[i] = (10 + rand() % 89);


	Sort(pArr, 10, SortByAx);
	for(int i = 0; i < 10; i++)
		cout << pArr[i] << " ";
	cout << endl;

	delete [] pArr;

	_getch();
	return 0;
}

