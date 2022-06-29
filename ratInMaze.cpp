// perfoem a dfs.
// at each node ,mark it as visited and call the dfs for all the other nodes.
void dfs(vector<vector<int>> m,int n,vector<string>&ans,string temp,int x,int y){
        if(x<0 || x>=n || y<0 || y>=n || m[x][y] == 0) return;
        if(x == n-1 and y == n-1){
            ans.push_back(temp);
            return;
        }
        int rx[4] = {1,0,0,-1};
        int ry[4] = {0,-1,1,0};
        string s = "DLRU";
        m[x][y] = 0;
        for(int i=0;i<4;i++){
            int nx = x+rx[i];
            int ny = y+ry[i];
            dfs(m,n,ans,temp+s[i],nx,ny);
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        if(m.size() == 0) return ans;
        if(m[0][0] == 0 || m[n-1][n-1] == 0) return ans;
        dfs(m,n,ans,"",0,0);
        return ans;
    }
