#include<iostream>
using namespace std;

void swap(int arr[],int n1,int n2)
{
    int temp = arr[n1];
    arr[n1]=arr[n2];
    arr[n2]=temp;
}

int partition(int arr[],int l,int r)
{
    int pi=arr[r];
    int i=l-1;

    for (int j = l; j < r; j++)
    {
        if (arr[j]<pi)
        {
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,r);        //rem
    return i+1;
}

void quicksort(int arr[],int l,int r)
{
    if (l<r)
    {
        int pi=partition(arr,l,r);

        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,r);
    }
}

int main()
{
    int n;
    cout<<"enter size of array- ";
    cin>>n;

    int arr[n];
    cout<<"enter array- ";
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    cout<<"array- ";
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";

    quicksort(arr,0,n-1);

    cout<<"\nsorted array- ";
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}