#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long puzzleSolved(const vector<int>& diffs, const vector<int>& times, int level, long long limit);

int main() {
    
    //diff <= level 퍼즐 틀리지 않음, time_cur만큼 시간 사용
    //diff > level 퍼즐 diff - level번 틀림 틀릴때마다 time_cur만큼 시간사용
    //추가로 time_prev만큼 이전 퍼즐을 다시 풀어야함 이전 퍼즐은 다시풀떄 난이도 상관 x 틀리지않음
    vector<int> diffs, times;
    long long total, limit = 59;
    int level = 1;
    int maxLevel;

    int a[4] = { 1, 4, 4, 2 };
    int b[4] = { 6, 3, 8, 2 };

    for (int i = 0; i < 4; i++) {
        diffs.push_back(a[i]);
        times.push_back(b[i]);
    }

    maxLevel = *max_element(diffs.begin(), diffs.end());
    while (level < maxLevel) {
        int midLevel = (level + maxLevel) / 2;
        total = puzzleSolved(diffs, times, midLevel, limit);

        if (total <= limit) {
            maxLevel = midLevel;
        }
        else {
            level = midLevel + 1;
        }
    }
    total = puzzleSolved(diffs, times, 2, limit);

    cout << total << endl;
    cout << level << endl;

    return 0;
}

long long puzzleSolved(const vector<int> &diffs, const vector<int> &times, int level, long long limit) {
    long long total;
    int prevTime;
    int len = diffs.size();

    total = times[0];
    prevTime = times[0];

    for (int i = 1; i < len; i++) {
        int diff = (diffs[i] - level) > 0 ? (diffs[i] - level) : 0;
        total += diff * (times[i] + prevTime) + times[i];

        if (total > limit) {
            return total;
        }
        else {
            prevTime = times[i];
        }
    }

    return total;
}
