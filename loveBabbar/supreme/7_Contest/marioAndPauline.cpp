// https://practice.geeksforgeeks.org/contest/codehelp-upcoming-sde-contest-2-4646/problems#
bool f(int x1, int y1, int x2, int y2) {
    // base case
    if(x1==x2 && y1==y2) return true;
    if(x1>x2 || y1>y2) return false;
    
    // recursive case
    bool move1 = f(x1+y1, y1, x2, y2);
    bool move2 = f(x1, y1+x1, x2, y2);
    
    // store and return
    bool ans = move1 || move2;
    return ans;
}
bool isPossible(int sx, int sy, int dx, int dy) {
    return f(sx, sy, dx, dy);
}