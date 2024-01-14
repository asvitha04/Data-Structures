#include<iostream>
using namespace std;
void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int left,int right)
{
    int pivot=arr[right];
    int i=(left-1);
    for(int j=left;j<=right-1;j++)
    {
        if(arr[j]<pivot)
            {
            i++;
            swap(&arr[i],&arr[j]);
            }
    }
swap(&arr[i+1],&arr[right]);
return (i+1);
}
void quicksort(int arr[],int left,int right)
{
    if(left<right)
        {
        int p_index=partition(arr,left,right);
        quicksort(arr,left,p_index-1);
        quicksort(arr,p_index+1,right);
        }
}
int main()
{
    int arr[30],n,i;
    cout<<"enter the no. of array elements:";
    cin>>n;
    cout<<"\nEnter the elements:";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    cout<<"\nArray after sorting:";
    for(int i=0;i<n;i++)
    {
        cout<<"\t"<<arr[i];
    }
    return 0;
}
