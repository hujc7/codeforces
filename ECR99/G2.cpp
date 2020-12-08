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
const long long INF = 1e18;
const int maxn = 2e5+1;
int n;
struct SegTree {
	ll base, mn;
	SegTree *lc, *rc;
};

SegTree *null = new SegTree;

SegTree *newTree() {
	auto t = new SegTree;
	t->lc = t->rc = null;
	t->base = 0;
	t->mn = INF;
	return t;
}

void add(SegTree *t, ll val) {
	t->base += val;
	t->mn += val;
}

void push(SegTree *t) {
	if (t->lc != null) add(t->lc, t->base);
	if (t->rc != null) add(t->rc, t->base);
	t->base = 0;
}

void pull (SegTree *t) {
	t->mn = min(t->lc->mn, t->rc->mn);
}

void modify(SegTree *&t, int l, int r, int x, ll val) {
	if (t == null) t = newTree();
	if (r - l == 1) {
		t->mn = val;
		return;
	}

	int m = (l + r) / 2;
	push(t);
	if (x < m) modify(t->lc, l, m, x, val);
	else modify(t->rc, m, r, x, val);
	pull(t);
}

ll query(SegTree *t, int l, int r, int x) {
	if (r - l == 1 || t == null) return t->mn;
	int m = (l + r) / 2;
	push(t);
	if (x < m) return query(t->lc, l, m, x);
	else return query(t->rc, m, r, x);
}

SegTree *merge(SegTree *t1, SegTree *t2) {
	if (t1 == null) return t2;
	if (t2 == null) return t1;
	t1->mn = min(t1->mn, t2->mn);
	push(t1);
	push(t2);
	t1->lc = merge(t1->lc, t2->lc);
	t1->rc = merge(t1->rc, t2->rc);
	return t1;
}

SegTree *solve(int now, ll cost, int ban) {
	SegTree *t = null;
	modify(t, 0, maxn, now, cost);
	string opt;
	while (n-- && cin >> opt) {
		if (opt == "end") return t;
		if (opt == "set") {
			int y, v; cin >> y >> v;
			// all value other than y increased cost by v
			// y will have cost which is lowerest before this opt
			ll mn = t->mn;
			add(t, v);
			
			if (y != ban) modify(t, 0, maxn, y, mn);
		} else {
			int y; cin >> y;
			auto t1 = solve(y, query(t, 0, maxn, y), ban);
			modify(t, 0, maxn, y, INF);
			t = merge(t, t1);
		}
	}

	return t;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
	null->mn = INF;
	null->lc = null->rc = null;

	int s; cin >> n >> s;

    auto t = solve(0, 0, s);
	cout << t->mn << nndl;

    return 0;
}