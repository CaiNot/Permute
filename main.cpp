#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> ans;
public:
    vector<vector<int>> permute(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() < 2) {
            this->result.push_back(nums);
            return this->result;
        }
        dfs(nums, -1);
        return this->result;
    }

private:
    void dfs(vector<int> nums, int delNode) {
        if (nums.size() > 1) {
            if (delNode >= 0)
                nums.erase(nums.begin() + delNode);
            for (int i = 0; i < nums.size(); i++) {
                this->ans.push_back(nums[i]);
                dfs(nums, i);
                this->ans.pop_back();
            }
        } else {
            if (!this->isConflict(this->ans))
                this->result.push_back(this->ans);
        }
    }

    void betterDfs(vector<int> nums, int left){
        
    }

    bool isConflict(vector<int> &ans) {
        int count = 0;
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                if (ans[j] == result[i][j]) {
                    count++;
                } else { break; }
            }
            if (count == result[i].size())
                return true;
            count = 0;
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution s;
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> re = s.permute(nums);
    for (int i = 0; i < re.size(); i++) {
        for (int j = 0; j < re[i].size(); j++) {
            cout << re[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}