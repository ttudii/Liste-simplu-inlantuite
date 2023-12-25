#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define SPATIU " "

struct Element{
    char cuv[15];
    struct Element *next;
};

int main(){

    char *fraza;
    struct Element *p,*q,*cap_lista,*copy;
    int nr=1;
    int out=0;
    char car;

    p=(struct Element*)malloc(sizeof(struct Element));
    p->next=NULL;
    cap_lista=p;

    printf("Cuvantul %d: ",nr);
    //getchar();
    scanf("%s",p->cuv);
    getchar();

    do{

        nr++;

        q=(struct Element*)malloc(sizeof(struct Element));

        printf("Cuvantul %d: ",nr);
        //getchar();
        scanf("%s",q->cuv);
        getchar();

        p->next=q;
        q->next=NULL;
        p=q;

        do{
            printf("Mai introduci?(y sau n)\n");
            scanf("%c",&car);
        }while(tolower(car)!='y' && tolower(car)!='n');

        if(tolower(car)=='n') out=1;
        else
        continue;

    }while(!out);

    copy=cap_lista;

    printf("\n\n");

    printf("primul element din lista are adresa: %p si contine cuvantul %s\n",cap_lista,copy->cuv);

    while(copy!=NULL){
        printf("%s %p\n",copy->cuv,copy->next);
        copy=copy->next;
    }

    //totul ok pana aici

    copy=cap_lista;

    fraza=(char*)malloc(sizeof(char)*strlen(copy->cuv)+1);

    strcpy(fraza,copy->cuv);

    do{

        copy=copy->next;

        fraza=(char*)realloc(fraza,sizeof(char)*(strlen(fraza)+strlen(copy->cuv)+1));
        strcat(fraza," ");
        strcat(fraza,copy->cuv);
        printf("\n\nFraza formata prin concatenare:\n\n");
        printf("%s",fraza);

    }while(copy!=NULL);

    printf("\n\nFraza formata prin concatenare:\n\n");
    printf("%s",fraza);

    return 0;
}