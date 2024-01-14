#include<iostream>
using namespace std;
int main()
{
    int arr[100],n, i, num, index;
    cout<<"Enter no of elements: ";
    cin>>n;
    for(i=0; i<n; i++)
        cin>>arr[i];
    cout<<"\nEnter a Number to Search: ";
    cin>>num;
    index=-1;
    for(i=0; i<n; i++)
    {
        if(arr[i]==num)
        {
            index = i;
            break;
        }
    }
    if(index==-1)
    {
        cout<<"Element not found!";
    }
    if(index>-1){
    cout<<"\nFound at Index No. "<<index;
    cout<<endl;}
    return 0;
}