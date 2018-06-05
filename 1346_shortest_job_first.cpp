#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

struct state {
    int id, st, en;
};

int main() {
    int i, j, k, l, m, n, p, q, t, x, y, tm = 1000000000;
    vector < pii > v;

    puts("Input the total number of jobs:");
    scanf("%d", &t);

    puts("AT ST");
    for(i=0; i<t; i++) {
        scanf("%d%d", &x, &y);
        v.push_back(pii(x, y));
        tm = min(x, tm);         /// just to find the starting time
    }

    int cur = 0;
    bool fin[1000] = {0};
    vector <state> v2;
    for(i=0; i<t; i++) {
        state temp;
        temp.id = cur+1;
        temp.st = tm;
        temp.en = tm + v[cur].second;

        v2.push_back(temp);
        fin[cur] = 1;

        tm += v[cur].second;

        int x, mx = 1000000000;
        for(j=0; j<t; j++) {
            if(!fin[j] && v[j].second < mx) {
                mx = v[j].second;
                x = j;
            }
        }

        cur = x;

    }

    puts("States according to shortest job first:");
    for(i=0; i<t; i++)
        printf("ID:%d Starts at: %d Ends at: %d\n", v2[i].id, v2[i].st, v2[i].en);

    int tt = 0, wt = 0, ttTemp;
    for(i=0; i<t; i++) {
        ttTemp = v2[i].en - v[v2[i].id-1].first;
        tt += ttTemp;
        wt += (ttTemp - v[v2[i].id-1].second);
    }

    double att = (double) tt, awt = (double) wt;

    printf("ATT = %.2lf, AWT = %.2lf\n", att / (double)t, awt / (double)t);

    return 0;
}
