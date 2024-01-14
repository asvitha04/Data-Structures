#include<iostream>
using namespace std;
int main()
{
 int i,j,len,temp,arr[30],num,first,last,middle;
 cout<<"enter size of array:";
 cin>>len;
 cout<<"enter array elements:";
 for(i=0;i<len;i++)
 {
  cin>>arr[i];
 }
  for(i=0;i<(len-1);i++)
  {
   for(j=0;j<(len-i-1);j++)
   {
    if(arr[j]>arr[j+1])
    {
     temp=arr[j];
     arr[j]=arr[j+1];
     arr[j+1]=temp;
    }
   }
  }
    cout<<"\n"<<"the sorted array is:";
    for(i=0;i<len;i++)
    {
     cout<<arr[i]<<" ";
    }
  cout<<"\n"<<"enter element to search:";
  cin>>num;
  first=0;
  last=(len-1);
  middle=(first+last)/2;
  while(first<=last)
  {
   if(arr[middle]<num)
   first=middle+1;
   else if(arr[middle]==num)
   {
    cout<<"\n"<<"the number,"<<num<<"found at position"<<middle+1;
    break;
   }
    else
    {
    last=middle-1;
    middle=(first+last)/2;
    }
  }
  if(first>last)
  {
  cout<<"\n"<<"the number,"<<num<<"is not found in given array";
  }
  return 0;
 }




