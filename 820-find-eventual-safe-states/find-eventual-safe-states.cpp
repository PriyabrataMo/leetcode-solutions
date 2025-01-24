class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        queue<int> q;
        vector<int> indeg(n,0);
        for(int i=0;i<n;i++){
            if(graph[i].size()==0){
                q.push(i);
            }
            
            for(auto &it:graph[i]){
                adj[it].push_back(i);
                indeg[i]++;
            }
            
        }
        vector<int> an(n,0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            an[node]=1;
            for(auto &it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0)q.push(it);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(an[i]==1)ans.push_back(i);
        }
        
        return ans;
    }
};