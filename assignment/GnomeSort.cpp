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
int i=0;
while(i<n)
{
if(i==0) i++;
if(arr[i]>=arr[i-1])
{
i++;
}
else
{
int g=0;
g=arr[i];
arr[i]=arr[i-1];
arr[i-1]=g;
i--;
}
}
for(int j=0;j<n;j++)
{
cout<<arr[j]<<endl;
}
return 0;
}