#include "stdio.h"
class Base{
 public:
     int Bar(char x){
         return (int)(x);
     }
     virtual int Bar(int x){
         return (2 * x);
     }
 };
 class Derived : public Base{
 public:
     int Bar(char x){
         return (int)(-x);
     }
     int Bar(int x){
         return (x / 2);
     }
 };
 int main(void)
 {
     Derived Obj;
     Base *pObj = &Obj;
     printf("%d,", pObj->Bar((char)(100)));
     printf("%d,", pObj->Bar(100));
 }