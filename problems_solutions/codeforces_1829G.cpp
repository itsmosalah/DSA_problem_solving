#include <bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define el '\n'
typedef long long ll;

const int N = 1e6 + 5,
        M = 1414; // the diagonal of the square grid. which is srqt(area) * sqrt(2)


ll ans[N], grid[M][M], gridIndex[M][M];
int maxN = 1e6 + 1;

bool isValid(int i, int j) {
    return i >= 0 and j >= 0 and i < M and j < M;
}

ll getValueAt(int i, int j) {
    return isValid(i, j) ? grid[i][j] : 0;
}

void fillValuesDiagonally(int index, int &n) {
    int i = index, j = 0;
    while (i >= 0 and n <= maxN) {
        grid[i][j] = 1ll * n * n;
        gridIndex[i][j] = n;
        n++, i--, j++;
    }
}

void calculatePrefixSum2D() {
    for (int row = 0; row < M; ++row) {

        // row prefixSum
        for (int col = 0; col < M; ++col) {
            grid[row][col] += getValueAt(row, col - 1);
        }

        // add previous row and evaluate answer for each cell
        for (int col = 0; col < M; ++col) {
            grid[row][col] += getValueAt(row - 1, col);
            ans[gridIndex[row][col]] = grid[row][col];
        }
    }
}

void calculate_answers() {
    int n = 1;
    for (int rowIndex = 0; rowIndex < M; ++rowIndex) {
        fillValuesDiagonally(rowIndex, n);
    }

    calculatePrefixSum2D();
}

void run_case(int test_case) {
    if (test_case == 1) {
        calculate_answers();
    }

    int n;
    cin >> n;
    cout << ans[n] << el;
}


int main(){
    io;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        run_case(i);
}
