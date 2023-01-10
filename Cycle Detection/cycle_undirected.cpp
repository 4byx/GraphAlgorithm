class Solution {
  public:
  bool dfs(int curr , int par , int * vis , vector<int> adj[]){
      vis[curr] = 1;
      
      for(auto x : adj[curr]){
          if(!vis[x]){
              if(dfs(x,curr,vis,adj)) return true;
          }else if(x != par){
              return true;
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V];
        memset(vis,0,sizeof(vis));
        bool ans = false;
        for(int i = 0 ; i < V ; i++)
        if(!vis[i])
        ans |= dfs(i,-1,vis,adj);
        
        return ans;
        // Code here
    }
};
