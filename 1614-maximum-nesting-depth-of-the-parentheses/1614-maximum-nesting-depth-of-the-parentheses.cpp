class Solution {
public:
    int maxDepth(string s) {
        int res=0,ans=0;
        for(char c :s){
            if(c=='(')res++;
            else if(c==')')res--;
            ans=max(ans,res);
        }
        return ans;
    }
};