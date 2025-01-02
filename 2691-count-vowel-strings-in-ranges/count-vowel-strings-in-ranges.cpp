class Solution {
public:
    
    vector<int> vowelStrings(vector<string>& arr, vector<vector<int>>& q) {
        int n = arr.size();
        vector<int> vo(n,0); 
       
        for(int i=0;i<n;i++){
            char c = arr[i][0];
            bool f1 = c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
            c = arr[i].back();
            bool f2 = c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
            
            if(f1&&f2){
                vo[i] = 1;
            }
            if(i>0){
                vo[i]+=vo[i-1];
            }
        }
        
        vector<int> ans;
        for(auto it:q){
           
            if(it[0]>0){
                ans.push_back(vo[it[1]]-vo[it[0]-1]);
            }
            else{
                ans.push_back(vo[it[1]]);
            }
        }
        return ans;
    }
};