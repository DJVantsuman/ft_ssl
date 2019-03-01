#include "../inc/md5.h"

void    print_output(t_variables *var, t_container *cnt)
{
    printf("Flag = %c; Revers = %d; Quite = %d\n", cnt->flag, cnt->isRevers, cnt->isQuiet);
    if (cnt->isQuiet == 1 || (cnt->flag == 'f' && cnt->isRevers == 0))
        printf("%.8x%.8x%.8x%.8x\n",
               rev_bit(var->A), rev_bit(var->B), rev_bit(var->C), rev_bit(var->D));
    else if (cnt->isRevers == 1 && cnt->flag == 'f')
        printf("%.8x%.8x%.8x%.8x (\"%s\")\n", rev_bit(var->A),
               rev_bit(var->B), rev_bit(var->C), rev_bit(var->D), cnt->fileName);
    else
        printf("(\"%s\") = %.8x%.8x%.8x%.8x\n", cnt->message,
               rev_bit(var->A), rev_bit(var->B), rev_bit(var->C), rev_bit(var->D));
}

void    print_outputSha256(t_variables *var, t_container *cnt)
{
    printf("Flag = %c; Revers = %d; Quite = %d\n", cnt->flag, cnt->isRevers, cnt->isQuiet);
    if (cnt->isQuiet == 1 || (cnt->flag == 'f' && cnt->isRevers == 0))
        printf("%.8x%.8x%.8x%.8x\n",
               rev_bit(var->A), rev_bit(var->B), rev_bit(var->C), rev_bit(var->D));
    else if (cnt->isRevers == 1 && cnt->flag == 'f')
        printf("%.8x%.8x%.8x%.8x (\"%s\")\n", rev_bit(var->A),
               rev_bit(var->B), rev_bit(var->C), rev_bit(var->D), cnt->fileName);
    else
        printf("(\"%s\") = %.8x%.8x%.8x%.8x\n", cnt->message,
               rev_bit(var->A), rev_bit(var->B), rev_bit(var->C), rev_bit(var->D));
}

unsigned int    rev_bit(unsigned int var)
{
    unsigned int t;

    t = var << 24;
    t += (var & 65280) << 8;
    t += (var & 16711680) >> 8;
    t += var >> 24;
    return t;
}
