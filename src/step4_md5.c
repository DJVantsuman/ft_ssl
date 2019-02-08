#include "../inc/md5.h"

void    raund1(unsigned int *X, t_variables *var, int i)
{
    var->A = var->B + rotate_left((var->A + F(var->B, var->C, var->D) + X[i+ 0] + var->T[ 0]), 7);
    var->D = var->A + rotate_left((var->D + F(var->A, var->B, var->C) + X[i+ 1] + var->T[ 1]), 12);
    var->C = var->D + rotate_left((var->C + F(var->D, var->A, var->B) + X[i+ 2] + var->T[ 2]), 17);
    var->B = var->C + rotate_left((var->B + F(var->C,var->D,var->A) + X[i+ 3] + var->T[ 3]), 22);

    var->A = var->B + rotate_left((var->A + F(var->B ,var->C, var->D) + X[i+ 4] + var->T[ 4]), 7);
    var->D = var->A + rotate_left((var->D + F(var->A, var->B, var->C) + X[i+ 5] + var->T[ 5]), 12);
    var->C = var->D + rotate_left((var->C + F(var->D, var->A, var->B) + X[i+ 6] + var->T[ 6]), 17);
    var->B = var->C + rotate_left((var->B + F(var->C, var->D, var->A) + X[i+ 7] + var->T[ 7]), 22);

    var->A = var->B + rotate_left((var->A + F(var->B, var->C, var->D) + X[i+ 8] + var->T[ 8]), 7);
    var->D = var->A + rotate_left((var->D + F(var->A, var->B, var->C) + X[i+ 9] + var->T[ 9]), 12);
    var->C = var->D + rotate_left((var->C + F(var->D, var->A, var->B) + X[i+10] + var->T[10]), 17);
    var->B = var->C + rotate_left((var->B + F(var->C, var->D, var->A) + X[i+11] + var->T[11]), 22);

    var->A = var->B + rotate_left((var->A + F(var->B, var->C, var->D) + X[i+12] + var->T[12]), 7);
    var->D = var->A + rotate_left((var->D + F(var->A, var->B, var->C) + X[i+13] + var->T[13]), 12);
    var->C = var->D + rotate_left((var->C + F(var->D, var->A, var->B) + X[i+14] + var->T[14]), 17);
    var->B = var->C + rotate_left((var->B + F(var->C, var->D, var->A) + X[i+15] + var->T[15]), 22);
}

void    raund2(unsigned int *X, t_variables *var, int i)
{
    var->A = var->B + rotate_left((var->A + G(var->B, var->C, var->D) + X[i+ 1] + var->T[16]), 5);
    var->D = var->A + rotate_left((var->D + G(var->A, var->B, var->C) + X[i+ 6] + var->T[17]), 9);
    var->C = var->D + rotate_left((var->C + G(var->D, var->A, var->B) + X[i+11] + var->T[18]), 14);
    var->B = var->C + rotate_left((var->B + G(var->C, var->D, var->A) + X[i+ 0] + var->T[19]), 20);

    var->A = var->B + rotate_left((var->A + G(var->B, var->C, var->D) + X[i+ 5] + var->T[20]), 5);
    var->D = var->A + rotate_left((var->D + G(var->A, var->B, var->C) + X[i+10] + var->T[21]), 9);
    var->C = var->D + rotate_left((var->C + G(var->D, var->A, var->B) + X[i+15] + var->T[22]), 14);
    var->B = var->C + rotate_left((var->B + G(var->C, var->D, var->A) + X[i+ 4] + var->T[23]), 20);

    var->A = var->B + rotate_left((var->A + G(var->B, var->C, var->D) + X[i+ 9] + var->T[24]), 5);
    var->D = var->A + rotate_left((var->D + G(var->A, var->B, var->C) + X[i+14] + var->T[25]), 9);
    var->C = var->D + rotate_left((var->C + G(var->D, var->A, var->B) + X[i+ 3] + var->T[26]), 14);
    var->B = var->C + rotate_left((var->B + G(var->C, var->D, var->A) + X[i+ 8] + var->T[27]), 20);

    var->A = var->B + rotate_left((var->A + G(var->B, var->C, var->D) + X[i+13] + var->T[28]), 5);
    var->D = var->A + rotate_left((var->D + G(var->A, var->B, var->C) + X[i+ 2] + var->T[29]), 9);
    var->C = var->D + rotate_left((var->C + G(var->D, var->A, var->B) + X[i+ 7] + var->T[30]), 14);
    var->B = var->C + rotate_left((var->B + G(var->C, var->D, var->A) + X[i+12] + var->T[31]), 20);
}

