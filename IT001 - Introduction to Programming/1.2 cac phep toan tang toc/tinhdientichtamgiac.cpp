cin >>a>>b>>c;
    float s,p;
     p=(a+b+c)/2.0;
    s=sqrt(p*(p-a)*(p-b)*(p-c));
    cout << round(s*100)/100;