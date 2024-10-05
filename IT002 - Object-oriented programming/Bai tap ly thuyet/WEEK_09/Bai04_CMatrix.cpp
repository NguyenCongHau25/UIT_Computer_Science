#include <iostream>
using namespace std;
#define MAX 20

class CMatrix
{
    private:
        int m;
        int n;
        int matrix[MAX][MAX];
    public:
        CMatrix(int row = 0, int column = 0)
        {
            n = row;
            m = column;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    matrix[i][j] = rand() / 10000 + 1;
        }

        ~CMatrix(){}

        void InputMatrix()
        {
            cout << "Nhap so dong: " << endl;
            cin >> m;

            cout << "Nhap so cot: " << endl;
            cin >> n;

            cout << "Nhap ma tran: " << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    cin >> matrix[i][j];
            }
        }

        void OutputMatrix()
        {
            cout << "Ma tran:" << endl;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                    cout << matrix[i][j] << "  ";
                cout << endl;
            }
        }

        CMatrix operator+(CMatrix b)
        {  
            CMatrix c(m, n);
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                    c.matrix[i][j]= matrix[i][j] + b.matrix[i][j];
            }
            return c;
        }

        CMatrix operator-(CMatrix b)
        {
            CMatrix c(m, n);
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                    c.matrix[i][j]= matrix[i][j] - b.matrix[i][j];
            }
            return c;
        }

        CMatrix operator*(CMatrix b)
        {
            CMatrix c(m, b.n);
            for (int i = 0; i < m; i++)
                for (int j = 0; j < b.n; j++)
                {
                    int tich = 0;
                    for (int k = 0; k < n; k++)
                    {
                        tich = tich + (matrix[i][k] * b.matrix[k][j]);
                    }
                    c.matrix[i][j] = tich;
                }
            return c;
        }
};

int main()
{
    CMatrix A(2,3);
    CMatrix B(3,4);
    CMatrix C, D, E;

    cout << "Ma tran A: " << endl;
    A.OutputMatrix();
    cout << "Ma tran B: " << endl;
    B.OutputMatrix();

    cout << "Tong hai ma tran: " << endl;
    C = A + B;
    C.OutputMatrix();

    cout << "Hieu hai ma tran: " << endl;
    D = A - B;
    D.OutputMatrix();

    cout << "Tich hai ma tran: " << endl;
    E = A*B;
    E.OutputMatrix();
    return 0;
}