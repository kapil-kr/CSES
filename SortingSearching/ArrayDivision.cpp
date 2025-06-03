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

// function to check the feasible partions with the current mid value
bool valid(vi nums, ll mid, int k) {
    int part = 1;
    ll sum = 0;
    for(int i=0; i<nums.size(); i++) {
        if(nums[i] > mid)
            return false;
        if(sum + nums[i] > mid) {
            part++;
            sum = nums[i];
        }
        else {
            sum += nums[i];
        }
    }
    if(part <= k)
        return true;
    else
        return false;
}

void solve() {
    int n, k, num;
    cin>>n>>k;
    ll sum=0;
    vi nums;
    ll ans;
    for(int i=0; i<n; i++) {
        cin>>num;
        sum+=num;
        nums.push_back(num);
    }
    ll beg = 0, end = sum;
    ans = sum;
    while(beg <= end) {
        ll mid = ((end-beg)/2)+beg;
        if(valid(nums, mid, k)) {
            ans = mid;
            end = mid-1;
        } 
        else {
            beg = mid+1; 
        }
    }
    cout<<ans<<endl;
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