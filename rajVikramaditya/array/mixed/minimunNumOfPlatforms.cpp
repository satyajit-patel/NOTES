//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381892
int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at+n);
    sort(dt, dt+n);
    int curPlatformReq = 1;
    int maxPlatformReq = 1;
    int i=1, j=0;
    while(i < n) {
        if(at[i] <= dt[j]) {
            curPlatformReq++;
            i++;
        }
        else {
            curPlatformReq--;
            j++;
        }
        maxPlatformReq = max(maxPlatformReq, curPlatformReq);
    }
    return maxPlatformReq;
}