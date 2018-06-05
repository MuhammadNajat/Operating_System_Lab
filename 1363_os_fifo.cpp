#include <bits/stdc++.h>
using namespace std;

int main() {

    int i, j, k, l, m, n, p, cnt, q[10000], a[10000];

    printf("How many values?\n");
    scanf("%d", &n);
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);

    printf("What is the size of the frame\n");
    scanf("%d", &m);

    map <int, int> mp;
    memset(q, -1, sizeof(q));
    j = 0;
    cnt = 0;
    bool f;

    for(i=0; i<n; i++) {
        f = 0;
        if(mp[a[i]] == 0) {
            mp[a[i]] = 1;
            mp[q[j]] = 0;
            q[j++] = a[i];
            cnt++;
            if(j == m)
                j = 0;
            f = 1;
        }
        for(k=0; k<m; k++)
            printf("%d ", q[k]);
            f? puts("Frame") : puts("");

    }

    printf("Total Frame is: %d\n", cnt);

    return 0;
}
