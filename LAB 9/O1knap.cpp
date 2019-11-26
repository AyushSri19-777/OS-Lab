#include <iostream>
using namespace std;
int main()
{
    int n,C,i,j,res=0,temp,profit=0;
    cout<<"Enter number of items and capacity\n";
    cin>>n>>C;
    float W[n],P[n],Pd[n],x[n];
    for(i=0;i<n;i++)
        x[i]=0;
    cout<<"Enter the weights and profit\n";
    for(i=0;i<n;i++){
        cout<<"Item "<<(i+1)<<" ";
        cin>>W[i]>>P[i];
        Pd[i]=P[i]/W[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {

            if(Pd[j]<Pd[j+1])
            {
                temp=Pd[j];      Pd[j]=Pd[j+1];         Pd[j+1]=temp;
                temp=P[j];      P[j]=P[j+1];         P[j+1]=temp;
                temp=W[j];      W[j]=W[j+1];         W[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
         if((res+W[i])<=C)
         {
             res+=W[i];
             x[i]=1;
             profit+=P[i];
         }
         //cout<<Pd[i];

    }
    cout<<"Weight=[";
    for(i=0;i<n;i++)
        cout<<W[i]<<" ";
    cout<<"]\n";
    cout<<"Profit=[";
    for(i=0;i<n;i++)
        cout<<P[i]<<" ";
    cout<<"]\n";
    cout<<"X=[";
    for(i=0;i<n;i++)
        cout<<x[i]<<" ";
    cout<<"]\n";
    cout<<"Total profit= "<<profit;


}
