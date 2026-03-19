#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>   // for sleep()

#define FINISH_LINE 100

void showProgress(char name[], int distance) {
    printf("%-10s | ", name);
    for (int i = 0; i < distance; i += 2) {
        printf("=");
    }
    printf(" %d\n", distance);
}

int main() {
    int pepsi = 0;
    int coca_cola = 0;

    srand(time(NULL));  // seed random numbers

    printf("🏁 RACE STARTED: Pepsi vs Coca-Cola 🏁\n\n");

    while (pepsi < FINISH_LINE && coca_cola < FINISH_LINE) {
        pepsi += rand() % 10 + 1;        // random speed 1–10
        coca_cola += rand() % 10 + 1;

        if (pepsi > FINISH_LINE) pepsi = FINISH_LINE;
        if (coca_cola > FINISH_LINE) coca_cola = FINISH_LINE;

        showProgress("Pepsi", pepsi);
        showProgress("CocaCola", coca_cola);

        printf("\n");
        sleep(1);   // pause for 1 second
    }

    if (pepsi >= FINISH_LINE && coca_cola >= FINISH_LINE)
        printf("It's a TIE!\n");
    else if (pepsi >= FINISH_LINE)
        printf("Pepsi WINS THE RACE!\n");
    else
        printf("Coca-Cola WINS THE RACE!\n");

    return 0;
}
