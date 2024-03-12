#include <iostream>
#include <algorithm>
using namespace std;

void floyds(int a[][10], int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                a[i][j] = std::min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
}

int main()
{
    int a[10][10];
    int n, m, p, q, c;
    cout << "enter number of vertices- ";
    cin >> n;
    cout << "enter number of edges- ";
    cin >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                a[i][j] = 0;
            else
                a[i][j] = 99999;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        cout << "enter source- ";
        cin >> p;
        cout << "enter destination- ";
        cin >> q;
        cout << "enter cost- ";
        cin >> c;
        a[p][q] = c;
    }

    cout << "the input matrix is- \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << "\n";
    }

    floyds(a, n);

    cout << "the solution matrix is- \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << "\n";
    }
}