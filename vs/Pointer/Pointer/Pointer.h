#pragma once
#ifndef _POINTER_H_
#define _POINTER_H_


template<typename T>
class Pointer
{
public:
	Pointer();
	Pointer(const T* mpointer);
	~Pointer();
	T* operator->();
	T& operator*();
protected:
	T* spointer;
};

template <int N>
class CW
{
private:
	int a[N][N];
public:
	void CW_array();

	void printaa();

	void initarray();
};



#endif // !_POINTER_H_
