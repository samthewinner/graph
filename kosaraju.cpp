void dfs(vector<int> adj[],vector<int>&vis,int node){
	    vis[node] = 1;
	    for(int it:adj[node]){
	        if(!vis[it])
	            dfs(adj,vis,it);
	    }
	}
	
	void topo(vector<int> adj[],vector<int>&vis ,stack<int>&s,int node){
	    vis[node] = 1;
	    for(int it:adj[node]){
	        if(!vis[it])
	            topo(adj,vis,s,it);
	    }
	    s.push(node);
	}
	
	
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int>s;
        int ans =0;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i])
                topo(adj,vis,s,i);
        }
        vis.clear();
        vis.assign(V,0);
        
        vector<int>a[V];
        
        
         for(int i=0;i<V;i++){
             for(auto it:adj[i]){
                a[it].push_back(i); 
             }
         }
        
        while(!s.empty()){
            int n = s.top();
            s.pop();
            if(!vis[n]){
                ans++;
                dfs(a,vis,n);
            }
        }
        return ans;
    }
