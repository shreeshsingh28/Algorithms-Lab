#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int p[6] = {0, 3, 9, 10, 8, 9};
    int w[6] = {0, 2, 6, 5, 3, 4};
    int x[5];
    int n = 5; // total elements
    int c = 8; // total capacity

    int k[5][9];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            if (i == 0 || j == 0)
                k[i][j] = 0;
            else if (w[i] <= j)
                k[i][j] = std::max(k[i - 1][j], k[i - 1][j - w[i]] + p[i]);
            else
                k[i][j] = k[i - 1][j];
        }
    }

    cout << "table- \n";

    for (int x = 0; x <= n; x++)
    {
        for (int y = 0; y <= c; y++)
        {
            cout << k[x][y] << "  ";
        }
        cout << "\n";
    }

    int i = n;
    int j = c;
    cout<<"\nselected- ";

    while (i > 0 && j > 0)
    {
        if (k[i][j] == k[i - 1][j])
        {
            //cout<<i<<"  ";
            i--;
        }
        else
        {
            cout<<i<<"  ";
            j = j - w[i];
            i--;
        }
    }
/*
    cout << "solution is- \n";
    for (int a = 1; a <= n; a++)
    {
        cout << x[a] << "  ";
    }
*/
}