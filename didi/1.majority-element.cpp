#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;++i) {
        cin>>a[i];
    }

    int candidate = 0, count = 0;
    for (auto&n:a) {
        if (candidate == n) {
            count++;
        } else {
            if (count) --count;
            else {
                candidate = n;
                count = 1;
            }
        }
    }

    if (count == 0) {
        cout<<0<<endl;
        return;
    }

    count = 0;
    for (auto &n:a) {
        if (n == candidate) ++count;
    }
    if (count > n / 2) {
        cout<<candidate<<endl;
    } else {
        cout<<0<<endl;
    }
}
int main() {
    int T;
    cin>>T;
    for (int t=0;t<T;++t) {
        solve();
    }
    return 0;
}
