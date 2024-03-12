#include<iostream>
using namespace std;

int maxi(int a[],int l,int r)
{
    if (l==r)
        return a[l];
    int m = (l+r)/2;
    int u = maxi(a,l,m);
    int v = maxi(a,m+1,r);
    return u>v?u:v;
}
int mini(int a[],int l,int r)
{
    if (l==r)
        return a[l];
    int m = (l+r)/2;
    int u = mini(a,l,m);
    int v = mini(a,m+1,r);
    return u<v?u:v;
}

int main()
{
    int n;
    cout<<"enter size of array- ";
    cin>>n;
    int a[n];
    cout<<"enter array- ";
    for (int i = 0; i < n; i++)
        cin>>a[i];

    int maximum = maxi(a,0,n-1);
    cout<<"max ele is- "<<maximum<<"\n";

    int minimum = mini(a,0,n-1);
    cout<<"max ele is- "<<minimum<<"\n";
}