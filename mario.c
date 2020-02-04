#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    do 
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j < height * 2 + 2; j++)
        {
            if (j < height - (i + 1) || j == height || j == height + 1)
            {
                printf(" ");
            } 
            else if (j >= height - (i + 1) && j < height + 3 + i)
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
