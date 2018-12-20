#include<iostream>
using namespace std;
 
class A
{
public:
  A()  {}
  ~A()  { cout << "A's destructor called" << endl; }
};
 
class B
{
public:
  B()  {}
  ~B()  { cout << "B's destructor called" << endl; }
};
 
class C: public B, public A  // Note the order
{
public:
  C()  {}
  ~C()  { cout << "C's destructor called" << endl; }
};
 
int main()
{
    C c;
    return 0;
}

// OUTPUT: 
//  C's destructor called
//  A's destructor called
//  B's destructor called
