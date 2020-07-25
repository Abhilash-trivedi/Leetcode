class Solution {
    int sum;
public:
    vector<int>value;
    Solution(vector<int>& w) {
        sum=0;
        for(auto i:w)
        {
            sum+=i;
            value.push_back(sum);
        }
    }
    
    int pickIndex() {
        int rnd=rand()%sum;
        vector<int>::iterator p;
        p=upper_bound(value.begin(),value.end(),rnd);
        return (int)(p-value.begin());
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */