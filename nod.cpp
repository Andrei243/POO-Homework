#include <iostream>
template <class T>
bool nod<T>::are_urm(){
        if(urm!=NULL)return true;
        return false;
    }
template <class T>
T nod<T>::return_val(){
        return val;
    }
template <class T>
void nod<T>::set_val(T x){
        val=x;
    }
template <class T>
nod<T>::nod(){
        urm=NULL;
    }
template <class T>
nod<T>::nod(T x){
        val=x;
        urm=NULL;
    }
template <class T>
bool nod<T>::operator==(nod<T> x) {
        if(val==x.val)return true;
        return false;
    }
template <class T>
bool nod<T>::operator!=(nod<T> x){
        if(val!=x.val)return true;
        return false;
    }
template <class T>
bool nod<T>::operator<(nod<T> x){
        if(val<x.val)return true;
        return false;
    }
template <class T>
ostream& operator<<(ostream& out,nod<T> &x)
{
    out<<x.return_val();
    return out;
}
template <class T>
istream& operator>>(istream& in,nod<T> &x)
{
    T aux;
    in>>aux;
    x.set_val(aux);
    return in;
}
template <class T>
nod<T> nod<T>::operator=(nod<T> x){
val=x.return_val();
return x;
}
