class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int  m=t.length();
        int ti[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0||j==0)ti[i][j]=0;
                else
                {
                    if(s[i-1]==t[j-1])
                    {
                        ti[i][j]=1+ti[i-1][j-1];
                    }
                    else
                    {
                        ti[i][j]=max(ti[i][j-1],ti[i-1][j]);
                    }
                }
            }
        }
        return ti[n][m]==n;
    }
};