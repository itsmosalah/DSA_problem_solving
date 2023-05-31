#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define el '\n'



void run_case(int test_case) {
    int n;
    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int maxDiff = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        maxDiff = max(maxDiff, a[i] - b[i]);
    }
    // those who aren't equal maxDiff must be 0 at b
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] - b[i] != maxDiff and b[i] != 0) {
            ok = false;
        }
    }
    cout << (ok ? "YES" : "NO") << el;

}


int main(){
    io;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        run_case(i);
}
