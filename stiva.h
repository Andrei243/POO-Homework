#ifndef STIVA_H_INCLUDED
#define STIVA_H_INCLUDED
#include "nod.h"
using namespace std;
template <class X>
class stiva1
{
    nod<X>* prim;
private:
    void stergere();
public:
    void push(nod<X> t);
    void push(X t);
    void pop();
    stiva1<X>();
    stiva1<X>(const stiva1<X>& a);
    stiva1<X> operator=(const stiva1<X>& a);
    ~stiva1<X>();
    X top();
    stiva1<X> operator-(const stiva1<X>& x);
    bool operator==(const stiva1<X> x);
    bool operator!=(const stiva1<X> x);
    bool nu_e_goala();
    void reverse();
    bool operator<(const stiva1<X>& x);
 template <class T>    friend istream& operator>>(istream& in, stiva1<T>& x);


};
#include "stiva.cpp"
#endif // STIVA_H_INCLUDED
