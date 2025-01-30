class Solution {
public:
    set<int> a, b;
    void bfs(int src ,vector<int>& vis, vector<vector<int>>& graph){
        vis[src]=1;
        queue<int> q;
        q.push(src);
        a.insert(src);
        while (!q.empty()) {
            int node = q.front();

            q.pop();
            cout<<node<<endl;
            if (a.find(node) == a.end()) {
                for (auto it : graph[node]) {
                    a.insert(it);
                    if (vis[it] == 0) {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            } else {
                for (auto it : graph[node]) {
                    b.insert(it);
                    if (vis[it] == 0) {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();

        vector<int> vis(n, 0);
        for(int i=0;i<n;i++){
            if(vis[i]==0)bfs(i , vis , graph);
        }
        for(int i=0;i<n;i++){
            if(a.find(i)!=a.end()&&b.find(i)!=b.end())return false;
        }
        return true;
    }
};