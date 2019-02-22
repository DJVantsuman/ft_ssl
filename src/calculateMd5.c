#include "../inc/ssl.h"
#include "../inc/md5.h"

void    checkFlags(t_container **container, int isRevers, int isQuiet)
{
    t_container *var;

    var = *container;
    while(var)
    {
        if(var->flag == 'r')
            isRevers = 1;
        else if (var->flag == 'q')
            isQuiet = 1;
        if ((var->flag == 's' || var->flag == 'p' || var->flag == 'f')
                 && isRevers == 1)
        {
            var->isRevers = 1;
            isRevers = 0;
        }
        if ((var->flag == 's' || var->flag == 'p' || var->flag == 'f')
                 && isQuiet == 1)
        {
            var->isQuiet = 1;
            isQuiet = 0;
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
    checkFlags(container, 0, 0);
    while(cnt)
    {
        if(cnt->flag == 'p' || cnt->flag == 's' ||
                (cnt->flag == 'f' && cnt->isValid ==1))
        {
            var.A = 0x67452301;
            var.B = 0xefcdab89;
            var.C = 0x98badcfe;
            var.D = 0x10325476;
            X = step3_md5(step2_md5(step1_md5(cnt), cnt), &var);
            step4_md5(X, &var);
            print_output(&var, cnt);
        }
        else if (cnt->flag != 's' && cnt->flag != 'p' && cnt->flag != 'r'
                 && cnt->flag != 'q' &&
                 !(cnt->flag == 'f' && cnt->isValid == 1))
            printf("ERROR: Wrong flag \"%c\"\n", cnt->flag);
        cnt = cnt->next;
    }
}
