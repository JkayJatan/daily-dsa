class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n =nums.size();
        long long int b=0;
        for (int i=0;i<n;++i){
            for (int j=i+1;j<n;++j){
              long long int a =nums[i] ;
              long long int x =nums[j];
              long long int g = gcd(a,x); 
              long long int s=(a/g)*(x/g);
              b=max(b,s);
            }
        }
        return b;
    }
};