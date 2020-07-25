class Solution {
public:

    int numSquares(int n) {
    int ans[n+2];
    ans[0]=0;
    for(int i=1;i<=n;i++)
    {
        ans[i]=100000;
        for(int j=1;j*j<=i;j++)
            ans[i]=min(ans[i],1+ans[i-j*j]);
    }
    return ans[n];
}
};