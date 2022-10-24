/*
Author  : Rusiru Thushara (thusharakart)
*/
#include <bits/stdc++.h>
using namespace std;
#define For(i, a, n) for (int i = a; i < n; i++)
#define F(n) for (int i = 0; i < n; ++i)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define sum accumulate
#define ar array
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define len(x) (ll)sizeof(x) / sizeof(x[0])
#define print(vec)        \
    for (auto x : vec)    \
        cout << x << " "; \
    cout << endl;
#define Print(vec)     \
    for (auto x : vec) \
    {                  \
        print(x)       \
    }
#define read(vec)        \
    for (auto &it : vec) \
        cin >> it;
#define en '\n'

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef double db;

mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }

const ll mod = 1000000007;
const int inf = 0x3f3f3f3f;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();

ll powmod(ll a, ll b)
{
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
template <class T>
inline void setmax(T &a, T const &b) { a = max(a, b); }
template <class T>
inline void setmin(T &a, T const &b) { a = min(a, b); }
int cord2pos(ii cord, int col) { return cord.first * col + cord.second; }
ii pos2cord(int pos, int col) { return mp(pos / col, pos % col); }

template <class T>
inline bool isin(unordered_map<T, T> &m, T key)
{
    if (m.find(key) == m.end())
        return false;
    return true;
}

char arr[505][505];
int grid[505][505];
bool vis[505][505];
map<ar<int, 2>, ar<int, 2>> parent;

// D, L, R, U
vector<ar<int, 2>> nei = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

bool is_safe(int i, int j, int n, int m)
{
    if (!vis[i][j] && i < n && i >= 0 && j < m && j >= 0 && (arr[i][j] == '.' || arr[i][j] == 'G' || arr[i][j] == 'P'))
    {
        return true;
    }
    return false;
}

void dfs(int i, int j, int n, int m)
{
    vis[i][j] = true;
    for (auto k : nei)
    {
        if (is_safe(i + k[0], j + k[1], n, m))
        {
            dfs(i + k[0], j + k[1], n, m);
        }
    }
}

ar<int, 2> &dfs2(int i, int j, int n, int m, ar<int, 2> mx_id)
{
    vis[i][j] = true;
    if (grid[i][j] != inf)
    {
        if (grid[mx_id[0]][mx_id[1]] < grid[i][j])
        {
            mx_id = {i, j};
        }
    }

    for (auto k : nei)
    {
        if (is_safe(i + k[0], j + k[1], n, m))
        {
            mx_id = dfs2(i + k[0], j + k[1], n, m, mx_id);
        }
    }
    return mx_id;
}

void bfs(ar<int, 2> start, int n, int m)
{
    queue<ar<int, 2>> q;
    q.push(start);
    grid[start[0]][start[1]] = 0;
    vis[start[0]][start[1]] = true;
    parent[{start[0], start[1]}] = {-1, -1};
    while (q.size() > 0)
    {
        ar<int, 2> u = q.front();
        q.pop();
        for (auto k : nei)
        {
            if (is_safe(u[0] + k[0], u[1] + k[1], n, m))
            {
                vis[u[0] + k[0]][u[1] + k[1]] = true;
                parent[{u[0] + k[0], u[1] + k[1]}] = u;
                setmin(grid[u[0] + k[0]][u[1] + k[1]], grid[u[0]][u[1]] + 1);
                q.push({u[0] + k[0], u[1] + k[1]});
            }
        }
    }
}

char direction(ar<int, 2> start, ar<int, 2> end)
{
    if (start[0] < end[0])
    {
        return 'D';
    }
    if (start[0] > end[0])
    {
        return 'U';
    }
    if (start[1] > end[1])
    {
        return 'L';
    }
    if (start[1] < end[1])
    {
        return 'R';
    }else{
        return '\0';
    }
}

int main()
{
    // vector<vi> adj(row, vi(col, val));
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    int T = t;
    cout<<t<<endl;
    while (t--)
    {

        cout << "Case #" << T - t << ": ";
        int n, m;
        cin >> n >> m;
        ar<int, 2> P;
        vector<ar<int, 2>> G;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> arr[i][j];
                if (arr[i][j] == 'P')
                {
                    P = {i, j};
                }
                else if (arr[i][j] == 'G')
                {
                    G.pb({i, j});
                }
            }
        }

        memset(vis, 0, sizeof(vis));

        for (auto x : G)
        {
            dfs(x[0], x[1], n, m);
        }

        if (vis[P[0]][P[1]] != true)
        {
            cout << "INFINITE ";
            // memset(vis, 0, 505 * 505 * sizeof(int));
            memset(vis, 0, sizeof(vis));
            bfs(P, n, m);
        }

        // memset(grid, 100000, 505 * 505 * sizeof(int));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                grid[i][j] = inf;
            }
        }

        for (auto g : G)
        {
            memset(vis, 0, sizeof(vis));
            bfs(g, n, m);
        }

        // memset(grid, 100000, 505 * 505 * sizeof(int));

        // for (int i = 0; i < n; ++i)
        // {
        //     for (int j = 0; j < m; ++j)
        //     {
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        memset(vis, 0, sizeof(vis));
        ar<int, 2> dest = dfs2(P[0], P[1], n, m, P);

        // cout << "#### " << dest[0] << " " << dest[1] << " ####";

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                grid[i][j] = inf;
                vis[i][j] = false;
            }
        }

        bfs(P, n, m);
        string ans_str = "";
        while (!(parent[dest][0] == -1 && parent[dest][1] == -1))
        {
            ans_str += direction(parent[dest], dest);
            dest = parent[dest];
        }
        reverse(all(ans_str));
        cout << ans_str << endl;
    }
}

/*

4
2 4
P...
....
4 6
...G..
.P.XX.
XX.X..
.....X

6 8
........
.X.X....
PX.X....
.XGXXX..
.XX...X.
....X...

8 11
GX..XX....G
.X..X..XG..
.X.........
...XX......
XXX.GX.....
..X.....XXX
...XXX..XG.
..P..X.X...
*/