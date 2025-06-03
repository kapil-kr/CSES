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

multiset<int> lessMedian;
multiset<int> greaterMedian;    

void insertMult(int val, int k) {
    auto currMedian = *lessMedian.rbegin(); 
	if(val > currMedian){
		greaterMedian.insert(val);
		if(greaterMedian.size() > k/2) {
			lessMedian.insert(*greaterMedian.begin());
			greaterMedian.erase(greaterMedian.find(*greaterMedian.begin()));
		}
	}
	else{
		lessMedian.insert(val);
		if(lessMedian.size() > (k + 1)/2) {
			greaterMedian.insert(*lessMedian.rbegin());
			lessMedian.erase(lessMedian.find(*lessMedian.rbegin()));
		}
	}
} 

void eraseMult(int val) {
    auto it = greaterMedian.find(val);
    if(it != greaterMedian.end()) 
        greaterMedian.erase(it);
	else 
        lessMedian.erase(lessMedian.find(val));
        
	if(lessMedian.empty()) {
		lessMedian.insert(*greaterMedian.begin());
		greaterMedian.erase(greaterMedian.find(*greaterMedian.begin()));
	}
}

void solve() {
    int n, k, num;
    cin>>n>>k;
    int nums[n];
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }
    if(k==1) {
        for(int i=0; i<n; i++) {
            cout<<nums[i]<<" ";
        }  
        return; 
    }
    lessMedian.insert(nums[0]);
    for( int i=1; i<k; i++) {
        insertMult(nums[i], k);
    }
    cout<<*lessMedian.rbegin()<< " ";
	for(int i = k; i < n; i++){  
        eraseMult(nums[i-k]);
        insertMult(nums[i], k);
		cout <<*lessMedian.rbegin()<<" ";
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