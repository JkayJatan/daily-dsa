class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int max_diff=INT_MAX;
        int result_sum;
        for(int i=0;i<n;++i){
            int l=i+1,r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                int diff=abs(sum-target);
                if(diff<max_diff){
                    max_diff=diff;
                    result_sum=sum;
                }
                if(sum==target){
                    return result_sum;
                }
                else if(sum<target){
                    l++;
                }
                else r--;
            }
        }
        return result_sum;
    }
};