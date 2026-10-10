
#include <stdio.h>

// Function prototypes
void introduction(void);
void display_menu(int *num1, int *num2);
int your_choice(void);
int addition(int num1, int num2);
int subtraction(int num1, int num2);
int multiplication(int num1, int num2);
float division(float num1, float num2);
void main_work(int choice, int num1, int num2);

void introduction(void) {
    printf("\t\t\tWelcome to the C Calculator!\n");
    printf("\t\t-----------------------------------------\n");
    printf("\tYou can perform addition, subtraction, multiplication, and division.\n\n");
}

// Collect the two numbers
// Understanding the code
// - int *num1 means the function receives a pointer to an integer.
// - scanf("%d", num1) stores the input at the address passed to the function. We don't need &num1 here because num1 is already a pointer.
// - When you call display_menu(&num1, &num2), the values entered by the user are stored in the variables declared in main().

void display_menu(int *num1, int *num2) {   // &num1	Gets the address of num1 in the calling function.
    printf("Enter the first number: ");    // int *num1	Declares num1 as a pointer that stores an address.
    scanf("%d", num1);                   // scanf("%d", num1)	Stores the user's input at the address held by the pointer.
                                         // *num1	Accesses the value stored at that address.
    printf("Enter the second number: ");
    scanf("%d", num2);
    // If the user enters 25 and 5, scanf() writes those values into the original variables in main(). When the function returns, main() can use num1 = 25 and num2 = 5.
}

// Arithmetic functions
int addition(int num1, int num2) {
    return num1 + num2;
}

int subtraction(int num1, int num2) {
    return num1 - num2;
}

int multiplication(int num1, int num2) {
    return num1 * num2;
}

float division(float num1, float num2) {
    return num1 / num2;
}

// Display operations and get the user's choice
int your_choice(void) {
    int choice;

    printf("\nChoose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice (1-4): ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input. Please enter a number.\n");

        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
            // Clear invalid input
        }

        return 0;
    }

    return choice;
}

// Perform the selected calculation
void main_work(int choice, int num1, int num2) {
    switch (choice) {
        case 1:
            printf("Result: %d + %d = %d\n",
                   num1, num2, addition(num1, num2));
            break;

        case 2:
            printf("Result: %d - %d = %d\n",
                   num1, num2, subtraction(num1, num2));
            break;

        case 3:
            printf("Result: %d * %d = %d\n",
                   num1, num2, multiplication(num1, num2));
            break;

        case 4:
            if (num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                printf("Result: %d / %d = %.2f\n",
                       num1, num2, division(num1, num2));
            }
            break;

        default:
            printf("Invalid choice. Please select an operation from 1 to 4.\n");
    }

    printf("\n");
}

int main(void) {
    int num1, num2;
    char continue_choice;

    introduction();

    while (1) {
        display_menu(&num1, &num2); // This passes the memory addresses of num1 and num2 to the display_menu() function.

        int choice = your_choice();

        if (choice == 0) {
            continue;
        }

        main_work(choice, num1, num2);

        printf("Do you want another calculation? (y/n): ");

        if (scanf(" %c", &continue_choice) != 1) {
            break;
        }

        if (continue_choice != 'y' && continue_choice != 'Y') {
            break;
        }

        printf("\n");
    }

    printf("\nThank you for using the C Calculator!\n");

    return 0;
}


