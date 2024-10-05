#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

class VatPham;
class XeTang;
class Boss;


class VatPham
{
    protected:

        string Ma;
        string Ten;

    public:

        VatPham(){}
        virtual ~VatPham(){}
        virtual void Nhap()
        {
            cout << "Nhap ma: ";
            getline(cin, Ma);
            cout << "Nhap ten: ";
            getline(cin, Ten);
        }

        virtual int GetSoLanSuDung()
        {
            return 0;
        }

        virtual int GetLuongSinhMenh()
        {
            return 0;
        }

        virtual bool isDanDon()
        {
            return 0;
        }

        virtual bool isDanKep()
        {
            return 0;
        }

        virtual int GetSatThuong()
        {
            return 0;
        }

        virtual void SetSoLanSuDung() {}

        virtual void AmThanh(){}
        friend class XeTang;
};

class DanDuoc: public VatPham
{
    protected:

        int SoLanSuDung;
        int LuongSatThuong;

    public:

        DanDuoc(){}
        ~DanDuoc(){}
        
        void Nhap()
        {
            VatPham::Nhap();
            cout << "Nhap so lan su dung: ";
            cin >> SoLanSuDung;
            cout << "Nhap luong sat thuong: ";
            cin >> LuongSatThuong;
        }

        int GetSatThuong()
        {
            return LuongSatThuong;
        }

        int GetSoLanSuDung()
        {
            return SoLanSuDung;
        }

};

class DanDon: public DanDuoc
{
    public:

        DanDon(){}
        ~DanDon(){}

        void AmThanh()
        {
            cout << "BUM" << endl;
        }
    
    bool isDanDon()
    {
        return 1;
    }

};

class DanKep: public DanDuoc
{
    public:

        DanKep(){}
        ~DanKep(){}

        void AmThanh()
        {
            cout << "BUM BUM";
        }

        bool isDanKep()
        {
            return 1;
        }
};

class SinhMenh: public VatPham
{
    private:

        int LuongSinhMenh;

    public:

        SinhMenh(){}

        ~SinhMenh(){}

        void Nhap()
        {
            VatPham::Nhap();
            cout << "Nhap luong sinh menh: ";
            cin >> LuongSinhMenh;
        }

        int GetLuongSinhMenh()
        {
            return LuongSinhMenh;
        }
};

class Boss
{
    private:

        string Ten;
        int SinhMenh;
        int SatThuong;
        int SoLanTanCong;
    
    public:

        Boss()
        {
            SinhMenh = 20;
        }
        ~Boss(){}

        void Nhap()
        {
            cin.ignore();
            cout << "Nhap ten boss: ";
            getline(cin, Ten);
            cout << "Nhap so lan tan cong: ";
            cin >> SoLanTanCong;
            cout << "Nhap sat thuong moi lan tan cong: ";
            cin >> SatThuong;
        }

        int GetSinhMenh() 
        {
            return SinhMenh;
        }

        void GiamSinhMenh(int SatThuong)
        {
            SinhMenh -= SatThuong;
        }

        int GetSatThuong() 
        {
            return SatThuong;
        }

        int GetSoLanTanCong()
        {
            return SoLanTanCong;
        }

        string GetTen()
        {
            return Ten;
        }

        void SetSoLanTanCong()
        {
            this->SoLanTanCong--;
        }

        void SetSinhMenh(float satthuong)
        {
            this->SinhMenh -= satthuong;
        }

        void TanCongXeTang(XeTang &XT);
};

class XeTang
{
    private:

        string SoHieu;
        string Ten;
        int  LuongSinhMenh;
        VatPham* VP;

    public:

        XeTang()
        {
            LuongSinhMenh = 10;
            VP = NULL;
        }

        ~XeTang(){}

        void Nhap()
        {
            cout << "Nhap so hieu xe tang: ";
            getline(cin, SoHieu);
            cout << "Nhap ten xe tang: ";
            getline(cin, Ten);
        }

        void Xuat()
        {
            cout << setw(20) << left << "So Hieu" << setw(20) << left << "Ten Xe Tang" << setw(20) << left << "Sinh Menh" << endl;
            cout << setw(20) << left << SoHieu << setw(20) <<  left << Ten << setw(20) << left << LuongSinhMenh << endl;
        }

        void NhatVatPham(VatPham* vp)
        {
            VP = vp;
            if (!vp->isDanDon() && !vp->isDanKep())
                LuongSinhMenh += vp->GetLuongSinhMenh();
        }

        void TinhSatThuong(VatPham* vp, int &LuongSatThuong)
        {
            if (vp->isDanDon() || vp->isDanKep())
                LuongSatThuong += vp->GetSatThuong();
        }

