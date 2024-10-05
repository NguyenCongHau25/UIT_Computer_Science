/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
###End banned keyword*/

#include <iostream>
#include <string>
using namespace std;

//###INSERT CODE HERE -

bool isRepeat(string inputString)
{
    if (inputString.size()%2!=0)
        return 0;
    else 
    {
        for (int i=0; i<(inputString.size()/2); i++)
            if (inputString[i]!=inputString[inputString.size()/2+i])
                return 0;
        return 1;
    }
}

int main ()
{
    string inputString;
    getline(cin,inputString);
    cout<< isRepeat(inputString) ;
    return 0;
}
