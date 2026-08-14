class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0;
        unordered_map<char, int> freq;
        int len = 0;

        for (int r = 0; r < s.size(); ++r) {
            freq[s[r]]++;

            while (freq[s[r]] > 2) {
                freq[s[l]]--;
                l++;
            }

            len = max(len, r - l + 1);
        }

        return len;
    }
};