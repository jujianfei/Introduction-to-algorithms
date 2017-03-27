// 15158286_AC_532MS_24836K.cc
#include<stdio.h>
#include<string.h>
#define prime  100000000 + 7
unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;

    while (*str)
    {
        hash = hash * seed + (*str++);
    }

    return (hash & 0x7FFFFFFF)%prime;
}
struct Node
{
    char first[12];
    char second[12];
    Node(){}
};
Node a[100000 + 10];
int hashindex[prime];
int main()
{
    //freopen("/home/zlq/acminging/in","r",stdin);
    char buffer[22];
    int index=1;
    while(gets(buffer))
    {
        if(buffer[0] == '\0')	break;
        /*********************/
        sscanf(buffer, "%s %s", a[index].first, a[index].second);
        /*********************/
        int hash_location=BKDRHash(a[index].second);

        hashindex[hash_location]=index;
        index++;

    }
    while(scanf("%s",buffer)!=EOF)
    {
        int tar=BKDRHash(buffer);
        int INDEX=hashindex[tar];
        if(INDEX)
        {
            printf("%s\n",a[INDEX].first);
        }
        else
        {
            printf("eh\n");
        }
    }

}
