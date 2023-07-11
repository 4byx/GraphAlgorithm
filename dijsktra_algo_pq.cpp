vector<pair<int, int>> gr[101];
vector<int> dis;

int djisktra(int source , int n ) {
    dis.resize(101);
    for (int i = 1; i <= 100 ; i++) {
        dis[i] = INT_MAX;
    }
    dis[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [distill , node] = pq.top();
        pq.pop();
        if (distill != dis[node]) continue;

        for (auto x : gr[node]) {
            auto [distance , nbr] = x;
            if (distill + distance < dis[nbr]) {
                dis[nbr] = distill + distance;
                pq.push({dis[nbr] , nbr});
            }
        }
    }

    return dis[n];
}