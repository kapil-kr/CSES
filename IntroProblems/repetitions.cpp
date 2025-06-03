#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(x), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626

typedef long long ll;
typedef vector<int> vi;
typedef vector<long> vl;
typedef pair<int,int> pi;
typedef pair<long, long> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;

void solve() {
    string s;
    getline(cin, s);
    unordered_map<char, int> lookup;
    int j, i=0;
    int count = 0;
    while(i<s.length()-1) {
        j = i+1;
        count = 1;
        while(s[i] == s[j]) {
            count++;   
            j++;
        }
        if(count > lookup[s[i]]) {
            lookup[s[i]] = count;
        }
        i = j;
    }
    int max = 1;
    for(auto i: lookup) {
        if(i.second > max) {
            max = i.second;
        }
    }
    cout<<max;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    //cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}