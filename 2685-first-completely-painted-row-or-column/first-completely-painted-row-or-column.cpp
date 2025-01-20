class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> pos((n*m)+1 , vector<int>(2,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pos[mat[i][j]][0] = i;
                pos[mat[i][j]][1] = j;
            }
        }
        int sz = arr.size();
        vector<int> ro(n,0) , co(m,0);
        for(int i=0;i<sz;i++){
            int r = pos[arr[i]][0];
            int c = pos[arr[i]][1];
            ro[r]++;
            co[c]++;
            if(ro[r]>=m||co[c]>=n) return i;
        }
        return -1;
    }
};