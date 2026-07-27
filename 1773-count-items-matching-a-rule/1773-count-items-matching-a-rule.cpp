class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        string arr[] = {"type", "color", "name"};

        int idx = 0;
        for (int i = 0; i < 3; i++) {
            if (arr[i] == ruleKey) {
                idx = i;
                break;
            }
        }

        int cnt = 0;
        for (auto &it : items) {
            if (it[idx] == ruleValue) {
                cnt++;
            }
        }

        return cnt;
    }
};