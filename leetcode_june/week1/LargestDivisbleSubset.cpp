class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& v) {
        
        sort(v.begin(),v.end());
        int n=v.size();
        if(n==0)return v;
        vector<int>val(n,1);
        int mx=n-1;
        for(int j=0;j<n;j++)
        {
            for(int i=j-1;i>=0;i--)
            {
                if(v[j]%v[i]==0)
                {
                    val[j]=max(val[j],val[i]+1);
                }
                
            }
            if(val[j]>val[mx])mx=j;
        }
        int value=val[mx];
        vector<int>r;
        for(int i=mx;i>=0;i--)
        {
            if(v[mx]%v[i]==0&&value==val[i])
            {
                r.push_back(v[i]);
                mx=i;
                value--;
            }
        }
        return r;
    }
};