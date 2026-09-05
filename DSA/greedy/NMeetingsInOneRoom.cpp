// Maximum Meetings in One Room
// Difficulty: MediumAccuracy: 33.57%Submissions: 108K+Points: 4Average Time: 20m
// Given two arrays s[] and f[], where s[i] and f[i] denote the start time and finish time of the ith meeting, respectively. There is only one meeting room. A meeting can be scheduled only if its start time is strictly greater than the finish time of the previously selected meeting.

// Find the maximum number of meetings that can be scheduled in the room such that no two selected meetings overlap. Return the indices (1-based) of the selected meetings in sorted (increasing) order.

// Note: If multiple schedules are possible, prefer meetings with earlier finish times. If two meetings have the same finish time, prefer the meeting with the smaller index.

// Examples:

// Input: s[] = [1, 3, 0, 5, 8, 5], f[] = [2, 4, 6, 7, 9, 9]
// Output: [1, 2, 4, 5]
// Explanation: We can attend the 1st meeting from (1 to 2), then the 2nd meeting from (3 to 4), then the 4th meeting from (5 to 7), and the last meeting we can attend is the 5th from (8 to 9). It can be shown that this is the maximum number of meetings we can attend.
// Input: s[] = [3], f[] = [7]
// Output: [1]
// Explanation: Since there is only one meeting, we can attend the meeting.
// Constraints:
// 1 ≤ s.size() = f.size() ≤ 105
// 0 ≤ s[i] ≤ f[i] ≤ 109

// approach: The problem can be solved using a greedy algorithm. We can create a vector of pairs where each pair contains the finish time and the index of the meeting. We then sort this vector based on the finish times. After sorting, we can iterate through the sorted meetings and select meetings that start after the last selected meeting's finish time. Finally, we return the indices of the selected meetings in sorted order.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f)
    {
        int n = s.size(); // get the number of meetings

        vector<vector<int>> meetings; // vector to store start time and finish time of meetings

        for (int i = 0; i < n; i++)
        {
            meetings.push_back({f[i], i + 1, s[i]}); // store finish time, start time, and index as a triplet
        }

        sort(meetings.begin(), meetings.end()); // sort the meetings based on finish time

        vector<int> selectedMeetings; // vector to store the indices of selected meetings
        int lastFinishTime = -1;      // initialize the finish time of the last selected meeting

        for (int i = 0; i < n; i++)
        {
            if (meetings[i].second > lastFinishTime) // if the start time of the current meeting is greater than the finish time of the last selected meeting
            {
                selectedMeetings.push_back(meetings[i].third); // add the index of the current meeting to the selected meetings
                lastFinishTime = meetings[i].first;            // update the finish time of the last selected meeting
            }
        }

        sort(selectedMeetings.begin(), selectedMeetings.end()); // sort the indices of selected meetings in increasing order

        return selectedMeetings; // return the indices of selected meetings
    }
};