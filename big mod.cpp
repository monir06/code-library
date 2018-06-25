long long PowerMod(long long a, int b, int k)
{
    long long tmp = a, ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * tmp % k;
        tmp = tmp * tmp % k;
        b >>= 1;
    }
    return ret;
}
