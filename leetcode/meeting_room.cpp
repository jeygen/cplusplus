/*
Problem: Meeting Room Scheduling

You are given a list of intervals, where each interval is represented
as a pair of start time and end time. The intervals are not necessaril
y sorted. Your task is to determine if a person can attend all the 
scheduled meetings.

You need to write a function canAttendAllMeetings that takes an arra
y of pairs as an input and returns true if a person can attend all 
the meetings, otherwise, it returns false.

Input: vector of pairs

Output: bool

Input example:

vector<pair<int,int>> intervals = {{0, 30},{5, 10},{15, 20}};

Output example:

false

Input example:

vector<pair<int,int>> intervals = {{7, 10},{2, 4}};

Output example:

true
*/


bool canAttendAllMeetings(std::vector<std::pair<int, int>>& intervals) {
  // hints, do this without hashmap and sort will work 
}














#include <vector>
#include <algorithm>

bool canAttendAllMeetings(std::vector<std::pair<int, int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    for(int i = 1; i < intervals.size(); i++) {
        if(intervals[i].first < intervals[i - 1].second)
            return false;
    }
    return true;
}

int main() {
    std::vector<std::pair<int,int>> intervals1 = {{0, 30},{5, 10},{15, 20}};
    std::cout << (canAttendAllMeetings(intervals1) ? "True" : "False") << std::endl;

    std::vector<std::pair<int,int>> intervals2 = {{7, 10},{2, 4}};
    std::cout << (canAttendAllMeetings(intervals2) ? "True" : "False") << std::endl;
    
    return 0;
}

