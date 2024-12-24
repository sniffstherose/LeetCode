/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
 public:
  static bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) {
      return a[1] < b[1];
    }
    return a[0] > b[0];
  }
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    // 局部最优：先按照身高排列，身高高的在前，身高相同的K小的排前面
    // 全局最优：身高排列完后按照人数排列，优先排列身高高的
    sort(people.begin(), people.end(), cmp);
    list<vector<int>> queue;
    for (int i = 0; i < people.size(); ++i) {
      int position = people[i][1];
      auto it = queue.begin();
      while (position--) {
        ++it;
      }
      queue.insert(it, people[i]);
    }
    return vector<vector<int>>(queue.begin(), queue.end());
  }
};
// @lc code=end
