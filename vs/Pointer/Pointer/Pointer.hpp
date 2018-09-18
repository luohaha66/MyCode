#ifndef _POINTER_HPP_
#define _POINTER_HPP_
#include "Pointer.h"
#include<iostream>

using namespace std;

template<class T>
Pointer<T>::Pointer()
{
	spointer = NULL;
}

template<typename T>
Pointer<T>::Pointer(const T* mpointer)
{
	spointer = const_cast<T*>(mpointer);
}

template<typename T>
Pointer<T>::~Pointer()
{
	delete (spointer);
}
template<typename T>
T* Pointer<T>::operator->()
{
	return spointer;
}

template<typename T>
T& Pointer<T>::operator*()
{
	return *spointer;
}
#endif // !1

//Ë³Ê±ÕëÊý×é
template<int N>
void CW<N>::CW_array()
{
	int sum = 0;
	int k = 0;
	int i = 0;
	int j = N-1;
	while (j>j/2)
	{
		for (i=k; i < j+1; i++,sum++)
		{
			a[k][i] = sum+1 ;
		}
		for (i=k; i < j; sum++, i++)
		{
			a[i][j] = sum;
		}
		for (i = j; i > k; i--, sum++)
		{
			a[j][i] = sum;
		}
		for (i = j; i > k; i--, sum++)
		{
			a[i][k] = sum;
		}
		sum = sum - 1;
		k = k + 1;
		j = j - 1;
	}

}

template<int N>
void CW<N>::printaa()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

template<int N>
void CW<N>::initarray()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; i < N; i++)
		{
			a[i][j] = 0;
		}
	}
}