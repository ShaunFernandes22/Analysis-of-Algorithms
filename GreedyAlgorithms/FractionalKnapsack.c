#include <stdio.h>

typedef struct {
    int weight, profit;
    float p_w_ratio;
}Item;

void insertionSort (Item objects[], int n) {
    int i, j; 
    Item temp;
    
    for (i=1;i<n;i++) {
        j=i-1;
        temp = objects[i];
        while (j>=0 && objects[j].p_w_ratio < temp.p_w_ratio) { // sort descending 
            objects[j+1] = objects[j];
            j--;
        }
        objects[j+1] = temp;
    }
}

void fractionalKnapsack(Item objects[], int n, int m) {
    float total_profit = 0;
    insertionSort(objects, n);

    for (int i=0; i<n; i++) {
        if (objects[i].weight <= m) {
            m -= objects[i].weight;
            total_profit += objects[i].profit;
        }
        else {
            float fraction = m/(float)objects[i].weight; // 
            m=0;
            total_profit += fraction * objects[i].profit;
            break;
        }
    }

    printf("The total profit is %.2f",total_profit);
}


int main() {
    Item objects[10];
    int i, n, m;
    
    printf("Enter the number of items : ");
    scanf("%d",&n);
    printf("Enter the capacity of knapsack : ");
    scanf("%d",&m);
    
    for (i=0; i<n; i++) {
        printf("Enter weight of item %d: ",i+1);
        scanf("%d", &objects[i].weight);
        printf("Enter profit of item %d: ",i+1);
        scanf("%d", &objects[i].profit);
        objects[i].p_w_ratio = objects[i].profit/(float)objects[i].weight ;
    }
    
    fractionalKnapsack(objects, n, m);
    return 0;
}
