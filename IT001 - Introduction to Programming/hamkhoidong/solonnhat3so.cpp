double larger(double x, double y)
{
    if (x>=y)
     return x;
    return y;
}
double compareThree(double x, double y, double z)
{
   return larger( larger(x,y),z);
}