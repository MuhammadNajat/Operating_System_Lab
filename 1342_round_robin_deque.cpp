#include <bits/stdc++.h>
using namespace std;

#define pii pair <int, int>
#define pb push_back

struct state {
    int id, st, en;
};

int main() {

    int i, j, k, m, n, p, q, t, cur, art, srt, dur, tm = 10000000, cnt = 0;
    vector < pii > v;

    puts("How many jobs?");
    scanf("%d", &t);

    puts("Input them...");
    for(i=0; i<t; i++) {
        scanf("%d%d", &art, &srt);
        v.pb(pii(art, srt));
        tm = min(tm, art);
    }

    cout << tm << '\n';

    puts("Quantam Size:");
    scanf("%d", &q);

    int fin[1000] = {0};
    bool touch[1000] = {0};
    bool comp[1000] = {0};
    deque <int> dq;
    vector <state> vs;

    dq.push_back(0);
    cnt = 0;

    while(1) {

        cur = dq.front();
        dur = min(q, v[cur].second-fin[cur]);
        fin[cur] += dur;

        if(fin[cur] == v[cur].second) {
            ++cnt;
            comp[cur] = 1;
        }

        state temp;
        temp.id = cur+1, temp.st = tm, temp.en = tm+dur;
        vs.pb(temp);

        if(cnt == v.size())
            break;

        tm += dur;

        for(i=cur+1; i<v.size(); i++) {           ///  If some jobs has appeared while running the current job namely cur, then push them in the deque
            if(v[i].first <= tm && !touch[i]) {
                dq.push_back(i);
                touch[i] = 1;
            }
        }

        if(fin[cur] != v[cur].second) {           /// If job cur isn't finished, push it in the deque
            dq.push_back(cur);
        }

        dq.pop_front();

        if(dq.empty() && cnt != v.size()) {       /// If there's some idle time, then find it and go to next job
            for(i=cur+1; i<v.size(); i++)
                if(!comp[i]) {
                    dq.push_back(i);
                    state idle;
                    idle.id = -999, idle.st = tm, idle.en = v[i].first;
                    vs.push_back(idle);
                    tm = idle.en;
                    break;
                }
        }

    }

    puts("The Gantt Chart is as Follows:");
    for(i=0; i<vs.size(); i++) {
        if(vs[i].id != -999)
            printf("Job ID: %d Starts at: %d Ends at: %d\n", vs[i].id, vs[i].st, vs[i].en);
        else
            printf("Idle Time Starts at: %d Ends at: %d\n", vs[i].st, vs[i].en);
    }

    /// Finding the Average Turn around Time and Average Waiting Time

    /**
        Turn Around Time = Finish Time - Arrival Time
        Waiting Time = Turn Around Time - Service Time
    */
    //not correct yet
    int tt = 0, wt = 0, ttTemp;
    bool isTaken[1000] = {0};
    for(i=vs.size()-1; i > -1; i--) {
        if(vs[i].id > 0 && !isTaken[vs[i].id]) {
            ttTemp = vs[i].en - v[vs[i].id - 1].first;
            tt += ttTemp;
            wt += (ttTemp - v[vs[i].id - 1].second);
            isTaken[vs[i].id] = 1;
        }
    }

    int sz = v.size();
    puts("___________________________________________________");
    printf("Average Turn Around Time = %.2lf\n", (double)tt / (double)sz);
    printf("Average Waiting Time = %.2lf\n", (double)wt / (double)sz);
    puts("___________________________________________________");

    return 0;
}
