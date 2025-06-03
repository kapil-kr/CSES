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
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef pair<long, long> pl;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<pll> vpll;

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
    int n, m, num;
    cin>>n>>m;
    int locatedAt[n+1], nums[n+1];

    for(int i=1; i<=n; i++) {
        cin>>num;
        nums[i] = num;
        locatedAt[num] = i;
    }
    int count = 1;
    for( int i=2; i<=n; i++) {
        if(locatedAt[i] < locatedAt[i-1]) {
            count++;
        }
    }
    int a, b, temp;
    for(int i=0; i<m; i++) {
        cin>>a>>b;

        if(nums[a] >= 2 && locatedAt[nums[a]] < locatedAt[nums[a]-1] 
                && locatedAt[nums[b]] >= locatedAt[nums[a]-1]) {
                    count--;
        }
        if(nums[a] >= 2 && locatedAt[nums[a]] > locatedAt[nums[a]-1] 
                && locatedAt[nums[b]] <= locatedAt[nums[a]-1]) {
                    count++;
        }
        
        if(nums[a] <= n-1 && locatedAt[nums[a]] < locatedAt[nums[a]+1] 
                && locatedAt[nums[b]] >= locatedAt[nums[a]+1]) {
                    count++;
        }
        if(nums[a] <= n-1 && locatedAt[nums[a]] > locatedAt[nums[a]+1] 
                && locatedAt[nums[b]] <= locatedAt[nums[a]+1]) {
                    count--;
        }

        ///
        if(nums[b] >= 2 && locatedAt[nums[b]] < locatedAt[nums[b]-1] 
                && locatedAt[nums[a]] >= locatedAt[nums[b]-1]) {
                    count--;
        }
        if(nums[b] >= 2 && locatedAt[nums[b]] > locatedAt[nums[b]-1] 
                && locatedAt[nums[a]] <= locatedAt[nums[b]-1]) {
                    count++;
        }
        
        if(nums[b] <= n-1 && locatedAt[nums[b]] < locatedAt[nums[b]+1] 
                && locatedAt[nums[a]] >= locatedAt[nums[b]+1]) {
                    count++;
        }

        if(nums[b] <= n-1 && locatedAt[nums[b]] > locatedAt[nums[b]+1] 
                && locatedAt[nums[a]] <= locatedAt[nums[b]+1]) {
                    count--;
        }
    
        if(abs(nums[a]-nums[b]) == 1) {
            if(nums[a] < nums[b] ){
                if (locatedAt[nums[a]] > locatedAt[nums[b]]){ 
                    count++;
                }
                if (locatedAt[nums[a]] < locatedAt[nums[b]]){ 
                    count--;
                }   
            }   
            else {
                if (locatedAt[nums[b]] > locatedAt[nums[a]]){ 
                    count++;
                }
                if (locatedAt[nums[b]] < locatedAt[nums[a]]){ 
                    count--;
                }
            }
        }
        temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
        temp = locatedAt[nums[a]];
        locatedAt[nums[a]] = locatedAt[nums[b]];
        locatedAt[nums[b]] = temp;
        cout<<count<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen("E:/CSES/SOrtingSearching/test_input.txt", "r", stdin);
    // freopen("E:/CSES/SOrtingSearching/test_output.txt", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}