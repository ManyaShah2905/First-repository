#include<iostream>
using namespace std;
void stoogeSort(int arr[],int lb,int ub)
{
if(lb>=ub) return;
int g;
if(arr[lb]>arr[ub])
{
g=arr[lb];
arr[lb]=arr[ub];
arr[ub]=g;
}
int noe=ub-lb+1;
if(noe>2)
{
int part=noe/3;
//left-side
stoogeSort(arr,lb,ub-part);
//right-side
stoogeSort(arr,lb+part,ub);
//left-side
stoogeSort(arr,lb,ub-part);
}
}
int main()
{
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
cin>>arr[i];
}
stoogeSort(arr,0,n-1);
for(int i=0;i<n;i++)
{
cout<<arr[i]<<" ";
}
return 0;
}