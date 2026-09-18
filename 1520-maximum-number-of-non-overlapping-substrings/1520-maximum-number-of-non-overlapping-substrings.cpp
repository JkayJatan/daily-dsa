class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        vector<int> foc(26, -1);
        vector<int> loc(26, -1); 
        for (int i = 0; i < s.size(); i++) {

            int idx = s[i] - 'a';

            if (foc[idx] == -1)
                foc[idx] = i;

            loc[idx] = i;
        }

        vector<vector<int>> ranges;
        for (int i = 0; i < 26; i++) {

            if (foc[i] == -1)
                continue;

            int f = foc[i];
            int l = loc[i];

            bool valid = true;
            for (int j = f; j <= l; j++) {
                if (foc[s[j] - 'a'] < f) {
                    valid = false;
                    break;
                }
                l = max(l, loc[s[j] - 'a']);
            }

            if (valid)
                ranges.push_back({f, l});
        }

        vector<string> ans;
        for (auto &r1 : ranges) {

            bool keep = true;

            for (auto &r2 : ranges) {

                if (r1 == r2)
                    continue;
                if (r2[0] >= r1[0] && r2[1] <= r1[1]) {
                    keep = false;
                    break;
                }
            }

            if (keep) {
                ans.push_back(
                    s.substr(r1[0], r1[1] - r1[0] + 1)
                );
            }
        }

        return ans;
    }
};