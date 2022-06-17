#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <algorithm> //lower_bound
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>

#include "Interval.h"
using namespace sol435;
using namespace std;

/*takeaways
  - sort the intervals by the start
  - keep the shorter interval when
    deciding which one to delete
*/

int Solution::erase(vector<vector<int>> &intervals)
{
  sort(begin(intervals), end(intervals));
  auto count = 0, end = 0;

  for (auto i : intervals)
  {
    if (end == 0)
    {
      end = i[1];
      continue;
    }
    /* over-lapping */
    if (i[0] < end)
    {
      count++;
      /* simulating deletion
         - we set the end to a smaller one
           of the two to simulate that we
           are keeping the interval with
           an earlier end time to reduce
           the chance of being overlapping
           again
         - this is how we achieve removing
           min number of intervals
      */
      end = min(end, i[1]);
    }
  }

  return count;
}