class Solution {
public:
    string getPermutation(int n, int k) 
    {
        int fact[10] = {1,1,2,6,24,120,720,5040,40320,362880};
        string ans="";
        string num="123456789";
        k--;
        for(int i=n; i>0; i--)
        {
            int j=k/fact[i-1];
            k = k%fact[i-1];
            ans += num[j];
            num.erase(num.begin()+j);
        }
        return ans;
    }
};