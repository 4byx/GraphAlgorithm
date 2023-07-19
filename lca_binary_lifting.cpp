const int N = 1e5+5  , M = 21;
int vis[N] , Par[N][M] , dep[N];
vector<int> gr[N];

void dfs(int curr , int parent) {
	dep[curr] = dep[parent]+1;
	vis[curr] = 1;
	Par[curr][0] = parent;
	for(auto x : gr[curr]) if(!vis[x]) dfs(x,curr);
}

int lift(int node , int dist) {
	for(int l = 0 ; l < M  ; l++) {
		if(node!=-1) if((dist>>l)&1) node = Par[node][l];
	}
	return node;
}

int lca(int a , int b) {
	a = lift(a , dep[a] - min(dep[a],dep[b]));
	b = lift(b , dep[b] - min(dep[a],dep[b]));
	if(a==b) return a;
	for (int j = M - 1; j >= 0; j--) {
		if (Par[a][j] != Par[b][j]) {
			a = Par[a][j];
			b = Par[b][j];
		}
	}
	return Par[a][0];
}