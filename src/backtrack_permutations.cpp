/// 题目： https://leetcode-cn.com/problems/permutations/

#include <iostream>
#include <vector>

#include "util.hpp"

using namespace std;

class Solution {
public:
  void backtrack(vector<int> &R, std::vector<int> A_n) {

    if (A_n.empty()) {
      if (!R.empty()) {
        result_.emplace_back(R);
      }
      return;
    }

    for (int i = 0; i < A_n.size(); ++i) {
      R.push_back(A_n[i]);

      auto A_n_1 = A_n;
      A_n_1.erase(std::next(A_n_1.begin(), i));
      backtrack(R, A_n_1);

      R.pop_back();
    }
  }
  vector<vector<int>> permute(vector<int> &nums) {
    result_.clear();
    R_.clear();
    backtrack(R_, nums);
    return result_;
  }

private:
  vector<int> R_;
  vector<vector<int>> result_;
};

int main() {
  Solution solution;
  {
    vector<int> input = {1, 2, 3};
    cout << "input: nums = " << input << endl;
    cout << "output: " << solution.permute(input) << endl;
  }
  {
    vector<int> input = {0, 1};
    cout << "input: nums = " << input << endl;
    cout << "output: " << solution.permute(input) << endl;
  }
  {
    vector<int> input = {1};
    cout << "input: nums = " << input << endl;
    cout << "output: " << solution.permute(input) << endl;
  }
  {
    vector<int> input = {};
    cout << "input: nums = " << input << endl;
    cout << "output: " << solution.permute(input) << endl;
  }
  return 0;
}