#include<iostream>
#include<bits/stdc++.h>
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
int min=arr[0];
int max=arr[0];
for(int r=0;r<n;r++)
{
if(arr[r]>max)
{
max=arr[r];
}
else if(arr[r]<min)
{
min=arr[r];
}
}
int range=(max-min)+1;
vector<int> list(range);
for(int j=0;j<n;j++)
{
int e=arr[i]-min;
list[e].push_back(arr[i]);
}
int y=0;
for(int i=0;i<range;i++)
{
vector<int> t;
for(t=list[i].begin();t!=list[i].end();++t)
{
arr[++y]=*t;
}
}

for(int i=0;i<n;i++)
{
cout<<arr[i]<<endl;
}
return 0;
}