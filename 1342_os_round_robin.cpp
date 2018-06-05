#include <bits/stdc++.h>                            /// doesn't match the output of Ravula @ youtube
using namespace std;

#define pii pair <int, int>
#define pb push_back

struct state {
    int id, st, en;
};

int main() {

    int i, j, k, l, m, n, p, q, r, t, art, srt;
    vector < pii > v;

    puts("How many jobs?");
    scanf("%d", &t);

    puts("Input them...");
    for(i=0; i<t; i++) {
        scanf("%d%d", &art, &srt);
        v.pb(pii(art, srt));
    }

    puts("Quantam Size:");
    scanf("%d", &q);

    int tm = 0, cnt = 0, cur = 0, dur, til, x, y, z;
    int fin[1000] = {0};
    bool touch[1000] = {0};
    bool done[1000] = {0};
    vector <state> vs;

    while(1) {

        //puts("Hi!");

        dur = min(q, v[cur].second-fin[cur]);
        fin[cur] += dur;
        //printf("fin[%d] = %d\n", cur, fin[cur]);
        touch[cur] = 1;

        if(fin[cur] == v[cur].second) {
            done[cur] = 1;
            cnt++;
            printf("Now Done: %d\n", cur);
        }

        state temp;
        temp.id = cur+1, temp.st = tm, temp.en = tm + dur;
        vs.pb(temp);

        tm += dur;

        if(cnt == v.size())
            break;

        for(i=cur+1; i<v.size(); i++) {
            if(v[i].first <= tm && done[i] == 0 && touch[i] == 0) {
                cur = i;
                break;
            }
        }



        if(i == v.size()) {
            for(i=0; i<v.size(); i++) {
                if(done[i] == 0) {
                    cur = i;
                    break;
                }
            }
        }

    }

    puts("The Gantt Chart is as Follows:");
    for(i=0; i<vs.size(); i++)
        printf("Job ID: %d Starts at: %d Ends at: %d\n", vs[i].id, vs[i].st, vs[i].en);


    return 0;
}
