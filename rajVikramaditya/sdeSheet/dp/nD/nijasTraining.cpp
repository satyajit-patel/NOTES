//https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include<bits/stdc++.h>
#define vvi vector<vector<int>>
int f(int day, int lastExercise, vvi &points, vvi &dp) {
    if(day == 0) {
        int maxi = 0;
        for(int i=0; i<3; i++) {
            if(i != lastExercise) maxi = max(maxi, points[day][i]);
        }
        return maxi;
    }
    if(dp[day][lastExercise] != -1) return dp[day][lastExercise];
    
    int maxi = 0;
    for(int i=0; i<3; i++) {
        if(i != lastExercise) {
            int point = points[day][i] + f(day-1, i, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][lastExercise] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points) {
    int m = points[0].size();
    vvi dp(n+1, vector<int>(m+1, -1));
    return f(n-1, m, points, dp);
}