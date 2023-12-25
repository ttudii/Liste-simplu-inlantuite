#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Element{
    char nume[30];
    int varsta;
    struct Element *next;
};

int main(){

    struct Element *cap_lista,*p,*q,*copy,*aux;
    char car;
    int out=0,nr=1;
    char find_name[]={"George"};
    int find_age=19;

    p=(struct Element*)malloc(sizeof(struct Element));
    printf("Elementul %d:\n",nr);
    printf("Nume: ");
    scanf("%s",p->nume);
    getchar();
    printf("Varsta: ");
    scanf("%d",&p->varsta);
    getchar();
    printf("\n\n");
    p->next=NULL;

    cap_lista=p;

    do{

        nr++;

        //se pot face verificari pentru ca numele sa fie unic

        q=(struct Element*)malloc(sizeof(struct Element));
        printf("Elementul %d:\n",nr);
        printf("Nume: ");
        scanf("%s",q->nume);
        getchar();
        printf("Varsta: ");
        scanf("%d",&q->varsta);
        getchar();
        printf("\n");

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
        printf("%s %d\n",copy->nume,copy->varsta);
        copy=copy->next;
    }

    //ok pana aici

    printf("\n\n");

    out=0;
    copy=cap_lista;

    while(!out){

        if(copy->next!=NULL && strcmp(find_name,copy->nume)==0 && copy->varsta==find_age){
            if(copy->next->varsta>=find_age){
                printf("False");
                out=1;
            }
            else
            if(copy->next->varsta<find_age){
                printf("True");
                out=1;
            }

        }
        else
        if(copy->next==NULL && strcmp(find_name,copy->nume)==0 && copy->varsta==find_age){
            printf("Nu poate fi comparat pentru ca este ultimul din sir!");
            break;
        }
        else
        copy=copy->next;
    }

    //se verifica pe rand fiecare element cu find_name si find_age
    //atentie daca George este ultimul element!
    

    return 0;

}

