#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**************************************************const variabel ********************************************************************************************/
#define n 10
#define m 10

/****************************************************variable global *******************************************************************************************/
typedef struct
{
    char g[m];
    char d[m];
}typeR;
typedef struct
{
    char s;
    char vn[n];
    char vt [n];
    typeR R[n];
}typeG;
FILE *grammar;

/****************************************************OPEN FICHIER****************************************************************************************/
int open_fichier()
{

    grammar=fopen("gramar.txt","r");
    if(grammar!=NULL)
        return 1;
    else
        return 0;
}
/****************************************************READ GRAMMER***********************************************************************************/
typeG G;
void read_grammer()
{
    char c;
    int i=0,j;
    c=getc(grammar);
    G.s=c;
    c=getc(grammar);
    c=getc(grammar);
    while(c!=EOF && c!='\n')
    {
        G.vt[i]=c;
        i++;
        c=getc(grammar);
    }
    if(c==EOF)
    {
        printf("la fichier terrminer");
    }
    else
    {
        c=getc(grammar);
        i=0;
        while(c!=EOF && c!='\n')
    {
        G.vn[i]=c;
        i++;
        c=getc(grammar);
    }
    if(c==EOF)
    {
        printf("la fichier terrminer");
    }
    else
    {
        c=getc(grammar);
        i=0;
         while(c!=EOF)
         {
          j=0;
        while( c!=' ')
    {
        G.R[i].g[j]=c;
        j++;
        c=getc(grammar);
    }
    j=0;
    c=getc(grammar);
    while(c!='\n'&& c!=EOF)
        {

        G.R[i].d[j]=c;
        //printf("%c", G.R[i].d[j]);
        j++;
        c=getc(grammar);
    }
    if(c==EOF)
    {
        printf("la fichier terrminer");
    }
    else
       {

       c=getc(grammar);
        i++; }
    }
    }
}
}
/****************************************************afich fichier *******************************************************************************************/
int show_grammer()
{
    int i=0;
    printf("\naxiom : %c.\n",G.s);
    printf("Vt={ %s}\n",G.vt);
    printf("Vn={%s}\n",G.vn);
    printf("R=\n");
    while(G.R[i].g[0]!='\0')
    {
        printf("%s -->%s\n",G.R[i].g,G.R[i].d);
        i++;
    }

}
/****************************************************recherch dans vt***************************************************************************************/
int find_vt(char c)
{
    int f =0,I;
    for (I=0;I<strlen(G.vn);I++)
    {
        if (G.vt[I]==c)
        {
            f=1;
        }
    }
    return f;
}
/****************************************************recherch dans vn***************************************************************************************/
int find_vn(char c)
{
    int f =0,I;
    for ( I=0;I<strlen(G.vn);I++)
    {
        if (G.vn[I]==c)
        {
            f=1;
        }
    }
    return f;
}
/******************************************************test type de regel **************************************************************************************/
int  type_R (int i)
{
    if (strlen (G.R[i].g)==1)
    {
        if((strlen (G.R[i].d)==2 && find_vt(G.R[i].d[1])==1 )||(strlen (G.R[i].d)==2 && find_vt(G.R[i].d[1])==1  && find_vn(G.R[i].d[2])==1 )||(strlen (G.R[i].d)-1==2 && find_vt(G.R[i].d[2])==1  && find_vn(G.R[i].d[1])==1 ))
        {
             return 3;//type 3
        }
        else
        {
            if (strlen(G.R[i].d)>=1 )
            {
               return 2;//type 2
            }
        }
    }
    else
    {int j,test=0;
    while((find_vt(G.R[i].g[j])==1 )&&j<strlen(G.R[i].g) )
    {
        j++;test=1;
    }
    int a,z,q,w;
    j=a;
  while((find_vt(G.R[i].g[j])==1 )&&j<strlen(G.R[i].d) )
        {
            j++;test=1;
        }
        j=z;
    while((find_vt(G.R[i].g[j])==1 )&&j<strlen(G.R[i].g) )
      {
        j++;test=1;
      }
      while(q<a&&w<z)
      {
          if((strcasecmp(G.R[i].g[q],G.R[i].g[w]))==0)
            {test=1;q++;z++;}
          else {test=0;}
      }


        if(test==1 )
        {
            return 1;//type 1
        }
        else
        {
            return 0;//type 0
        }
    }
}
/******************************************************test type de grammer ********************************************************************************/
int type_G()
{
    int type =3 ;
    int i=0,x;
while (G.R[i].g[0]!='\0')
{
    x=type_R(i);
    if(x<=type)
    {

type=x;
    }
    i++;
}
return type; //type de grammer
}
/*******************************************************programme principale******************************************************************************/
int main()
{
    int x,co;
    if(open_fichier()==0)
    {
        printf("la fichier n'exist pas\n");
    }
    else
    {
        printf("la fichier est open\n");
        printf("tap any key to contune\n");
        getchar();
        read_grammer();
        printf("\nla grammer dans le programme\n");
        show_grammer();
        x=type_G();
        printf("le type du grammer est : type %d\n",x);
       }
    return 1;
}
