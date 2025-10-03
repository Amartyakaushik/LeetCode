class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for(auto &edge : times){
            int src = edge[0];
            int target = edge[1];
            int time = edge[2];
            adj[src].push_back({target, time});
        } 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            auto [tem, node] = pq.top();
            cout<<"poping: "<<tem<<" "<<node<<endl;
            pq.pop();
            if(tem > dist[node]) continue;
            for(auto &[nei, time] : adj[node]){
                if((dist[node] + time) < dist[nei]){
                    dist[nei] = dist[node] + time;
                    cout<<"pushing: "<<dist[nei]<<" "<<nei<<endl;
                    pq.push({dist[nei], nei});
                }
            }
        }
        int maxTime = 0;
        cout<<endl<<endl<<endl;
        for(int i : dist) cout<<i<<endl;
        for(int i = 1; i < n + 1; i++){
            if(dist[i] == INT_MAX) return -1;
            cout<<"checking: "<<dist[i]<<endl;
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};