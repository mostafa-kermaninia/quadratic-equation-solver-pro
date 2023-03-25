#include <stdio.h>
#define False 0
#define True 1

int main()
{
    /* The base form is x^3 + ax^2 + bx + c = 0 */
    /* receive inputs from user and declare base variables */
    double a, b, c;
    double funcFault, xFault;
    scanf("%lf\n%lf\n%lf\n%lf", &a, &b, &c, &xFault);

    /* Find absolute value of variables */
    double ABSa = a, ABSb = b, ABSc = c, maxVariable;
    if (a < 0)
        ABSa = -a;
    if (b < 0)
        ABSb = -b;
    if (c < 0)
        ABSc = -c;

    /* Find largest absolute value*/
    if (ABSa >= ABSb && ABSa >= ABSc)
        maxVariable = ABSa;
    else if (ABSb >= ABSa && ABSb >= ABSc)
        maxVariable = ABSb;
    else
        maxVariable = ABSc;

    int haveAns1 = False, haveAns2 = False, haveAns3 = False, isAns = False, answersCount = 0;
    double ans1, ans2, ans3, answersSum = 0, finalAns;
    double func;

    /* adding xFault to condition part is for error prevention in times that the max variable is an answer! */
    /* for more precision you can divide the step, by a number */
    for (double x = -maxVariable; x <= maxVariable + xFault; x += xFault)
    {
        /* If we dont find an answer */
        func = (x * x * x) + (a * x * x) + (b * x) + c;
        funcFault = xFault * (3 * x * x + 2 * a * x + b);
        /* we can add this to funcFault for max precision :
                    xFault * xFault * (a + 3 * x) +
                    xFault * xFault * xFault; */

        /* func fault should be positive */
        if (funcFault < 0)
        {
            funcFault = -funcFault;
        }

        if (-funcFault <= func && func <= funcFault)
        {
            isAns = True;

            answersCount++;
            answersSum += x;
        }

        /* If we dont find an answer but the previous item was the answer */
        else if (isAns == True)
        {
            isAns = False;

            finalAns = answersSum / answersCount;
            answersCount = 0;
            answersSum = 0;

            /* now we should put finalAns in a related variable */
            if (haveAns1 == False && haveAns2 == False && haveAns3 == False)
            {
                ans1 = finalAns;
                haveAns1 = True;
            }
            else if (haveAns1 == True && haveAns2 == False && haveAns3 == False)
            {
                ans2 = finalAns;
                haveAns2 = True;
            }
            else if (haveAns1 == True && haveAns2 == True && haveAns3 == False)
            {
                ans3 = finalAns;
                haveAns3 = True;

                break;
            }
        }
    }

    /* print results */
    if (haveAns1 && haveAns2 && haveAns3)
        printf("%lf\n%lf\n%lf", ans1, ans2, ans3);
    else if (haveAns1 && haveAns2)
        printf("%lf\n%lf\nbedoon rishe", ans1, ans2);
    else if (haveAns1)
        printf("%lf\nbedoon rishe\nbedoon rishe", ans1);
    else
        printf("ERROR! cant find any result", ans1);

    return 0;
} /* ( ͡ಠ ͜ʖ ͡ಠ) */
