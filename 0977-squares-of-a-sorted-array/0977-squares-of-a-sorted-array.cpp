class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        vector<int>res(r+1);
        int n=nums.size();
        while(l<=r){
            if(abs(nums[l])<abs(nums[r])){
                res[n-1]=nums[r]*nums[r];
                n--;
                r--;
            }
            else {
                res[n-1]=nums[l]*nums[l];
                n--;
                l++;
            }
        }
        return res;
    }
};