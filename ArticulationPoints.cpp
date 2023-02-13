void dfs(int u) {
    dfs_num[u]=dfs_low[u]=cnt++;
    for(int i=0; i<adj[u].size(); i++) {
        if(dfs_num[adj[u][i]]==0) {
            dfs_parent[adj[u][i]] = u;
            dfs(adj[u][i]);
            if(dfs_low[adj[u][i]] > dfs_num[u]) {
                vector <int> p;
                p.push_back(u);
                p.push_back(adj[u][i]);
                ans.push_back(p);
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[adj[u][i]]);
        } else {
            if(dfs_parent[u]!=adj[u][i]) {
                dfs_low[u] = min(dfs_low[u], dfs_num[adj[u][i]]);    
            }
        }
    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
    memset(dfs_num, 0, sizeof(dfs_num));
    for(int i=0; i<con.size(); i++) {
        adj[con[i][0]].push_back(con[i][1]);
        adj[con[i][1]].push_back(con[i][0]);  
    }
    for(int i=0; i<n; i++) {
        if(dfs_num[i]==0) {
            dfs(i);
        }
    }
    return ans;
}
