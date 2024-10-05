#include <iostream>
#include <math.h>
using namespace std;
typedef struct Diem
{        
    float x, y;
}D;
typedef struct TamGiac
{

        Diem A, B, C;
        float S, P;
        float gocA, gocB, gocC ;
        float a, b, c;
        float R, r;
        float ha, hb, hc;
}TG;
void inputonepoint(D M)
{
    cin >> M.x >> M.y;
}
void input(TG &X)
{
    inputonepoint(X.A);
    inputonepoint(X.B);
    inputonepoint(X.C);
}
float khoangcach(D a, D b)
{
    return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}
int check(TG X)
{
    float m = khoangcach(X.A,X.B);
    float n = khoangcach(X.B,X.C);
    float p = khoangcach(X.A,X.C);
    if (m + n < p || m+p,n || n+p<m)
        return 0;
    return 1;

}
void Tamgiac(TG X)
{
    X.a = khoangcach(X.A,X.B);
    X.b = khoangcach(X.B,X.C);
    X.c = khoangcach(X.A,X.C);

    X.P= (X.a+X.b+X.c)/2.0+0;

    X.S= sqrt(X.P*((X.P)-X.a)*(X.P-X.b)*(X.P-X.c))+0;

    X.R= (X.a*X.b*X.c)/(4*X.S)+0;

    X.r= X.S/X.P;

    X.ha=2*X.P/X.a;
    X.hb=2*X.P/X.b;
    X.hc=2*X.P/X.c;

    X.gocA=cos((X.b/X.c)*M_PI/180.0);
    X.gocB=cos((X.a/X.c)*M_PI/180.0);
    X.gocC=cos((X.a/X.b)*M_PI/180.0);

}

void xuly(char x, TG T)
{
    switch (x)
    {
        case 'P':
            cout << T.P; break;
        case 'S':
            cout << T.S; break;
        case 'a':
            cout << T.a; break;
        case 'b':
            cout << T.b; break;
        case 'c':
            cout << T.c; break;
        case 'gocA':
            cout << T.gocA; break;
        case 'gocB':
            cout << T.gocB; break;
        case 'gocC':
            cout << T.gocC; break;
        case 'R':
            cout << T.R;break;
        case 'r':
            cout << T.r;break;
        case 'ha':
            cout << T.ha;break;
        case 'hb':
            cout << T.hb;break;
        case 'hc':
            cout << T.hc;break;
    }
    
}


void output(TG X)
{
    cout << X.A.x << X.A.y;
    cout << X.B.x << X.B.y;
    cout << X.C.x << X.C.y;
}

int main()
{
    TG A;
    char x;
    input(A);
    cin >> x;
    output(A);
    if (check(A)==0)
        cout << "Day khong phai la tam giac";
    else
        xuly(x,A);
    return 0;
}