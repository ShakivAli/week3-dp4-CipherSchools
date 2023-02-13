bool dfs(int node, vector<int> adj[], vector<int> &color, unordered_map<int, bool> &vis)
{

    vis[node] = 1;

    for (auto i : adj[node])
    {

        if (!vis[i] and color[node] == 0)
        {

            color[i] = 1;

            bool checkColor = dfs(i, adj, color, vis);

            if (checkColor == 0)
            {

                return 0;
            }
        }

        else if (!vis[i] and color[node] == 1)
        {

            color[i] = 0;

            bool checkColor = dfs(i, adj, color, vis);

            if (checkColor == 0)
            {

                return 0;
            }
        }

        else if (vis[i] == 1 and color[node] == color[i])
        {

            return 0;
        }
    }

    return 1;
}

bool isBipartite(int V, vector<int> adj[])
{

    vector<int> color(V, -1);

    unordered_map<int, bool> vis;

    for (int i = 0; i < V; i++)
    {

        if (!vis[i])
        {

            color[i] = 0;

            bool ans = dfs(i, adj, color, vis);

            if (ans == 0)
            {

                return 0;
            }
        }
    }

    return 1;
}
