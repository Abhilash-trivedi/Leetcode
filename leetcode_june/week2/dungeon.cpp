class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        if(n == 0) return 0;
        int m = dungeon[0].size();
        if(m == 0) return 0;
        int i,j;
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[n-1][m-1] = dungeon[n-1][m-1];
        for(i = n-2; i >= 0; i--){
            dp[i][m-1] = min(dungeon[i][m-1], dungeon[i][m-1]+dp[i+1][m-1]) ;
        }
        for(j = m-2; j >= 0; j--){
            dp[n-1][j] = min(dungeon[n-1][j],dungeon[n-1][j]+dp[n-1][j+1]);
        }
        for(i = n - 2; i >= 0; i--){
            for(j = m-2 ; j >= 0; j--){
                
                dp[i][j] = min(dungeon[i][j], dungeon[i][j] + max(dp[i+1][j],dp[i][j+1]));
            }
        }
        return 1 + max(0, - dp[0][0]);
    }
};
