#include<iostream>
using namespace std;
int maxsum(int n, int a[])
{
    int thesum, maxsum1, i, j, k, flag = 0;
    maxsum1 = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] > 0)
            flag = 1;
        thesum = 0;
        for (j = i; j < n; j++)
        {
            thesum += a[j];
            if (thesum > maxsum1)
                maxsum1 = thesum;
        }
    }
    if (flag == 0)
        maxsum1 = 0;
    return maxsum1;
}
int main()
{
    int n, a[100], i,j;
    for (j = 0;; j++)
    {
        cin >> n;
        if (n == 0)
            break;
        for (i = 0; i < n; i++)
            cin >> a[i];
        cout << maxsum(n, a);
    }
    return 0;
}
