#include "../inc/ssl.h"
#include "../inc/md5.h"
#include "../inc/sha256.h"

unsigned char *step2_sha256(unsigned char *msg, t_container *var)
{
    size_t length_bit;

    length_bit = var->message_len * 8;

    for (size_t i = 0; i < 4; i ++)
    {
        msg[size - 4 + i] = (unsigned char)(length_bit >> i * 8);
    }
    return msg;
}

unsigned int    *step3_sha256(unsigned char *msg)
{
    unsigned int *X;

    X = (unsigned int *)malloc(size / 4);
    X = (unsigned int *)(msg);
    X[(size / 4) - 1] = rev_bit(X[(size / 4) - 1]);
    return X;
}

void            initializeT(t_variables     *var)
{
    unsigned int	k[] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b,
        0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74,
        0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f,
        0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3,
        0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354,
        0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819,
        0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3,
        0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa,
        0xa4506ceb, 0xbef9a3f7, 0xc67178f2 };
    int					i;

    i = -1;
    while (++i < 64)
        var->T[i] = k[i];
}

void            initializeH(t_variables     *var)
{
    var->h0 = 0x6A09E667;
    var->h1 = 0xBB67AE85;
    var->h2 = 0x3C6EF372;
    var->h3 = 0xA54FF53A;
    var->h4 = 0x510E527F;
    var->h5 = 0x9B05688C;
    var->h6 = 0x1F83D9AB;
    var->h7 = 0x5BE0CD19;
}

void    illegalOpt(char flag)
{
    printf("sha256: illegal option -- %c\n", flag);
    printUsage();
}

void            calculateSHA256(t_container **container)
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
            illegalOpt(cnt->flag);
        else if(cnt->error == 1)
            printf("md5: %s: No such file or directory\n", cnt->fileName);
        else if(cnt->flag == 'p' || cnt->flag == 's' ||
                (cnt->flag == 'f' && cnt->isValid ==1))
        {
            initializeH(&var);
            initializeT(&var);
            X = step3_sha256(step2_sha256(step1_md5(cnt), cnt));
            mainLoopSha256(X, &var);
            print_outputSha256(&var, cnt);
        }
        cnt = cnt->next;
    }
}
