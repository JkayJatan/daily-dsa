class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>freq;
        int n=fruits.size(),l=0,len=-1;
        for(int r=0;r<n;++r){
            freq[fruits[r]]++;
            while(freq.size()>2){
                freq[fruits[l]]--;
                if(freq[fruits[l]]==0)freq.erase(fruits[l]);
                l++;
            }
            len=max(len,r-l+1);
        }
        return len;
    }
};