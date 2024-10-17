// Companies asking this question: Amazon, Microsoft, MakeMyTrip, Flipkart, Adobe, Zomato

/***************************************************************************
Problem statement
You are given the schedule of 'N' meetings with their start time 'Start[i]' and end time 'End[i]'.

You have only 1 meeting room. So, you need to return the maximum number of meetings you can organize.

Note:
The start time of one chosen meeting can’t be equal to the end time of the other chosen meeting.

For example:
'N' = 3, Start = [1, 3, 6], End = [4, 8, 7].

You can organize a maximum of 2 meetings. Meeting number 1 from 1 to 4, Meeting number 3 from 6 to 7.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
6
1 3 0 5 8 5
2 4 6 7 9 9
Sample Output 1:
4
Explanation For Sample Input 1:
You can organize a maximum of 4 meetings: 

Meeting number 1 from 1 to 2.
Meeting number 2 from 3 to 4.
Meeting number 4 from 5 to 7.
Meeting number 5 from 8 to 9.
Sample Input 2:
5
0 7 1 4 8
2 9 5 9 10
Sample Output 2:
2 
Constraints:
1 <= 'N' <= 10^5
0 <= 'Start[i]' < 'End[i]' <= 10^9

Time Limit: 1 sec
****************************************************************************/

struct meet
{
    int meetingID;
    int startTime;
    int endTime;
};

bool compare(struct meet a, struct meet b)
{
    if (a.endTime == b.endTime)
    {
        return a.meetingID < b.meetingID;
    }
    else
    {
        return a.endTime < b.endTime;
    }
}

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();

    struct meet meeting[n];

    for (int i = 0; i < n; i++)
    {
        meeting[i].meetingID = i + 1;
        meeting[i].startTime = start[i];
        meeting[i].endTime = end[i];
    }

    sort(meeting, meeting + n, compare);

    int ans = 1;
    int currentTime = meeting[0].endTime;

    for (int i = 1; i < n; i++)
    {

        if (meeting[i].startTime > currentTime)
        {
            ans++;
            currentTime = meeting[i].endTime;
        }
    }

    return ans;
}