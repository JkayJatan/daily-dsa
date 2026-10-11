
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,vector<int>& newInterval) {
        if (intervals.empty())
            return {newInterval};

        vector<vector<int>> nums;
        bool insert = false;

        for (int i = 0; i < intervals.size(); ++i) {
            if (!insert && newInterval[0] <= intervals[i][0]) {
                insert = true;
                nums.push_back(newInterval);
            }

            nums.push_back(intervals[i]);
        }

        // BUG FIX: newInterval belongs at the end
        if (!insert)
            nums.push_back(newInterval);

        vector<vector<int>> res;

        int s1 = nums[0][0];
        int e1 = nums[0][1];

        for (int i = 1; i < nums.size(); ++i) {
            int s2 = nums[i][0];
            int e2 = nums[i][1];

            if (e1 >= s2) {
                e1 = max(e1, e2);
            } else {
                res.push_back({s1, e1});
                s1 = s2;
                e1 = e2;
            }
        }

        res.push_back({s1, e1});
        return res;
    }
};
