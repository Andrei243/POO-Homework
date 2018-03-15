
template <class X>
 void  stiva1<X>::stergere(){
     while(nu_e_goala())
        {
            pop();
        }
    }
template <class X>
void   stiva1<X>::push(nod<X> t){
        nod<X>* aux=new nod<X>;
        aux=t;
        aux.urm=&prim;
        prim=aux;
    }
template <class X>
 void  stiva1<X>::push(X t){

        nod<X>* aux=new nod<X>;
        aux->set_val(t);
        aux->urm=prim;
        prim=aux;
    }
template <class X>
void   stiva1<X>::pop(){
        if(nu_e_goala())
        {
            nod<X>* aux;
            aux=prim;
            prim=prim->urm;
            delete aux;
        }
    }
template <class X>
   stiva1<X>::stiva1(){
        prim=new nod<X>;
        prim->urm=NULL;

    }
template <class X>
   stiva1<X>::stiva1(const stiva1<X>& a){
        prim=new nod<X>;
        prim->urm=NULL;
        nod<X>* aux;
        nod<X>* aux2;
        aux=prim;
        aux2=a.prim;
        X auxh;
        while(aux2->urm!=NULL)
        {
            auxh=aux2->return_val();
            aux->set_val(auxh);
            aux->urm=new nod<X>;
            aux=aux->urm;
            aux2=aux2->urm;
        }
        aux->urm=NULL;
    }
template <class X>
stiva1<X>   stiva1<X>::operator=(const stiva1<X>& a){
        while(nu_e_goala())pop();
        stiva1 aux(a);
        aux.reverse();
        while(aux.nu_e_goala())
        {
            push(aux.top());
            aux.pop();
        }
        return *this;
    }
template <class X>
   stiva1<X>::~stiva1<X>(){

        stergere();
        delete prim;
    }
template <class X>
 X  stiva1<X>::top(){
        if(prim->urm!=NULL)
            return prim->return_val();
        else
        {
            return prim->return_val();
        }
    }
template <class X>
stiva1<X>   stiva1<X>::operator-(const stiva1<X>& x){
        stiva1<X> aux=*this;
        stiva1<X> aux2=x;
        aux.reverse();
        aux2.reverse();
        while(aux.top()==aux2.top()&&aux.nu_e_goala()&&aux2.nu_e_goala())
        {
            aux.pop();
            aux2.pop();
        }
        aux.reverse();
        return aux;
    }
template <class X>
 bool  stiva1<X>::operator==(const stiva1<X> x){
        nod<X>* aux1;
        nod<X>* aux2;
        aux1=prim;
        aux2=x.prim;
        while(aux1->urm!=NULL&&aux2->urm!=NULL&&aux1->return_val()==aux2->return_val())
        {
            aux1=aux1->urm;
            aux2=aux2->urm;
        }
        if(aux1->urm==NULL&&aux2->urm==NULL)return true;
        return false;
    }
template <class X>
 bool  stiva1<X>::operator!=(const stiva1<X> x){
        nod<X>* aux1;
        nod<X>* aux2;
        aux1=prim;
        aux2=x.prim;
        while(aux1->urm!=NULL&&aux2->urm!=NULL&&aux1==aux2)
        {
            aux1=aux1->urm;
            aux2=aux2->urm;
        }
        if(aux1->urm!=NULL&&aux2->urm!=NULL)return false;
        return true;
    }
template <class X>
 bool  stiva1<X>::nu_e_goala(){
        if(prim->urm!=NULL)return true;
        return false;
    }
template <class X>
void   stiva1<X>::reverse() {
        stiva1<X> a1;
        stiva1<X> a2;
        while(nu_e_goala())
        {
            a1.push(top());
            pop();
        }
        while(a1.nu_e_goala() )
        {
            a2.push(a1.top());
            a1.pop();
        }
        while(a2.nu_e_goala() )
        {
            push(a2.top());
            a2.pop();
        }
    }
template <class X>
bool   stiva1<X>::operator<(const stiva1<X>& x)
{
        stiva1<X> aux(x);
        stiva1<X> aux2(*this);
        aux.reverse();
        aux2.reverse();
        while(aux.nu_e_goala()&&aux2.nu_e_goala())
        {
            if(aux2.top()<aux.top())return true;
            if(aux2.top()>aux.top())return false;
        }
        if(!aux.nu_e_goala())return true;
        return false;
    }

template <class T>
ostream& operator<<(ostream& out, stiva1<T>& x)
{
    x.reverse();
    while(x.nu_e_goala())
    {
        out<<x.top()<<' ';
        x.pop();
    }
    return out;
}
ostream& operator<<(ostream& out, stiva1<char>& x)
{
    x.reverse();
    while(x.nu_e_goala())
    {
        out<<x.top();
        x.pop();
    }
    return out;
}
ostream& operator<<(ostream& out, stiva1<string>& x)
{
    x.reverse();
    while(x.nu_e_goala())
    {
        out<<x.top();
out<<'\n';
        x.pop();
    }
    return out;
}
template <class T>
istream& operator>>(istream& in, stiva1<T>& x)
{ x.stergere();
    T aux;
    int nr_ob;
    in>>nr_ob;
    for(int i=0; i<nr_ob; i++)
    {
        in>>aux;
        x.push(aux);
    }
    return in;
}
