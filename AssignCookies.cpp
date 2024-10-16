/********************************************************************
Problem statement
There are ‘N’ children and ‘M’ cookies.

You are given two arrays, ‘SIZE’, and ‘GREED’, where ‘GREED[i]’ is the greed of ‘ith’ children and ‘SIZE[j]’ is the size of the ‘jth’ cookie.

You must assign ‘jth’ cookie to ‘ith’ child such that the greed of maximum children is satisfied. A child's greed is satisfied if the size of the cookie assigned to him is greater than or equal to his greed.

You must return the maximum number of children whose greed can be satisfied.

Example:
Input:
GREED = [3, 5, 6, 4], SIZE = [1, 4, 5], N = 4, M = 3

Output:
2

Explanation: We can assign the second cookie to the fourth child and the third to the second.
Hence we return 2.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
3 4
1 2 3 
1 2 3 4
Sample Output 1:
3
Explanation Of Sample Input 1:
Input:
GREED = [1, 2, 3], SIZE = [1, 2, 3, 4], N = 3, M = 4

Output:
3

Explanation: We can assign the first cookie to the first child, the second cookie to the second child, and the third cookie to the third child.
Hence we return 2.
Sample Input 2:
5 5
4 5 6 7 8
2 3 4 5 6
Sample Output 2:
3
Constraints:
1 <= N, M <= 10^5
1 <= GREED[i], SIZE[j] <= 10^9
Time Limit: 1 sec
*********************************************************************/

#include <bits/stdc++.h>
using namespace std;

int assignCookie(vector<int> &greed, vector<int> &size) {
    sort(greed.begin(), greed.end());
    sort(size.begin(), size.end());

    int childIndex = 0;
    int cookieIndex = 0;
    int satisfiedChildren = 0;

    while (childIndex < greed.size() && cookieIndex < size.size()) {
        if (size[cookieIndex] >= greed[childIndex]) {
            satisfiedChildren++;
            childIndex++;
        }
        cookieIndex++;
    }

    return satisfiedChildren;
}
