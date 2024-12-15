class Solution {
public:
    double val(double a ,double b){
        return (a+1)/(b+1) -(a/b);
    }
    double maxAverageRatio(vector<vector<int>>& arr, int k) {
        priority_queue<pair<double, int>> pq;
                       
        int n = arr.size();
        double sum = 0;
        for(int i=0;i<n;i++){
            double v = val((double)arr[i][0] , (double)arr[i][1]);
            sum+=(double)arr[i][0] / (double)arr[i][1];
            pq.push({v, i});
            // cout<<val(arr[i][0] , arr[i][1])<<endl;
        }
        while(k>0){
            auto it = pq.top();
            pq.pop();
            
            int ind = it.second;
            sum-=(double)arr[ind][0] / (double)arr[ind][1];
            arr[ind][0]++;
            arr[ind][1]++;
            sum+=(double)arr[ind][0] / (double)arr[ind][1];
            double v = val((double)arr[ind][0] , (double)arr[ind][1]);
            pq.push({v ,ind});
            k--;

        }     
        
        return sum/n;       
    }
};