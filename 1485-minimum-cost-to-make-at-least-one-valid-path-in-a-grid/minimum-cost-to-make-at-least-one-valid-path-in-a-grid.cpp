class Solution {
public:
    
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;
        pq.push({0 , {0,0}});
        vector<vector<int>> vis(n ,vector<int>(m,INT_MAX));
        vis[0][0]=0;
        int arr[4] = {0,0,1,-1};
        int brr[4] = {1,-1,0,0};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int r = it.second.first;
            int c = it.second.second;
            
            int val = it.first;
            // cout<<r<<" "<<c<<" "<<val<<endl;
            //cout<<grid[r][c];
            if(r==n-1&&c==m-1) return val;
            for(int i=0;i<=3;i++){

                int nr = r+arr[i];
                int nc = c+brr[i];
                int add = 1;
                if(grid[r][c]==i+1)add=0;
                if(nr>=0&&nc>=0&&nr<n&&nc<m){
                    //cout<<nr<<" "<<nc<<" "<<val<<endl;
                    if(vis[nr][nc]>val+add){
                        
                        pq.push({val+add , {nr,nc}});
                        vis[nr][nc]=val+add;
                        
                    }
                    
                }
                
            }


        }
        return -1;
    }
};