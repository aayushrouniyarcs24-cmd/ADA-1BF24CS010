
#include <stdio.h>


struct Item
{
    int weight;
    int profit;
    float ratio;
};

void sortItems(struct Item items[], int n)
{
    struct Item temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (items[i].ratio < items[j].ratio)
            {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}


float fractionalKnapsack(struct Item items[], int n, int capacity)
{
    float totalProfit = 0.0;


    sortItems(items, n);

    for (int i = 0; i < n; i++)
    {

        if (items[i].weight <= capacity)
        {
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        }
        else
        {

            totalProfit += items[i].profit *
                           ((float)capacity / items[i].weight);
            break;
        }
    }

    return totalProfit;
}

int main()
{
    int n, capacity;


    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];


    for (int i = 0; i < n; i++)
    {
        printf("Enter weight and profit of item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].profit);


        items[i].ratio =
            (float)items[i].profit / items[i].weight;
    }


    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);


    float maxProfit =
        fractionalKnapsack(items, n, capacity);


    printf("Maximum Profit = %.2f\n", maxProfit);

    return 0;
}
