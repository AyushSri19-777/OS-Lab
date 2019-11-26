#include <iostream>
using namespace std;
int main()
{
    int n,k,i,j,temp=0;
    cout<<"Enter the number of elements";
    cin>>n;
    cout<<"Enter array:";
    int A[n],B[n];
    for(i=0;i<n;i++)
        cin>>A[i];
    cout<<"Enter modulo:";
    cin>>k;
    for(i=0;i<n;i++)
        B[i]=A[i]%k;
    cout<<"The modulos\n";
    for(i=0;i<n;i++)
        cout<<B[i]<<" ";

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(B[j]>B[j+1]||((B[j]==B[j+1])&&(A[j]>A[j+1])))
            {
                temp=B[j];  
		B[j]=B[j+1];
		B[j+1]=temp;
                temp=A[j];  
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
    cout<<"\nOutput Array\n";
    for(i=0;i<n;i++)
        cout<<A[i]<<" ";
}
