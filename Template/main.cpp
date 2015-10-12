// Template.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

template<typename T, class T2>
T Mult(T a, T2 b)			// возвращается T  
{
	return a*b;
}
//**************************************//
template<class T>
void Init(T *pT, int nSize)
{
	for (int i = 0; i < nSize; i++)
	{
		pT[i] = rand()%26 + 'A';
	}
}
//**************************************//
//template<class T>
void InitDouble(double *pT, int nSize)
{
	for (int i = 0; i < nSize; i++)
	{
		pT[i] =  0.23 *(rand() % 99);
	}
}
//**************************************//
template<class T1>
void Show(T1 *pT, int nSize)
{
	for (int i = 0; i < nSize; i++)
	{
		cout << pT[i] <<' ';
	}
	cout<< endl;
}
//**************************************//
template<typename T>
void SortArr(T *pAr, int nSize)
{
	T min = 0;
	int iCurIndex = 0;
	int iIndex = 0;
	bool b1 = false;
	for(int i = 0; i < nSize-1; i++)
	{	
		min = pAr[i]; 
		iCurIndex = i+1;
		b1 = false;
		do
		{
			if(min > pAr[iCurIndex])
			{
				min = pAr[iCurIndex];
				iIndex = iCurIndex;
				b1 = true;
			}
			iCurIndex++;
		} while(iCurIndex < nSize);
		if (b1)
			swap(pAr[i], pAr[iIndex]);
	}
}
//**************************************//
template<typename T>
class ArrayGuard
{
	T *mpArr;
public:
	ArrayGuard(T *pT) : mpArr(pT) {};
	~ArrayGuard() {delete [] mpArr;};
};
//**************************************//

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

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(0, "");

	int a = 5;
	int b = 7;
	double d1 = 12.3;
	double d2 = 17.4;

//	cout << Mult(a, b) << endl;
//	cout << Mult('5', '6') << endl;
	{

	cout << "-------------INT--------------\n";
	int *pArr = new int[20];
	ArrayGuard<int> ar(pArr);
	Init(pArr, 20);
	cout << "-----------Before Sort--------\n";
	Show(pArr, 20);
	SortArr(pArr, 20);
	cout << "-----------After Sort---------\n";
	Show(pArr, 20);
	cout << "------------------------------\n";

	cout << "-------------CHAR--------------\n";
	char *pChar = new char[26];
	ArrayGuard<char> ar1(pChar);
	Init(pChar, 26);
	cout << "-----------Before Sort--------\n";
	Show(pChar, 26);
	SortArr(pChar, 26);
	cout << "-----------After Sort---------\n";
	Show(pChar, 26);
	cout << "------------------------------\n";

	cout << "-----------DOUBLE-------------\n";
	double *pDoub = new double[15];
	ArrayGuard<double> ar3(pDoub);
	InitDouble(pDoub, 15);
	cout << "-----------Before Sort--------\n";
	Show(pDoub, 15);
	SortArr(pDoub, 15);
	cout << "-----------After Sort---------\n";
	Show(pDoub, 15);
	cout << "------------------------------\n";


	
	}

	if (_CrtDumpMemoryLeaks())
		cout << "MemoryLeak!\n";
	_getch();
	return 0;
}

