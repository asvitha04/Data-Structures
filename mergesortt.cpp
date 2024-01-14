#include<iostream>
using namespace std;
void merge(int arr[30],int const l,int const m,int const r)
{
int i,j,k;
int const n1=m-l+1;
int const n2=r-m;
int L[n1],R[n2];
for(i=0;i<n1;i++)
{
L[i]=arr[l+i];
}
for(j=0;j<n2;j++)
{
R[j]=arr[m+1+j];
}
i=0;
j=0;
k=l;
while(i<n1 && j<n2)
{
if(L[i]<=R[j])
{
arr[k]=L[i];
i++;
}
else
{
arr[k]=R[j];
j++;
}
k++;
}
while(i<n1)
{
arr[k]=L[i];
i++;
k++;
}
while(j<n2)
{
arr[k]=R[j];
j++;
k++;
}
}
void mergeSort(int arr[30],int l,int r)
{
if(l<r)
{
int m=l+(r-l)/2;
mergeSort(arr,l,m);
mergeSort(arr,m+1,r);
merge(arr,l,m,r);
}
}
int main()
{
int arr[30],n,i;
cout<<"Enter the number of elements:";
cin>>n;
cout<<"\nEnter the element:";
for(i=0;i<n;i++)
{
cin>>arr[i];
}
mergeSort(arr,0,n-1);
cout<<"\nArray after sorting:";
for(i=0;i<n;i++)
{
cout<<"\t"<<arr[i];}
return 0;
}
