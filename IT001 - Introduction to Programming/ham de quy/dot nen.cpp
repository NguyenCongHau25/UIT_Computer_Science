
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include <iostream>

using namespace std;

//###INSERT CODE HERE -
int burnCandles(int candles, int makeNew)
{   if (candles < makeNew)
        return candles;
    return (candles - candles%makeNew) + burnCandles(candles/makeNew+(candles%makeNew),makeNew);
}

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);


    int candles, makeNew;
    cin>>candles>>makeNew;

    cout <<burnCandles(candles,makeNew)<< endl;
    return 0;
}
