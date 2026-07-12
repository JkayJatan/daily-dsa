class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>sarr=arr;
        sort(sarr.begin(),sarr.end());
        unordered_map<int,int>rank;
        int r=1;
        for(int val:sarr){
            if(!rank.count(val)){
                rank[val]=r++;
            }
        }
        vector<int>ans;
        for(int val:arr){
            ans.push_back(rank[val]);
        }
        return ans;
    }
};