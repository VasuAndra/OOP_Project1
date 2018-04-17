#include <iostream>
#include <stdexcept>
#include <cmath>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("/Users/camiub/Desktop/Andra_drive/C++_programe/An1_Sem2/POO/POO_Pr1/fis1.txt");
ofstream g("/Users/camiub/Desktop/Andra_drive/C++_programe/An1_Sem2/POO/POO_Pr1/fis2.txt");

ofstream adun("/Users/camiub/Desktop/Andra_drive/C++_programe/An1_Sem2/POO/POO_Pr1/adun.txt");
ofstream scad("/Users/camiub/Desktop/Andra_drive/C++_programe/An1_Sem2/POO/POO_Pr1/scad.txt");
ofstream inm("/Users/camiub/Desktop/Andra_drive/C++_programe/An1_Sem2/POO/POO_Pr1/inm.txt");
ofstream determ("/Users/camiub/Desktop/Andra_drive/C++_programe/An1_Sem2/POO/POO_Pr1/determ.txt");
ofstream inv("/Users/camiub/Desktop/Andra_drive/C++_programe/An1_Sem2/POO/POO_Pr1/inv.txt");

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
            if(c.im>0)
            os << "(" << c.re <<"+" << c.im <<"i)";
                else
            os << "(" << c.re << c.im <<"i)";
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
    
    c_Matrice() {};
    void init (int l,int c)
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
    c_Matrice (int l, int c)
    {
        init(l, c);
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
    
    void copiereMat (c_Matrice N);
    
    c_Matrice operator+(c_Matrice N);
    
    c_Matrice operator-(c_Matrice N);
    
    c_Matrice operator*(c_Matrice N);
    
    c_Matrice operator= (c_Matrice N);
    
    int operator<(const c_Matrice & N);
    
    int operator>(const c_Matrice & N);
    
    int operator!=(const c_Matrice & N);
    
    void init0();
    
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
    
    int i,j;
    init(N.lin,N.col);
    for(i=0;i<lin;i++)
        for(j=0;j<col;j++)
            mat[i][j]=N.mat[i][j];
}
void c_Matrice :: copiereMat (c_Matrice N)
{
    
    int i,j;
    lin=N.lin;
    col=N.col;
    for(i=0;i<lin;i++)
        for(j=0;j<col;j++)
            mat[i][j]=N.mat[i][j];
}
c_Matrice c_Matrice :: operator= (c_Matrice N)
{
    c_Matrice T(N.lin,N.col);
    T.copiereMat(N);
    copiereMat(N);
    return T;
}
c_Matrice c_Matrice :: operator+(c_Matrice N)
{
    int i,j;
    c_Matrice T(lin,col); //matricea se si zerorizeaza
    cout<<"Adun matricile cu "<<lin<<" , "<<N.lin<<" si "<<col<<" , "<<N.col<<" coloane"<<endl;
    cout<<"Matr 1:\n";
    print();
    cout<<"Matr 2:\n";
    N.print();
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

void c_Matrice :: init0()
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
            //cout<<mat[ii][j]<<endl;
            //cout<<"C="<<c<<endl;
        }
        
        det=det+c;
    }
    for(i=0;i<lin;i++)
    {
        c=mat[i][col-1];
        ii=i;
        for(j=col-2;j>=0;j--)
        {
            ii++;
            if(ii>=lin)
                ii=ii-lin;
            c=c*mat[ii][j];
            //cout<<mat[ii][j]<<endl;
            //cout<<"C=-"<<c<<endl;
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
            T.init0();
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
    //tastatura meniu
    int alegere;
    cout<<"Doriti sa cititi datele din fisier(1) sau de la tastaura(2)? ";
    cin>>alegere;
    if(alegere==2)
    {
    char opt;
        int nr;
        do{
            cout<<"a) Adunare "<<endl;
            cout<<"b) Scadere "<<endl;
            cout<<"c) Inmultire "<<endl;
            cout<<"d) Determinant "<<endl;
            cout<<"e) Inversa "<<endl;
            cout<<"x) Terminare."<<endl;
            cin>>opt;
            switch(opt)
            {
                case 'a': {
                    cout<<"Dati numarul de matrice pe care doriti sa le adunati ";
                    cin>>nr;

             //c_Matrice **matrice_vect=new c_Matrice[nr];
            c_Matrice matrice_vect[nr];
                    c_Matrice matr_rez;
                    int i,linii,coloane;
                    for(i=0;i<nr;i++)
                    {
                        
                        cout<<"Dati nr de linii pentru matricea "<<i+1;
                        cin>>linii;
                        cout<<"Dati nr de coloane pentru matricea "<<i+1;
                        cin>>coloane;
                        
                        matrice_vect[i].init(linii,coloane);
                        
                        if(i!=0)
                        {
                            if(matrice_vect[i].lin!= matrice_vect[0].lin || matrice_vect[i].col!= matrice_vect[0].col)
                            {
                                cout<<"Matricea introdusa nu se poate aduna (diefra numarul de linii/coloane)";
                                break;
                            }
                        }
            
                        (matrice_vect[i]).read();
                        
                        if(i==0)
                        {
                            matr_rez.init(linii,coloane);
                            cout<<"Mat "<<i<<" init:\n";
                            matrice_vect[i].print();
                            matr_rez=matrice_vect[i];
                            cout<<"Mat rez init:\n";
                            matr_rez.print();
                        }
                        else
                            matr_rez=(matrice_vect[i])+matr_rez;
                        
                    }
                    cout<<"Matricea rezultata in urma adunarilor este "<<endl;
                    matr_rez.print();
                    break;
                    
                          }
                    
                case 'b': {
                    cout<<"Dati numarul de matrice pe care doriti sa le scadeti ";
                    cin>>nr;
                    
                    //c_Matrice **matrice_vect=new c_Matrice[nr];
                    c_Matrice matrice_vect[nr];
                    c_Matrice matr_rez;
                    int i,linii,coloane;
                    for(i=0;i<nr;i++)
                    {
                        cout<<"Dati nr de linii pentru matricea "<<i+1;
                        cin>>linii;
                        cout<<"Dati nr de coloane pentru matricea "<<i+1;
                        cin>>coloane;
                        
                        matrice_vect[i].init(linii,coloane);
                        
                        if(i!=0)
                        {
                            if(matrice_vect[i].lin!= matrice_vect[0].lin || matrice_vect[i].col!= matrice_vect[0].col)
                            {
                                cout<<"Matricea introdusa nu se poate scade (diefra numarul de linii/coloane)";
                                break;
                            }
                        }
                        
                        matrice_vect[i].read();
                        
                        if(i==0)
                        {
                            matr_rez.init(linii,coloane);
                            matr_rez=matrice_vect[i];
                        }
                        else
                            matr_rez=matr_rez-matrice_vect[i];
                        
                    }
                    cout<<"Matricea rezultata in urma scaderilor este "<<endl;
                    matr_rez.print();
                    break;
                    
                }
                case 'c': {
                    cout<<"Dati numarul de matrice pe care doriti sa le inmultiti ";
                    cin>>nr;
                    
                    //c_Matrice **matrice_vect=new c_Matrice[nr];
                    c_Matrice matrice_vect[nr];
                    c_Matrice matr_rez;
                    int i,linii,coloane;
                    for(i=0;i<nr;i++)
                    {
                        cout<<"Dati nr de linii pentru matricea "<<i+1;
                        cin>>linii;
                        cout<<"Dati nr de coloane pentru matricea "<<i+1;
                        cin>>coloane;
                        
                        matrice_vect[i].init(linii,coloane);
                        
                        if(i!=0)
                        {
                            if( matrice_vect[i].lin!= matrice_vect[0].col )
                            {
                                cout<<"Matricea introdusa nu se poate inmulti (diefra numarul de linii/coloane)";
                                break;
                            }
                        }
                        matrice_vect[i].read();
                        
                        if(i==0)
                        {
                            matr_rez.init(linii,coloane);
                            matr_rez=matrice_vect[i];
                        }
                        else
                            matr_rez=matr_rez*matrice_vect[i];
                    }
                    cout<<"Matricea rezultata in urma inmultirilor este "<<endl;
                    matr_rez.print();
                    break;
                    
                }
                 
                case 'd': {
                    
                    int linii,coloane;
                        cout<<"Dati nr de linii ";
                        cin>>linii;
                        cout<<"Dati nr de coloane ";
                        cin>>coloane;
                    
                    c_Matrice matrice_det(linii,coloane);
                    c_numar_complex rez_determinant(0,0);
                    
                    
                    matrice_det.read();
                    
                    rez_determinant=matrice_det.detMat();
                    cout<<"Determinantul matricei introduse este ";
                    cout<<rez_determinant<<endl;
                    break;
                    
                }
                case 'e': {
                    
                    int linii,coloane;
                    
                    cout<<"Dati nr de linii ";
                    cin>>linii;
                    cout<<"Dati nr de coloane ";
                    cin>>coloane;
                    
                    c_Matrice matrice(linii,coloane);
                    c_Matrice inversa(linii,coloane);
                    
                    matrice.read();
                    
                    inversa=matrice.inversa();
                    
                    cout<<"Matricea inversa este "<<endl;
                    inversa.print();
                    
            break;
            
        }
    
                case 'x': break;
                default : {
                    cout<<"Optiune incorecta ";
                    cout<<endl;break;
                }
        }
        }
        while (opt!='x');
    }
    else
        
    
    //fisier meniu
    {
        char opt;
    int nr;
    do{
        cin>>opt;
        switch(opt)
        {
            case 'a': {
                //cout<<"Dati numarul de matrice pe care doriti sa le adunati ";
                f>>nr;
                
                //c_Matrice **matrice_vect=new c_Matrice[nr];
                c_Matrice matrice_vect[nr];
                c_Matrice matr_rez;
                int i;
                for(i=0;i<nr;i++)
                {
                    //cout<<"Dati nr de linii pentru matricea "<<i+1;
                    f>>matrice_vect[i].lin;
                    //cout<<"Dati nr de coloane pentru matricea "<<i+1;
                    f>>matrice_vect[i].col;
                    
                    if(i!=0)
                    {
                        if(matrice_vect[i].lin!= matrice_vect[0].lin || matrice_vect[i].col!= matrice_vect[0].col)
                        {
                            adun<<"Matricea introdusa nu se poate aduna (diefra numarul de linii/coloane)";
                            break;
                        }
                    }
                    
                    f>>matrice_vect[i];
                    
                    if(i==0)
                    {
                        matr_rez=matrice_vect[i];
                    }
                    else
                        matr_rez=matr_rez+matrice_vect[i];
                    
                }
                adun<<"Matricea rezultata in urma adunarilor este "<<endl;
                adun<<matr_rez;
                break;
                
            }
                
            case 'b': {
                //cout<<"Dati numarul de matrice pe care doriti sa le scadeti ";
                f>>nr;
                
                //c_Matrice **matrice_vect=new c_Matrice[nr];
                c_Matrice matrice_vect[nr];
                c_Matrice matr_rez;
                int i;
                for(i=0;i<nr;i++)
                {
                    //cout<<"Dati nr de linii pentru matricea "<<i+1;
                    f>>matrice_vect[i].lin;
                    //cout<<"Dati nr de coloane pentru matricea "<<i+1;
                    f>>matrice_vect[i].col;
                    
                    if(i!=0)
                    {
                        if(matrice_vect[i].lin!= matrice_vect[0].lin || matrice_vect[i].col!= matrice_vect[0].col)
                        {
                            scad<<"Matricea introdusa nu se poate scade (diefra numarul de linii/coloane)";
                            break;
                        }
                    }
                    
                    f>>matrice_vect[i];
                    
                    if(i==0)
                    {
                        matr_rez=matrice_vect[i];
                    }
                    else
                        matr_rez=matr_rez+matrice_vect[i];
                    
                }
                scad<<"Matricea rezultata in urma scaderilor este "<<endl;
                scad<<matr_rez;
                break;
                
            }
            case 'c': {
                //cout<<"Dati numarul de matrice pe care doriti sa le inmultiti ";
                f>>nr;
                
                //c_Matrice **matrice_vect=new c_Matrice[nr];
                c_Matrice matrice_vect[nr];
                c_Matrice matr_rez;
                int i;
                for(i=0;i<nr;i++)
                {
                    //cout<<"Dati nr de linii pentru matricea "<<i+1;
                    f>>matrice_vect[i].lin;
                    //cout<<"Dati nr de coloane pentru matricea "<<i+1;
                    f>>matrice_vect[i].col;
                    
                    if(i!=0)
                    {
                        if( matrice_vect[i].lin!= matrice_vect[0].col )
                        {
                            inm<<"Matricea introdusa nu se poate inmulti (diefra numarul de linii/coloane)";
                            break;
                        }
                    }
                    f>>matrice_vect[i];
                    
                    if(i==0)
                    {
                        matr_rez=matrice_vect[i];
                    }
                    else
                        matr_rez=matr_rez*matrice_vect[i];
                }
                inm<<"Matricea rezultata in urma inmultirilor este "<<endl;
                inm<<matr_rez;
                break;
                
            }
                
            case 'd': {
                c_Matrice matrice_det;
                c_numar_complex rez_determinant;
                
                //cout<<"Dati nr de linii ";
                f>>matrice_det.lin;
                //cout<<"Dati nr de coloane ";
                f>>matrice_det.col;
                
                f>>matrice_det;
                
                rez_determinant=matrice_det.detMat();
                determ<<"Determinantul matricei introduse este "<<endl;
                determ<<rez_determinant;
                break;
                
            }
            case 'e': {
                c_Matrice matrice;
                c_Matrice inversa;
                
                //cout<<"Dati nr de linii ";
                f>>matrice.lin;
                //cout<<"Dati nr de coloane ";
                f>>matrice.col;
                
                f>>matrice;
                
                inversa=matrice.inversa();
                
                inv<<"Matricea inversa este "<<endl;
                inv<<inversa;
                
                break;
                
            }
                
            case 'x': break;
            default : {
                cout<<"Optiune incorecta ";
                cout<<endl;break;
            }
        }
    }
    while (opt!='x');
    }
    
    //tastatura
    
    /*
     int linii,coloane;
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
     } */
    
    
    //fisier
    
    /*int l,c;
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
     
     */
    
    
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
