class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans=abs(nums[0]),mini=nums[0],maxi=nums[0];
        for(int i=1;i<nums.size();++i){
            mini=min(mini+nums[i],nums[i]);
            maxi=max(maxi+nums[i],nums[i]);
            ans=max({ans,maxi,abs(mini)});
        }
        return abs(ans);
    }
};