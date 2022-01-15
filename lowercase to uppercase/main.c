#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a;
    printf("Enter in lowercase: ");
    scanf("%c",&a);
    printf("Lowercase letter in Uppercase: ");
    printf("%c",a-32);

    return 0;
}
