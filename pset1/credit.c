#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) 
{
    
    int first_digit_sum = 0;
    int second_digit_sum = 0;
    long card_number = get_long("Number: ");
    long shortened_card_number = card_number;
    int digit = 0;
    int counter = 1;

    do
    {
        digit = shortened_card_number - (shortened_card_number / 10) * 10;
        if (counter % 2 != 0)
        {
            first_digit_sum += digit;
        } 
        else
        {
            if (digit * 2 > 9)
            {
                digit *= 2;
                second_digit_sum += digit / 10 + (digit - (digit / 10) * 10);
            } 
            else
            {
                second_digit_sum += digit * 2;
            }
        }
        shortened_card_number /= 10; 
        counter ++;
    } 
    while (shortened_card_number > 0);

    int checksum = (first_digit_sum + second_digit_sum) % 10;
    int number_length = counter - 1;
    int first_two_digits = card_number / pow(10, (number_length - 2));
    
    if (checksum == 0 && number_length == 15 && (first_two_digits == 34 || first_two_digits == 37))
    {
        printf("AMEX\n");
    } 
    else if (checksum == 0 && number_length == 16 && first_two_digits >= 51 && first_two_digits <= 55)
    {
        printf("MASTERCARD\n");
    } 
    else if (checksum == 0 && (number_length == 13 || number_length == 16) && first_two_digits / 10 == 4)
    {
        printf("VISA\n");
    } 
    else
    {
        printf("INVALID\n");
    }
}