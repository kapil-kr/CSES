#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define lli long long int
#define ulli unsigned long long int
#define lld long double
#define MP make_pair
#define PB push_back
#define MT make_tuple
#define rep0(i,n) for(lli i=0;i<n;i++)
#define rep1(i,n) for(lli i=1;i<=n;i++)
#define rep(i,x,y) for(lli i=x;i<=y;i++)
#define per1(i,n) for(lli i=n;i>0;i--)
#define per0(i,n) for(lli i=n-1;i>=0;i--)
#define per(i,x,y) for(lli i=x;i>=y;i--)
#define ff first
#define ss second
#define pli pair <lli,lli>
#define plli pair <pli,lli>
#define vi vector<int>
#define vli vector<long long int>
#define vs vector<string>
#define vc vector<char>
#define vipair vector<pair<int,int>>
#define vlipair vector<pair<lli,lli>>
#define all(c) c.begin(),c.end()
#define print(c) for(lli i=0;i<c.size();i++) cout<<c[i]<<' '
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define sz(a) a.size()
#define INF64 1e18
#define INF32 1e9
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const lli mod = 1e9+7;
const lld eps = 1e-9;
const lli maxn = 5*1e5 + 10;
const lli max_nodes=15;
const lli alpha=26;
const lli max_log=19;
lli fact[maxn+3];
template <typename T> void add(T &a, T b){a += b;if(a >= mod)a -= mod;}
template <typename T> void sub(T &a, T b){a -= b;if(a < 0)a += mod;}
template <typename T> void mul(T &a, T b){a *= b;if(a >= mod)a %= mod;}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void calcfac() {fact[0]=1;fact[1]=1;rep(i,2,maxn) fact[i] = (fact[i-1]*i)%mod;}
lli gcd(lli a,lli b) {if(b==0) return a; return gcd(b,a%b);}
lli gcdext(lli a,lli b,lli &x,lli &y){if(a==0){x=0;y=1;return b;}lli x1,y1;lli g=gcdext(b%a,a,x1,y1);x=y1-(b/a)*x1;y=x1;return g;}
lli fastexp(lli a,lli b) {a%=mod;lli res=1;while(b>0){if(b&1) res=(res*a)%mod; a=(a*a)%mod; b>>=1;}return res;}
lli inverse(lli n) {return fastexp(n,mod-2);}
lli ncr(lli n , lli r){if(n < r|| (n < 0) || (r < 0)) return 0 ; if(r==0) return 1; return (((fact[n] * inverse(fact[r]))%mod)*inverse(fact[n-r]))%mod;}
int pct(int x) { return __builtin_popcount(x);} //number of set bits 
int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
// TRIE
// int triex[max_nodes][alpha],globcount=1;
// void build_triex(string s) {int i = 0, v = 0;while(i < s.size()){if(triex[v][s[i]-'a'] == -1)v = triex[v][s[i++]-'a'] = globcount++ ;else v = triex[v][s[i++]-'a'];}}
// SPARSE TABLE
// lli logarithm[maxn+1];
// void calclog() {logarithm[1]=0;for(lli i=2;i<=maxn;i++)logarithm[i]=logarithm[i/2]+1;}
// lli sp_table[maxn][max_log+1];
// void build_sp(vli &nums) {calclog();lli n=nums.size();rep0(i,n)sp_table[i][0]=nums[i];for(lli j=1;j<=max_log;j++){for(lli i=0;i+(1<<j)<=n;i++){sp_table[i][j]=min(sp_table[i][j-1],sp_table[i+(1<<(j-1))][j-1]);}}}
// lli query_sp(lli l,lli r) {lli j=logarithm[r-l+1];return min(sp_table[l][j],sp_table[r-(1<<j)+1][j]);}
 
 
void solve() {
	string s;
	cin>>s;
	lli mx=1,curr=1;
	rep1(i,s.size()-1) {
		if(s[i]==s[i-1]) {
			curr++; mx = max(mx,curr);
		}
		else curr=1;
	}
	cout<<mx;
}
    
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int TC;
    TC=1;
    // cin>>TC;
    for(int t=0;t<TC;t++) solve();
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}