#include<bits/stdc++.h>
using namespace std;
const bool debug = false;
#define log(msg) if (debug) cout<<msg<<endl;
int quick_select(vector<int>& a, int start, int end, int k) {
    if (start == end) return a[start];
    int p=a[(start+end)>>1];
    int l = start - 1, r = end + 1;
    while (l<r) {
        while (a[++l]<p);
        while (a[--r]>p);
        if (l<r) swap(a[l], a[r]);
    }
    // start . . . l, r, r+1, ... end
    int lcnt = r - start + 1;
    if (k > lcnt) {
        return quick_select(a, r+1, end, k - lcnt);
    } else {
        return quick_select(a, start, r, k);
    }
}
void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for (int i=0;i<n;++i) cin>>a[i];
    cout<<quick_select(a, 0, n - 1, k)<<endl;
}
int main() {
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}
