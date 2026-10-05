class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        int curr=arr[0],ans=arr[0],del=-10000;
        for(int i=1;i<n;++i){
            int p_curr=curr,p_del=del;
            curr=max(arr[i],arr[i]+p_curr);
            del=max(p_curr,p_del+arr[i]);
            ans=max({ans,curr,del});
        }
        return ans;
    }
};