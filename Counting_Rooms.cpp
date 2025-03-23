#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define ppb pop_back
#define read(a) for(auto &i: a) cin >> i
#define print(a) for(auto &i: a) cout << i << " "; cout << "\n"
#define read2(a, n, m) for (ll i = 0; i < (n); ++i) for (ll j = 0; j < (m); ++j) cin >> (a)[i][j]
#define print2(a, n, m) for (int i = 0; i < (n); ++i) { for (int j = 0; j < (m); ++j) cout << (a)[i][j] << " "; cout << endl; }

ll rowspan[] = {-1, 0, 1, 0};
ll colspan[] = {0, 1, 0, -1};

ll n, m, cnt = 0;
vector<vector<bool>> vis(n, vector<bool>(m, false));
vector<vector<char>> grid(n, vector<char>(m));

bool isValid(ll x, ll y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(ll x, ll y) {
    vis[x][y] = true;
    for (ll i = 0; i < 4; i++) {
        ll nx = x + rowspan[i];
        ll ny = y + colspan[i];
        if (isValid(nx, ny) && grid[nx][ny] == '.' && !vis[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    read2(grid, n, m);

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }
    
    cout << cnt << endl; 
}