#include <stdio.h>
#include <stdlib.h>

int search(char s[], char t, int n);
int fact(int q);

main()
{
    char s[100],p[100],tmp,t;
    int i,j,n,a,sum,k;
    sum=0;

    printf("No. of unique letters : ");
    scanf("%d",&n);

    printf("\nENTER THE ELEMENTS\n");
    for(i=0;i<n;i++)
    {
        printf("s[%d] = ",i);
        scanf("%s",&s[i]);
    }

    printf("\nenter the word to be ranked : ");
    scanf("%s",&p);

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(s[j]>s[j+1])
            {
                tmp=s[j];
                s[j]=s[j+1];
                s[j+1]=tmp;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        t=p[i];
        a=search(s, t, n);
        k=(a*fact(n-1-i));
        sum=sum+k;
    }
    if(p[n-2]>p[n-1])
       printf("required word is present at position : %d",(sum+2));
    else
        printf("required word is present at position : %d",(sum+1));
}

int search(char s[], char t, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(t==s[i])
            return i;
    }
}

int fact(int q)
{
    int pdt;
    pdt=1;
    if(q==0 || q==1)
        return (0);
    while(q>0)
    {
        pdt=pdt*q;
        q--;
    }
    return pdt;
}
