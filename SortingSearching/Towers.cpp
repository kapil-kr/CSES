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

// int binarySearch(vi arr, int beg, int end, int data) {
//     while (beg <= end) {
//         int mid = ((end - beg)/2) + beg;
//         if(arr[mid] == data) {
//             beg = mid +1;
//         }
//         else
//             if(arr[mid] < data) 
//                 beg = mid+1;
//         else    
//             if(arr[mid] > data)
//                 end = mid-1;
//     }
//     if(end >= 0 && arr[end] > data)
//         return end;
//     else
//         if(beg < arr.size()  && arr[beg] > data)
//             return beg;
//     else
//         return -1;
// }

// void solve() {
//     int n, num;
//     vi nums;
//     vi topOfTower;
//     cin>>n;
//     for(int i=0; i<n; i++) {
//         cin>>num;
//         nums.push_back(num);
//     }
//     //int count = 0;
//     bool entry = false;
//     for( int i =0; i<n; i++) {
//         int loc = binarySearch(topOfTower, 0, topOfTower.size()-1, nums[i]);
//         if(loc == -1)
//             topOfTower.push_back(nums[i]);
//         else
//             topOfTower[loc] = nums[i];
//         // for(int j=0; j<topOfTower.size(); j++) {
//             // if(nums[i] < topOfTower[j]) {
//             //     topOfTower[j] = nums[i];
//             //     entry = true;
//             //     break;
//             // }
//         // }
//         // if(!entry)
//         //     topOfTower.push_back(nums[i]);
//         // entry = false;
//     }
//     cout<<topOfTower.size()<<endl;
// }

// modified insetion sort
void solve() {
    int n, num;
    vi nums;
    vi topOfTower;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>num;
        nums.push_back(num);
    }
    topOfTower.push_back(nums[0]);
    int count = 1, j =0;
    for(int i=1; i<n; i++) {
        j = topOfTower.size()-1;
        if(topOfTower[j] <= nums[i]) {
            count++;
            topOfTower.push_back(nums[i]);
        }
        else {
            while (j>=0 && topOfTower[j] > nums[i])
            {
                j--;
            }
            topOfTower[j+1] = nums[i];
        }
    }
    cout<<count<<endl;
    // printall(topOfTower);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen("E:/CSES/SOrtingSearching/test_input.txt", "r", stdin);
    // freopen("E:/CSES/TreeAlgorithms/test_output.txt", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}