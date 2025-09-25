class Solution {
public:
    vector<int> topo(int n, vector<vector<int>> &adj){
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++){
            for(int j : adj[i]) indegree[j]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> toporder;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            toporder.push_back(node);
            cout<<"pushed "<<node<<endl;
            for(int edge : adj[node]){
                indegree[edge]--;
                if(indegree[edge] == 0) q.push(edge);
            }
        }

        return (toporder.size() == n) ? toporder : vector<int>();
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &edge : prerequisites){
                int v = edge[0];
                int u = edge[1];
                adj[u].push_back(v);
        }
        return topo(numCourses, adj);

    }
};