class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        int n=intervals.size();
        int s1=intervals[0][0],e1=intervals[0][1];
        for(int i=1;i<n;++i){
            int s2=intervals[i][0],e2=intervals[i][1];
            if(e1>=s2){
                e1=max(e1,e2);
            }
            else{
                res.push_back({s1,e1});
                s1=s2;
                e1=e2;
            }
        }
        res.push_back({s1,e1});
        return res;
    }
};