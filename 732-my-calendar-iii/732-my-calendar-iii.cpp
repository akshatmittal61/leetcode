class MyCalendarThree {
    multiset<pair<int,int>> mp;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp.insert({start,1});
        mp.insert({end,-1});
        int counter = 0;
        int res = 0;
        multiset<pair<int,int>> :: iterator it;
        for(it = mp.begin();it != mp.end();it++){
            counter = counter + it->second;
            res = max(res,counter);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */