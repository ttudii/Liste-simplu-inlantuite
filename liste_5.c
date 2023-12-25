#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Student{
    char nume[21];
    int nr_matricol;
    int cod[3];
    float medie[3];
    struct Student *next;
};

int main(){

    struct Student *p,*q,*cap_lista,*copy,*new,*temp;
    int nr=1,i;
    int out=0;
    char car;
    float *medie_stud;
    float medie_tot=0;

    new=(struct Student*)malloc(sizeof(struct Student));

    p=(struct Student*)malloc(sizeof(struct Student));

    p->next=NULL;
    cap_lista=p;
    
    //introducerea datelor]

    printf("Studentul %d\n\n",nr);
    printf("Introduceti numele: ");
    scanf("%s",p->nume);
    getchar();
    printf("Numarul matricol: ");
    scanf("%d",&p->nr_matricol);
    p->cod[0]=1;
    p->cod[1]=2;
    p->cod[2]=3;
    printf("Codul materiei I: %d, iar media obtinuta este: ",p->cod[0]);
    scanf("%f",&p->medie[0]);
    printf("Codul materiei II: %d, iar media obtinuta este: ",p->cod[1]);
    scanf("%f",&p->medie[1]);
    printf("Codul materiei III: %d, iar media obtinuta este: ",p->cod[2]);
    scanf("%f",&p->medie[2]);
    getchar();
    printf("\n\n");

    do{

    nr++;
    
    q=(struct Student*)malloc(sizeof(struct Student));

    q->next=NULL;
    p->next=q;
    p=q;

        //introducerea datelor

    printf("Studentul %d\n\n",nr);
    printf("Introduceti numele: ");
    scanf("%s",q->nume);
    getchar();

    reintroduce:
    
    printf("Numarul matricol: ");
    scanf("%d",&q->nr_matricol);

    copy=cap_lista;

    while(copy!=NULL){
        if(copy->nr_matricol==q->nr_matricol && copy->next!=NULL){
            printf("Acest cod matricol a mai fost introdus!\n");
            goto reintroduce;
        }
        else
        copy=copy->next;
    }

    q->cod[0]=1;
    q->cod[1]=2;
    q->cod[2]=3;
    printf("Codul materiei I: %d, iar media obtinuta este: ",q->cod[0]);
    scanf("%f",&q->medie[0]);
    printf("Codul materiei II: %d, iar media obtinuta este: ",q->cod[1]);
    scanf("%f",&q->medie[1]);
    printf("Codul materiei III: %d, iar media obtinuta este: ",q->cod[2]);
    scanf("%f",&q->medie[2]);
    getchar();
    printf("\n\n");

    do{
        printf("mai introduci?(y sau n)");
        scanf("%c",&car);
        getchar();
    }while(tolower(car)!='y' && tolower(car)!='n');

    if(tolower(car)=='n') out=1;

    }while(!out);

    //media tuturor studentilor;

    i=0;

    medie_stud=(float*)malloc(sizeof(float)*nr);

    copy=cap_lista;

    while(copy!=NULL){

        *(medie_stud+i)=(copy->medie[0]+copy->medie[1]+copy->medie[2])/3;
        medie_tot+=*(medie_stud+i);
        i++;
        copy=copy->next;

    }

    medie_tot=medie_tot/(float)nr;

    printf("Media generala a grupei este: %3.2f\n",medie_tot);

    float max;
    int indice;

    max=*(medie_stud);
    i=1;
    copy=cap_lista;

    while(i<nr){
        if(max<*(medie_stud+i)){
            max=*(medie_stud+i);
            indice=i;
        }
    i++;
    }

    int j;

    j=0;
    copy=cap_lista;

    while(j<indice){
        copy=copy->next;
        j++;
    }

    printf("Premiantul clasei este studentul cu numele %s si cu numarul matricol %d",copy->nume,copy->nr_matricol);

    //adaugare provizorie student

    copy=cap_lista;

    while(copy->next!=NULL) copy=copy->next;

    copy->next=new;
    new->next=NULL;

    printf("\n\n");

    printf("Studentul nou\n\n");
    printf("Introduceti numele: ");
    scanf("%s",new->nume);
    getchar();

    reintroduce_new:
    
    printf("Numarul matricol: ");
    scanf("%d",&new->nr_matricol);

    copy=cap_lista;

    while(copy!=NULL){
        if(copy->nr_matricol==new->nr_matricol && copy->next!=NULL){
            printf("Acest cod matricol a mai fost introdus!\n");
            goto reintroduce_new;
        }
        else
        copy=copy->next;
    }

    new->cod[0]=1;
    new->cod[1]=2;
    new->cod[2]=3;
    printf("Codul materiei I: %d, iar media obtinuta este: ",new->cod[0]);
    scanf("%f",&new->medie[0]);
    printf("Codul materiei II: %d, iar media obtinuta este: ",new->cod[1]);
    scanf("%f",&new->medie[1]);
    printf("Codul materiei III: %d, iar media obtinuta este: ",new->cod[2]);
    scanf("%f",&new->medie[2]);
    getchar();
    printf("\n\n");

    //verificare ca noul student a fost adaugat

    copy=cap_lista;

    while(copy!=NULL){
        printf("%s\n",copy->nume);
        copy=copy->next;
    }

    printf("\n\n");


    //ordonarea cu noul student

    copy=cap_lista;

    int trecere=0;

    while(copy->next!=new){
        //verificare daca este inaintea prmului element
        if(trecere==0 && strcmp(copy->nume,new->nume)>0){
            cap_lista=new;
            new->next=copy;
            break;
        }
        trecere=1;

        if(strcmp(copy->nume,new->nume)<0 && strcmp(copy->next->nume,new->nume)>0){
            //temp=copy;
            new->next=copy->next;
            copy->next=new;
            break;
        }
        else{
        copy=copy->next;
        }

    }

    i=1;
    copy=cap_lista;

    while(i<=nr){
        copy=copy->next;
        i++;
    }

    copy->next=NULL;

    //verificare noul sir a fost aranjat in ordine alfabetica

    printf("\n\n");

    copy=cap_lista;

    while(copy!=NULL){
        printf("%s\n",copy->nume);
        copy=copy->next;
    }


    //eliminare din sir elementul al treilea si afisarea primelor 4 nume

    nr++;

    copy=cap_lista;

    //ajungem la elementul 2

    copy=copy->next;

    //realizam stergerea

    temp=copy->next;
    copy->next=copy->next->next;
    free(temp);

    //afisarea sirului astfel format (primele 4 nume pentru confirmare)

    printf("\n\n");
    printf("Stergerea s-a realizat cu succes!\n\n");

    copy=cap_lista;
    i=1;

    while(i<=4){
        printf("%s\n",copy->nume);
        copy=copy->next;
        i++;
    }


    return 0;
}


//ordonarea dupa adaugarea noului student pe ultima pozitie;
//eliminarea celui de al treilea student;