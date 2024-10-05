#include <iostream>
using namespace std;

class CString
{
    private:
        int n;
        char *string;
    public:
        CString(): n(0), string(NULL){}

        CString(int nn, char *s) : n(nn), string(new char[nn])
        {
            for (int i = 0; i < nn; ++i)
                string[i] = s[i];
        }

        ~CString(){}

        friend istream &operator>>(istream &in, CString &s)
        {
            cout << "Nhap do dai chuoi: ";
            in >> s.n;

            s.string = new char[s.n + 1];
            in.ignore();

            in.getline(s.string, s.n + 1);

            return in;
        }

        friend ostream &operator<<(ostream &out, const CString &s)
        {
            cout << "Chuoi: " << s.string << endl;
            return out;
        }
        CString operator+(const CString &other) const
        {
            int size = n + other.n;
            char *NewString = new char[size + 1];

            for (int i = 0; i < n; i++)
                NewString[i] = string[i];

            for (int i = 0; i < other.n; i++)
                NewString[n + i] = other.string[i];

            NewString[size + 1] = '\0';

            return CString(size, NewString);
        }

        CString &operator=(CString other)
        {
            if (this->string != other.string)
            {
                delete[] string;
                n = other.n;
                string = new char[n+1];
                for (int i = 0; i < n; i++)
                    string[i] = other.string[i];

                string[n] = '\0';
            }
            
            return (*this);
        }

        bool operator==(const CString &other) const
        {
            if (this->n != other.n)
                return 0;
            for (int i = 0; i < n; i++)
            {
                if (this->string[i]!=other.string[i])
                    return 0;
            }
            return 1;
        }
};

int main()
{
    cout << "Nhap chuoi s: " << endl;
    CString s;
    cin >> s;
    cout << s;

    cout << "Nhap chuoi other: " << endl;
    CString  other;
    cin >> other;
    cout << other;

    CString PhepCong;
    PhepCong = s + other;
    cout << "s + other: " << PhepCong;

    CString PhepGan;
    PhepGan = other;
    cout << "other gan s: " << PhepGan;

    if(s == other)
        cout << "Hai chuoi bang nhau" << endl;
    else 
        cout << "Hai chuoi khong bang nhau";
    return 0;
}
