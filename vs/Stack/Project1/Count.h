#pragma once
#ifndef _COUNT_H_
#define _COUNT_H_

int isnumber(char c);

int isoperator(char c);

int value(char c);

int express(int left, int right, char op);

int compute(const char* exp);
#endif // !_COUNT_H_
