#include <bits/stdc++.h>
using namespace std;

#define pii pair <int, int>

struct state {
    int id, st, en;
};

bool cmp(pii p1, pii p2) {
    return p1.first < p2.first;
}

int main() {

    int i, j, k, l, m, n, t, p, q, tm = 1000000000;
    vector < pii > v;

    puts("How many jobs?");
    scanf("%d", &t);
    puts("Input the jobs\nAT ST");
    for(i=0; i<t; i++) {
        scanf("%d%d", &m, &n);
        v.push_back(pii(m, n));
        tm = min(m, tm);
    }

    sort(v.begin(), v.end(), cmp);

    vector <state> vs;
    for(i=0; i<t; i++) {

        state temp;
        temp.id = i + 1;
        temp.st = tm;
        temp.en = tm + v[i].second;
        vs.push_back(temp);

        tm += v[i].second;

        if(i != (t-1) && (tm < v[i+1].first) ) {
            temp.id = -999;
            temp.st = tm;
            temp.en = v[i+1].first;
            vs.push_back(temp);
            tm = v[i+1].first;
        }
        //else
            //tm += v[i].second;
    }

    for(i=0; i<vs.size(); i++) {
        if(vs[i].id > 0)
            printf("ID: %d start: %d end: %d\n", vs[i].id, vs[i].st, vs[i].en);
        else {
            printf("Idle Time start: %d end: %d\n", vs[i].st, vs[i].en);
        }
    }

    int tt = 0, wt = 0, temp;

    for(i=0; i<vs.size(); i++) {
        if(vs[i].id > 0) {
            temp = vs[i].en - v[vs[i].id-1].first;
            tt += temp;
            wt += (temp - v[vs[i].id-1].second);
        }
    }

    puts("_________________________________________");
    printf("ATT = %.2lf\nAWT = %.2lf\n", (double)tt / (double)t, (double)wt / (double)t);
    puts("_________________________________________");

    return 0;
}

