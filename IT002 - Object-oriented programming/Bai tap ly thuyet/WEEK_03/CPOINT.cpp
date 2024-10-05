#include <iostream>
using namespace std;
class point {
 /*khai báo các thành phần dữ liệu riêng*/
 private:
 int x,y;
/*khai báo các hàm thành phần công cộng*/
 public:

 point(){x = 0; y = 0;}
 point(int ox, int oy){x = ox; y = oy;}
 //ham khoi tao mac dinh

 void init(int ox, int oy);
 void move(int dx, int dy);
 void display();
 int Trung(point pt);
};

void point::init(int ox, int oy) {
 cout<<"Ham thanh phan init\n";
 x = ox; y = oy;
/*x,y là các thành phần của đối tượng gọi hàm thành phần*/
}
void point::move(int dx, int dy) {
 cout<<"Ham thanh phan move\n";
x += dx; y += dy;
}
void point::display() {
 cout<<"Ham thanh phan display\n";
 cout<<"Toa do: "<<x<<" "<<y<<"\n";
}

int point::Trung(point pt)
{
    int kt;
    if(this -> x == pt.x && this -> y == pt.y)
        kt = 1;
    else
        kt = 0;
    pt.x =2 ; pt.y = 4;
    return kt
}

int main()
{
 point p, p2;
 p.init(2,4); /*gọi hàm thành phần từ đối tượng*/
 p.display();
 p.move(1,2);
 p.display();
 p2.init (3,5);
 if (p.Trung(p2)) cout << "Diem P trung voi P2";
 else   
    cout << 
 return 0;
}