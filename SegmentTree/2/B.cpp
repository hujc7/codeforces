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
using ll = long long;
struct Node {
    ll sum;

    static Node single(int x) {
        return {x};
    }

    static Node merge(Node l, Node r) {
        return {l.sum + r.sum};
    }

    static const Node INF;
};

const Node Node::INF = {0};

template <class T>
class SegmentTree {
public:
    int size;
    vector<T> v;
    SegmentTree(int  n) {
        size = 1;
        while (size < n) size *= 2;
        v.resize(2*size);
    }

    void build_tree(vector<int>& a) {
        build_tree(a, 0, 0, size);
    }

    void set(int index, int val) {
        set(index, val, 0, 0, size);
    }

    int query(int k) {
        return query(k, 0, 0, size);
    }
// private:
    void build_tree(vector<int>& a, int i, int l, int r) {
        if (r - l == 1) {
            if (l < a.size()) v[i] = T::single(a[l]);
            return;
        }
        int mid = (l + r) / 2;
        build_tree(a, 2*i+1, l, mid);
        build_tree(a, 2*i+2, mid, r);
        v[i] = T::merge(v[2*i+1], v[2*i+2]);
    }

    void set(int index, int val, int i, int l, int r) {
        if (r - l == 1) {
            v[i].sum ^= val;
            return;
        }

        int mid = (l + r) / 2;
        if (index < mid) set(index, val, 2*i+1, l, mid);
        else set(index, val, 2*i+2, mid, r);
        v[i] = T::merge(v[2*i+1], v[2*i+2]);
    }

    int query(int k, int i, int l, int r) {
        if (r - l == 1) return l;
        int mid = l + (r - l)/2;
        int left = v[2*i+1].sum;
        if (k < left) return query(k, 2*i+1, l, mid);
        return query(k - left, 2*i+2, mid, r);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> v(n);
    read(v);
    SegmentTree<Node> st(n);
    st.build_tree(v);
    
    while (m--) {
        int t, c1; cin >> t >> c1;
        if (t == 1) {
            st.set(c1, 1);
        } else {
            cout << st.query(c1) << "\n";
        }
        
    }
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}