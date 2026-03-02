#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>

// Usage:
// rand_input [n] [m] [q] [mode]
// mode = A -> many large-rectangle queries (solution_3 advantage)
// mode = B -> many point queries (no advantage)

int main(int argc, char** argv){
    srand(time(0));
    int n = 50, m = 50, q = 20;
    char mode = 0;
    if(argc >= 4){
        n = atoi(argv[1]);
        m = atoi(argv[2]);
        q = atoi(argv[3]);
    }
    if(argc >= 5) mode = argv[4][0];

    printf("%d %d\n", n, m);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            printf("%d ", rand()%1001);
        }
        printf("\n");
    }

    printf("%d\n", q);
    for(int i=0;i<q;++i){
        if(mode == 'A'){
            // large rectangles: a,b roughly half..full size
            int x = rand()%(n/4+1) + 1;
            int y = rand()%(m/4+1) + 1;
            int a = rand()%(n - x + 1 - n/2 + 1) + n/2; // ensure >= n/2
            if(a < 1) a = 1;
            if(x + a - 1 > n) a = n - x + 1;
            int b = rand()%(m - y + 1 - m/2 + 1) + m/2;
            if(b < 1) b = 1;
            if(y + b - 1 > m) b = m - y + 1;
            printf("%d %d %d %d\n", x, y, a, b);
        } else if(mode == 'B'){
            // point queries
            int x = rand()%n + 1;
            int y = rand()%m + 1;
            printf("%d %d 1 1\n", x, y);
        } else {
            // default random queries
            int x = rand()%n + 1;
            int y = rand()%m + 1;
            int a = rand()%(n - x + 1) + 1;
            int b = rand()%(m - y + 1) + 1;
            printf("%d %d %d %d\n", x, y, a, b);
        }
    }
    return 0;
}