        int GetLuongSinhMenh() 
        {
            return LuongSinhMenh;
        }

        VatPham* GetVatPham() 
        {
            return VP;
        }

        string GetTen() 
        {
            return Ten;
        }

        int GetSatThuong()
        {
            if (VP->isDanDon() || VP->isDanKep())
                return VP->GetSatThuong();
            return 0;
        }

        void SetSinhMenh(float sinhmenh)
        {
            this->LuongSinhMenh += sinhmenh;
        }

        string GetSoHieu()
        {
            return SoHieu;
        }

        void SetVatPham(VatPham *&vatpham)
        {
            this->VP = vatpham;
        }

        void TanCong(Boss);
};

void XeTang::TanCong(Boss NYC)
{
    cout << "Xe tang mang so hieu " << SoHieu<< " da tan cong Boss " << NYC.GetTen() << " gay ra " << VP->GetSatThuong() << " sat thuong. ";
    VP->AmThanh();
}
void Boss::TanCongXeTang(XeTang &XT)
{
    cout << "Boss " << Ten << " da tan cong xe tang mang so hieu " << XT.GetSoHieu() << " gay ra " << SatThuong << " sat thuong.\n";
}

class BanDo
{
    private:

        int SoXeTang;
        XeTang *XT;

        int SoVatPham;
        VatPham** VP;

        Boss NYC;

        XeTang XTCoSatThuongLonNhat;

    public:

        BanDo(){}
        ~BanDo()
        {
            delete[] XT;
            for (int i = 0; i < SoVatPham; ++i)
            {
                delete VP[i];
            }
            delete[] VP;
        }

        void NhapThongTinBanDo()
        {
            cout << "Nhap so luong xe tang: ";
            cin >> SoXeTang;
            cin.ignore();
            XT = new XeTang[SoXeTang];
            for(int i = 0; i < SoXeTang; i++)
                XT[i].Nhap();   

            cout << "Nhap so vat pham: ";
            cin >> SoVatPham;
            cin.ignore();
            VP = new VatPham*[SoVatPham];
            
            cout << "Nhap danh sach thong tin cac vat pham\n";
            int LuaChon;
            for (int i = 0; i < SoVatPham; i++)
            {
                cout << "Nhap loai vat pham (0. Sinh Menh, 1. Dan Doi, 2. Dan Don): ";
                cin >> LuaChon;
                cin.ignore();
                switch (LuaChon)
                {
                case 0:
                    VP[i] = new SinhMenh;
                    break;
                case 1:
                    VP[i] = new DanKep;
                    break;
                case 2:
                    VP[i] = new DanDon;
                    break;
                default:
                    break;
                }
                VP[i]->Nhap();
            }


            cout << "Nhap thong tin boss: ";
            NYC.Nhap();

            for (int i = 0; i < SoXeTang; i++)
            {
                int RandomNumber = (rand()%SoVatPham);

                    XT[i].NhatVatPham(VP[RandomNumber]);
            }
                
        }

        void TimXeTangCoSatThuongLonNhatSau1LanBan()
        {
            int MaxSatThuong = 0;
            string TenXeTang;
            for (int i = 0; i < SoXeTang; ++i)
            {
                int LuongSatThuong = 0;
                XT[i].TinhSatThuong(XT[i].GetVatPham(), LuongSatThuong);
                if (LuongSatThuong > MaxSatThuong)
                {
                    MaxSatThuong = LuongSatThuong;
                    TenXeTang = XT[i].GetTen();
                }
            }
            cout << "Xe tang co sat thuong lon nhat sau 1 lan ban: " << TenXeTang << " voi luong sat thuong: " << MaxSatThuong << "\n";
        }

        void TimXeTangCoTongSatThuongLonNhatKhiHetDan()
        {
            int ViTri = 0;
            float temp2;
            for (int i = 1; i < SoXeTang; ++i)
            {
                float temp1 = XT[i].GetVatPham()->GetSoLanSuDung() * XT[i].GetVatPham()->GetSatThuong();
                temp2 = XT[ViTri].GetVatPham()->GetSoLanSuDung() * XT[ViTri].GetVatPham()->GetSatThuong();
                if (temp1 > temp2)
                    ViTri = i;
            }
            XTCoSatThuongLonNhat = XT[ViTri];
            cout << "Xe tang co tong sat thuong lon nhat khi het dan: " << XT[ViTri].GetTen() << endl;
        }

