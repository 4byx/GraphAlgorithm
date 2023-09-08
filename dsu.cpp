struct DSU{
        int n;
        vector<int> parent , rank;
        DSU(int n) {
            this->n = n;
            parent.resize(n+1,-1);
            rank.resize(n+1,1);
        }

        int find_parent(int u) {
            if(parent[u]==-1){
                return u;
            }
            return parent[u] = find_parent(parent[u]);
        }

        void merge(int u , int v) {
            u = find_parent(u);
            v = find_parent(v);
            if(u==v) return;
            if(rank[u] < rank[v]) swap(u,v);
            rank[u] += rank[v];
            parent[v] = u;
        }
    };