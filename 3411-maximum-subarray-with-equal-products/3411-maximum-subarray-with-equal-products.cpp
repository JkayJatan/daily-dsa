class Solution {
public:
    int maxLength(vector<int>& nums) {
        const int MASKS[] = {0, 0, 1, 2, 1, 4, 3, 8, 1, 2, 5};

        int res = min((int)nums.size(), 2);
        int window_mask = 0;
        int start = 0;

        for (int end = 0; end < nums.size(); end++) {
            int m = MASKS[nums[end]];

            while (window_mask & m) {
                window_mask ^= MASKS[nums[start]];
                start++;
            }

            window_mask |= m;

            int curr_len = end - start + 1;
            if (curr_len > res) {
                res = curr_len;
            }
        }

        return res;
    }
};