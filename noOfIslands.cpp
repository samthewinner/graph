void dfs(vector<vector<char>>&g,int x,int y){
        g[x][y] = '0';
        int dx[8] = {-1,-1,-1,0,0,1,1,1,};
        int dy[8] = {-1,0,1,-1,1,-1,0,1};
        for(int i=0;i<8;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 and nx<g.size() and ny>=0 and ny<g[0].size() and g[nx][ny] == '1')
                dfs(g,nx,ny);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid,i,j);
                }
                    
            }
        }
        return ans;
    }
