#include <stdio.h>
#include <cs50.h>
void print_credit_card_type(long long ccn);
bool check_validity(long long credit_card_number);
int find_length(long long n);
bool checksum(long long ccn);

int main(void)
{
    long long credit_card_number;                                                       //prompt user for ccn. its a 'long long' number.
    do
    {
        credit_card_number = get_long_long("Number: ");                                 //See above.
    } while(credit_card_number < 0);                                                    //While, if ccn is less than 0.. start loop. until a higher no. is inputted.

    if(check_validity(credit_card_number))                                              //If a true ccn. continue in loop.
        print_credit_card_type(credit_card_number);
    else
        printf("INVALID\n");                                                            //If Not, print INVALID.
}

bool check_validity(long long credit_card_number)                                       //Detect Validity. Use a bool for two outcomes. Yes cc or No not cc.
{                                                                                       //Detect length digits.
    int len = find_length(credit_card_number);                                          //Int needed to find length of number. Just a small number, not a decimal, obv.
    return (len == 13 || len == 15 || len == 16) && checksum(credit_card_number);       //Return a validation if equal to 13, 15 or 16 digits. run the Checksum.
}                                                                                       //Checksum calculation further down.

int find_length(long long n)                                                            //Detect number total number of digits.
{
    int len;                                                                            //This number is also an integer.
    for (len = 0; n != 0; n /= 10, len++);                                              //For length, detect if number 0, not equal to zero but still divisible by 10..
    return len;                                                                         //..yes it's a number, so len++ means move onto next. comp. will detect when
}                                                                                       //..numbers stop and RETURN a length.

bool checksum(long long ccn)                                                            //The Checksum input.
{
    int sum = 0;                                                                        //Int sum value 0. Meaning make left side same as right side (variable.)
    for (int i = 0; ccn != 0; i++, ccn /= 10)                                           //i=index. if ccn not 0; Value of ccn/10 (removes digit from the end)
    {
        if (i % 2 == 0)                                                                 //If index remainder is 2 of (equal to) sum...
           sum += ccn % 10;                                                             //sum + remainder of ccn/10.
        else
        {
            int digit = 2 * (ccn % 10);                                                 //if digit = 2 x (Remainder of ccn divided by 10).
            sum += digit / 10 + digit % 10;                                             //Divide that no. by 10 to get the 1st digit or multiply by 10 for last digit.
        }
    }
    return(sum % 10) == 0;                                                              //Return (remainder of sum divided by 10) as the equal comparison of Sum.
}

void print_credit_card_type(long long ccn)                                              //assign the brand.
{
    if ((ccn >= 34e13 && ccn < 35e13) || (ccn >= 37e13 && ccn < 38e13))                 //Parameters for each CC brand.
    printf("AMEX\n");
    else if (ccn >= 51e14 && ccn < 56e14)
    printf("Mastercard\n");
    else if ((ccn >= 4e12 && ccn < 5e12) || (ccn >= 4e15 && ccn < 5e15))
    printf("VISA\n");
    else
    printf("INVALID\n");
}

