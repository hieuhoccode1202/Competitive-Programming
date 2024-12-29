#include <bits/stdc++.h>

using namespace std;

const string NAME = "Test";
const int NTEST = 100;
#define ll long long
#define rd(a, b) uniform_int_distribution<int>(a, b)(rnd)
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

void MakeTest()
{
    for (int i = 1; i <= 20; ++i)
    {
        string s = "test_0";
        s = s + to_string(i);
        s += ".inp";
        ofstream cout(s);
        if (i <= 10)
        {
            int n = rd(1, 1e3);
            cout << n << endl;
            for (int i = 0; i < n; ++i)
            {
                int x = rd(-1e9, 1e9);
                cout << x << " ";
            }
        }
        else
        {

            int n = rd(1e5, 1e6);
            if (i == 20)
            {
                n = 1e6;
            }
            cout << n << endl;
            for (int i = 0; i < n; ++i)
            {
                int x = rd(-1e8, 1e8);
                cout << x << " ";
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    MakeTest();
    // for (int iTest = 1; iTest <= NTEST; iTest++)
    // {
    //     system((NAME + ".exe").c_str());
    //     system((NAME + "_trau.exe").c_str());
    //     if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
    //     {
    //         cout << "Test " << iTest << ": WRONG!\n";
    //         return 0;
    //     }
    //     cout << "Test " << iTest << ": CORRECT!\n";
    // }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";

    return 0;
}