#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

float calc_mean(int dataset[], int num);
void sort(int dataset[], int num);
float calc_median(int dataset[], int num);
int calc_mode(int dataset[], int num);
void print(int dataset[], int num);
float calc_stdev(int dataset[], int num);

int main()
{
    int num;

    printf("Enter number of datasets: ");
    scanf("%d", &num);

    int dataset[num];
    printf("Enter the values of the data set:\n");
    for (int i = 0; i < num; i++) {
        printf("Data Value #%d: ", i + 1);
        scanf("%d", &dataset[i]);
    }

    float mean = calc_mean(dataset, num);
    float median = calc_median(dataset, num);
    int mode = calc_mode(dataset, num);
    float std_dev = calc_stdev(dataset, num);
    sort(dataset, num);

    printf("\nThe sorted values of the dataset: ");
    print(dataset, num);
    printf("\nCALCULATING. . .\n");
    sleep(2);
    printf("\nThe mean for the following dataset is: %.2f\n", mean);
    printf("The median for the following dataset is: %.2f", median);
    printf("\nThe mode for the following dataset is: %d", mode);
    printf("\nThe standard deviation for the following dataset is: %.2f", std_dev);
    printf("\n\n");

    return 0;
}

float calc_mean(int dataset[], int num)
{
    float sum = 0;
    for (int i = 0; i < num; i++)
    {
        sum += dataset[i];
    }
    return sum / num;
}

void sort(int dataset[], int num)
{
    for (int i = 0; i < num - 1; i++) {
        int min = i;
        for (int j = i + 1; j < num; j++) {
            if (dataset[j] < dataset[min]) {
                min = j;
            }
        }
        int temp = dataset[i];
        dataset[i] = dataset[min];
        dataset[min] = temp;
    }
}

float calc_median(int dataset[], int num)
{
    sort(dataset, num);
    int mid1 = dataset[(num / 2) - 1];
    int mid2 = dataset[num / 2];
    if (num % 2 == 0)
    {
        return (mid1 + mid2) / 2.0;
    } else
    {
        return dataset[num / 2];
    }
}

int calc_mode(int dataset[], int num)
{
    int max_val = 0, max_count = 0;
    for (int i = 0; i < num; i++)
    {
        int count = 0;
        for (int j = 0; j < num; j++) {
            if (dataset[j] == dataset[i]) {
                ++count;
            }
        }
        if (count > max_count) {
            max_count = count;
            max_val = dataset[i];
        }
    }
    return max_val;
}

void print(int dataset[], int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("%d, ", dataset[i]);
    }
    printf("\n");
}

float calc_stdev(int dataset[], int num)
{
    float variance = 0, standard_dev;
    float cumm_mean = calc_mean(dataset, num);

    for (int i = 0; i < num; i++) {
        variance += pow(dataset[i] - cumm_mean, 2);
    }
    variance /= (num - 1);
    standard_dev = sqrt(variance);
    return standard_dev;
}
