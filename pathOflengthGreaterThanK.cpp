// first sort the adjacency list according to the highest weights
// perform a dfs
// backtrack and unvisit each node after it's every adjacent node has been visited

bool dfs( vector<vector<pair<int,int>>> &adj,vector<int>&vis,int k,int val,int node){
           vis[node] = 1;        
           for(auto it:adj[node]){            
               int v = it.first;
               int w = it.second;                                                             
               if(!vis[v]){
                   if(w+val>=k) return true;                      
                     if(dfs(adj,vis,k,val+w,v)) return true;
                }
           }       
           vis[node] = 0;
           return false;
       }

    static bool comp( pair<int,int>&a, pair<int,int>&b){
        return a.second>b.second;    
    }

    bool pathMoreThanK(int V, int E, int k, int *a) 
    { 
       vector<vector<pair<int,int>>>adj(V);
//       create adjacency list
        for(int i=0;i<3*E;i+=3){
            adj[a[i]].push_back({a[i+1],a[i+2]});
            adj[a[i+1]].push_back({a[i],a[i+2]});
        }
//       sort each vector of adjacency list based on higher weights
        for(int i=0;i<V;i++)
        {
        sort(adj[i].begin(),adj[i].end(),comp);
        }        

        vector<int>vis(V,0);
        int val = 0;
        
        if(dfs(adj,vis,k,0,0)) return true;        
        return false;
    } 
