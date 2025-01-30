class Solution {
public:
    
    bool bfs(int src ,vector<int>& vis, vector<vector<int>>& graph){
        vis[src]=1;
        queue<int> q;
        q.push(src);
        while (!q.empty()) {
            int node = q.front();

            q.pop();
            for(auto it:graph[node]){
                if(vis[it]!=-1){
                    if(vis[it]==vis[node]) return true;
                }
                else{
                    q.push(it);
                    vis[it]=vis[node]?0:1;
                }
            }
            
                   
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();

        vector<int> vis(n, -1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1&&bfs(i , vis , graph)) return false;
        }
       
        return true;
    }
};