//Allali Mohamed Baha Eddine
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//FILE *f = NULL;


int type_01(char c[]){
        char *left = strtok(c, "->");
         printf("%s\n",left);
        char *right = strtok(NULL, "->");
         printf("%s\n",right);
        if (strlen(left) <= strlen(right)) {
            return 1;
        }
        else
             return 0;
}
int type_02(char c[]){
    //char *left1 = strtok(c," ");
    if(c[1] == '-' && !islower(c[0]))
        return 1;
    else
      return 0;
}

int type_03(char c[]){
    int x = 0;
     while (c[x] != '\0') {
        x++;
    }
        char *left2= strtok(c," ");
    if(c[1] == '-' && !isupper(c[0]) )
        return 0;
    else if ( (isupper(c[3]) && islower(c[x-1])) /*|| (islower(c[3]) && isupper(c[strlen(c)]))*/ ){
        return 1;
    }
    else if(islower(c[3]) && isupper(c[x-1])){
        return 1;
    }
    /*else if (islower(c[3]) && islower(c[strlen(c)]))
        return 0;*/
    else
        return 0;
}

int main()
{
    char c[10];
    printf("the language : ");
    gets(c);
    printf("%s\n",c);
    if(type_03(c) == 1)
        printf("type 3");
    else if(type_02(c) == 1)
        printf("type 2");
    else if(type_01(c) == 1)
        printf("type 1");
    else
        printf("type 0");
}


int type_re(FILE *file){
    fgets(txt,100,file);    i=1;
    while(txt[i-1]!='>')    {
        i++;
    }    if(txt[i]=='$')//type 4
    {        return 4;
    }    if(i==3)//type 2 or type 3
    {        while(txt[i]!='\0'&&txt[i]!='\n')
        {            if(contain(i,'t')==0){
                        if(contain(i-1,'t')==0){
                            return 2;
                }            }
            i++;
             }
        return 3;    }
    else//type 1 or type 0    {
    j=0;    k=parcore(i,j);//u
    if(k==0)//not find u        {
            return 0;        }
        else        {
            //k=parcore(i,j);//u            i=i+k+1;
            j=j+k+1;//vt            k=parcore(i,j);//v
            i=i+k;            j=j+k;
            if(txt[i]=='\0'||txt[i]=='\n')            {
                return 1;            }
            return 0;        }
    }}
