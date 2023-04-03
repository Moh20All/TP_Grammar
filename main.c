#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*----------------------------------------------------const variabel ------------------------------------------------------*/
#define n 10
#define m 10
#define sz 20
char line[sz];
int contain(char c[],char ch[]);
/*---------------------------------------------------variable global------------------------------------------------------------------------------------*/
typedef struct rule
{
    char g[n];
    char d[n]
}typeR;
//

//
typedef struct
{
    char s[n];
    char vn[n];
    char vt [n];
}typeG;
FILE *grammar;
typeR T[10];
/*--------------------------------------OPEN FICHIER-------------------------------------------*/
int open_fichier()
{

    grammar=fopen("gramar.txt","r");
    if(grammar!=NULL)
        return 1;
    else
        return 0;
}
// -------------------------------- Read File --------------------------------------------
void display(FILE* ptr){

    printf("le contenu de fichier:\n");
    while (fgets(line,sz,ptr)!=NULL)
    {
        printf("%s\n", line);
    }
}
// ------------------------- Fichier Type ---------------------------------
typeG g1;
void store_file(FILE* ptr){

    printf("Reading file info.......\n");
    int i=0;
    while (i<3)
    {
        fgets(line,sz,ptr);
        if(i==0)
        strcpy(g1.vt,line);
        if(i==1)
        strcpy(g1.vn,line);
        if(i==2)
        strcpy(g1.s,line);

        i++;
    }

}
// Store rules into structure
void store_rule(FILE *ptr){
    //
    char *left,*right;
    //
    int i=0,num=0;
    //
    fgets(line,sz,ptr);
    sscanf(line,"%d",&num);
    while(i<num){
        fgets(line,sz,ptr);
        left=strtok(line,"->");
        right=strtok(NULL,"->");
        strcpy(T[i].g,left);
        strcpy(T[i].d,right);
                i++;
    }

Type_search(num);
}
// --------------------------------Search Type ----------------------------------------------
int Type_search(int num){
    int min=999,i=0,k=999;
    int tp3=0,tp2=0,tp1=0,tp0=0;
    while(i<num){
          //  printf("%d   %d",strlen(T[i].g),strlen(T[i].d));
            // Type 3
        if(contain(g1.vn,T[i].g) && contain(g1.vt,T[i].d) && contain(g1.vn,T[i].d) && (strlen(T[i].g)==1)){
            printf("The Type of rule %d : 3\n",i+1);
            tp3++;
            k=3;
            if(k<min)
                min=k;
        }else{
            // Type 2
            if(strlen(T[i].g)==1 && contain(g1.vt,T[i].d)){
                printf("The Type of rule %d : 2\n",i+1);
                tp2++;
                k=2;
            if(k<min)
                min=k;
        }else{
                // Type 1
                if(strlen(T[i].g)==strlen(T[i].d)-1){
                    printf("The Type of rule %d : 1\n",i+1);
                    tp1++;
                    k=1;
            if(k<min)
                min=k;
                }else {//Type 0
                    printf("The Type of rule %d : 0\n",i+1);
                    tp0++;
                    k=0;
            if(k<min)
                min=k;
                }
        }
        }
    i++;
    }
    //////
        printf("------------------------------------------------------------");
        printf("\nLe Type de grammar : %d\n",min);
        printf("Le Nombre de Type 3 : %d\n",tp3);
        printf("Le Nombre de Type 2 : %d\n",tp2);
        printf("Le Nombre de Type 1 : %d\n",tp1);
        printf("Le Nombre de Type 0 : %d\n",tp0);
        Num_ter(num);
}

//////
void Num_ter(int num){
    int min=999,i=0,k=999,flag=0,flag1=0;
     for (int i=0;i<num;i++){
    int j=0;
        while(j<strlen(g1.vn)|| j<strlen(g1.vt)){
          if((T[i].g)[i]==g1.vn[j])
            flag++;
            if((T[i].g)[i]==g1.vt[j])
                flag1++;
            j++;
        }
    printf("------------------------------------------------------------");
    printf("\nLe nombre de non terminal de Rule %d is : %d \n",i+1,flag);
    printf("\nLe nombre de terminal de Rule %d is : %d \n",i+1,flag1);
    }

}
// ------------------------- Main function --------------------------------
int main()
{
   // ------ Open File
   open_fichier();
   // ------ Display File
   display(grammar);
   // ------ Open File
   open_fichier();
   // ------ Type fichier
   store_file(grammar);
   store_rule(grammar);

    return 0;
}

// test Containing character
int contain(char c[],char ch[]){
    int num=strlen(c);
    int flag=0;
    for (int i=0;i<num;i++){
    int j=0;
        while(j<strlen(ch)){
          if(c[i]==ch[j])
            flag=1;
            j++;
        }
    }
    return flag;
}
