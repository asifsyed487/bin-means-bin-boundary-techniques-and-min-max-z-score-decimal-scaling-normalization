#include<stdio.h>
int arr[100];
int sum[100];
int main()
{
    int i,j,temp;
    int length;
    int bin[100][100];
    int t;
    for(t=0; t<100;t++) {
        sum[t] = 0;
    }
    printf("\nHow many data?: ");
    scanf("%d",&length);
    printf("\n Insert Data : ");
    for(i=0;i<length;i++) {
        scanf("%d,",&arr[i]);
    }

    for(i=0;i<length;i++) {
        printf(" %d ", arr[i]);
    }
    printf("\n\n After Sorting => \n");
    for(i=0; i<length; i++) {
        for(j=0;j< length-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(i=0;i<length;i++) {
        printf(" %d ", arr[i]);
    }

    int binSize = 3;
    int k;
    int l;
    for(k=0; k<length; k++) {
        if(k<binSize) {
            l=0;
            sum[l] = sum[l] + arr[k];
        } else  if(k>=binSize && k<binSize+3) {
            l=1;
            sum[l] = sum[l] + arr[k];
        } else {
            l=2;
            sum[l] = sum[l] + arr[k];


    }
        l++;
    }
    int mean;
    for(i=0;i<binSize;i++) {
        for(j=0;j<binSize;j++) {
            mean = sum[i]/binSize;
            bin[i][j] = mean;
        }
    }
    printf("\n\n");
    printf("Binning my means ->\n");
    for(i=0;i<binSize;i++) {
        for(j=0;j<binSize;j++) {
            printf(" %d ", bin[i][j]);
        }
        printf("\n");
    }
    /////////////////////////////////////////////////////////////

    int trvrs =0;
    for(i=0;i<binSize;i++) {
        for(j=0;j<binSize;j++) {
            bin[i][j] = arr[trvrs];
            trvrs++;
        }
    }

    printf("\n\n\n");
     for(i=0;i<binSize;i++) {
        int lowest = bin[i][0];
        int highest = bin[i][binSize-1];
        for(j=0;j<binSize;j++) {
            if(bin[i][j]-lowest < highest-bin[i][j]) {
                bin[i][j]=lowest;
            } else {
                bin[i][j]=highest;
            }

        }

    }
    printf("\nBinning my Boundaries ->\n");
    for(i=0;i<binSize;i++) {
        for(j=0;j<binSize;j++) {
            printf(" %d ", bin[i][j]);
        }
        printf("\n");
        }


}
