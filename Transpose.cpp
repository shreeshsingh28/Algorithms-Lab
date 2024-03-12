#include<iostream>
using namespace std;

int main()
{
    int a[10][10],n,m,x,p,q;
    cout<<"enter number of vertices- ";
    cin>>n;
    cout<<"enter number of edges- ";
    cin>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<"enter source- ";
        cin>>p;
        cout<<"enter destination- ";
        cin>>q;
        a[p][q]=1;
        //a[q][p]=1;
    }
    cout<<"the matrix is- \n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[i][j]<<"  ";
        }
        cout<<"\n";
    }
    int b[10][10];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            b[i][j]=a[j][i];
        }
    }

    cout<<"the transpose is- \n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<b[i][j]<<"  ";
        }
        cout<<"\n";
    }
}
