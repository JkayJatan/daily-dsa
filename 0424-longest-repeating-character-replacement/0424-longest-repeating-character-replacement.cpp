class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>freq;
        int n=s.length(),l=0,len=0;
        int max_f=0;
        for(int r=0;r<n;++r){
            freq[s[r]]++;
            max_f=max(max_f,freq[s[r]]);
            while(r-l+1-max_f>k){
                freq[s[l]]--;
                l++;
            }
            len=max(len,r-l+1);

        }
        return len;
    }
};