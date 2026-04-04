#include <stdio.h>
#include <string.h>

long int balance = 0;
int acc_created = 0;
char first_name[50];
char last_name[50];
char account_number[12];
char City[50];
char mobile_number[10];

void withdraw() // Withdraw Function
{
    if (acc_created == 1)
    {
        long int withdraw_amount;
        do
        {
            printf("\n Enter How Much Money you Want to Withdraw: ");
            scanf("%ld", &withdraw_amount);
            if (withdraw_amount <= balance && withdraw_amount >= 0)
            {
                balance -= withdraw_amount;
            }
            else
            {
                printf("\nAccount Withdraw Amount Limit Reached!");
            }
        } while (withdraw_amount <= balance);
    }
    else
    {
        printf("\nCreate Account First!");
    }
}
void deposit() // Deposit Function
{
    long int deposite_amount = 0;
    if (acc_created == 1)
    {

        do
        {

            printf("\n Enter How Much Money you Want to Deposit ");
            scanf("%ld", &deposite_amount);

            if (deposite_amount >= 100)
            {
                printf("\nYour Money Rs.%ld has been credited To you A/c no. %s", deposite_amount, account_number);
                balance += deposite_amount;
            }
            else
            {
                printf("\n Transaction failed.\nDeposite minimum 100rs or above!");
            }
        } while (deposite_amount <= 100);
    }
    else
    {
        printf("\nCreate Account First!");
    }
}
void create_account() // Create A/c Fnuction
{
    long int first_deposit;
    int validation;
    do
    {
        validation = 1;
        printf("\n Enter Your First Name: ");
        scanf(" %s", &first_name);

        for (int i = 0; i < strlen(first_name); i++)
        {
            if (!((first_name[i] >= 'A' && first_name[i] <= 'Z') || (first_name[i] >= 'a' && first_name[i] <= 'z')))
            {
                printf("\nOnly Alphabets Allowed!");
                validation = 0;
                break;
            }
        }

    } while (validation == 0);
    do // last name Validation
    {
        validation = 1;
        printf("\n Enter Your Last Name: ");
        scanf(" %s", &last_name);
        for (int i = 0; i < strlen(last_name); i++)
        {
            if (!((last_name[i] >= 'a' && last_name[i] <= 'z') || (last_name[i] >= 'A' && last_name[i] <= 'Z')))
            {
                printf("\nOnly Alphabets Allowed!");
                validation = 0;
                break;
            }
        }

    } while (validation == 0);

    do // Phone Number Validation
    {
        validation = 1;

        printf("\n Enter Your Phone Number: ");
        scanf("%s", &mobile_number);

        if (strlen(mobile_number) != 10)
        {
            printf(" Enter exact 10 digits!\n");
            validation = 0;
        }

        for (int i = 0; i < 10; i++)
        {
            if (mobile_number[i] < '0' || mobile_number[i] > '9')
            {
                printf(" only numerical digits allowed!\n");
                validation = 0;
                break;
            }
        }

    } while (validation == 0);

    printf("\n Enter Your Current City Name You Live: "); // City input
    scanf(" %s", &City);
    printf("\n Your Verification Is Successful.\n");
    do // A/c Number Validation
    {
        validation = 1;

        printf("\nCreate A 11 digits Account Number: ");
        scanf(" %s", &account_number);

        if (strlen(account_number) != 11)
        {
            validation = 0;
            printf("\nAccount number must be exactly 11 digits!\n");
        }
        else
        {
            for (int i = 0; i < 11; i++)
            {
                if (account_number[i] < '0' || account_number[i] > '9')
                {
                    validation = 0;
                    printf("\nOnly digits are allowed!\n");
                    break;
                }
            }
        }

    } while (validation == 0);

    printf("\nYour A/c Has Been Created Successfully"); // first Deposit
    acc_created = 1;
    if (acc_created == 1)
    {
        do
        {
            printf("\n You have to Deposit minimum 500rs & Above!");
            printf("\n Enter Opening Balance: ");
            scanf("%ld", &first_deposit);

            if (first_deposit >= 500)
            {
                balance += first_deposit;
                printf("\n Rs.%ld Has been Credited to Your A/c - %s", first_deposit, account_number);
            }
            else
            {
                printf("\n Minimum Opening Balance is 500 Rs!");
            }
        } while (first_deposit < 500);
    }
    else
    {
        printf("\n Create Account First!");
    }
}


int main()
{
    char character_options;

    printf("\t\nPROJECT:-  BANKING MANAGEMENT SYSTEM\n");
    printf("\n Wellcome to Shubham's Bank Management Project. ");
    while (1)
    { // Menu
        printf("\n---------------------------------------");
        printf("\n\t Create Account  -> 'A' ");
        printf("\n\t Deposit         -> 'D' ");
        printf("\n\t Withdraw        -> 'W' ");
        printf("\n\t Check Balance   -> 'C' ");
        printf("\n\t Show A/c Info.  -> 'S' ");
        printf("\n\t Exit            -> 'X' ");
        printf("\n---------------------------------------\n");
        printf("\n Please Enter Special Character In Capital Form Only!");
        printf("\n Enter Special Character: ");
        scanf(" %c", &character_options);

        if (character_options == 'A')
        {
            create_account();
        }
        else if (character_options == 'D')
        {
            deposit();
        }
         else if (character_options == 'W')
        {
            withdraw();
        }

        else if (character_options == 'X')
        {
            if (acc_created == 1)
            {
                printf("\nThank You For Using Our Bank Services.");
            }
            else
            {
                printf("\nExiting...");
                break;
            }
        }
        else
        {
            printf("\nYou Enterd Wrong Character Or Formate!");
        }
    }

    return 0;
}