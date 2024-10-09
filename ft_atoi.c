int atoi(const char *str)
{
    size_t  i = 0;
    int res = 0;
    int sign = 1;

    if(! str || *str == '\0')
        return (0);
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * (str[i] - '0');
        i++;
    }       
}