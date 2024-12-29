#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define fastIn                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

void solve()
{
    for (int i = 1; i <= 20; ++i)
    {
        string s = "test_0" + to_string(i) + ".inp";
        string s2 = "test_0" + to_string(i) + ".out";
        ifstream cin(s);
        ofstream cout(s2);
    }
}

signed main()
{
    fastIn;
    ll t = 1;
    while (t--)
    {
        solve();
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}
