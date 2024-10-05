#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main()
{
    char a[100002];
    cin.getline(a, 100001);

    stack<char> s;

    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] == '{' || a[i] == '[' || a[i] == '(')
            s.push(a[i]);
        else if (a[i] == '}' ||a[i] == ']' || a[i] == ')')
        {
            if (s.empty())
            {
                cout << "0";
                return 0;
            }

            char top = s.top();
            s.pop();

            if ((a[i] == '}' && top != '{') || (a[i] == ']' && top != '[') || (a[i] == ')' && top != '('))
            {
                cout << "0";
                return 0;
            }
        }
    }
    if (s.empty())
        cout << "1";
    else 
        cout << "0";

    return 0;
}
