int prims(int n, vector<pair<int, int>> gr[]) {
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // weight node
    int ans = 0;
    vector<bool> vis(n, 0);
    while (!pq.empty()) {
        auto [weight, node] = pq.top();
        pq.pop();
        if (vis[node]) continue;
        vis[node] = 1;
        ans += weight;

        for (auto nbr : gr[node]) {
            auto [nbrnode, edge] = nbr;
            if (!vis[nbrnode]) {
                pq.push({edge, nbrnode});
            }
        }
    }
    return ans;
}