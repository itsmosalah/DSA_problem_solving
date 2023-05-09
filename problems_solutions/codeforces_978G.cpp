#include <bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define el '\n'

void run_case(int test_case) {
    int n, m;
    cin >> n >> m;

    vector<int> isExamDay(n + 1, 0);
    vector<int> prepDays(m + 1);
    vector<int> examEndDay(m + 1);
    vector<vector<int>> publishedExamsOnDay(n + 1);
    vector<bool>isExamDone(m + 1, false);

    for (int i = 1, a, b, c; i <= m; ++i) {
        cin >> a >> b >> c;
        publishedExamsOnDay[a].push_back(i);
        isExamDay[b] = i;
        prepDays[i] = c;
        examEndDay[i] = b;
    }

    bool possible = true;
    priority_queue<pair<int, int>> soonestExamDue;
    vector<int> ans(n, 0);

    for (int day = 1; day <= n; ++day) {
        for (int examID: publishedExamsOnDay[day]) {
            soonestExamDue.emplace(-examEndDay[examID], examID);
        }

        int examToday = isExamDay[day];
        if (examToday == 0) {
            if (!soonestExamDue.empty()) {
                auto examID = soonestExamDue.top().second;
                if (isExamDone[examID]) {
                    possible = false;
                    break;
                }
                ans[day - 1] = examID;
                prepDays[examID]--;
                if (prepDays[examID] == 0)
                    soonestExamDue.pop();
            }
        }
        else {
            ans[day - 1] = m + 1;
            isExamDone[examToday] = true;
        }
    }

    if (possible)
        for (int i = 1; i <= m; ++i) if (prepDays[i] > 0)
            {
                possible = false;
                break;
            }


    if (possible)
        for (int i : ans)
            cout << i << ' ';
    else cout << "-1\n";

}


int main(){
    io;
    run_case(1);
}
