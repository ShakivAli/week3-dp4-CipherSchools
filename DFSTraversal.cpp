void dfs(int i ,unordered_map<int,set<int>> &adj,vector<bool> &vis,vector<int> &ans){
    ans.push_back(i);
    vis[i] = 1;
    for(auto j : adj[i]){
        if(!vis[j]) dfs(j,adj,vis,ans);
    }
    return;
}



vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int,set<int>> adj;
    vector<bool> vis(V,false);
    for(auto i : edges){
        adj[i[0]].insert(i[1]);
        adj[i[1]].insert(i[0]);
    }
    vector<vector<int>> ans;
    for(int i= 0;i < V;i++){
        if(!vis[i]){
            vector<int> temp;
            dfs(i,adj,vis,temp);
            ans.push_back(temp);
            temp.clear();
        }
    }
    return ans;
}
