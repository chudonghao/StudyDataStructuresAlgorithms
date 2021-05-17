/// 题目：https://leetcode-cn.com/problems/n-queens/

#include <string>

#include "util.hpp"

using namespace std;

class Solution {
public:
  string generateA_n(const vector<string> &R) const {
    int row0 = R.size();
    string A;
    A.resize(n_, '.');
    if (row0 == n_) {
      return A;
    }

    for (int i0 = 0; i0 < A.size(); ++i0) {
      bool valid = true;

      for (int row = 0; row < R.size(); ++row) {
        int i_1 = i0;
        int i_2 = -(row - row0) + i0;
        int i_3 = row - row0 + i0;

        if (i_1 >= 0 && i_1 < R[row].size()) {
          valid = valid && R[row][i_1] != 'Q';
        }
        if (i_2 >= 0 && i_2 < R[row].size()) {
          valid = valid && R[row][i_2] != 'Q';
        }
        if (i_3 >= 0 && i_3 < R[row].size()) {
          valid = valid && R[row][i_3] != 'Q';
        }
      }

      if (valid) {
        A[i0] = 'Q';
      }
    }
    return A;
  }

  void backtrack(vector<string> &R, string A_n) {
    if (A_n.empty()) {
      return;
    }
    if (R.size() == n_) {
      result_.push_back(R);
    }

    for (int i = 0; i < A_n.size(); ++i) {
      if (A_n[i] != 'Q') {
        continue;
      }

      string a = string(n_, '.');
      a[i] = 'Q';
      R.push_back(a);

      backtrack(R, generateA_n(R));
      R.pop_back();
    }
  }

  vector<vector<string>> solveNQueens(int n) {
    n_ = n;
    R_.clear();
    result_.clear();

    if (n <= 0) {
      return result_;
    }

    backtrack(R_, generateA_n(R_));
    return result_;
  }

private:
  int n_{};
  vector<string> R_;
  vector<vector<string>> result_;
};

int main() {
  Solution solution;
  for (int n = 0; n <= 5; ++n) {
    cout << "input: n = " << n << endl;
    auto result = solution.solveNQueens(n);
    cout << "output: " << result << endl;
  }
#if 0
  for (int n = 0; n <= 5; ++n) {
    cout << "input: n = " << n << endl;
    auto result = solution.solveNQueens(n);
    for (int i = 0; i < result.size(); ++i) {
      cout << "output " << i << ":" << endl;
      for (auto &row : result[i]) {
        for (auto &p : row) {
          cout << p << ' ';
        }
        cout << endl;
      }
    }
  }
#endif
  return 0;
}