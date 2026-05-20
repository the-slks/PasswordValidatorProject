#include <stdio.h>
#include <string.h>

int checkLength(char p[], int min)
{
    if (strlen(p) >= min)
        return 1;
    return 0;
}

int hasUppercase(char p[])
{
    int i;
    for (i = 0; p[i] != '\0'; i++)
        if (p[i] >= 'A' && p[i] <= 'Z')
            return 1;
    return 0;
}

int hasLowercase(char p[])
{
    int i;
    for (i = 0; p[i] != '\0'; i++)
        if (p[i] >= 'a' && p[i] <= 'z')
            return 1;
    return 0;
}

int hasDigit(char p[])
{
    int i;
    for (i = 0; p[i] != '\0'; i++)
        if (p[i] >= '0' && p[i] <= '9')
            return 1;
    return 0;
}

int hasSpecialChar(char p[])
{
    char special[] = "!#$%&*+-=?^_.";
    int i, j;
    for (i = 0; p[i] != '\0'; i++)
        for (j = 0; special[j] != '\0'; j++)
            if (p[i] == special[j])
                return 1;
    return 0;
}

int hasNoSpace(char p[])
{
    int i;
    for (i = 0; p[i] != '\0'; i++)
        if (p[i] == ' ')
            return 0;
    return 1;
}

int calculateStrength(char p[])
{
    int score = 0;
    score += checkLength(p, 8);
    score += hasUppercase(p);
    score += hasLowercase(p);
    score += hasDigit(p);
    score += hasSpecialChar(p);
    score += hasNoSpace(p);
    return score;
}

void printFeedback(char p[])
{
    int score = calculateStrength(p);

    if (score <= 1)
        printf("Score: \033[1;31m%d/6\033[0m [!] Very Weak -- do not use this password.\n", score);
    else if (score == 2)
        printf("Score: \033[1;31m%d/6\033[0m [!] Weak -- significant improvements needed.\n", score);
    else if (score == 3)
        printf("Score: \033[1;33m%d/6\033[0m [ ] Fair -- getting there, but not safe yet.\n", score);
    else if (score == 4)
        printf("Score: \033[1;33m%d/6\033[0m [+] Good -- a few tweaks and you are set.\n", score);
    else if (score == 5)
        printf("Score: \033[1;32m%d/6\033[0m [+] Strong -- almost perfect.\n", score);
    else
        printf("Score: \033[1;32m%d/6\033[0m [*] Very Strong -- excellent password.\n", score);

    if (score == 6)
    {
        printf("All requirements satisfied.\n");
        return;
    }

    printf("Missing requirements:\n");
    if (!checkLength(p, 8))
        printf("  - At least 8 characters (current: %d)\n", (int)strlen(p));
    if (!hasUppercase(p))
        printf("  - At least one uppercase letter\n");
    if (!hasLowercase(p))
        printf("  - At least one lowercase letter\n");
    if (!hasDigit(p))
        printf("  - At least one digit\n");
    if (!hasSpecialChar(p))
        printf("  - At least one special character (!#$%%&*+-=?^_.)\n");
    if (!hasNoSpace(p))
        printf("  - No whitespace characters allowed\n");
}

int main()
{
    char input[100];
    int len;

    printf("=== Password Strength Validator ===\n\n");

    while (1)
    {
        printf("Enter password (or 'q' to quit): ");
        fgets(input, 100, stdin);

        len = strlen(input);
        if (input[len - 1] == '\n')
            input[len - 1] = '\0';

        if (strcmp(input, "q") == 0)
            break;

        printFeedback(input);
        printf("\n");
    }

    return 0;
}