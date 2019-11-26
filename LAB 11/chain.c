#include <limits.h>
#include <stdio.h>
#include <color.c>
int MatrixChainOrder(int p[], int n)
{
    int m[n][n];

    int i, j, k, L, q;

    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1];
}

int main()
{
    int arr[50], n, i;    //{9, 8, 7, 2};

    bold_blue();
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    bold_cyan();
    printf("Enter matrix dimentions in an array format: ");

    for(i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }

    bold_yellow();
    printf("Minimum number of multiplications is %d\n", MatrixChainOrder(arr, n));
    reset();
    return 0;
}
