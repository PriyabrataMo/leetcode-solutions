class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int,int>> pos((n*m)+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pos[mat[i][j]].first = i;
                pos[mat[i][j]].second = j;
            }
        }
        int sz = arr.size();
        vector<int> ro(n,0) , co(m,0);
        for(int i=0;i<sz;i++){
            int r = pos[arr[i]].first;
            int c = pos[arr[i]].second;
            
            if(++ro[r]>=m||++co[c]>=n) return i;
        }
        return -1;
    }
};