#include <stdio.h>


char first_name[50];
char last_name[50];
long long int account_number;
char City[50];
long long int mobile_number;

void create_account()
{

    printf("\n Enter Your First Name: ");
    scanf(" %s", &first_name);
    printf("\n Enter Your Last Name: ");
    scanf(" %s", &last_name);
    printf("\n Enter Your Phone Number: ");
    scanf("%lld", &mobile_number);
    if (mobile_number > 1000000000 && mobile_number < 9999999999)
    {
        printf("\n Enter Your Current City Name You Live: ");
        scanf(" %s", &City);
        printf("\n Your Verification Is Successful.\n");
        printf(" Create A 11 digits Account Number: ");
        scanf("%lld", &account_number);
        if (account_number > 10000000000 && account_number < 99999999999)
        {
            printf("\n Your Account Has Been Created Successfully ");
            printf("\n You have to Deposit Account Opening Fee in Your Account minimum 500rs !");
        }
        else
        {
            printf("\nAccount number is not valid!");
        }
    }
}

int main()
{
    char character_options;

    printf("\t\nPROJECT:-  BANKING MANAGEMENT SYSTEM\n");
    printf("\n Wellcome to Shubham's Bank Management Project. ");
 while (1)
 {
    printf("\n---------------------------------------\n");
    printf("\n Create Account  -> 'A' ");
    printf("\n Deposit         -> 'D' ");
    printf("\n Withdraw        -> 'W' ");
    printf("\n Check Balance   -> 'C' ");
    printf("\n Show A/c Info.  -> 'S' ");
    printf("\n Exit            -> 'X' ");
    printf("\n---------------------------------------\n");
    printf("\n Please Enter Special Character In Capital Form Only!");
    printf("\n Enter Special Character: ");
    scanf(" %c", &character_options);

    if (character_options=='A')
    {
        create_account();
    }
    else if (character_options=='X')
    {
       printf("\nExiting...");
       break;
    }
    else
    {
        printf("\nPlease Enter Valid Character and Formate");
    }
 }
 
    
    
    

    return 0;
}