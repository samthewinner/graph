// perform a bfs traversal
// maintain 2 visited arrays, one for the entire graph and the other for the particular path.
// if a node has been visited previously (in vis) and is also being visited in dfsvis, then that node was part of a previous path and this path as well.
// Therefore the graph contains cycle

bool dfs(vector<int>adj[],int *vis,int*dfsvis,int node){
        vis[node] = dfsvis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(adj,vis,dfsvis,it)) return true;
            }
            else if(vis[it] and dfsvis[it]) return true;
        }
        dfsvis[node] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V]={};
        int dfsvis[V]={};
        for(int i=0;i<V;i++){
            if(!vis[i])
                if(dfs(adj,vis,dfsvis,i)) return true;
        }
        return false;
    }
