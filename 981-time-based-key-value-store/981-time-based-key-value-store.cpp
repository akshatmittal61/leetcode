class TimeMap {
public:
    map<string  , map<int ,string >> m ;
    map<string , vector<int> > mm ; 
    TimeMap() {
        
    }
    
    void set(string key, string value, int time) {
        m[key][time]= value ; 
      mm[key].push_back(time) ; 
    }
    
    string get(string key, int time) {
        
        int t=-1;
        // vector<int>v = mm[key]; 
        // if we take it in a vector it give MLE
        int l =0 , r = mm[key].size()-1; 
        
        while(l<=r)
        {
            int mid = (l+r)/2; 
            if(mm[key][mid]<=time)
            {
                l= mid+1 ;
                t = mm[key][mid]; 
            }
            else
               r =mid-1 ;  
            
        }
        
        if(t==-1)
            return "" ; 
        return m[key][t]  ;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */