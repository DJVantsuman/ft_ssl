#include "../inc/md5.h"

void    print_output(t_variables *var, t_container *cnt)
{
    if (cnt->isQuiet == 1 || cnt->flag == 'p')
        printf("%.8x%.8x%.8x%.8x\n",
               rev_bit(var->A), rev_bit(var->B), rev_bit(var->C), rev_bit(var->D));
    else if (cnt->flag == 'f' && cnt->isRevers == 0)
        printf("MD5 (%s) = %.8x%.8x%.8x%.8x\n", cnt->fileName,
               rev_bit(var->A), rev_bit(var->B), rev_bit(var->C), rev_bit(var->D));
    else if (cnt->isRevers == 1 && cnt->flag == 'f')
        printf("%.8x%.8x%.8x%.8x %s\n", rev_bit(var->A),
               rev_bit(var->B), rev_bit(var->C), rev_bit(var->D), cnt->fileName);
    else if (cnt->isRevers == 1)
        printf("%.8x%.8x%.8x%.8x \"%s\"\n", rev_bit(var->A),
               rev_bit(var->B), rev_bit(var->C), rev_bit(var->D), cnt->message);
    else
        printf("MD5 (\"%s\") = %.8x%.8x%.8x%.8x\n", cnt->message,
               rev_bit(var->A), rev_bit(var->B), rev_bit(var->C), rev_bit(var->D));
}

void    print_outputSha256(t_variables *var, t_container *cnt)
{
    if (cnt->isQuiet == 1 || cnt->flag == 'p')
        printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n",
                var->h0, var->h1, var->h2, var->h3,
                var->h4, var->h5, var->h6, var->h7);
    else if (cnt->flag == 'f' && cnt->isRevers == 0)
        printf("SHA256 (%s) = %.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n", cnt->fileName,
               var->h0, var->h1, var->h2, var->h3,
               var->h4, var->h5, var->h6, var->h7);
    else if (cnt->isRevers == 1 && cnt->flag == 'f')
        printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x  %s\n",
                var->h0, var->h1, var->h2, var->h3,
                var->h4, var->h5, var->h6, var->h7,
               cnt->fileName);
    else if (cnt->isRevers == 1)
        printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x  \"%s\"\n",
               var->h0, var->h1, var->h2, var->h3,
               var->h4, var->h5, var->h6, var->h7,
               cnt->message);
    else
        printf("SHA256 (\"%s\") = %.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n", cnt->message,
                var->h0, var->h1, var->h2, var->h3,
                var->h4, var->h5, var->h6, var->h7);
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
