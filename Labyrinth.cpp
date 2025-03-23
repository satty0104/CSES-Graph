#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
#define ff first
#define ss second
#define NO cout << "NO" << endl
#define YES cout << "YES" << endl
#define pt(x) cout << (x) << endl

ll n, m;

bool isValid(ll x, ll y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m; 
    char s[n][m]; 

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> s[i][j];
        }
    }

    ll stx, sty, ex, ey;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (s[i][j] == 'A') {
                stx = i;
                sty = j;
            }
            if (s[i][j] == 'B') {
                ex = i;
                ey = j;
            }
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, -1));
    vector<vector<int>> prev(n, vector<int>(m, -1));
    int dx[] = {0, 0, 1, -1};
    int dy[] = {-1, 1, 0, 0};

    vis[stx][sty] = 0;
    queue<pi> q;
    q.push({stx, sty});

    while (!q.empty()) {
        auto e = q.front();
        q.pop();
        int x = e.ff;
        int y = e.ss;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny) && vis[nx][ny] == -1 && s[nx][ny] != '#') {
                vis[nx][ny] = 1 + vis[x][y];
                q.push({nx, ny});
                prev[nx][ny] = i;
            }
        }
    }

    if (vis[ex][ey] == -1) {
        NO;
        return 0; 
    }

    YES;
    pt(vis[ex][ey]);
    string ans = "";
    string d = "LRDU";

    while (ex != stx || ey != sty) {
        ans += d[prev[ex][ey]];
        int x = ex - dx[prev[ex][ey]];
        int y = ey - dy[prev[ex][ey]];
        ex = x;
        ey = y;
    }

    reverse(ans.begin(), ans.end());
    pt(ans);
    return 0;
}