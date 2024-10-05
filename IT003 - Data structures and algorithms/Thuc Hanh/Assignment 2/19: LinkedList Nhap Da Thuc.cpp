/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
	
	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}
	
	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;
	
	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}
	
};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};


//###INSERT CODE HERE -

bool check(const DATHUC &B)
{
    Node *p=B.head;
    while (p != NULL) 
	{
        if (p -> data -> heso != 0) 
		   return 1;
        p=p->next;
    }
    return 0;
}

void Nhap(DATHUC& B, double heso, int somu) 
{
    DONTHUC *New_DonThuc = new DONTHUC(heso, somu);

    Node *New_Node = new Node(NewDonThuc);
    if (B.head == NULL) 
        B.head = B.tail = New_Node;
	else 
	{
        B.tail -> next = New_Node;
        B.tail = NewN_ode;
    }
}


void Xuat(const DATHUC &B)
{
	Node *p = B.head;

	if (check(B) == 0)
	{
		cout << 0;
	}
	else
		while (p->data->heso == 0)
			p = p->next;

	if (p != NULL && p->data->heso != 0)
	{
		if (p->data->somu == 0)
			cout << p->data->heso;

		else if (p->data->heso != 0 && p->data->somu != 1)
		{
			if (p->data->heso == 1)
				cout << "x^" << p->data->somu;
			else if (p->data->heso == -1)
				cout << "-x^" << p->data->somu;
			else
				cout << p->data->heso << "x^" << p->data->somu;
		}

		else if (p->data->heso != 0 && p->data->somu == 1)
		{
			if (p->data->heso == 1)
				cout << "x";
			else if (p->data->heso == -1)
				cout << "-x";
			else
				cout << p->data->heso << "x";
		}
	}

	p = p->next;

	while (p != NULL)
	{
		if (p->data->heso != 0)
		{
			if (p->data->heso > 0 && p->data->heso != 1)
			{
				if (p->data->somu == 0)
					cout << '+' << p->data->heso;
				else if (p->data->somu == 1)
					cout << '+' << p->data->heso << 'x';
				else
					cout << '+' << p->data->heso << "x^" << p->data->somu;
			}
			else if (p->data->heso < 0 && p->data->heso != -1)
			{
				if (p->data->somu == 0)
					cout << p->data->heso;
				else if (p->data->somu == 1)
					cout << p->data->heso << 'x';
				else
					cout << p->data->heso << "x^" << p->data->somu;
			}
			else if (p->data->heso == 1)
			{
				if (p->data->somu == 0)
					cout << '+' << 1;
				else if (p->data->somu == 1)
					cout << "+x";
				else
					cout << '+' << "x^" << p->data->somu;
			}
			else if (p->data->heso == -1)
			{
				if (p->data->somu == 0)
					cout << -1;
				else if (p->data->somu == 1)
					cout << "-x";
				else
					cout << '-' << "x^" << p->data->somu;
			}
		}
	p = p->next;
	}
}

double TinhDaThuc(const DATHUC& B, double x) 
{
    double kq = 0;

    Node *p = B.head;
	
	while (p != NULL) 
	{
        kq += p->data->heso * pow(x, p->data->somu);
        p = p->next;
    }
    return kq;
}

int main() {
    DATHUC B;
    int N;
    
    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    
    
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
