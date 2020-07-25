class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                nums.erase(nums.begin()+i);
                nums.insert(nums.begin(),{0});
                //i--;
            }
            if(nums[i]==2)
            {
                nums.erase(nums.begin()+i);
                nums.insert(nums.end(),{2});
                   if(i<n-count)
                   {i--;
                    count++;
                   }
                
            }
        }
        for(auto i:nums)cout<<i<<" ";
    }
};