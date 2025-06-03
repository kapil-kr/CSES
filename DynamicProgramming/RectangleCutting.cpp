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
int static table[501][501];

int solveDP(int a, int b) {
    int lPart, rPart;
    if(a == 0 || b==0)
        return 0;
    if(a==b)
        return 0;
    
    if(table[a][b] != -1)
        return table[a][b];
    
    int moves = INT_MAX;
    for(int i=1; i<a; i++) {
        if(table[i][b] != -1) {
            lPart = table[i][b]; 
        } else
        {
            lPart = solveDP(i,b);
            table[i][b] = lPart;
        }

        if(table[a-i][b] != -1) {
            rPart = table[a-i][b]; 
        } else
        {
            rPart = solveDP(a-i,b);
            table[a-i][b] = rPart;
        }
        
        int temp = 1 + lPart + rPart;
        //int temp = 1 + solveDP(i,b) + solveDP(a-i,b);
        moves = min(moves, temp);
    }
    for(int j=1; j<b; j++) {
        if(table[j][a] != -1) {
            lPart = table[j][a]; 
        } else
        {
            lPart = solveDP(j,a);
            table[j][a] = lPart;
        }

        if(table[b-j][a] != -1) {
            rPart = table[b-j][a]; 
        } else
        {
            rPart = solveDP(b-j,a);
            table[b-j][a] = rPart;
        }
        
        int temp = 1 + lPart + rPart;
        //int temp = 1 + solveDP(j,a) + solveDP(b-j,a);
        moves = min(moves, temp);
    }
    table[a][b] = moves;
    return moves;
}

void solve() {
    int a,b;
    cin>>a>>b;
    memset(table, -1, sizeof(table));
    
    int ans = solveDP(a, b);
    
    cout<<ans;
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