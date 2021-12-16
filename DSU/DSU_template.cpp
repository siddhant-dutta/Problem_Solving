class DisjointSet
{
public:
    vector<int> parent, rank;
    DisjointSet(int n): parent(n), rank(n) {
        for(int i=0; i<n; i++)
            parent[i] = i;
    }
    void make_set(int v){
        parent[v] = v;
        rank[v] = 0;
    }
    int find_set(int v){
        if(v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_set (int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            if(rank[a] < rank[b])
                swap(a,b);
            parent[b] = a;
            if(rank[a] == rank[b])
                rank[a]++;
        }
    }
};
