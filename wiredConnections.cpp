 void dfs(vector<int>&vis,vector<int>adj[],int node){
        vis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]) dfs(vis,adj,it);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& c) {
        
        vector<int>vis(n,0);
        vector<int>adj[n];
        
        for(int i=0;i<c.size();i++){            
                adj[c[i][0]].push_back(c[i][1]);
                adj[c[i][1]].push_back(c[i][0]);            
        }
        
        int comp=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                comp++;
                dfs(vis,adj,i);
            }
        }
        
        int e = c.size();        
        int red = e - (n-comp+1);
        if(red >= comp-2) return comp-1;
        return -1;                                                       
        if(red >= comp-1) return comp-1 ;
        return -1;                                                         
    }
