#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

class DSU {
public:
    vector<int> parent, size;
    
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] == i) return i; 
        return parent[i] = find(parent[i]); 
    }

    void Union(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return; 
        
        if (size[px] > size[py]) { 
            parent[py] = px;
            size[px] += size[py];
        } else {
            parent[px] = py;
            size[py] += size[px]; 
        }
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    
    for (int j = 0; j < m; j++) {
        int u, v;
        cin >> u >> v;
        dsu.Union(u, v);  
    }

    for (int i = 1; i <= n; i++) {
        if (dsu.find(i) == i) {
            ans.push_back(i);
        }
    }

    cout << ans.size() - 1 << endl;
    for (int i = 0; i < ans.size() - 1; i++) {
        cout << ans[i] << " " << ans[i + 1] << endl;
    }
    return 0;
}
