class Solution {
public:
    int singleNumber(vector<int>& nums) {
       
        int o = 0, t = 0;
         for(int n: nums){
             o = (o ^ n) & (~t);
             t = (t ^ n) & (~o);
         }
        return o;
    
    }
};