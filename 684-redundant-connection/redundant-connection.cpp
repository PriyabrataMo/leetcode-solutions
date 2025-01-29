class Disjoint
{
private:
    vector<int> parent , rank , siz;
public:
    Disjoint(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        siz.resize(n+1,1);
        for(int i=0;i<n;i++){
            parent[i] = i ;
        }
    }
    int upar(int x){
        if (x == parent[x]){
            return x;
        }
        return parent[x] = upar(parent[x]);
    }
    void unionbyrank(int x,int y){
        int par_x = upar(x);
        int par_y = upar(y);
        if (par_x == par_y) return;
        if (rank[par_x] > rank[par_y]) {
            parent[par_y] = par_x;
        }
        else if(rank[par_x] < rank[par_y]){
            parent[par_x] = par_y;
        }
        else{
            parent[par_x] = par_y;
            rank[par_x]++;
        }
        return;
    }
    void unionbysize(int x,int y){
        int par_x = upar(x);
        int par_y = upar(y);
        if (par_x == par_y) return;
        if (siz[par_x] > siz[par_y]) {
            parent[par_y] = par_x;
            siz[par_x] +=siz[par_y]; 
        }
        else{
            parent[par_x] = par_y;
            siz[par_y] +=siz[par_x]; 
        }
        return;
    }
   
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        Disjoint d(n);
        for(auto it:edges){
            if(d.upar(it[0])==d.upar(it[1])){
                return it;
            }
            d.unionbysize(it[0] , it[1]);
        }
        return {-1,-1};

    }
};