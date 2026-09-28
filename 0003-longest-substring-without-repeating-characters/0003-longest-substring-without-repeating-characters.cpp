class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length(),len=0,l=0;
        unordered_map<char,int>freq;
        for(int r=0;r<n;++r){
            freq[s[r]]++;
            while(freq[s[r]]>1){
                freq[s[l]]--;
                l++;
            }
            len=max(len,r-l+1);
        }
        return len;
    }
};