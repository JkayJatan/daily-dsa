class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int r_sum=0;
        for(int x:nums)r_sum+=x;
        int l_sum=0;
        for(int i=0;i<nums.size();++i){
            r_sum-=nums[i];
            if(r_sum==l_sum)return i;
            l_sum+=nums[i];
        }
        return -1;
    }
};