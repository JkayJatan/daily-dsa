class Solution {
private:
    bool canreach(vector<vector<pair<int,int>>>& adj,long long k,int len){
        int n=adj.size();
        vector<long long> vis(n,-1);
        vis[0]=k;
        priority_queue<pair<long long,int>> pq;
        pq.push({k,0});
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            long long rem=temp.first;
            int node=temp.second;
            if(vis[node]>rem){
                continue;
            }
            for(int i=0;i<adj[node].size();i++){
                int next=adj[node][i].first,wt=adj[node][i].second;
                if(vis[next]>rem-wt){
                    continue;
                }
                if(wt>=len && rem>=wt){
                    if(next==n-1){
                        return true;
                    }
                    vis[next]=max(vis[next],rem-wt);
                    pq.push({rem-wt,next});
                }
            }
        }
        if(vis[n-1]!=-1){
            return true;
        }
        return false;
    }
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            if(online[edges[i][0]] && online[edges[i][1]]){
                adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            }
        }
        int low=0,hi=INT_MAX,ans=-1;
        while(low<=hi){
            int mid=low+(hi-low)/2;
            bool con=canreach(adj,k,mid);
            if(con){
                ans=mid;
                low=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return ans;
    }
};