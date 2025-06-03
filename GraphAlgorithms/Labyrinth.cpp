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

char grid[1000][1000];

void bfs (int i, int j, int n, int m) {
    int dist =0;
    bool found = false;
    queue<pi> table;
    vector<char> path;
    table.push({i,j});
    while (!table.empty())
    {
        auto f = table.front();
        table.pop();
        i = f.first;
        j = f.second;
        
        if(i-1 >= 0  && (grid[i-1][j] == '.' || grid[i-1][j] == 'B')) {
            if(grid[i-1][j] == 'B') {
                grid[i-1][j] = 'U';
                found =true;
                i = i-1;
                break;
            }
            grid[i-1][j] = 'U';
            table.push({i-1, j});
        }
        
        if(j-1 >= 0 && (grid[i][j-1] == '.' || grid[i][j-1] == 'B')) { 
            if(grid[i][j-1] == 'B') {
                grid[i][j-1] = 'L';
                found =true;
                j= j-1;
                break;
            }
            grid[i][j-1] = 'L';
            table.push({i, j-1});
        }

        if(j+1 < m && (grid[i][j+1] == '.' || grid[i][j+1] == 'B')) {
            if(grid[i][j+1] == 'B') {
                grid[i][j+1] = 'R';
                found =true;
                j = j+1;
                break;
            }
            grid[i][j+1] = 'R';
            table.push({i, j+1});
        }

        if(i+1 < n && (grid[i+1][j] == '.' || grid[i+1][j] == 'B')) {
            if(grid[i+1][j] == 'B') {
                grid[i+1][j] = 'D';
                found =true;
                i = i+1;
                break;
            }
            grid[i+1][j] = 'D';
            table.push({i+1, j});
        }
    }
    if(found) {
        cout<<"YES"<<endl;
        while(grid[i][j] != 'A') {
            dist++;
            path.push_back(grid[i][j]);
            if(grid[i][j] == 'U') 
                i += 1;
            else
            if(grid[i][j] == 'D')
                i -=1;
            else
            if(grid[i][j] == 'L')
                j += 1;
            else
            if(grid[i][j] == 'R')
                j -= 1;
        }
        cout<<dist<<endl;
        reverse(all(path));
        for(auto p : path) {
            cout<<p;
        }
        cout<<"\n";
    } else
    {
        cout<<"NO"<<endl;
    }
}

void solve() {
    int n,m, count = 0;
    char c;
    cin>>n>>m;
    vi path;
    bool ans;
    clr(grid);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            cin>>c;
            grid[i][j] = c;
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 'A') {
                bfs(i,j,n,m);
                break;
            }
        }
    }
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