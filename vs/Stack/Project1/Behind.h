#pragma once
#ifndef _BEGIND_H_
#define _BEHIND_H_

int isNumber(char c);

int isOperator(char c);

int isLeft(char c);

int isRight(char c);

int priority(char c);

void output(char c);

void transform(const char* exp);

#endif // !_BEGIND_H_
