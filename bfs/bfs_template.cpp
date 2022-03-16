void bfs(int s, vector<int> adj[], int n){
    // s is the source node from which dfs starts
    // n is the number of nodes
    vector<int> p(n); // parent
    queue<int> q; 
    vector<bool> used(n); // already fired nodes
    // vector<int> d(n); // shortest distance of each node from the source node

    q.push(s);
    used[s] = true;
    p[s] = -1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto u: adj[v]){
            if(!used[u]){
                q.push(u);
                used[u] = true;
                p[u] = v;
                // d[u] = d[v] + 1;
            }
        }
    }
}
