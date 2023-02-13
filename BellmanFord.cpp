int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    
    vector<int> dist(n+1,1e9);
    dist[src]=0;
    for(int count = 0;count < n;count++){
        
        for(int i=0;i<m;i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
           
            if(dist[u] != 1e9 && dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;
            }
        }
    
            
    }
    return dist[dest];
}
