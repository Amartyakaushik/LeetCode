class Solution {
public:
    bool cycle(int numCourses, vector<vector<int>> &adj){
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            for(int course : adj[i]) indegree[course]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> topologicalOrder;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topologicalOrder.push_back(node);
            for(auto &edge : adj[node]){
                indegree[edge]--;
                if(indegree[edge] == 0) q.push(edge);
            }
        }
        if(topologicalOrder.size() != numCourses) return true;
        return false;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &edge : prerequisites){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        return (!cycle(numCourses, adj));
    }
};