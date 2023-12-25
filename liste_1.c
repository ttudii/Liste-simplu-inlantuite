#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Element{
    int val;
    struct Element *next;
};

int main(){

    struct Element *cap_lista,*p,*q,*copy,*aux;
    char car;
    int out=0,nr=1;

    p=(struct Element*)malloc(sizeof(struct Element));
    printf("Elementul %d: ",nr);
    scanf("%d",&p->val);
    getchar();
    p->next=NULL;

    cap_lista=p;

    do{

        nr++;

        q=(struct Element*)malloc(sizeof(struct Element));
        printf("Elementul %d: ",nr);
        scanf("%d",&q->val);
        getchar();
        p->next=q;
        q->next=NULL;
        p=q;

        do{
        printf("Mai introduci?(y sau n)\n");
        scanf("%c",&car);
        getchar();
        }while(tolower(car)!='y' && tolower(car)!='n');

        if(tolower(car)=='n') out=1;


    }while(!out);

    printf("\n\n");

    copy=cap_lista;

    while(copy!=NULL){
        printf("%d ",copy->val);
        copy=copy->next;
    }

    printf("\n\n");

    copy=cap_lista;

    while(copy->val%2==0){
        copy=copy->next;
    }

    printf("%d",copy->val);
    cap_lista=copy;

    while(copy!=NULL){

        if(copy->next->next==NULL && copy->next->val%2==0){
            copy->next=NULL;
            break;
        }
        else

        if(copy->next->next!=NULL && copy->next->val%2==0){
        aux=copy->next;
        copy->next=copy->next->next;
        free(aux);
        }

        else
        copy=copy->next;
    }

    copy=cap_lista;

    printf("\n\nLista dupa eliminare elementelor pare:\n\n");

    while(copy!=NULL){
        printf("%d ",copy->val);
        copy=copy->next;
    }

    printf("\n");


    return 0;

}