
void interest_rate()
{
    int money = 0;
    float rate = 0.0;
    int days = 0;
    double result = 0.0;

    do {
        printf("Enter the money amount:\n");
        scanf("%d", &money);
    } while (money < 0);


    do {
        printf("Enter the interest rate\n");
        scanf("%f", &rate);
    } while (rate < 0.0);


    do {
        printf("Enter the days\n");
        scanf("%d", &days);
    } while (rate < 0);

    result = money * rate * days / 36000;

    printf("Your interests for %d days are %.2f", days, result);

    return 0;
}
