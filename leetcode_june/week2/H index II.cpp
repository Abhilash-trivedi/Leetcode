class Solution {
public:
    int hIndex(vector<int>&v)
    {
        sort(v.begin(),v.end(),greater<int>());
        int n=v.size();
        if(n==0)return 0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]>=(i+1))
            {
                ans=i+1;
            }
        }
        if(n==1)
        {
            if(v[0]>0)return 1;
            
        }
        return ans;
    }
};