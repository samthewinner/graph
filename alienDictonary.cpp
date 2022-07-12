void dfs(vector<vector<int>> &adj, string &ans,int*vis,int node){
        vis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(adj,ans,vis,it);
            }
        }
        char ad = node + 'a';
        ans = ad + ans;
    }
    
    string findOrder(string dict[], int n, int k) {
        // if(k==1 || n==1) {
        //     string emp = "a";
        //     return emp;
        // }
        vector<vector<int>> adj(k);
        //create adjacency list
        for(int i=0;i<n-1;i++){
            string f = dict[i];
            string s = dict[i+1];
            for(int j=0;j<min(f.size(),s.size());j++){
                if(f[j] != s[j]) 
                {
                    adj[f[j]-'a'].push_back(s[j]-'a');
                    break;
                }
            }
        }
        int vis[k] = {0};
        string ans = "";
        for(int i=0;i<k;i++){
            if(!vis[i]){
                dfs(adj,ans,vis,i);
            }
        }
        
        return ans;
    }
