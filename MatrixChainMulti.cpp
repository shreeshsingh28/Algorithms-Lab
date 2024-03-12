#include <bits/stdc++.h>
using namespace std;

int d[5] = {3, 2, 4, 2, 5};
const int n = 4; // number of matrices

int m[n + 1][n + 1] = {-1};
int k[n + 1][n + 1] = {-1};

void chain()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                m[i][j] = 0;
            else if (i < j)
            {
                int size = j - i;
                int ms[size] = {0};
                int ks[size] = {0};

                int a = 0;
                for (int k = i; k < j; k++)
                {
                    ms[a] = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j];
                    ks[a++] = k;
                }

                int min = 9999;
                int kindex = -1;
                for (int b = 0; b < size; b++)
                {
                    if (min > ms[b])
                    {
                        min = ms[b];
                        kindex = ks[b];
                    }
                }
                m[i][j] = min;
                k[i][j] = kindex;
            }
            else
            {
                m[i][j] = 0;
                k[i][j] = 0;
            }
        }
    }
}

void print_optimal(int i, int j)
{
    if (i == j)
        cout << "A" << i;
    else
    {
        cout << "(";
        print_optimal(i, k[i][j]);
        print_optimal(k[i][j] + 1, j);
        cout << ")";
    }
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        chain();
    }

    cout << "m matrix- \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "k matrix- \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << k[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "Order of multiplication: ";
    print_optimal(1, n);
    cout << "\n";
}
