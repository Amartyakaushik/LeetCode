class Solution {
public:
    void dfs(vector<vector<int>>& adj, int start, int destination, vector<bool> &visited, bool &ans){
        if(start == destination){
            ans = true;
            return;
        }
        visited[start] = true;
        for(auto& edge : adj[start]){
            if(!visited[edge]){
                visited[edge] = true;
                dfs(adj, edge, destination, visited, ans);
                if(ans) return;
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        bool ans = false;
        vector<bool> visited(n, false);
        dfs(adj, source, destination, visited, ans);
        return ans;
    }
};