class Solution {
public:
    bool checkString(string s) {
        if(s.size()<2)return true;
        for(int i=1;i<s.size();++i){
            if(s[i]=='a' && s[i-1]=='b')return false;
        }
        return true;
    }
};