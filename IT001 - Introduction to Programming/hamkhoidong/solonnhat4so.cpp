int inputNumber()
{
    int x;
   cout << "Enter a positive integer:" ;
   do {
   cin >>x;
   if (x<0)
    cout << "\nInvalid number, please try again: ";
   }
    while (x<=0);
    return x;
}
int larger(int x, int y)
{
    if (x>=y)
     return x;
    return y;
}
int compareFour(int x, int y, int z, int w)
{
    return larger(larger(x,y), larger(z,w));
    
}