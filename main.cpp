#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "interval.h"
#include "util.h"

using namespace std;
using namespace sol435;

/* Example 1:
Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
*/
tuple<vector<vector<int>>, int>
testFixture1()
{
  auto input = vector<vector<int>>{{1, 2}, {2, 3}, {3, 4}, {1, 3}};

  return make_tuple(input, 1);
}

/* Example 2:
Input: [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.

*/
tuple<vector<vector<int>>, int>
testFixture2()
{
  auto input = vector<vector<int>>{{1, 2}, {1, 2}, {1, 2}};

  return make_tuple(input, 2);
}

/*
Input: [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
*/

tuple<vector<vector<int>>, int>
testFixture3()
{
  auto input = vector<vector<int>>{{1, 2}, {2, 3}};

  return make_tuple(input, 0);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see : " << get<1>(f) << endl;
  Solution sol;
  cout << sol.erase(get<0>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see : " << get<1>(f) << endl;
  Solution sol;
  cout << sol.erase(get<0>(f)) << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Expect to see : " << get<1>(f) << endl;
  Solution sol;
  cout << sol.erase(get<0>(f)) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}