        void MoPhongTraoDoiSatThuong()
        {
            
            int ChiSo = 0;
            for (int i = 1; i < SoXeTang; i++)
            {
                if (XT[i].GetVatPham()->GetSatThuong() * XT[i].GetVatPham()->GetSoLanSuDung() > 
                    XT[ChiSo].GetVatPham()->GetSatThuong() * XT[ChiSo].GetVatPham()->GetSoLanSuDung())
                        ChiSo = i;
            }
            cout << "Xe tang co tong sat thuong lon nhat neu ban het dan o thoi diem hien tai la:\n";
            XT[ChiSo].Xuat();
            cout << " => Voi tong sat thuong la: " << XT[ChiSo].GetVatPham()->GetSatThuong() * XT[ChiSo].GetVatPham()->GetSoLanSuDung() << endl;

            cout << "----- QUA TRINH GIA LAP TRAO DOI SAT THUONG GIUA XE TANG " << XT[ChiSo].GetSoHieu() << " VA BOSS " << NYC.GetTen() << " -----\n";
            cout << setw(50) << left << "Thong tin xe tang" << setw(15) << left << "Thong tin Boss\n";
            cout << setw(15) << left << "- Mau xe tang: " << XT[ChiSo].GetLuongSinhMenh() << setw(45) << right << "- Mau Boss: " <<  NYC.GetSinhMenh() << endl;
            cout << setw(26) << left << "- Sat thuong moi lan ban: " <<  XT[ChiSo].GetVatPham()->GetSatThuong() << setw(50) << right << "- Sat thuong moi lan danh: " << NYC.GetSatThuong() << endl;
            cout << setw(24) << left << "- So luong dan con lai: " <<  XT[ChiSo].GetVatPham()->GetSoLanSuDung() << setw(52) << right << "- So lan tan cong con lai: " <<  NYC.GetSoLanTanCong() << endl; 
            cout << "--------------------------------------------------------------------------------------------\n";
            bool check1 = 0, check2 = 0;
            while (XT[ChiSo].GetLuongSinhMenh() > 0 && NYC.GetSinhMenh() > 0)
            {
                if (XT[ChiSo].GetVatPham()->GetSoLanSuDung() != 0)
                {
                    XT[ChiSo].TanCong(NYC);
                    NYC.SetSinhMenh(XT[ChiSo].GetVatPham()->GetSatThuong());
                    XT[ChiSo].GetVatPham()->SetSoLanSuDung();
                    if (NYC.GetSinhMenh() > 0)
                    {
                        cout << " + Mau Boss: " << NYC.GetSinhMenh() << endl;
                        cout << " + So lan con lai cua xe tang: " << XT[ChiSo].GetVatPham()->GetSoLanSuDung() << endl;
                    }
                    else
                    {
                        cout << "Boss da chet! Xin chuc mung cho xe tang mang so hieu " << XT[ChiSo].GetSoHieu() << " da chien thang\n";
                        break;
                    }
                }

                if (XT[ChiSo].GetVatPham()->GetSoLanSuDung() == 0)
                {
                    if (!check1)
                    {
                        cout << "Xe tang da het dan!\n";
                        check1 = 1;
                    }
                }

                if (NYC.GetSoLanTanCong() != 0)
                {
                    NYC.TanCongXeTang(XT[ChiSo]);
                    XT[ChiSo].SetSinhMenh(-NYC.GetSatThuong());
                    NYC.SetSoLanTanCong();
                    if (XT[ChiSo].GetLuongSinhMenh() > 0)
                    {
                        cout << " + Mau xe tang: " << XT[ChiSo].GetLuongSinhMenh() << endl;
                        cout << " + So lan tan cong con lai cua Boss: " << NYC.GetSoLanTanCong() << endl;
                    } 
                    else
                    {
                        cout << "Xe tang da thua tran! Boss " << NYC.GetTen() << " da chien thang\n";
                        break;
                    }
                }

                if (NYC.GetSoLanTanCong() == 0)
                {
                    if (!check2)
                    {
                        cout << "Boss da het nang luong!\n";
                        check2 = 1;
                    }
                }

                if (XT[ChiSo].GetVatPham()->GetSoLanSuDung() == 0 && NYC.GetSoLanTanCong() == 0)
                {
                    cout << "Ca hai ben deu da het dan va het nang luong nhung van chua het sinh menh. Ket qua cua tran dau la hoa\n";
                    break;
                }
            }

        }
    
};

int main()
{
    BanDo GamePlay;
    GamePlay.NhapThongTinBanDo();
    GamePlay.TimXeTangCoSatThuongLonNhatSau1LanBan();
    GamePlay.TimXeTangCoTongSatThuongLonNhatKhiHetDan();
    GamePlay.MoPhongTraoDoiSatThuong();

    return 0;
}