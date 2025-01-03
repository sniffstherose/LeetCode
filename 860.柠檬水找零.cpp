/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
 public:
  bool lemonadeChange(vector<int>& bills) {
    // 给20，三张5元或一张5元一张10元
    // 给10，一张5元
    int five = 0, ten = 0;
    for (const int bill : bills) {
      if (bill == 5) {
        ++five;
      } else if (bill == 10) {
        ++ten;
        --five;
      } else {
        if (ten > 0 && five > 0) {
          --ten;
          --five;
        } else {
          five -= 3;
        }
      }
      if (five < 0 || ten < 0) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