void    raund3(unsigned int *X, t_variables *var, int i)
{
    var->A = var->B + rotate_left((var->A + H(var->B, var->C, var->D) + X[i+ 5] + var->T[32]), 4);
    var->D = var->A + rotate_left((var->D + H(var->A, var->B, var->C) + X[i+ 8] + var->T[33]), 11);
    var->C = var->D + rotate_left((var->C + H(var->D, var->A, var->B) + X[i+11] + var->T[34]), 16);
    var->B = var->C + rotate_left((var->B + H(var->C, var->D, var->A) + X[i+14] + var->T[35]), 23);

    var->A = var->B + rotate_left((var->A + H(var->B, var->C, var->D) + X[i+ 1] + var->T[36]), 4);
    var->D = var->A + rotate_left((var->D + H(var->A, var->B, var->C) + X[i+ 4] + var->T[37]), 11);
    var->C = var->D + rotate_left((var->C + H(var->D, var->A, var->B) + X[i+ 7] + var->T[38]), 16);
    var->B = var->C + rotate_left((var->B + H(var->C, var->D, var->A) + X[i+10] + var->T[39]), 23);

    var->A = var->B + rotate_left((var->A + H(var->B, var->C, var->D) + X[i+13] + var->T[40]), 4);
    var->D = var->A + rotate_left((var->D + H(var->A, var->B, var->C) + X[i+ 0] + var->T[41]), 11);
    var->C = var->D + rotate_left((var->C + H(var->D, var->A, var->B) + X[i+ 3] + var->T[42]), 16);
    var->B = var->C + rotate_left((var->B + H(var->C, var->D, var->A) + X[i+ 6] + var->T[43]), 23);

    var->A = var->B + rotate_left((var->A + H(var->B, var->C, var->D) + X[i+ 9] + var->T[44]), 4);
    var->D = var->A + rotate_left((var->D + H(var->A, var->B, var->C) + X[i+12] + var->T[45]), 11);
    var->C = var->D + rotate_left((var->C + H(var->D, var->A, var->B) + X[i+15] + var->T[46]), 16);
    var->B = var->C + rotate_left((var->B + H(var->C, var->D, var->A) + X[i+ 2] + var->T[47]), 23);
}

void    raund4(unsigned int *X, t_variables *var, int i)
{
    var->A = var->B + rotate_left((var->A + I(var->B, var->C, var->D) + X[i+ 0] + var->T[48]), 6);
    var->D = var->A + rotate_left((var->D + I(var->A, var->B, var->C) + X[i+ 7] + var->T[49]), 10);
    var->C = var->D + rotate_left((var->C + I(var->D, var->A, var->B) + X[i+14] + var->T[50]), 15);
    var->B = var->C + rotate_left((var->B + I(var->C, var->D, var->A) + X[i+ 5] + var->T[51]), 21);

    var->A = var->B + rotate_left((var->A + I(var->B, var->C, var->D) + X[i+12] + var->T[52]), 6);
    var->D = var->A + rotate_left((var->D + I(var->A, var->B, var->C) + X[i+ 3] + var->T[53]), 10);
    var->C = var->D + rotate_left((var->C + I(var->D, var->A, var->B) + X[i+10] + var->T[54]), 15);
    var->B = var->C + rotate_left((var->B + I(var->C, var->D, var->A) + X[i+ 1] + var->T[55]), 21);

    var->A = var->B + rotate_left((var->A + I(var->B, var->C, var->D) + X[i+ 8] + var->T[56]), 6);
    var->D = var->A + rotate_left((var->D + I(var->A, var->B, var->C) + X[i+15] + var->T[57]), 10);
    var->C = var->D + rotate_left((var->C + I(var->D, var->A, var->B) + X[i+ 6] + var->T[58]), 15);
    var->B = var->C + rotate_left((var->B + I(var->C, var->D, var->A) + X[i+13] + var->T[59]), 21);

    var->A = var->B + rotate_left((var->A + I(var->B, var->C, var->D) + X[i+ 4] + var->T[60]), 6);
    var->D = var->A + rotate_left((var->D + I(var->A, var->B, var->C) + X[i+11] + var->T[61]), 10);
    var->C = var->D + rotate_left((var->C + I(var->D, var->A, var->B) + X[i+ 2] + var->T[62]), 15);
    var->B = var->C + rotate_left((var->B + I(var->C, var->D, var->A) + X[i+ 9] + var->T[63]), 21);
}

void    step4_md5(unsigned int *X, t_variables *var)
{
    unsigned int AA;
    unsigned int BB;
    unsigned int CC;
    unsigned int DD;

    for(int i = 0; i < 0; i++)
    {
        AA = var->A;
        BB = var->B;
        CC = var->C;
        DD = var->D;
        raund1(X, var, i);
        raund2(X, var, i);
        raund3(X, var, i);
        raund4(X, var, i);
        var->A += AA;
        var->B += BB;
        var->C += CC;
        var->D += DD;
    }
}
