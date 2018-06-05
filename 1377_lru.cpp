#include <bits/stdc++.h>
using namespace std;

int main() {

    int a[10000], p[10000], i, j, k, l, m, n, t, x, faults;

    printf("How Many Inputs?\n");
    scanf("%d", &n);
    printf("Input Them...\n");
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Input The Size...\n");
    scanf("%d", &m);

    bool f = 0;
    k = 0;
    faults = 0;
    memset(p, -1, sizeof(p));
    for(i=0; i<n; i++) {

        printf("%d : ", a[i]);

        for(l=0; l<m; l++) {
            if(a[i] == p[l])
                break;
        }

        if(l < m) {
            for(j=0; j<m; j++)
                printf("%d ", p[j]);
            printf("\n");
            continue;
        }


        if(!f) {
            p[k++] = a[i];
            faults++;
        }
        else  {
            set <int> s;
            for(j=i-1; j>-1; j--) {
                x = a[j];
                s.insert(a[j]);
                if(s.size() == m)
                    break;
            }
            for(l=0; l<m; l++) {
                if(p[l] == x) {
                    p[l] = a[i];
                    break;
                }
            }

            faults++;
        }

        if(k == m) {
            f = 1;
        }

        for(j=0; j<m; j++)
            printf("%d ", p[j]);
        printf(": F\n");

    }

    printf("Total Fault(s): %d\n", faults);

    return 0;
}
