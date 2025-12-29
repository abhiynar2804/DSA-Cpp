// help of vs copilot
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes;
        for (const string& time : timePoints) {
            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3, 2));
            minutes.push_back(hour * 60 + minute);
        }   
        sort(minutes.begin(), minutes.end());
        int minDiff = INT_MAX;
        for (int i = 1; i < n; ++i) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }

        return min(minDiff, minutes[0] + 1440 - minutes[n - 1]);
    }
};

// help of love babbar
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;

        for(int i = 0; i < timePoints.size(); i++) {
            int hour = stoi(timePoints[i].substr(0, 2));
            int minute = stoi(timePoints[i].substr(3, 2));
            int totalMinutes = hour * 60 + minute;
            minutes.push_back(totalMinutes);
        }

        sort(minutes.begin(), minutes.end());

        int mini = INT_MAX;
        int n = minutes.size();

        for(int i = 1; i < n; i++) {
            mini = min(mini, minutes[i] - minutes[i - 1]);
        }

        mini = min(mini, (minutes[0] + 1440) - minutes[n - 1]);

        return mini;
    
    }
};