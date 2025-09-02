#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n, target;
    cin>>n>>target;
    int a[n];
    for (int i=0;i<n;++i) {
        cin>>a[i];
    }
    sort(a, a+n);
    int left=0, right=n-1, cnt=0;
    while (left<right) {
        if (a[left] + a[right] == target) {
            if (a[left] == a[right]) {
                cnt += (right - left + 1) * (right - left) / 2;
                break;
            }
            int left_count = 1, right_count = 1;
            while (left + left_count < right && a[left_count + left] == a[left]) ++left_count;
            while (right - right_count > left && a[right - right_count] == a[right]) ++right_count;
            cnt += left_count * right_count;
            right -= right_count;
            left += left_count;
        } else if (a[left] + a[right] < target) {
            ++left;
        } else {
            --right;
        }
    }
    cout<<cnt<<endl;
}
int main() {
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}
