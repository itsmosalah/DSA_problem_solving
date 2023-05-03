#include <bits/stdc++.h>

using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)


class MentoredMembersEstimation {
    int number_of_members;
    vector<int> members_skills;
    vector<int> members_skills_sorted;
    vector<int> answer;
    map<int,vector<int>> quarrels;
public:
    MentoredMembersEstimation(int number_of_members,
                              vector<pair<int,int>>&quarrel_pairing,
                              vector<int>&skills) :
            number_of_members(number_of_members)
    {
        initializeMemberSkills(skills);
        initializeAndSortQuarrels(quarrel_pairing);
        calculateAnswer();
    }

    vector<int> getAnswer()
    {
        return answer;
    }

private:

    void initializeMemberSkills(vector<int>&skills){
        members_skills = skills;
        members_skills_sorted = skills;
        sort(members_skills_sorted.begin(), members_skills_sorted.end());
    }

    void initializeAndSortQuarrels(vector<pair<int,int>>&quarrel_pairing){
        for (auto &q : quarrel_pairing){
            quarrels[q.first].push_back(members_skills[q.second]);
            quarrels[q.second].push_back(members_skills[q.first]);

        }
        for (auto &q : quarrels){
            sort(q.second.begin(), q.second.end());
        }
    }

    void calculateAnswer(){
        answer = vector<int>(number_of_members);
        for (int i = 0; i < number_of_members; i++)
            answer[i] = countEligibleMentoredMembers(i);
    }

    int countEligibleMentoredMembers(int member){
        int countLessSkilledInQuarrel = countValuesLessThan(members_skills[member], quarrels[member]);
        int countLessSkilledGlobally = countValuesLessThan(members_skills[member], members_skills_sorted);
        return max(countLessSkilledGlobally - countLessSkilledInQuarrel, 0);
    }

    static int countValuesLessThan(int value, vector<int>&values){
        auto lwr = lower_bound(values.begin(), values.end(), value);
        return int(lwr - values.begin());
    }


};


int main() {
    io;
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<pair<int,int>>q(k);
    for (int i = 0; i < k; ++i) {
        cin >> q[i].first >> q[i].second;
        q[i].first--;
        q[i].second--;
    }

    auto solution = MentoredMembersEstimation(n, q, v);

    auto ans = solution.getAnswer();
    for (auto i : ans)
        cout << i << ' ';
}