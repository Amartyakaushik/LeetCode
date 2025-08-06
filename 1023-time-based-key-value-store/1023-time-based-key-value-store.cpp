using valueTimePair = pair<int, string>;
class TimeMap {
public:
    unordered_map<string, vector<valueTimePair> > store;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        store[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if(store.find(key) == store.end()) return "";
        vector<valueTimePair>& entries = store[key];
        string ans;
        auto it = lower_bound(entries.begin(), entries.end(), timestamp, [](const valueTimePair& p, int t){
            return p.first < t;
        });
        // while(left <= right){
        //     int mid = (left + (right - left) + 1) / 2;
        //     if(enteries[mid].first <= timestamp){
        //         ans = enteries[mid].second;
        //         left = mid + 1;
        //     }else{
        //         right = mid - 1;
        //     }
        // }
        if(it == entries.begin() && it->first > timestamp) return "";
        if(it == entries.end() || it->first > timestamp) it--;
    return it->second;
    }
};

// /**
//  * Your TimeMap object will be instantiated and called as such:
//  * TimeMap* obj = new TimeMap();
//  * obj->set(key,value,timestamp);
//  * string param_2 = obj->get(key,timestamp);
//  */