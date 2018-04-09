#include <iostream>
#include <stdexcept>
#include <cmath>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("/Users/camiub/Desktop/Andra_drive/C++_programe/An1_Sem2/POO/POO_Pr1/fis1.txt");
ofstream g("/Users/camiub/Desktop/Andra_drive/C++_programe/An1_Sem2/POO/POO_Pr1/fis2.txt");

class c_numar_complex
{
    double re,im;
    
public:
    
    c_numar_complex (double x,double y) // constructor
        {
            init(x,y);
        }
    c_numar_complex () // constructor
    {
        init(0,0);
    }
    void copiereComp(const c_numar_complex &x);
    
    c_numar_complex (const c_numar_complex &x); // constructor de copiere
    void init(double x,double y)
    {
        re=x;
        im=y;
    }
    ~ c_numar_complex ()
    {
        
    }
    bool is_null()
      { return (re==0 and im==0);}
    
   c_numar_complex operator+ (c_numar_complex y);
    
   c_numar_complex operator- (c_numar_complex y);
    
   c_numar_complex operator* (c_numar_complex y);
    
   c_numar_complex operator/ (c_numar_complex y);
    
   c_numar_complex operator= (c_numar_complex y);
    
    int operator==(const c_numar_complex & y);
    
    int operator!=(const c_numar_complex & y);
    
    int operator<(const c_numar_complex & y);
    
    int operator>(const c_numar_complex & y);
    
    friend ostream& operator<<(ostream& os, const c_numar_complex& c);
    friend istream& operator>>(istream& is, c_numar_complex& c);
    
    friend class c_matrice;
};
void c_numar_complex :: copiereComp(const c_numar_complex &x)
{
    re=x.re;
    im=x.im;
}
c_numar_complex :: c_numar_complex (const c_numar_complex &x)
{
    copiereComp(x);
}
ostream& operator<<(ostream& os, const c_numar_complex& c)
{
    if(c.re==0)
        os << c.im<<"i";
    else
        if(c.im==0)
            os <<c.re;
        else
            os << "(" << c.re <<"," << c.im <<"i)";
   return os;
};
istream& operator>>(istream& is, c_numar_complex& c)
{
   is >> c.re >> c.im;
   return is;
};
c_numar_complex c_numar_complex :: operator+ (c_numar_complex y)
{
    c_numar_complex t(0,0);
    
    t.re= re +y.re;
    t.im= im +y.im;
    return t;
}
c_numar_complex c_numar_complex :: operator- (c_numar_complex y)
{
    c_numar_complex t(0,0);
    
    t.re=re -y.re;
    t.im=im -y.im;
    return t;
}
c_numar_complex c_numar_complex :: operator* (c_numar_complex y)
{
    c_numar_complex t(0,0);
    t.re=(re*y.re)-(im*y.im);
    t.im=(re*y.im)+(y.re*im);
    return t;
}
c_numar_complex c_numar_complex :: operator/ (c_numar_complex y)
{
    c_numar_complex t(0,0);
    
    if(y.re==0 && y.im==0)
        throw invalid_argument( "Impartire la 0!" );
        
    if((y.re*y.re + y.im*y.im)==0)
        throw invalid_argument( "Impartire la 0!" );
    
    t.re=((re*y.re)+(im*y.im))/(y.re*y.re + y.im*y.im);
    t.im=((y.re*im)-(re*y.im))/(y.re*y.re + y.im*y.im);
    
    return t;
}
c_numar_complex c_numar_complex :: operator= (c_numar_complex y)
{
    (*this).copiereComp(y);
    return *this;
}
int c_numar_complex :: operator==(const c_numar_complex & y)
{
    return re==y.re && im==y.im;
};
int c_numar_complex :: operator!=(const c_numar_complex & y)
{
    return re!=y.re || im!=y.im;
}
int c_numar_complex :: operator<(const c_numar_complex & y)
{
    if(re<y.re)
    {
        return 1;
    }
    else
    if(re==y.re)
    {
        if(im<y.im)
           return 1;
        else
           return 0;
    }
    else
           return 0;

}
int c_numar_complex :: operator>(const c_numar_complex & y)
{
    if(re>y.re)
    {
        return 1;
    }
    else
        if(re==y.re)
        {
            if(im>y.im)
                return 1;
            else
                return 0;
        }
        else
            return 0;
    
}





