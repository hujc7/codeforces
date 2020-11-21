#include <bits/stdc++.h>
// #include <climits>
// #include <iostream>
// #include <vector>
// #include <utility>
using namespace std;
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define fi first
#define se second
#define rep(i,L,R) for (int i = L; i < R; ++i)
#define rrep(i,L,R) for (int i = R; i > L; --i)
#define each(x, a) for (auto& x: a)

using ul = unsigned long;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;
using ii = pair<int, int>;

template<class T> void read(T& x) {
    cin >> x;
}
template <class H, class... T>
void read(H& h, T&... t) {
    cin >> h;
    read(t...);
}
template<class T> void read(vector<T>& v) {
    each(x, v)
        read(x);
}
template<class A> void write(A x) {
	cout << x;
}
template<class H, class... T> void write(const H& h, const T&... t) { 
	write(h);
	write(t...);
}
void print() {
	write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}
template<class T> void print(vector<T>& v) {
    each(x, v)
        write(x, " ");
    write("\n");
}

// code
unordered_map<ll, bool> memo;
const ll offset = 1e6;
ll hcode(int x, int y) {
    return offset*x + y;
}

bool dfs(int x, int y, int d, int k) {
    if (x * x + y * y > d * d) return true;
    if (x > y) swap(x, y);
    ll id = hcode(x, y);

    auto it = memo.find(id);
    if (it != memo.end()) return it->second;
    
    bool left  = dfs(x + k, y, d, k);
    bool right = dfs(x, y + k, d, k);

    // print(x, y, !left || !right);
    return memo[id] = !left || !right;
}

void solve() {
    ll d, k; cin >> d >> k;
    memo.clear();
    cout << (dfs(0, 0, d, k) ? "Ashish" : "Utkarsh") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}