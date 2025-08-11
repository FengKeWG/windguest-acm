#include <bits/stdc++.h>
using namespace std;

struct Team
{
    string name;
    int problemCount; // 通过的题目数
    int totalTime;    // 总时间
    Team(string n, int c, int t) : name(n), problemCount(c), totalTime(t) {}

    // 排序规则：题目数 -> 总时间 -> 字典序
    bool operator<(const Team &other) const
    {
        if (problemCount != other.problemCount)
            return problemCount > other.problemCount;
        if (totalTime != other.totalTime)
            return totalTime < other.totalTime;
        return name < other.name;
    }
};

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n, m, q;
        cin >> n >> m >> q;
        unordered_map<string, vector<pair<int, int>>> teamsData;
        for (int i = 0; i < n; i++)
        {
            string teamName;
            int p;
            cin >> teamName >> p;
            while (p--)
            {
                int time, failCount;
                cin >> time >> failCount;
                teamsData[teamName].emplace_back(time, failCount);
            }
        }
        for (int i = 0; i < m; i++)
        {
            string teamName;
            int time, failCount;
            cin >> teamName >> time >> failCount;
            teamsData[teamName].emplace_back(time, failCount);
        }
        vector<Team> teams;
        for (auto &entry : teamsData)
        {
            string teamName = entry.first;
            vector<pair<int, int>> &submissions = entry.second;
            int problemCount = submissions.size();
            int totalTime = 0;
            for (auto &submission : submissions)
            {
                totalTime += submission.first + submission.second * 20;
            }
            teams.emplace_back(teamName, problemCount, totalTime);
        }
        sort(teams.begin(), teams.end());
        cout << "Case #" << t << ":\n";
        for (int i = 0; i < q; i++)
        {
            string queryTeam;
            cin >> queryTeam;
            int rank = 1;
            for (auto &team : teams)
            {
                if (team.name == queryTeam)
                {
                    cout << rank << "\n";
                    break;
                }
                rank++;
            }
        }
    }
    return 0;
}
