#include<bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<int> dist(vertices,INT_MAX);
    unordered_map<int,list<pair<int,int>>> adj;
    for(auto i : vec){
        adj[i[0]].push_back({i[1],i[2]});
        adj[i[1]].push_back({i[0],i[2]});
    }

    dist[source] = 0;
    set<pair<int,int>> set;
    set.insert({0,0});
    while(!set.empty()){
        auto top = *(set.begin());
        set.erase(top);
        int currdist = top.first;
        int node = top.second;
        for(auto neigh : adj[node]){
            if(currdist + neigh.second < dist[neigh.first]){
                 pair<int,int> record = make_pair(dist[neigh.first],neigh.first);
                 if(set.find(record) != set.end()) set.erase(record);
                 dist[neigh.first] = currdist + neigh.second;
                 set.insert({dist[neigh.first], neigh.first});
            }
        }
    }

    return dist;
}
