 vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        vector<vector<int>> ans(V) ;
        for(int i = 0;i<V;i++){
            ans[i].push_back(i);
            for(auto it: adj[i]){
                ans[i].push_back(it);
                
            }
                
        }
        return ans;
    }