class c_Matrice
{
public:
    c_numar_complex **mat;
    int lin, col;
    
    c_Matrice (int l,int c) //constructor
    {
        lin = l;
        col = c;
        int i,j;
        c_numar_complex zero (0,0);
        try
        {
            mat = new c_numar_complex *[l];
        for(i=0; i<l; i++)
            mat[i] = new c_numar_complex [c];
        }
        catch (const char *mesaj)
        {
            
            cout<<"Nu s-a putut aloca matricea"<<endl<<mesaj;
            throw invalid_argument (mesaj);
        }
        
        for(i=0; i<l; i++)
         for(j=0; j<c; j++)
           mat[i][j]=zero;
    }
    void print()
    {
        int i,j;
        for(i=0; i<lin; i++)
        {
            for(j=0; j<col; j++)
                cout<<mat[i][j]<<" ";
            cout<<endl;
        }
    }
    void read()
    {
        cout<<"Citesc matricea cu "<<lin<<" de linii si "<<col<<" de coloane "<<endl;
        int i,j;
        
        for(i=0; i<lin; i++)
        {
            for(j=0; j<col; j++)
            {
                cout<<"Dati elementul complex mat["<<i+1<<"]["<<j+1<<"] ";
                cin>>mat[i][j];
            }
        }
    }
    
    c_Matrice (const c_Matrice &N); // constructor de copiere
    
    void copiereMat (const c_Matrice &N);
    
    c_Matrice operator+(c_Matrice N);
    
    c_Matrice operator-(c_Matrice N);
    
    c_Matrice operator*(c_Matrice N);
    
    void operator= (c_Matrice N);
    
    int operator<(const c_Matrice & N);
    
    int operator>(const c_Matrice & N);
    
    int operator!=(const c_Matrice & N);
    
    void init();
    
    c_numar_complex detMat ();
    
    c_Matrice transpusa();
    
    c_Matrice A_stelat();
    
    c_Matrice inversa();
    
        friend ostream& operator<<(ostream& os, const c_Matrice& m);
        friend istream& operator>>(istream& is, c_Matrice& m);
};
ostream& operator<<(ostream& os, const c_Matrice& m)
{
    int i,j;
    for(i=0; i<m.lin; i++)
    {
        for(j=0; j<m.col; j++)
            os<<m.mat[i][j]<<" ";
        os<<endl;
    }
    return os;
}
istream& operator>>(istream& is, c_Matrice& m)
{
    //is >> m.lin >> m.col;
    int i,j;
    for(i=0; i<m.lin; i++)
    {
        for(j=0; j<m.col; j++)
            is>>m.mat[i][j];
    }
    return is;
}
c_Matrice :: c_Matrice (const c_Matrice &N)
{
    copiereMat(N);
}
void c_Matrice :: copiereMat (const c_Matrice &N)
{
    
    int i,j;
    for(i=0;i<lin;i++)
        for(j=0;j<col;j++)
            mat[i][j]=N.mat[i][j];
}
void c_Matrice :: operator= (c_Matrice N)
{
    copiereMat(N);
}
c_Matrice c_Matrice :: operator+(c_Matrice N)
{
    int i,j;
    c_Matrice T(lin,col); //matricea se si zerorizeaza
    if(lin!=N.lin)
        throw invalid_argument( "Matricele nu au acelasi nr de linii" );
    if(col!=N.col)
        throw invalid_argument( "Matricele nu au acelasi nr de coloane" );
    for(i=0; i<lin; i++)
        for(j=0; j<col; j++)
            T.mat[i][j] = mat[i][j] + N.mat[i][j];
    return T;
}
c_Matrice c_Matrice :: operator-(c_Matrice N)
{
    int i,j;
    c_Matrice T(lin,N.col); //matricea se si zerorizeaza
    if(lin!=N.lin)
        throw invalid_argument( "Matricele nu au acelasi nr de linii" );
    if(col!=N.col)
        throw invalid_argument( "Matricele nu au acelasi nr de coloane" );
    for(i=0; i<lin; i++)
        for(j=0; j<col; j++)
            T.mat[i][j] = mat[i][j] - N.mat[i][j];
    return T;
}
c_Matrice c_Matrice :: operator*(c_Matrice N)
{
    int i,j,k;
    c_numar_complex c;
    c_Matrice T(lin,N.col); //matricea se si zerorizeaza
    if(col!=N.lin)
        throw invalid_argument( "Matricele nu corespund(prima trebuie sa aiba primele atatea coloane cate linii are a doua)" );
    
    for(i=0; i<lin; i++)
        for(j=0; j<N.col; j++)
            for(k=0; k<col; k++)
                T.mat[i][j] = T.mat[i][j]+(mat[i][k] * N.mat[k][j]);
    return T;
}
int c_Matrice :: operator<(const c_Matrice & N)
{
    if(lin!=N.lin || col!=N.col)
        throw invalid_argument( "Matricele au numar de linii/coloane diferit,nu se pot compara" );
    else
    {
    int i,j;
        for(i=0;i<lin;i++)
            for(j=0;j<col;j++)
            {
                if(mat[i][j]<N.mat[i][j])
                {
                    return 1;
                }
                else
                if(mat[i][j]>N.mat[i][j])
                {
                        return 0;
                }
            }
    }
    return 0;
    
}
int c_Matrice :: operator>(const c_Matrice & N)
{
    if(lin!=N.lin || col!=N.col)
        throw invalid_argument( "Matricele au numar de linii/coloane diferit,nu se pot compara" );
    else
    {
        int i,j;
        for(i=0;i<lin;i++)
            for(j=0;j<col;j++)
            {
                if(mat[i][j]>N.mat[i][j])
                {
                    return 1;
                }
                else
                    if(mat[i][j]<N.mat[i][j])
                    {
                        return 0;
                    }
            }
    }
    return 0;
    
}

