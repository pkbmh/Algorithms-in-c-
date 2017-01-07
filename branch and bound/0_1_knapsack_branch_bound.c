#include <stdio.h>
#define max 100

typedef struct items {
    int profit;
    int weight;
} items;

int cmp (const void * a, const void * b)
{
    items *a1 = (items *) a;
    items *a2 = (items *) b;
    float r1 = (a1->profit * 1.0) / (a1->weight);
    float r2 = (a2->profit * 1.0) / (a2->weight);
    if (r1 - r2 == 0) {
        return 0;
    }

    if (r1 > r2)
        return -1;

    return 1;
}

int p[max];
int w[max];
int maxprofit = 0;
int include[max];
int solution[max];
int W;
int numbest = 0;
int n;

int is_solution(int i, int profit, int weight) {
    int j, k;
    int totweight;
    float bound;
    if (weight >= W)
        return 0;
    j = i + 1;
    bound = profit * 1.0;
    totweight = weight;
    while (j <= n && totweight + w[j] <= W) {
        totweight = totweight + w[j];
        bound = bound + p[j];
        j++;
    }

    k = j;
    if (k <= n) {
        bound += bound + (W - totweight) * p[k] / w[k];
    }
    if (bound > maxprofit)
        return 1;
    return 0;
}

void knapsack(int i, int profit, int weight) {
    if (weight <= W && profit > maxprofit) {
        maxprofit = profit;
        numbest = i;
        int j;
        for (j = 1; j <= n; j++)
           // printf ("%d ", include[j]);
            //printf ("\n");
           solution[j] = include[j];
    }
    if (is_solution(i, profit, weight)) {
        include[i + 1] = 1;
        knapsack(i + 1, profit + p[i + 1], weight + w[i + 1]);
        include [i + 1] = 0;
        knapsack(i + 1, profit, weight);
    }
}

int main() {
    scanf("%d", &n);
    items item[n];
    int i;
    for (i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        item[i].profit = x;
        item[i].weight = y;
    }
    scanf ("%d", &W);
    qsort(item, n, sizeof (item[0]), cmp);
    for (i = 0; i < n; i++) {
        p[i + 1] = item[i].profit;
        w[i + 1] = item[i].weight;
    }
    memset(include, 0, sizeof include);
    memset(solution, 0, sizeof solution);
    knapsack(0, 0, 0);
    printf ("%d\n", maxprofit);
    for (i = 1; i <= n; i++) {
        printf ("%d ", solution[i]);
    }
}
