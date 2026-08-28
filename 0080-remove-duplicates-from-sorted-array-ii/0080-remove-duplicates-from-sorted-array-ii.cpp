class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0,r=0,n=nums.size();
        unordered_map<int,int>freq;
        while(r<n){
            freq[nums[r]]++;
            if(freq[nums[r]]>2){
                r++;
            }
            else{
                nums[l]=nums[r];
                l++;
                r++;
            }
        }
        return l;
    }
};