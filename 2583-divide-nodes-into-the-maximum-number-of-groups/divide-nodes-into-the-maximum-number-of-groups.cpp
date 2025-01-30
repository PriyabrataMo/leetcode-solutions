int n;
bool bfs(int src, vector<int>& vis, vector<vector<int>>& graph) {
    vis[src] = 1;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto it : graph[node]) {
            if (vis[it] != -1) {
                if (vis[it] == vis[node])
                    return true;
            } else {
                q.push(it);
                vis[it] = vis[node] ? 0 : 1;
            }
        }
    }
    return false;
}
bool isBipartite(vector<vector<int>>& graph) {

    vector<int> vis(n, -1);
    for (int i = 0; i < n; i++) {
        if (vis[i] == -1 && bfs(i, vis, graph))
            return false;
    }

    return true;
}
vector<int> bfs2(int src, vector<int>& vis, vector<vector<int>>& graph) {
    vis[src] = 1;
    queue<int> q;
    q.push(src);
    vector<int> ans;
    ans.push_back(src);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto it : graph[node]) {
            if (vis[it] == 0) {
                ans.push_back(it);
                q.push(it);
                vis[it] = 1;
            }
        }
    }
    return ans;
}
int bfs3(int src, vector<vector<int>>& graph) {
    vector<int> vis(n, 0);
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, 1});
    int ans = 0;
    while (!q.empty()) {
        auto no = q.front();
        int node = no.first;
        int dep = no.second;
        ans = max(ans, dep);
        q.pop();
        for (auto it : graph[node]) {
            if (vis[it] == 0) {

                q.push({it, dep + 1});
                vis[it] = 1;
            }
        }
    }
    return ans;
}
class Solution {
public:
    

    int magnificentSets(int nn, vector<vector<int>>& edges) {
        n = nn;
        vector<vector<int>> graph(n);
        for (auto it : edges) {
            graph[it[0]-1].push_back(it[1]-1);
            graph[it[1]-1].push_back(it[0]-1);
        }
        if (isBipartite(graph) == false)
            return -1;
        vector<int> vis(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                vector<int> comp;
                comp = bfs2(i, vis, graph);
                int temp = 0;
                for (auto it : comp) {
                    temp = max(temp, bfs3(it , graph));
                }
                ans += temp;
            }
        }
        return ans;
    }
};