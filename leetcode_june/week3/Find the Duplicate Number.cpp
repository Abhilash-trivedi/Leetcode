class Solution {
public:
   int findDuplicate(vector<int>& nums) {
        int result = 0;
       for (int i = 0; i < nums.size(); i++) {
           int index = abs(nums[i]);
           if(nums[index] > 0) {
               nums[index] = -nums[index];
           } else {
               result = abs(nums[i]);
               break;
           }
       } 
        return result;
    }
    
};