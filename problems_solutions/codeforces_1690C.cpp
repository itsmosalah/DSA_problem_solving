#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define el '\n'



void run_case(int test_case) {
    int n;
    cin >> n;
    vi start(n), finish(n);
    for (int i = 0; i < n; ++i) {
        cin >> start[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> finish[i];
    }
    for (int i = 0; i < n; ++i) {
        if (i == 0)
            cout << finish[0] - start[0];
        else
            cout << finish[i] - max(start[i], finish[i - 1]);
        cout << ' ';
    }
    cout << el;

}


int main(){
    io;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        run_case(i);
}
