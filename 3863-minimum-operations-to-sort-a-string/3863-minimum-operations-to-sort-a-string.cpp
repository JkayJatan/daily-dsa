class Solution {
public:
    int minOperations(string s) {
        int c=0;
        int n=s.size();
        bool flag=true;
        bool okay=false;
        int a=INT_MIN;
        int b=INT_MAX;
        for(int i=0;i<s.size()-1;i++){
            if(s[i+1]< s[i])flag=false;
            a=max(a,s[i]-'a');
            b=min(b,s[i]-'a');
        }
            a=max(a,s[n-1]-'a');
            b=min(b,s[n-1]-'a');
        if(flag)return 0;
        if(n==2 && !flag)return -1;
        if(s[0]==b+'a'||s[n-1]=='a'+a )return 1;
        for(int i=1;i<=s.size()-2;i++){
            if(s[i]=='a'+a ||s[i]=='a'+b)okay=true;
        }
        if(s[0]=='a'+a && s[n-1]==b+'a' && okay==false)return 3;
        return 2;
        }
};