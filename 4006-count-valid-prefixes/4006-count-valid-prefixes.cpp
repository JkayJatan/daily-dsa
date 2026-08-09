class Solution {
public:
    int countValidPrefixes(string s) {
        int n = s.length();
        int ans=0;

        int count0 = 0;
        int count1 = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '0') count0++;
            if(s[i] == '1') count1++;

            if(abs(count0-count1) <= 1) ans++;
        }

        return ans;
    }
};