
// Nhan vector a[n] với Matrix B[n][m] cột trả về Vector C[m]
//i = 1-> m; j = 1->n, k = 1->m => C[i] += A[j]*B[j][k]

#include <iostream>
using namespace std;
#define MAX 20
class CMatrix
{
private:
    int row;
    int column;
    int matrix[MAX][MAX];
public:
    friend class CVector;
    CMatrix(int n=0, int m=0)
    {
        row = n; column = m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                matrix[i][j] = rand() / 1000 + 1;
    }
    ~CMatrix(){}
    void Show()
    {
        cout << "\n Matrix:" <<endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
                cout << matrix[i][j] << "  ";
            cout << endl;
        }
    }
};
class CVector
{
private:
    int num;
    int vector[MAX];
public:
    CVector(int n = 0)
    {
        num = n;
        for (int i = 0; i < num; i++)
            vector[i] = rand() / 1000 + 1;
    }
    ~CVector(){}
    void Show()
    {
        cout << "\n Vector:" << endl;
        for (int i = 0; i < num; i++)
            cout << vector[i] << "  ";
    }
    CVector Multiple(CMatrix M)
    {
        CVector C;
        C.num = M.column;
        for (int i = 0; i < M.column; i++)
        {
            C.vector[i] = 0;
            for (int j = 0; j < num; j++)
                for (int k = 0; k< M.column; k++)
                C.vector[i] += vector[j] * M.matrix[j][k];
        }
        return C;
    }
};
int main()
{
    CVector a(5);
    a.Show();
    CMatrix b(5, 3);
    b.Show();
    CVector c;
    c = a.Multiple(b);
    c.Show();


}
