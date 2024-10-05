#include <iostream>
#include <vector>

using namespace std;
struct DIEM
{
    int x;
    int y;
};

void NhapMotDiem(DIEM A)
{
    cin >> A.x >> A.y;
}

void XuatMotDiem(DIEM A)
{
    cout << A.x << " " << A.y;
}

void NhapDanhSach(vector<DIEM> &v)
{
    DIEM tmp;
    
    cout << "Nhap Danh Sach Diem" << endl;
    
    while (1)
    {
        NhapMotDiem(tmp);
        if (tmp.x == 0 && tmp.y == 0)
            break;
        else
            v.push_back(tmp);
    }
}

void XuatDanhSach(vector<DIEM> v)
{
    for(int i = 0; i < v.size(); i++)
        XuatMotDiem(v[i]);
    cout << endl;
}

int main()
{
    vector<DIEM> A;
    
    NhapDanhSach(A);

    XuatDanhSach(A);

    return 0;
}