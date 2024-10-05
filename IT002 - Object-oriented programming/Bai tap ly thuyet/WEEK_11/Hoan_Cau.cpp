#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class CNhanVien
{
    protected:
        string ID;
        string Name;
        string Old;
        string PhoneNumber;
        string Email;
        long BasicSalary;

    public:
        CNhanVien()
        {
            ID = "";
            Name = "";
            Old = "";
            PhoneNumber = "";
            Email = "";
            BasicSalary = 0;
        }

        CNhanVien(string _ID, string _Name, string _Old, string _PhoneNumber, string _Email, long _BasicSalary)
        {
            ID = _ID;
            Name = _Name;
            Old = _Old;
            PhoneNumber = _PhoneNumber;
            Email = _Email;
            BasicSalary = _BasicSalary;
        }

        ~CNhanVien() {}

        void Input()
        {
            cout << "Nhap ma nhan vien: ";
            getline(cin, ID);

            cout << "Nhap ho va ten nhan vien: ";
            getline(cin, Name);

            cout << "Nhap tuoi nhan vien: ";
            getline(cin, Old);

            cout << "Nhap so dien thoai: ";
            getline(cin, PhoneNumber);

            cout << "Nhap Email: ";
            getline(cin, Email);

            cout << "Nhap muc luong co ban: ";
            cin >> BasicSalary;
        }

        void Output()
        {
            cout << left << setw(10) << ID
             << setw(20) << Name
             << setw(10) << Old
             << setw(15) << PhoneNumber
             << setw(25) << Email << "\t"
             << setw(15) << BasicSalary
             << setw(20);
        }
};

class CLapTrinhVien : public CNhanVien
{
    private:
        int Overtime;

    public:
        CLapTrinhVien()
        {
            Overtime = 0;
        }

        CLapTrinhVien(int _Overtime)
        {
            Overtime = _Overtime;
        }
        ~CLapTrinhVien() {}

        void Input()
        {
            CNhanVien::Input();
            cout << "Nhap so gio lam them: ";
            cin >> Overtime;
            cin.ignore();
        }

        void Output()
        {
            CNhanVien::Output();
            cout << left << setw(10) << Overtime<< setw(25) << Salary() << endl;
        }

        long Salary()
        {
            return BasicSalary + Overtime * 200000;
        }
};

class CKiemChungVien : public CNhanVien
{
    private:
        int Error;

    public:
        CKiemChungVien()
        {
            Error = 0;
        }

        CKiemChungVien(int _Error)
        {
            Error = _Error;
        }

        ~CKiemChungVien() {}

        void Input()
        {
            CNhanVien::Input();
            cout << "Nhap so loi phat hien: ";
            cin >> Error;
            cin.ignore();
        }

        void Output()
        {
            CNhanVien::Output();
            cout << left << setw(10) << Error << setw(25) << Salary()<< endl;
        }

        long Salary()
        {
            return BasicSalary + Error * 50000;
        }
};

class CDSLapTrinhVien
{
    private:
        int NumberLTV;
        CLapTrinhVien *LTV;

    public:
        CDSLapTrinhVien()
        {
            NumberLTV = 0;
            LTV = new CLapTrinhVien[0];
        }

        CDSLapTrinhVien(int Number)
        {
            this->NumberLTV = Number;
            LTV = new CLapTrinhVien[NumberLTV];
        }

        ~CDSLapTrinhVien()
        {
            delete[] LTV;
        }

        void Input()
        {
            cout << "Nhap so luong LTV: " << endl;
            cin >> NumberLTV;
            cin.ignore();

            LTV = new CLapTrinhVien[NumberLTV];
            for (int i = 0; i < NumberLTV; i++)
                LTV[i].Input();
        }

        void Output()
        {
            
        for (int i = 0; i < NumberLTV; i++)
            LTV[i].Output();
        cout << endl;
        }

        float LuongTB()
        {
            int Sum = 0;
            for (int i = 0; i < NumberLTV; i++)
                Sum+=LTV[i].Salary();
            return Sum/NumberLTV;
        }

        void LuongThapHonTrungBinh()
        {
            for (int i = 0; i <  NumberLTV; i++)
                if (LTV[i].Salary() < LuongTB())
                    LTV[i].Output();
        }
};

class CDSKiemChungVien
{
    private:
        int NumberKCV;
        CKiemChungVien *KCV;

    public:
        CDSKiemChungVien()
        {
            NumberKCV = 0;
            KCV = new CKiemChungVien[0];
        }

        CDSKiemChungVien(int Number)
        {
            NumberKCV = Number;
            KCV = new CKiemChungVien[NumberKCV];
        }

        ~CDSKiemChungVien()
        {
            delete[] KCV;
        }

        void Input()
        {
            cout << "Nhap so luong KCV: " << endl;
            cin >> NumberKCV;
            cin.ignore();

            KCV = new CKiemChungVien[NumberKCV];
            for (int i = 0; i < NumberKCV; i++)
                KCV[i].Input();
        }

        void Output()
        {
            
        for (int i = 0; i < NumberKCV; i++)
            KCV[i].Output();
        cout << endl;
        }

        float LuongTB()
        {
            int Sum = 0;
            for (int i = 0; i < NumberKCV; i++)
                Sum+=KCV[i].Salary();
            return Sum/NumberKCV;
        }

        void LuongThapHonTrungBinh()
        {
            for (int i = 0; i <  NumberKCV; i++)
                if (KCV[i].Salary() < LuongTB())
                    KCV[i].Output();
        }
};

int main()
{
    CDSLapTrinhVien A;
    CDSKiemChungVien B;

    cout << "Nhap danh sach lap trinh vien: " << endl;
    A.Input();
    cout << "Nhap danh sach kiem chung vien: " << endl;
    B.Input();
    cout << endl;

    cout << left << setw(10) << "ID"
         << setw(20) << "Ho va Ten"
         << setw(10) << "Tuoi"
         << setw(15) << "So DT"
         << setw(33) << "Email"
         << setw(10) << "Luong CB"
         << setw(15) << "SoLoi/GioThem"
         << setw(20) << "Luong"
         << endl;


    cout << "Danh sach lap trinh vien: " << endl;
    A.Output();
    cout << "Danh sach kiem chung vien: " << endl;
    B.Output();

    cout << "Danh sach nhan vien co muc luong thap hon trung binh: " << endl;
    cout << "Kiem chung vien: " << endl;
    A.LuongThapHonTrungBinh();
    cout << "Lap trinh vien: " << endl;
    B.LuongThapHonTrungBinh();

    return 0;
}