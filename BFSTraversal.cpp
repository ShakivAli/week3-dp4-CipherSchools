#include <bits/stdc++.h> 

void bfs(int i,vector<bool> &vis,
unordered_map<int,set<int>> &adj,
vector<int> &ans){
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for(int k : adj[x]){
            if(!vis[k]) {
                q.push(k);
                vis[k] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> ans;
    unordered_map<int,set<int>> adj;
    vector<bool> vis(vertex);
    for( pair<int,int> temp : edges ){
        adj[temp.first].insert(temp.second);
        adj[temp.second].insert(temp.first);
    }
    for(int i=0;i<vertex;i++){
        if(!vis[i]) bfs(i,vis,adj,ans);
    }
    return ans;
}
