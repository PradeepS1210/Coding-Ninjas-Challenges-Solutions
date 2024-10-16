// Companies asking this question: HSBC, IBM

/****************************************************************
Problem statement
Ninja wants to build a number pattern for the given integer.

For example, If the given integer ‘N’ is 4 

Pattern:

1
23
345
4567
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
2
3
5
Sample Output 1:
1
23
345
1
23
345
4567
56789
Explanation of Sample Input 1:
Test case 1:

In the first test case, as ‘N’ is equal to 3, We will have to print three lines. Each line starts with its row number and prints next (row number - 1) numbers.

As in this example:
The first row starts with “1” as the row number is one and print only “1” as “row number - 1“ is 0
For the second row, it starts with two and prints one more number that is 3.Similarly, the third line starts with 3 and ends at 5.

Test case 2:

In the second test case, as “N” is equal to “5”, We will have to print five lines. Each line starts with its row number and prints next (row number - 1) numbers.

As in this example:
The first row starts with 1 as the row number is one and print only 1 as “row number - 1“ is 0
The second row starts with two and prints one more number that is “3”.
Similarly, the 5th row starts with “5” and ends at “9”.
Sample Input 2:
1
1
Sample Output 2:
1
Explanation of Sample Input 2:
Test case 1:
As ‘N’ is equal to ‘1’, we just need to print one line i.e 1.
****************************************************************/

#include <bits/stdc++.h> 
using namespace std;

vector<string> numberPattern(int n) {
    vector<string> result;
    
    for (int i = 1; i <= n; ++i) {
        string row = "";
        for (int j = i; j < i + i; ++j) {
            row += to_string(j);
        }
        result.push_back(row);
    }
    
    return result;
}
