#include<iostream>
using namespace std;

int** add(int** a,int** b)
{
    int** c = new int*[2];
    for (int i = 0; i < 2; i++)
    {
        c[i]=new int[2];
        for (int j = 0; j < 2; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}

int** sub(int** a,int** b)
{
    int** c = new int*[2];
    for (int i = 0; i < 2; i++)
    {
        c[i]=new int[2];
        for (int j = 0; j < 2; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    return c;
}

int** multi(int** a,int** b)
{
    int** c = new int*[2];
    for (int i = 0; i < 2; i++)
    {
        c[i]=new int[2];
        for (int j = 0; j < 2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

void strassen(int** a,int** b)
{
    int** a1 = new int* [2];
    int** a2 = new int* [2];
    int** a3 = new int* [2];
    int** a4 = new int* [2];
    int** b1 = new int* [2];
    int** b2 = new int* [2];
    int** b3 = new int* [2];
    int** b4 = new int* [2];

    for (int i = 0; i < 2; i++) 
    {
        a1[i] = new int[2];
        a2[i] = new int[2];
        a3[i] = new int[2];
        a4[i] = new int[2];
        b1[i] = new int[2];
        b2[i] = new int[2];
        b3[i] = new int[2];
        b4[i] = new int[2];
        for (int j = 0; j < 2; j++) 
        {
            a1[i][j] = a[i][j];
            a2[i][j] = a[i][j + 2];
            a3[i][j] = a[i + 2][j];
            a4[i][j] = a[i + 2][j + 2];

            b1[i][j] = b[i][j];
            b2[i][j] = b[i][j + 2];
            b3[i][j] = b[i + 2][j];
            b4[i][j] = b[i + 2][j + 2];
        }
    }
    int** d = new int* [2];
    int** e = new int* [2];
    int** f = new int* [2];
    int** g = new int* [2];
    int** h = new int* [2];
    int** I = new int* [2];
    int** j = new int* [2];
    int** c1 = new int* [2];
    int** c2 = new int* [2];
    int** c3 = new int* [2];
    int** c4 = new int* [2];


    for (int k = 0; k < 2; k++) 
    {
        d[k] = new int[2];
        e[k] = new int[2];
        f[k] = new int[2];
        g[k] = new int[2];
        h[k] = new int[2];
        I[k] = new int[2];
        j[k] = new int[2];
        c1[k] = new int[2];
        c2[k] = new int[2];
        c3[k] = new int[2];
        c4[k] = new int[2];
    }

    d = multi(a1,sub(b2,b4));
    e = multi(a4,sub(b3,b1));
    f = multi(add(a3,a4),b1);
    g = multi(add(a1,a2),b4);
    h = multi(sub(a3,a1),add(b1,b2));
    I = multi(sub(a2,a4),add(b3,b4));
    j = multi(add(a1,a4),add(b1,b4));

    c1 = add(add(e,I),sub(j,g));
    c2 = add(d,g);
    c3 = add(e,f);
    c4 = add(add(d,h),sub(j,f));  

    int** c = new int*[4]; 

    for (int k = 0; k < 4; k++)
    {
        c[k]=new int[4];
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c[i][j] = c1[i][j];
            c[i][j + 2] = c2[i][j];
            c[i + 2][j] = c3[i][j];
            c[i + 2][j + 2] = c4[i][j];
        }
    }
    cout<<"product is- \n";

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<c[i][j]<<"  ";
        }
        cout<<"\n";
    }
}

int main()
{
    int** a = new int*[4];
    int** b = new int*[4];

    cout<<"enter first martix- ";
    for (int i = 0; i < 4; i++)
    {
        a[i] = new int[4];
        b[i] = new int[4];
        for (int j = 0; j < 4; j++)
        {
            cin>>a[i][j];
        }   
    }
    cout<<"enter second martix- ";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin>>b[i][j];
        }   
    }

    strassen(a,b);
}
