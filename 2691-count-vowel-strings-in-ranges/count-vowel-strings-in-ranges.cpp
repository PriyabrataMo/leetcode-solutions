class Solution {
public:
    bool isvowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    vector<int> vowelStrings(vector<string>& arr, vector<vector<int>>& q) {
        int n = arr.size();
        vector<int> vo(n,0); 
       
        for(int i=0;i<n;i++){
            if(isvowel(arr[i][0])&&isvowel(arr[i].back())){
                vo[i] = 1;
            }
        }
        for(int i=1;i<n;i++){
            vo[i] += vo[i-1];
        }
        vector<int> ans;
        for(auto it:q){
            int st = it[0];
            int en = it[1];
            if(st>0){
                ans.push_back(vo[en]-vo[st-1]);
            }
            else{
                ans.push_back(vo[en]);
            }
        }
        return ans;
    }
};