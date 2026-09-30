class Solution {
private:
bool check(vector<int>&need,vector<int>&have){
    for(int i=0;i<256;++i){
        if(have[i]<need[i])return false;
    }
    return true;
}
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length())return "";
        vector<int>need(256,0);
        for(char c:t){
            need[c]++;
        }
        vector<int>have(256,0);
        int l=0,n=s.length(),len=n+1,li=-1;
        for(int r=0;r<n;++r){
            have[s[r]]++;
            while(check(need,have)){
                if(len>r-l+1){
                    len=r-l+1;
                    li=l;
                }
                have[s[l]]--;
                l++;
            }
        }
        return li==-1?"":s.substr(li,len);
    }
};