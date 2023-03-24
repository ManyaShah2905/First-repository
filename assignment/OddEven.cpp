#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
cin>>arr[i];
}
int odd=0;
int even=0;
for(int i=0;i<n;i++)
{
if(arr[i]%2==0)
{
even++;
}
else
{
odd++;
}
}
int g;
int flag=0;
while(!flag)
{
flag=1;
for(int i=1;i<odd;i+=2)
{
if(arr[i]>arr[i+1])
{
g=arr[i];
arr[i]=arr[i+1];
arr[i+1]=g;
flag=0;
}
}
for(int i=0;i<even;i+=2)
{
if(arr[i]>arr[i+1])
{
g=arr[i];
arr[i]=arr[i+1];
arr[i+1]=g;
flag=0;
}
}
}
for(int i=0;i<n;i++)
{
cout<<arr[i]<<endl;
}
return 0;
}