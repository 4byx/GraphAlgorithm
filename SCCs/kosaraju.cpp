#include <bits/stdc++.h>
using namespace std;


const int N = 2 * 1e5 + 1;
vector<int> gr[N], rgr[N];
int vis[N] , comp[N] , par[N];
vector<int> order;


// for marking nodes in graph visiting to get topo sort

void dfs1(int curr) {
	vis[curr] = 1;
	for (auto x : gr[curr]) {
		if (!vis[x]) {
			dfs1(x);
		}
	}
	order.push_back(curr);
}



// reverse graph traversal to get the order

void dfs2(int curr, int cmp) {
	vis[curr] = 1;
	comp[curr] = cmp;
	for (auto x : rgr[curr]) {
		if (!vis[x]) {
			dfs2(x, cmp);
		}
	}
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n , m;
	cin >> n >> m;

	for (int i = 0 ; i < m ; i++) {
		int a, b;
		cin >> a >> b;

		gr[a].push_back(b);
		rgr[b].push_back(a);
	}
	for (int i = 1 ; i <= n ; i++) {
		if (!vis[i]) dfs1(i);
	}
	reverse(order.begin(), order.end());


	// toposort creation
	// for (auto x : order) {
	// 	cout << x << " ";
	// }


	memset(vis, 0, sizeof(vis));
	int cmp = 1;
	for (auto i : order) {
		if (!vis[i]) dfs2(i, cmp++);
	}

	for (int i = 1 ; i <= n ; i++) {
		cout << i << " " << comp[i] << "\n";
	}
}