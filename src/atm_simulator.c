#include <stdio.h>
#include "atm.h"
int main()
{
    int pin = PIN, enteredPin, choice;
    float balance = INITIAL_BALANCE, amount;
    int attempt = 0;

    printf("=============================================\n");
    printf("         Welcome to Simple ATM Machine        \n");
    printf("=============================================\n");

    while (attempt < 3)
    {
        printf("\nPlease enter your 4-digit PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == pin)
        {
            printf("\nPIN verified successfully! Access granted.\n");
            break;
        }
        else
        {
            attempt++;
            printf("Incorrect PIN! Attempts left: %d\n", 3 - attempt);
        }
    }

    if (attempt == 3)
    {
        printf("\nYour card has been blocked for security reasons.\n");
        printf("Please contact your bank.\n");
        return 0;
    }

    do
    {
        printf("\n========= ATM Main Menu =========\n");
        printf("1. Check Balance\n");
        printf("2. Withdraw Cash\n");
        printf("3. Deposit Money\n");
        printf("4. Exit\n");
        printf("=================================\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nYour current balance is: %.2f\n", balance);
            break;

        case 2:
            printf("\nEnter the amount to withdraw: ");
            scanf("%f", &amount);

            if (amount <= 0)
            {
                printf("Invalid amount entered!\n");
            }
            else if (amount > balance)
            {
                printf("Insufficient balance!\n");
            }
            else
            {
                balance -= amount;
                printf("Please collect your cash.\n");
                printf("Remaining balance: %.2f\n", balance);
            }
            break;

        case 3:
            printf("\nEnter the amount to deposit: ");
            scanf("%f", &amount);

            if (amount <= 0)
            {
                printf("Invalid amount entered!\n");
            }
            else
            {
                balance += amount;
                printf("Amount deposited successfully!\n");
                printf("New balance: %.2f\n", balance);
            }
            break;

        case 4:
            printf("\nThank you for using our ATM. Please take your card.\n");
            printf("Have a great day!\n");
            break;

        default:
            printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 4);

    printf("\n=============================================\n");
    printf("         Transaction session ended.           \n");
    printf("=============================================\n");

    return 0;
}
