class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n%2!=0) return false;
        int lo = 0 ; int lc = 0 , op = 0;
        vector<int>a , b;
        for(int i=0;i<n;i++){
            if(locked[i]=='0'){
                op++;
                a.push_back(i);
            }
            else{
                if(s[i]==')'){
                    if(lo>0){
                        lo--;
                        b.pop_back();
                    }
                    else if(op>0){
                        op--;
                        a.pop_back();
                    }
                    else return false;
                }
                else{
                    lo++;
                    b.push_back(i);
                }
            }
        }

        while(!a.empty()&&!b.empty()){
            if(a.back()<b.back()) return false;
            a.pop_back();
            b.pop_back();
        }
        if(b.empty()&&!a.empty()){
            return a.empty()%2==0;
        }
        return b.empty();
    }
};