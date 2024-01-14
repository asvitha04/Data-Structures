#include<iostream>
using namespace std;
template<typename T>
class sort
{
public:
    T a[50];
    int n,i,j;
    void ss()
    {
        cout<<"enter size of array:"<<endl;
        cin>>n;
        cout<<"enter elements of array:"<<endl;
        for(i=0;i<n;i++)
        {
            cin>>a[i];

        }
        T temp;
        int min;
        for(i=0;i<n-1;i++)
{
min=i;
for(j=i+1;j<n;j++)
{
if(a[min]>a[j])
{
min=j;
}
}
if(min!=i)
{
temp=a[i];
a[i]=a[min];
a[min]=temp;
}
}
cout<<"sorted array:"<<endl;
for(i=0;i<n;i++)
{
cout<<a[i]<<"\t";
}
cout<<endl;
    }
};
int main()
{
   sort<int>s1;
sort<float>s2;
sort<char>s3;
cout<<"INTEGER SORTING:"<<endl;
s1.ss();
cout<<"FLOAT SORTING"<<endl;
s2.ss();
cout<<"CHARACTER SORTING"<<endl;
s3.ss();
return 0;
}