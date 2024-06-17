#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double Ui(double min, double max)
{
    double result = (double)rand() / RAND_MAX * (max - min) + min;
    return result;
}

void random_password(int length, char* password)
{
    const int Xmin = 33;
    const int Xmax = 126;
    srand((unsigned int)time(0));
    double Xi;
    for (int i = 0; i < length; i++)
    {
        Xi = Xmin + (Xmax - Xmin) * Ui(0, 1);
        password[i] = (char)Xi;
    }
    password[length] = '\0'; 
}

int main()
{
    int length;
    char password[33]; 
    printf("\t\t\t###################################");
    printf("\n\t\t\t|Welcome to the password generator|\n");
    printf("\t\t\t###################################\n");
    printf("\nEnter the length of password (8-32 symbols):");
    scanf_s("%d", &length);
    if (length < 8)
    {
        printf("You are entering incorrect parameters. Please try again!\n");
        return 1;
    }
    if (length > 32)
        {
         printf("You are entering incorrect parameters. Please try again!\n");
         return 1;
        }
    random_password(length, password);
    printf("Your generated password: %s\n", password);
    
    return 0;
}
