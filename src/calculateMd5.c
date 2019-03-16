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

void    illegalOption(char flag)
{
    printf("md5: illegal option -- %c\n", flag);
    printUsage();
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
        if (cnt->flag != 's' && cnt->flag != 'p' && cnt->flag != 'r'
                 && cnt->flag != 'q' &&
                 !(cnt->flag == 'f' && cnt->isValid == 1))
            illegalOption(cnt->flag);
        else if(cnt->error == 1)
            printf("md5: %s: No such file or directory\n", cnt->fileName);
        else if(cnt->flag == 'p' || cnt->flag == 's' ||
                (cnt->flag == 'f' && cnt->isValid ==1))
        {
            X = step3_md5(step2_md5(step1_md5(cnt), cnt), &var);
            step4_md5(X, &var);
            print_output(&var, cnt);
        }
        cnt = cnt->next;
    }
}
