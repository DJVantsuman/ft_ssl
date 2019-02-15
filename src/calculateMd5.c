#include "../inc/ssl.h"
#include "../inc/md5.h"

void print_hex(t_variables *var)
{
    printf(" A = %.8x B = %.8x C = %.8x D = %.8x\n", var->A, var->B, var->C, var->D);
}

void    checkFlags(t_container **container)
{
    t_container *var;

    var = *container;
    while(var)
    {
        if(var->flag != 'p' && var->flag != 's' &&
                var->flag != 'r' && var->flag != 'q')
        {
            var->isValid = 0;
            printf("ERROR: Wrong flag \"%c\"\n", var->flag);
        }
        var = var->next;
    }
}

void    calculateMd5(t_container **container)
{
    t_container     *cnt;
    t_variables     var;
    unsigned int    *X;

    cnt = *container;
    checkFlags(container);
    while(cnt)
    {
        var.A = 0x67452301;
        var.B = 0xefcdab89;
        var.C = 0x98badcfe;
        var.D = 0x10325476;
        X = step3_md5(step2_md5(step1_md5(cnt), cnt), &var);
        step4_md5(X, &var);
        print_hex(&var);
        cnt = cnt->next;
    }
}
