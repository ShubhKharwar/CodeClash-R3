#include <bits/stdc++.h>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

int main() {
	fastio();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("Error.txt", "w", stderr);
#endif

	ll n ; cin >> n;
	vector<ll> a(n, 0);

	for (ll i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	sort(all(a));


	vector<ll> hash(a[n - 1] + 1);

	for (ll i = 0; i < n; ++i)
	{
		hash[a[i]]++;
	}

	vector<ll> dp(a[n - 1] + 1);

	dp[1] = hash[1] * 1;
	if (2 <= a[n - 1]) dp[2] = hash[2] * 2;
	if (3 <= a[n - 1]) dp[3] = max(dp[1] + 3 * hash[3] , dp[2]);

	for (ll i = 4; i <= a[n - 1] ; ++i)
	{
		vector<ll> tmp;

		tmp.pb(dp[i - 1]);
		for (ll j = i - 2; j >= i - 3; --j)
		{
			tmp.pb(dp[j] + (i * hash[i]));
		}
		sort(all(tmp));

		dp[i] = tmp[sz(tmp) - 1];
	}

	cout << dp[a[n - 1]] << nline;


	return 0;
}
