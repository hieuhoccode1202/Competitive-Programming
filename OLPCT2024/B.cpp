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
int cntDiv(int n, int p)
{

    int ans = 0;
    while (n)
    {
        n /= p;
        ans += n;
    }
    return ans;
}
bool check(int n, int k)
{
    int cnt1 = cntDiv(n, 2);
    int cnt2 = cntDiv(k, 2);
    int cnt3 = cntDiv(n - k, 2);
    return cnt1 == cnt2 + cnt3;
}
void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (auto &i : a)
        cin >> i;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (check(n - 1, i))
        {
            ans ^= a[i];
        }
    }
    cout << ans << endl;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("Test.txt", "r", stdin);
    freopen("Test.ans", "w", stdout);
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
