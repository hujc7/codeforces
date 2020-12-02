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
#define nndl "\n"

using ul = unsigned long;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

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

ll len(const pll& a) {
    return a.se - a.fi;
}

pll getSeg(ll a, ll b) {
    return {min(a, b), max(a, b)};
}

pll getOpt(const pll &a, const pll &b) {
    return {max({a.fi - b.se, b.fi - a.se, 0LL}),
            max({a.se - b.fi, b.se - a.fi, 0LL})};
}

ll x[4], y[4];

void solve() {
    // vector<ll> x(4), y(4);
    rep(i, 0, 4) {
        cin >> x[i] >> y[i];
    }

    // vector<ll> xt(4), yt(4);
    vi index(4);
    iota(all(index), 0);

    ll res = LLONG_MAX;
    do {
        ll cur = 0;
        auto x1 = getSeg(x[index[0]], x[index[3]]);
        auto x2 = getSeg(x[index[1]], x[index[2]]);

        // calculate cost and optimal range
        cur += len(x1) + len(x2);
        auto xSeg = getOpt(x1, x2);

        auto y1 = getSeg(y[index[0]], y[index[1]]);
        auto y2 = getSeg(y[index[2]], y[index[3]]);

        cur += len(y1) + len(y2);
        auto ySeg = getOpt(y1, y2);

        ll extra = min(xSeg.se, ySeg.se) - max(xSeg.fi, ySeg.fi);
        cur += 2 * max(0LL, -extra);
        
        res = min(res, cur);
    } while (next_permutation(all(index)));

    cout << res << nndl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}