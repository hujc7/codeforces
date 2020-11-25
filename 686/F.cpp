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
#define rrep(i,R,L) for (int i = R; i >= L; --i)
#define each(x, a) for (auto& x: a)

using ul = unsigned long;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
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

#define nndl "\n"
// code

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    read(v);

    vector<int> ml = v, mr = v;
    rep(i,1,n) ml[i] = max(ml[i-1], ml[i]);
    rrep(i,n-2,0) mr[i] = max(mr[i+1], mr[i]);

    int max_num = mr.front();
    vi indices;
    rep(i,0,n)
        if (v[i] == max_num)
            indices.pb(i);
        
    int lo = indices[indices.size()/2], hi = lo;
    
    bool found = false;
    while (0 < lo && hi < n) {
        if (ml[lo-1] == max_num && mr[hi+1] == max_num) {
            found = true;
            cout << "YES" << endl;
            cout << lo << " " << hi - lo + 1 << " " << n - 1 - hi << endl;
            break;
        }
        int u = (lo-1 == 0) ? INT_MIN : min(ml[lo-2], v[lo-1]);
        int w = (hi+1 == n-1) ? INT_MIN : min(mr[hi+2], v[hi+1]);
        // cout << lo << " " << hi << " " << u << " " << w << endl;
        if (u > w) {
            max_num = min(max_num, v[lo-1]);
            lo--;
        } else {
            max_num = min(max_num, v[hi+1]);
            hi++;
        }
    }

    if (!found) cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}