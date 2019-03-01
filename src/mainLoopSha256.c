#include "../inc/sha256.h"
#define ULL unsigned long long

void	prepareMessage(unsigned int *X, unsigned int m[])
{
    int		i;

    i = -1;
    while (++i < 16)
        m[i] = rev_bit(X[i]);
    while (i < 64)
    {
        m[i] = (m[i - 16] + delta0(m[i - 15]) + m[i - 7] +
                delta1(m[i - 2]));
        ++i;
    }
}

void    init_tmp(t_variables *tmp, t_variables *var)
{
    int i;

    i = -1;
    while (++i < 64)
        tmp->T[i] = var->T[i];
    tmp->h0 = var->h0;
    tmp->h1 = var->h1;
    tmp->h2 = var->h2;
    tmp->h3 = var->h3;
    tmp->h4 = var->h4;
    tmp->h5 = var->h5;
    tmp->h6 = var->h6;
    tmp->h7 = var->h7;
}

void    update_tmp(t_variables *tmp, t_variables *var)
{
    var->h0 = tmp->h0;
    var->h1 = tmp->h1;
    var->h2 = tmp->h2;
    var->h3 = tmp->h3;
    var->h4 = tmp->h4;
    var->h5 = tmp->h5;
    var->h6 = tmp->h6;
    var->h7 = tmp->h7;
}

void            loop(unsigned int m[], t_variables *tmp)
{
    int					i;
    unsigned long long	tmp1;
    unsigned long long	tmp2;

    i = -1;
    while (++i < 64)
    {
        tmp1 = (((ULL)tmp->h7 + sigma1(tmp->h4)) % 4294967296) +
                (ch(tmp->h4, tmp->h5, tmp->h6) % 4294967296) +
                (m[i] % 4294967296) +
                (tmp->T[i] % 4294967296);
        tmp2 = ((ULL)(sigma0(tmp->h0)) + maj(tmp->h0, tmp->h1, tmp->h2)) %
                4294967296;
        tmp->h7 = tmp->h6;
        tmp->h6 = tmp->h5;
        tmp->h5 = tmp->h4;
        tmp->h4 = (unsigned int)((tmp->h3 + tmp1) % 4294967296);
        tmp->h3 = tmp->h2;
        tmp->h2 = tmp->h1;
        tmp->h1 = tmp->h0;
        tmp->h0 = (unsigned int)((tmp1 + tmp2) % 4294967296);
    }
}

void            mainLoopSha256(unsigned int *X, t_variables *var)
{
    unsigned int	m[64];
    t_variables     tmp;

    for(size_t i = 0, j = 0; i < size / 64; i++, j += 16)
    {
        prepareMessage(X + j, m);
        init_tmp(&tmp, var);
        loop(m, &tmp);
        update_tmp(&tmp, var);
    }
}
