#include <iostream>
using  namespace std;
int main()
{
    int n,l=0,h,mid=0,val,f=0;
    cout<<"Enter the number of elements\n";
    cin>>n;
    h=n;
    int a[n];
    cout<<"Enter array elements\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the element to be searched\n";
    cin>>val;
    while(l<h)
    {
        mid=(l+h)/2;
        if(a[mid]==val)
        {
            f=1;
            break;
        }
        if(a[mid]>val)
            h=mid-1;
        if(a[mid]<val)
            l=mid-1;
    }
    if(f==1)
        cout<<"Element found";
    else
        cout<<"Not found";

}
