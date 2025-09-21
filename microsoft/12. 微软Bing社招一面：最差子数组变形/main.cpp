#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin>>n;
    vector<int> a(n), b(n);

    for (int i=0;i<n;++i) cin>>a[i];
    for (int i=0;i<n;++i) cin>>b[i];
    for (int i=0;i<n;++i) a[i] = a[i] - b[i];

    if (n<2) {
        cout<<"invalid input, n must >= 2"<<endl;
        return;
    }

    vector<int> left_min(n, 0), left_max(n, 0);
    vector<int> right_min(n, 0), right_max(n, 0);
    int cur_min = a[0], cur_max = a[0];
    left_min[0] = cur_min, left_max[0] = cur_max;
    for (int i=1;i<n;++i) {
        cur_min = min(cur_min + a[i], a[i]);
        left_min[i] = min(left_min[i-1], cur_min);

        cur_max = max(cur_max + a[i], a[i]);
        left_max[i] = max(left_max[i-1], cur_max);
    }
    cur_min = a[n-1], cur_max = a[n-1];
    right_min[n-1] = cur_min, right_max[n-1] = cur_max;
    for (int i=n-2;i>=0;--i) {
        cur_min = min(cur_min + a[i], a[i]);
        right_min[i] = min(right_min[i+1], cur_min);

        cur_max = max(cur_max + a[i], a[i]);
        right_max[i] = max(right_max[i+1], cur_max);
    }
    int ans = INT_MIN;
    for (int k=0; k<=n-2;++k) {
        // 0~k, k+1~n-1
        ans = max(left_max[k] - right_min[k+1], ans);
        ans = max(right_max[k+1] - left_min[k], ans);

    }
    cout<<ans<<endl;

}
int main() {
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}
