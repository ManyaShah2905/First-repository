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
int start=0;
int end=n-1;
bool isSorted=true;
while(!isSorted)
{
isSorted=false;
//left-side(Cycle-1)
for(int l=start;l<end;l++)
{
int g;
if(arr[l]>arr[l+1])
{
g=arr[l];
arr[l]=arr[l+1];
arr[l+1]=g;
isSorted=true;
}
}
if(!isSorted)
{
break;
}
isSorted=false;
end--;
//right-side(Cycle-2)
for(int r=end-1;r>=start;r--)
{
int g;
if(arr[r]>arr[r+1])
{
g=arr[r];
arr[r]=arr[r+1];
arr[r+1]=g;
isSorted=true;
}
}
++start;
}
for(int i=0;i<n;i++)
{
cout<<arr[i]<<" ";
}
return 0;
}