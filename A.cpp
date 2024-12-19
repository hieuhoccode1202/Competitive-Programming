#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define fastIn                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const ll mod = 1e9 + 7;
const ll Max = 1e9;
const int N = 1e6 + 1;
#define endl "\n"
int n, m, k;
bool vis[1001][1001];
int p[N];
int dp[1001][1001];
void init()
{
    p[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        p[i] = p[i - 1] * i;
        p[i] %= mod;
    }
}
int powmod(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
        {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b /= 2;
    }
    return res;
}
int C(int k1, int n1)
{
    if (k1 > n1)
        return 0;
    int t = p[n1];
    int x1 = p[k1], x2 = p[n1 - k1];
    x1 = powmod(x1, mod - 2), x2 = powmod(x2, mod - 2);
    t *= x1;
    t %= mod;
    t *= x2;
    t %= mod;
    return t;
}
void solve()
{
    init();
    cin >> n >> m >> k;
    int x, y;
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        vis[x][y] = 1;
    }
    dp[1][1] = 1;
    int sizex = min(1000LL, n);
    int sizey = min(1000LL, m);
    for (int i = 1; i <= sizex; ++i)
    {
        for (int j = 1; j <= sizey; ++j)
        {
            if (vis[i][j])
                continue;
            if (!vis[i - 1][j])
                dp[i][j] += dp[i - 1][j];
            dp[i][j] %= mod;
            if (!vis[i][j - 1])
                dp[i][j] += dp[i][j - 1];
            dp[i][j] %= mod;
        }
    }
    if (n <= 1000 && m <= 1000)
    {
        cout << dp[n][m] << endl;
        return;
    }
    if (k == 0)
    {
        cout << C(n - 1, n + m - 2) << endl;
        return;
    }

    int ans = 0;
    for (int i = 1; i <= sizex; ++i)
    {
        for (int j = 1; j <= sizey; ++j)
        {
            if (i == sizex && i < n)
            {
                ans += (dp[i][j] * C(m - j, n + m - i - j - 1)) % mod;
            }
                ans%= mod;
            if (j == sizey && j < m)
                ans += (dp[i][j] * C(n - i, n + m - i - j - 1)) % mod;
            ans %= mod;
        }
    }
    cout << ans << endl;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("Test.txt", "r", stdin);
    freopen("Test.out", "w", stdout);
#endif // ONLINE_JUDGE

    fastIn;
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}
