 void dfs(vector<int>adj[],vector<int>&dis,vector<int>&low,vector<int>&parent,vector<bool>&ap,int &timer,int node){
      low[node] = dis[node] = timer;
      timer++;
      int child = 0;
      for(auto it:adj[node]){
        //   not visited
          if(dis[it] == -1){
              parent[it] = node;
              child++;
              
              dfs(adj,dis,low,parent,ap,timer,it);
              
              low[node] = min(low[node],low[it]);
              
              if(parent[node] == -1 && child>1 ){
                      ap[node] = true;
              }
              if(parent[node] != -1 && low[it] >= dis[node]){
                    ap[node] = true;
              }
          }
          else if(it!=parent[node]){
                  low[node] = min(low[node],dis[it]);
              }
              
          
      }
  }
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int>dis(V,-1);
        vector<int>low(V,-1);
        vector<int>parent(V,-1);
        vector<bool>ap(V,false);int timer = 0;
        for(int i=0;i<V;i++){
            if(dis[i]==-1){
                dfs(adj,dis,low,parent,ap,timer,i);
            }
                
        }
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(ap[i])
            ans.push_back(i);
        }
        if(ans.size() == 0)ans.push_back(-1);
        return ans;
    }
