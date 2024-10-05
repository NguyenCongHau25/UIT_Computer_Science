#include <iostream>

using namespace std;

typedef struct HOCSINH
{
    char Name[35];
    float DiemToan;
    float DiemVan;
    float Aver;
}HS;

void NhapMotHocSinh(HOCSINH &a)
{
    cin.ignore();
    cin.getline(a.Name, 34);
    cin >> a.DiemToan >> a.DiemVan; 
    a.Aver = (a.DiemToan + a.DiemVan)/2;
}

void NhapNhieuHocSinh(HS A[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        NhapMotHocSinh(A[i]);
}

float TinhDTBChung(HS A[], int n)
{
    float s = 0;
    for (int i = 0; i < n; i++)
        s+=A[i].Aver;
    return s*1.00/n;
}

void TinhDTBCaoNhat(HS A[], int n)
{
    HS max = A[0];
    for (int i = 1; i < n; i++)
        if ( A[1].Aver > max.Aver )
            max = A[i];
    cout << "Cac hoc sinh co DTB cao nhat lop: " << endl;
    for (int i = 0; i < n; i++)
        if (A[i].Aver == max.Aver)
            cout << A[i].Name << " " << A[i].DiemToan << " " <<  A[i].DiemVan << " " << A[i].Aver << endl;
}

void TinhDTBThapHon(HS A[], int n)
{
    float DTB = TinhDTBChung(A,n);
    cout << "Cac hoc sinh co DTB thap hon DTB lop: " << endl;

    for (int i = 0; i < n; i++)
        if (A[i].Aver < DTB)
            cout << A[i].Name << " " << A[i].DiemToan << " " << A[i].DiemVan << " " << A[i].Aver << endl;
}
int main()
{
    HS A[100];
    int n;

    NhapNhieuHocSinh(A,n);

    TinhDTBCaoNhat(A,n);
    TinhDTBThapHon(A,n);

    return 0;
}