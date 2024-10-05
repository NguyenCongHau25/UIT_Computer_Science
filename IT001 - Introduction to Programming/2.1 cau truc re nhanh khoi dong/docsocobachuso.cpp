#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,dv,ch,tram;
    cin >> n;
    dv = (n % 10);

    ch= ((n/10))%10;

    tram= n/100;
    if (ch==0 && dv ==0)
        switch (tram)
         {
            case 1:
               cout << "mot tram";
               break;
            case 2:
               cout << "hai tram";
               break;
            case 3:
               cout << "ba tram";
               break;
            case 4:
               cout << "bon tram";
               break;
            case 5:
               cout << "nam tram";
               break;
            case 6:
               cout << "sau tram";
               break;
            case 7:
               cout << "bay tram";
               break;
            case 8:
               cout << "tam tram";
               break;
            case 9:
                cout <<"chin tram";
                break;
         }
    else if (ch!=0)
    {
     switch (tram){
        case 1:
            cout << "mot tram " ;
            break;
        case 2:
            cout << "hai tram ";
            break;
        case 3:
            cout << "ba tram ";
            break;
        case 4:
            cout << "bon tram ";
            break;
        case 5:
            cout << "nam tram ";
            break;
        case 6:
            cout << "sau tram ";
            break;
        case 7:
            cout << "bay tram ";
            break;
        case 8:
            cout << "tam tram ";
            break;
        case 9:
            cout << "chin tram ";
            break;
    }

     switch (ch){
        case 0:
            cout << "le ";
            break;
        case 1:
            cout << "muoi " ;
            break;
        case 2:
            cout << "hai muoi ";
            break;
        case 3:
            cout << "ba muoi ";
            break;
        case 4:
            cout << "bon muoi ";
            break;
        case 5:
            cout << "nam muoi ";
        case 6:
            cout << "sau muoi ";
            break;
        case 7:
            cout << "bay muoi ";
            break;
        case 8:
            cout << "tam muoi ";
            break;
        case 9:
            cout << "chin muoi ";
            break;
    }
     switch (dv){

        case 1:
            cout << "mot ";
            break;
        case 2:
            cout << "hai ";
            break;
        case 3:
            cout << "ba ";
            break;
        case 4:
            cout << "bon ";
            break;
        case 5:
            cout << "lam ";
            break;
        case 6:
            cout << "sau ";
            break;
        case 7:
            cout << "bay ";
            break;
        case 8:
            cout << "tam ";
            break;
        case 9:
            cout << "chin ";
            break;
    }
    }
    else
    {
       switch (tram){
        case 1:
            cout << "mot tram " ;
            break;
        case 2:
            cout << "hai tram ";
            break;
        case 3:
            cout << "ba tram ";
            break;
        case 4:
            cout << "bon tram ";
            break;
        case 5:
            cout << "nam tram ";
            break;
        case 6:
            cout << "sau tram ";
            break;
        case 7:
            cout << "bay tram ";
            break;
        case 8:
            cout << "tam tram ";
            break;
        case 9:
            cout << "chin tram ";
            break;
            }
        switch (ch){
            case 0:
            cout << "le ";
            break;}
        cout << "nam";
    }
    return 0;
}