class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int sum=0,res=0;
        freq[0]++;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int mod=sum%k;
            if(mod<0){
                mod+=k;
            }
            if(freq.find(mod)!=freq.end()){
                res+=freq[mod];
            }
            freq[mod]++;
        }
        return res;
    }
};