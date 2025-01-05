class MyCalendarTwo {
public:
    map<int,int> mpp;
    MyCalendarTwo() {
        
    }
    
    bool book(int st, int en) {
        mpp[st]++;
        mpp[en]--;
        int c = 0;
        for(auto it:mpp){
            c+=it.second;
            if(c>=3){
                mpp[st]--;
                mpp[en]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */