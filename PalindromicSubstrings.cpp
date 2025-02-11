// Companies asking this question: Salesforce, Paytm, Microsoft, Infosys, Amazon, Phone Pe, Cognizant, Netlink, TCS, Wipro

/***********************************************************************************
Problem statement
You have been given a string STR. Your task is to find the total number of palindromic substrings of STR.

Example :
If the input string is "abbc", then all the possible palindromic substrings would be: ["a", "b", "b", c", "bb"] and hence, the output will be 5 since we have 5 substrings in total which form a palindrome.
Note :
A string is said to be a 'Palindrome' if it is read the same forwards and backwards. 
For example, “abba” is a palindrome, but “abbc” is not.

A 'Substring' is a contiguous sequence of characters within a string. 
For example, "a", "b", "c", "ab", "bc", "abc" are substrings of "abc".
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= t <= 100
0 <= N <= 1000

Where 't' is the number of test cases, 'N' is the length of the given string.
Time Limit: 1 sec.
Sample Input 1 :
1
abc
Sample Output 1 :
3
Explanation For Sample Output 1:
All the substrings of the given string are "a", "b", "c", "ab", "bc", "abc".
The plaindromics substrings are "a", "b", "c". So the output will be 3.   
Sample Input 2 :
1
aaa
Sample Output 2 :
6
***********************************************************************************/

int palindromicSubstrings(string input) {
    int count = 0;
    int n = input.length();
    
    auto expandAroundCenter = [&](int left, int right) {
        while (left >= 0 && right < n && input[left] == input[right]) {
            count++;
            left--;
            right++;
        }
    };
    
    for (int i = 0; i < n; i++) {
        expandAroundCenter(i, i);
    }
    
    for (int i = 0; i < n - 1; i++) {
        expandAroundCenter(i, i + 1);
    }
    
    return count;
}
