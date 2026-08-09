class Solution {
public:
    bool helper(string sub){
        int countZero=0;
        int countOne=0;
        for(char ch: sub){
            if(ch=='1'){
                countOne++;
            }
            if(ch=='0'){
                countZero++;
            }
        }
        if(countZero==0 && countOne==1 || countZero==1 && countOne==0 ){
            return 1;
        }
        if(countZero+1==countOne || countZero==countOne+1 || countZero==countOne ){
            return 1;
        }  
        return 0;
    }
    int countValidPrefixes(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            string sub=s.substr(0,i+1);
            if(helper(sub)){
                ans++;
            }
        }
        return ans;
    }
};