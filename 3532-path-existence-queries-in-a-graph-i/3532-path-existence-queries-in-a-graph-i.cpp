class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> id(n);
        int comp = 0;

        for (int i = 0; i < n-1; i++) {
            if (nums[i+1] - nums[i] <= maxDiff) {
                id[i] = comp;
            }
            else {
                id[i] = comp++;
            }
        }
        id[n-1] = comp;

        int nq = queries.size();
        vector<bool> ans(nq, false);

        for (int i = 0; i < nq; i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            if (id[u] == id[v])
                ans[i] = true;
        }
        return ans;
    }
};