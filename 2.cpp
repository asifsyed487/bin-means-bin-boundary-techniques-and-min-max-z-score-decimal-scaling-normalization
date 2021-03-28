
#include <bits/stdc++.h>

using namespace std;

float *sorting(float arr[], int n) {
    int i, j, temp;
    for(i=0;i<n;i++) {
        for(j=0;j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return arr;
}

float maxFromArray(float arr[], int n) {
    int i;
    float max = arr[0];
    for(i=0; i<n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

float minFromArray(float arr[], int n) {
    int i;
    float min = arr[0];
    for(i=0; i<n; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int main()
{
    char str[100];
    gets(str);
    float newmax=1, newmin=0;
    int i, j, choice;
    int str_length = strlen(str);
    float arr[str_length] = { 0 };

    int n = 0;

    for (i = 0; str[i] != '\0'; i++) {

        if (str[i] == ',') {
             continue;
        }
         if (str[i] == ' '){
            n++;
        }
        else {
            arr[n] = arr[n] * 10 + (str[i] - 48);
        }
    }
    n++;
    float v[n];
    float max = maxFromArray(arr, n);
    float min = minFromArray(arr, n);
    //printf("max = %.f  and min = %.f", max, min);
    printf("\n1.MinMax Normalization\n2.Z-Score Normalization\n3.Decimal Scaling Normalization");
    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("\nMinMax Normalization: \n");
    for(i=0;i<n;i++) {
        newmax=1;
        newmin = 0;
        v[i] = (((arr[i] - min)*(newmax - newmin))/(max-min)) + newmin;
        }
    printf("\n");
    for(i=0;i<n;i++) {
        printf(" %.1f, ", v[i]);
        }
    }
    else if(choice == 2) {
        printf("\nZ-Score Normalization: \n");
        float sum = 0.0, mean, SD = 0.0;
        for (i = 0; i < n; i++) {
            sum += arr[i];
        }
        mean = sum / n;
        for (i = 0; i < n; i++) {
            SD += pow(arr[i] - mean, 2);
        }
        SD = sqrt(SD/n);
        //printf("\n\n %f \n\n", SD);

        for(i=0;i<n;i++) {
            v[i] = (arr[i] - mean)/SD;
        }
        printf("\n");
        for(i=0;i<n;i++) {
            printf(" %f, ", v[i]);
        }

    }
    else if(choice ==3) {
        printf("\nDecimal Scaling Normalization: \n");
        float *arr2 = sorting(arr, n);
        printf("\n");
        /*for(i=0;i<n;i++) {
            printf(" %.1f ", arr2[i]);
        } */
        int caught;
        float biggestNumber = arr[n-1];
        //printf("\n big= %f \n", biggestNumber);
        for(j=1; j<biggestNumber; j++) {
            if(biggestNumber/pow(10,j) < 1) {
                caught = j;
                break;
            }
        }
        //printf(" %d ", caught);
        for(i=0;i<n;i++) {
            v[i] = arr[i]/pow(10,caught);
        }
        printf("\n");
        for(i=0;i<n;i++) {
            printf(" %.3f, ", v[i]);
        }
    }



    return 0;
}
