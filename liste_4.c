#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Element{
    int nr;
    struct Element *next;
};

int main(){

    struct Element *p,*q,*cap_lista,*copy,*aux;
    int nr=1;
    int out=0;
    char car;

    p=(struct Element*)malloc(sizeof(struct Element));
    printf("Elementul %d: ",nr);
    scanf("%d",&p->nr);

    p->next=NULL;
    cap_lista=p;

    do{

    nr++;
    
    q=(struct Element*)malloc(sizeof(struct Element));
    q->next=NULL;
    p->next=q;
    p=q;
    printf("Elementul %d: ",nr);
    scanf("%d",&q->nr);
    getchar();

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
        printf("%d ",copy->nr);
        copy=copy->next;
    }

    copy=cap_lista;

    if(cap_lista->nr==6){
        printf("Elementul 6 se afla pe prima pozitie\n");
        exit(0);
    }

    while(copy!=NULL){

        if(copy->next->next==NULL && copy->next->nr==6){
            copy->next=NULL;
            break;
        }
        else
        if(copy->next->next!=NULL && copy->next->nr==6){
            aux=copy->next;
            copy->next=copy->next->next;
            free(aux);
            break;
        }
        else
        copy=copy->next;
    }

    printf("\n\n");

    copy=cap_lista;

    while(copy!=NULL){
        printf("%d ",copy->nr);
        copy=copy->next;
    }

    copy=cap_lista;

    struct Element *new;

    new=(struct Element*)malloc(sizeof(struct Element));

    printf("Introduceti valorea de inserat: ");
    scanf("%d",&new->nr);

    new->next=cap_lista->next->next;
    cap_lista->next->next=new;

    printf("Sirul format dupa inserare:\n\n");

    copy=cap_lista;

    while(copy!=NULL){
        printf("%d ",copy->nr);
        copy=copy->next;
    }
    

    return 0;
}