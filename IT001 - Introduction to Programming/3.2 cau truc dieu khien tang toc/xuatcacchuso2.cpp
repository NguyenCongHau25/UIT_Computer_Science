if (x>=0)
    {
    x/1;
    if (x==0) cout << x;
    else 
       while (x>0)
       {
        cout << x%10<< endl;
        x/=10;
       }
    }
    else 
    { 
        x=-x;
      x/1;
    if (x==0) cout << x;
    else 
       while (x>0)
       {
        cout << x%10<< endl;
        x/=10;
       } 
       cout << "-"; 
    }