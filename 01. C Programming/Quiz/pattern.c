int fun(int x, int y)
{
    if (x < 0)
    {
        x = x * -1;
    }
    if (y < 0)
    {
        y = y * -1;
    }
    if (x > y)
        return x;
    else
        return y;
}
int main(void)
{
    int n, y, x, r, num, m, i;
    while (1)
    {
        scanf("%d", &num);

        n = num * 2 + 1;
        for (y = -1 * num; y <= num; y = y + 1)
        {
            for (x = -1 * num; x <= num; x++)
            {

                printf("%d", fun(x, y));
            }
            printf("\n");
        }
    }
    return 0;
}
