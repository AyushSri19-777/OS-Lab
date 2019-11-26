#include<iostream>
using namespace std;
int max(int a, int b) { return (a > b)? a : b; }
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n+1][W+1];
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i==0 || w==0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                    K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            else
                    K[i][w] = K[i-1][w];
        }
    }
    return K[n][W];
}
int main()
{
    int n,C,i,j,res=0,temp,profit=0;
    cout<<"Enter number of items and capacity\n";
    cin>>n>>C;
    int W[n],P[n];
    cout<<"Enter the weights and profit\n";
    for(i=0;i<n;i++){
        cout<<"Item "<<(i+1)<<" ";
        cin>>W[i]>>P[i];
    }
	cout<<"Total Profit: "<<knapSack(C, W, P, n);
	return 0;
}
