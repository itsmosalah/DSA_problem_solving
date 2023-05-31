#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define el '\n'

int getCount(int l, int r, vi&v){
    return v[r] - v[l - 1];
}

void run_case(int test_case) {
    int n, m;
    cin >> n >> m;
    vi blackCount(n + 1);
    blackCount[0] = 0;
    char c;
    for (int i = 1; i <= n; ++i) {
        cin >> c;
        blackCount[i] = (c == 'B' ? 1 : 0);
        blackCount[i] += blackCount[i - 1];
    }
    int maxCount = 0;
    for (int i = 1; i + m - 1 <= n; i++){
        int count = getCount(i, i + m - 1, blackCount);
        maxCount = max(maxCount, count);
    }

    cout << m - maxCount << el;

}


int main(){
    io;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        run_case(i);
}
