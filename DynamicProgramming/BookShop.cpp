#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define printall(x) for(int i=0; i<x.size(); i++) cout<<x[i]<<" ";
#define PI 3.1415926535897932384626

typedef long long ll;
typedef vector<int> vi;
typedef vector<long> vl;
typedef pair<int,int> pi;
typedef pair<long, long> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;

const int mod = 1e9+7;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n, x, num;
    cin>>n>>x;
    vi price, pages;
    for(int i=0; i<n; i++) {
        cin>>num;
        price.push_back(num);
    }
    for(int i=0; i<n; i++) {
        cin>>num;
        pages.push_back(num);
    }
    int table[n+1][x+1];
    clr(table);
    for( int i=1; i<=n; i++) {
        for(int j=1; j<=x; j++) {
            if(j < price[i-1]) {
                table[i][j] = table[i-1][j];
            } else
            {
                table[i][j] = max(table[i-1][j], 
                                pages[i-1] + table[i-1][j-price[i-1]]);
            }
        }
    }
    cout<<table[n][x];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen("E:/CSES/DynamicProgramming/test_input.txt", "r", stdin);
    // freopen("E:/CSES/DynamicProgramming/test_output.txt", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}