int c_Matrice :: operator!=(const c_Matrice & N)
{
    if(lin!=N.lin || col!=N.col)
        return 0;
    else
    {
        int i,j;
        for(i=0;i<lin;i++)
            for(j=0;j<col;j++)
                if(mat[i][j]!=N.mat[i][j])
                {
                    return 1;
                }
    }
    return 0;
    
}

void c_Matrice :: init()
{
    int i,j;
    for(i=0;i<lin;i++)
        for(j=0;j<col;j++)
            mat[i][j].init(0,0);
}
c_numar_complex c_Matrice :: detMat ()
{
    c_numar_complex det(0,0),c(0,0);
    int i,j,ii;
    if(lin!=col)
        throw invalid_argument( "Matricea nu este patratica, deci nu poate avea inversa" );
    if(lin==1 && col==1)
    {
        det=mat[0][0];
        return det;
        
    }
    if(lin==2 && col==2)
    {
        det=mat[0][0]*mat[1][1]-(mat[0][1]*mat[1][0]);
        return det;
    }
    for(i=0;i<lin;i++)
    {
        c=mat[i][0];
        ii=i;
        for(j=1;j<col;j++)
        {
            ii++;
            if(ii>=lin)
                ii=ii-lin;
            c=c*mat[ii][j];
        }
        
        det=det+c;
    }
    for(i=0;i<lin;i++)
    {
        c=mat[i][col-1];
        ii=i;
        for(j=col-2;j>=0;j--)
        {
            c=c*mat[ii][j];
            ii++;
            if(ii>=lin)
                ii=ii-lin;
        }
        det=det-c;
    }
    return det;
}
c_Matrice c_Matrice :: transpusa()
{
    c_Matrice T(lin,col);
    int i,j;
    
    for(i=0;i<lin;i++)
        for(j=0;j<col;j++)
            T.mat[i][j]=mat[i][j];
    return T;
}
c_Matrice c_Matrice :: A_stelat()
{
    c_Matrice T(lin-1,col-1);
    c_Matrice rez(lin,col);
    int i,j,ki,kj,pozi,pozj;
    c_numar_complex nr0(0,0),nr;
    
    for(i=0;i<lin;i++)
        for(j=0;j<col;j++)
        {
            pozi=0;
            T.init();
            for(ki=0;ki<lin;ki++)
            {
                if(ki!=i)
                {
                    pozj=0;
                    for(kj=0;kj<lin;kj++)
                        if(kj!=j)
                        {
                            T.mat[pozi][pozj]=mat[ki][kj];
                            pozj++;
                        }
                    pozi++;
                }
                
            }
            cout<<"T intermediar "<<i<<","<<j<<endl<<T<<endl;
            nr=T.detMat();
            cout<<"Det intermediar "<<endl<<nr<<endl;
            if((i+j)%2==0)
                rez.mat[i][j]=T.detMat();
            
            else
                rez.mat[i][j]=nr0-T.detMat();
            
        }
    cout<<"A stelat din functie este "<<rez<<endl;
    return rez;
}
c_Matrice c_Matrice :: inversa()
{
    c_Matrice T(lin,col);
    c_numar_complex d;
    try
    {
        d=detMat();
    }
    catch (const char *mesaj)
    {
        cout<<mesaj;
        throw invalid_argument (mesaj);
    }
    cout<<"Det este "<<d<<endl;
    /*if(d.is_null())
        throw invalid_argument( "Determinantul este 0 => nu are inversa" );*/
    c_numar_complex nr(1,0);
    try
    {
        nr=nr/d;
        
    }
    catch (const char * mesaj)
    {
        cout<<mesaj;
        throw invalid_argument( "Determinantul este 0 => nu are inversa" );
    }
    cout<<"Nr este "<<nr<<endl;
    int i,j;
    c_Matrice A_stel(lin,col);
    A_stel=A_stelat();
    cout<<"A stelat "<<endl<<A_stel;
    for(i=0;i<lin;i++)
        for(j=0;j<col;j++)
            T.mat[i][j]=nr*A_stel.mat[i][j];
    return T;
}
int main()
{
    //tastatura
    /*int linii,coloane;
    cout<<"Dati nr de linii ";
    cin>>linii;
    cout<<"Dati nr de coloane ";
    cin>>coloane;
    c_Matrice matr(linii,coloane),inv(linii,coloane);
    matr.read();
    matr.print();

     try
     {
    inv=matr.inversa();
        cout<<"Inversa matricei date este :"<<endl;
        cout<<inv;
     }
     catch (const char * mesaj)
     {
     cout<<mesaj;
     cout<<"Nu exista inversa";
     }
     */
    //fisier
    int l,c;
    f>>l>>c;
    cout<<"Linii "<<l<<" coloane "<<c<<endl;
    c_Matrice matrF(l,c),invF(l,c);
    f>>matrF;
    
    try
    {
        invF=matrF.inversa();
        g<<invF;
    }
    catch (const char * mesaj)
    {
        cout<<mesaj;
        cout<<"Nu exista inversa";
        
    }

    
    return 0;
}
/*  matrice de numere complexe reprezentate ca tablouri bidimensionale (nu neaparat ca matrici patratice):
 
 o clasa numar complex sa contina metode pentru:
 supraincarcarea operatorilor << si >>;
 suma a doua numere complexe, implementata prin supraincarcarea operatorului +;
 produsul a doua numere complexe, implementat prin supraincarcarea operatorului *;
 scaderea a doua numere complexe implementataprin supraincarcarea operatorului -;
 impartirea a doua numere complexe implementata prin supraincarcarea operatorului /;
 aruncarea unei excepti in caz ca se imparte la 0.
 
 o clasa matrice sa fie prietena a clasei numar complex si sa contina metode pentru:
 supraincarcarea operatorilor << si >>, apelandu-le pe cele din clasa numar complex;
 suma a doua matrici, implementata prin supraincarcarea operatorului + si pe baza functiei de supraincarcare a lui + din clasa numar complex;
 produsul a doua matrici, implementat prin supraincarcarea operatorului * si pe baza functiilor de supraincarcare ale lui + si * din clasa numar complex;
 determinantul unei matrici patratice, implementat tot cu ajutorul sumei si produsului de numere complexe (cele care supraincarca + si * in clasa numar complex);
 inversa unei matrici patratice cu determinantul nenul, care sa foloseasca funcile descrise anterior;
 aruncarea unei exceptii daca se apeleaza functia inversa, dar inversa matricii nu exista.
o Clasa matrice trebuie implementata folosind alocare dinamica
 */
