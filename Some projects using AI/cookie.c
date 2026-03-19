#include <stdio.h>

// Simple Cookie Clicker game in C language by AAQ/DaPasta11
int main() {
    long long cookies = 0;       // Total cookies. A variable cookie is declared of type long long (which means a very long integer)
    int cookiesPerClick = 1;     // Cookies gained per click
    int upgradeCost = 50;        // Cost of first upgrade
    int choice;

    printf("=== COOKIE CLICKER ===\n");
    printf("Press:\n");
    printf("  1 - Click cookie 🍪\n");
    printf("  2 - Buy upgrade (+1 cookie per click)\n");
    printf("  3 - Show stats\n");
    printf("  0 - Quit\n\n");

    while (1) {       //this starts an infinite loop in which 1 is always true
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {    //if the player presses 1 the cookies +=cookiesPerClick will add cookies (per click amount) to the total
            cookies += cookiesPerClick;
            printf("You clicked! +%d 🍪 (Total: %lld)\n", cookiesPerClick, cookies);
        }
        else if (choice == 2) {             /*if the player presses 2:

First checks if they have enough cookies (cookies >= upgradeCost).

If yes:

Subtract upgrade cost from total cookies.

Increase cookies per click (cookiesPerClick++).

Double the cost of the next upgrade (upgradeCost *= 2).

Tell player upgrade was successful.*/
            if (cookies >= upgradeCost) {
                cookies -= upgradeCost;
                cookiesPerClick++;
                upgradeCost *= 2;  // Double cost each time
                printf("Upgrade bought! Now %d cookies per click. Next upgrade costs %d 🍪.\n",
                       cookiesPerClick, upgradeCost);
            } else {
                printf("Not enough cookies! Need %d 🍪.\n", upgradeCost);
            }
        }
        else if (choice == 3) {
            printf("Stats: %lld 🍪 | %d per click | Next upgrade: %d 🍪\n",
                   cookies, cookiesPerClick, upgradeCost);
        }
        else if (choice == 0) {
            printf("Thanks for playing! Final cookies: %lld 🍪\n", cookies);
            break; //this breaks the loop
        }
        else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
