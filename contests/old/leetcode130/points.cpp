#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        // We have to take care of the same points
        int total_points = s.size();
        unsigned long long int max_size[26][2];
        for (int i = 0; i < 26; i++){
            max_size[i][0] = ULONG_LONG_MAX;
            max_size[i][1] = ULONG_LONG_MAX;
        }
        // int exists[26] = {0};
        long long int pointA, pointB;
        unsigned long long int curr_point;
        for (int i = 0; i < total_points; i++){
            //if (exists[s[i]-97] == 1){
            pointA = points[i][0] > 0 ? points[i][0] : points[i][0] * -1;
            pointB = points[i][1] > 0 ? points[i][1] : points[i][1] * -1;
            curr_point = pointA > pointB ? pointA : pointB;
            if (curr_point < max_size[s[i]-97][0]){
                max_size[s[i]-97][1] = max_size[s[i]-97][0];
                max_size[s[i]-97][0] = curr_point;
            } else {
                if (curr_point < max_size[s[i]-97][1]){
                    max_size[s[i]-97][1] = curr_point;
                }
            }
            // exists[s[i]-97]++;
            //max_size[s[i]-97][0] = points[i][0] > points[i][1] ? points[i][0] : points[i][1];
        }
        cout << "Reached Here" << endl;
        int answer = 0;
        unsigned long long int square_width = ULONG_LONG_MAX;
        for (int i = 0; i < 26; i++){
            square_width = square_width < max_size[i][1] ? square_width : max_size[i][1];
        }
        cout<< "Reached here" << endl;
        for (int i = 0; i < total_points; i++){
            pointA = points[i][0] > 0 ? points[i][0] : points[i][0] * -1;
            pointB = points[i][1] > 0 ? points[i][1] : points[i][1] * -1;
            curr_point = pointA > pointB ? pointA : pointB;
            answer += curr_point < square_width ? 1 : 0;
        }
        return answer;

    }
};


int main() {
    Solution mysol;
    vector<vector<int>> points
    {
        {1, 1},
        {-2, -2},
        {-2, 2}
    };
    string s = "aba";

    cout << mysol.maxPointsInsideSquare(points, s) << endl;

}


