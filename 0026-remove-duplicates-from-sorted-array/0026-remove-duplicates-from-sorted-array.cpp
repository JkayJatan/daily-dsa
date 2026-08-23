class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=1,r=1,res=1,n=nums.size();
        while(r<n){
            if(nums[r]==nums[r-1])r++;
            else{
                nums[l++]=nums[r++];
                res++;
            }
        }
        return res;
    }
};