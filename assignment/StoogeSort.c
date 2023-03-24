#include<stdio.h>
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
int part=((ub+1)*2)/3;
//left-side
stoogeSort(arr,lb,part-1);
//right-side
stoogeSort(arr,part+1,ub);
//left-side
stoogeSort(arr,lb,part-1);
}
}
int main()
{
int n;
printf("Enter the number of elements:");
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++)
{
printf("Enter the elements:");
scanf("%d",&arr[i]);
}
stoogeSort(arr,0,n-1);
printf("Sorted Array is:");
for(int i=0;i<n;i++)
{
printf("%d\n",arr[i]);
}
return 0;
}