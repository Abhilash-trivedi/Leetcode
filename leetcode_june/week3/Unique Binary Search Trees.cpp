class Solution {
public:
    int numTrees(int n) {
        int i,dp[n+5],j;
        dp[0] = 1;dp[1] = 1; 
        for(i=2;i<=n;i++){
            dp[i] = 0;
            for(j=1;j<=i;j++){
                dp[i] = dp[i]+dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};