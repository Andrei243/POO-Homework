#ifndef NOD_H_INCLUDED
#define NOD_H_INCLUDED
using namespace std;
template <class T>
class nod
{
    T val;
    nod<T>* urm;
public:
    template <class X>  friend class stiva1;
    bool are_urm();
    T return_val();
    void set_val(T x);
    nod<T>();
    nod<T>(T x);
    bool operator==(nod<T> x);
    bool operator!=(nod<T> x);
    bool operator<(nod<T> x);
    nod<T> operator=(nod<T> x);
};
#include "nod.cpp"
#endif // NOD_H_INCLUDED
