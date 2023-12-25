#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Produs{
    int id;
    int cant;
    float pret;
    struct Produs *next;
};

int main(){

    struct Produs *p,*q,*cap_lista,*copy,*temp,*aux;
    int nr=1;
    int out=0;
    char car;

    printf("Popularea listei pentru evidenta produselor din magazin:\n\n");

    p=(struct Produs*)malloc(sizeof(struct Produs));
    cap_lista=p;
    p->next=NULL;
    printf("Produsul %d\n\n",nr);
    printf("ID produs: ");
    scanf("%d",&p->id);
    printf("Cantitate produs: ");
    scanf("%d",&p->cant);
    printf("Pret produs: ");
    scanf("%f",&p->pret);
    printf("\n\n");

    do{
    
    nr++;

    q=(struct Produs*)malloc(sizeof(struct Produs));

    q->next=NULL;
    p->next=q;
    p=q;
    printf("Produsul %d\n\n",nr);

    reintroduce:

    printf("ID produs: ");
    scanf("%d",&q->id);

    //verificre id unic

    copy=cap_lista;

    while(copy!=NULL){
        if(copy->id==q->id && copy->next!=NULL){
            printf("Acest produs a mai fost introdus!\n");
            goto reintroduce;
        }
        else
        copy=copy->next;
    }

    printf("Cantitate produs: ");
    scanf("%d",&q->cant);
    printf("Pret produs: ");
    scanf("%f",&q->pret);
    getchar();

    do{
        printf("mai introduci?(y sau n)");
        scanf("%c",&car);
        getchar();
    }while(tolower(car)!='y' && tolower(car)!='n');

    if(tolower(car)=='n') out=1;

    printf("\n");

    }while(!out);


    printf("\n\n");
    printf("Numarul de produse din evidenta este egal cu %d",nr);
    printf("\n\n");



    //popularea cosului de cumparaturi



    printf("Cosul de cumparaturi:\n\n");

    struct Produs *cap_cos,*cos1,*cos2;
    int nr_cos=1;
    char check;
    int count;
    out=0;

    cos1=(struct Produs*)malloc(sizeof(struct Produs));
    cap_cos=cos1;
    cos1->next=NULL;

    printf("Produsul %d\n\n",nr_cos);

    reintroduce_cos1:

    copy=cap_lista;
    count=1;

    printf("ID produs: ");
    scanf("%d",&cos1->id);

    while(copy!=NULL){

        if(copy->id==cos1->id){
            printf("valoarea exista in evidenta!\n");
            break;
        }
        else
        copy=copy->next;

        count++;
    
    }

    if(count==nr+1) 
    {
        printf("valoarea nu exista in evidenta!\n");
        goto reintroduce_cos1;
    }

    temp=copy;

    //verificare ca cantitatea introdusa este <= cu cea din evidenta

    do{
        printf("Cantitate produs: ");
        scanf("%d",&cos1->cant);
        if(temp->cant<cos1->cant) printf("Cantitatea introdusa este prea mare!\n");
    }while(temp->cant<cos1->cant);

     //verificare ca pretul produsului este acelasi ca in evidenta

    do{
        printf("Pret produs: ");
        scanf("%f",&cos1->pret);
        if(temp->pret!=cos1->pret) printf("Acesta nu este pretul produsului!\n");
    }while(temp->pret!=cos1->pret);
   
    getchar();

    printf("\n\n");

    do{
    
    nr_cos++;

    cos2=(struct Produs*)malloc(sizeof(struct Produs));

    cos2->next=NULL;
    cos1->next=cos2;
    cos1=cos2;
    printf("Produsul %d\n\n",nr_cos);

    reintroduce_cos:

    printf("ID produs: ");
    scanf("%d",&cos2->id);

    //verificare ca id-ul produsului exista in lista pentru produse

    copy=cap_lista;
    count=1;

    while(copy!=NULL){

        if(copy->id==cos2->id){
            printf("valoarea exista in evidenta!\n");
            break;
        }
        else
        copy=copy->next;

        count++;
    
    }

    if(count==nr+1) 
    {
        printf("valoarea nu exista in evidenta!\n");
        goto reintroduce_cos;
    }

    temp=copy;

    //verificre id unic

    copy=cap_cos;

    while(copy!=NULL){
        if(copy->id==cos2->id && copy->next!=NULL){
            printf("Acest produs a mai fost introdus!\n");
            goto reintroduce_cos;
        }
        else
        copy=copy->next;
    }

    //verificare ca cantitatea introdusa este <= cu cea din evidenta

    do{
        printf("Cantitate produs: ");
        scanf("%d",&cos2->cant);
        if(temp->cant<cos2->cant) printf("Cantitatea introdusa este prea mare!\n");
    }while(temp->cant<cos2->cant);

     //verificare ca pretul produsului este acelasi ca in evidenta

    do{
        printf("Pret produs: ");
        scanf("%f",&cos2->pret);
        if(temp->pret!=cos2->pret) printf("Acesta nu este pretul produsului!\n");
    }while(temp->pret!=cos2->pret);
   
    getchar();

    do{
        printf("mai introduci?(y sau n)\n");
        scanf("%c",&check);
        getchar();
    }while(tolower(check)!='y' && tolower(check)!='n');

    if(tolower(check)=='n') out=1;

    printf("\n\n");

    }while(!out);

    printf("\n\n");
    printf("In acest moment in cosul de cumparaturi se afla %d produse", nr_cos);
    printf("\n\n");

    //adaugare sau eliminare produse in/din cos, modificarea cantitatilor

    char change;
    out=0;
    char choice;

    do{
        
        do{
            printf("Doresti sa modifici cosul de cumparaturi?(y sau n)\n");
            scanf("%c",&change);
            getchar();
        }while(tolower(change)!='y' && tolower(change)!='n');

    if(tolower(change)=='n') out=1;

    else
{
    do{
        printf("Doresti sa modifici(m), sa adaugi(a) sau se elimini(e) produse din cosul de cumparaturi?\n");
        scanf("%c",&choice);
        getchar();
    }while(tolower(choice)!='m' && tolower(choice)!='a' && tolower(choice)!='e');

    //descrierea fiecarui caz in parte
    
    int modif,new_cant,elim;
    struct Produs *add;
    int ies,erased;

    if(tolower(choice)=='m'){

        reintroduce_modif:

        //int modif;
        //int new_cant;
        
        printf("\n");
        printf("Ce id are produsul pe care vrei il modifici?\n");
        scanf("%d",&modif);
        getchar();

        //verificare ca id-ul produsului exista in cos

        copy=cap_cos;
        count=1;

        while(copy!=NULL){

            if(copy->id==modif){
                printf("valoarea exista in cos!\n");
                break;
            }
            else
            copy=copy->next;

            count++;
    
        }

        if(count==nr_cos+1) 
        {
            printf("valoarea nu exista in cos!\n");
            goto reintroduce_modif;
        }

        //modificare cantitate
         
            reintroduce_cant:

            printf("Care este noua cantitate?");
            scanf("%d",&new_cant);
            getchar();
            temp=cap_lista;
            //ies=0;
            while(temp!=NULL){
                if(temp->id==modif){
                    if(temp->cant<new_cant) {
                        printf("Aceasta cantitate este prea mare!\n");
                        goto reintroduce_cant;
                    }

                    else
                    {
                        break;
                    }
                }
                else
                temp=temp->next;
            }

        copy->cant=new_cant;
        printf("\nProdusul a fost modificat cu succes!\n\n");

    }

    //adaugarea unui nou element

    if(tolower(choice)=='a' && nr_cos!=nr){

    //struct Produs *add;

    add=(struct Produs*)malloc(sizeof(struct Produs));

    //adaugare la finalul cosului

    copy=cap_cos;
    while(copy->next!=NULL) copy=copy->next;
    copy->next=add;
    add->next=NULL;

    printf("\nProdusul adaugat\n\n");

    reintroduce_add:

    printf("ID produs: ");
    scanf("%d",&add->id);
    getchar();

    //verificare ca id-ul produsului exista in lista pentru produse

    copy=cap_lista;
    count=1;

    while(copy!=NULL){

        if(copy->id==add->id){
            printf("valoarea exista in evidenta!\n");
            break;
        }
        else
        copy=copy->next;

        count++;
    
    }

    if(count==nr+1) 
    {
        printf("valoarea nu exista in evidenta!\n");
        goto reintroduce_add;
    }

    temp=copy;

    //verificre id unic

    copy=cap_cos;

    while(copy!=NULL){
        if(copy->id==add->id && copy->next!=NULL){
            printf("Acest produs a mai fost introdus!\n");
            goto reintroduce_add;
        }
        else
        copy=copy->next;
    }

    //verificare ca cantitatea introdusa este <= cu cea din evidenta

    do{
        printf("Cantitate produs: ");
        scanf("%d",&add->cant);
        getchar();
        if(temp->cant<add->cant) printf("Cantitatea introdusa este prea mare!\n");
    }while(temp->cant<add->cant);

     //verificare ca pretul produsului este acelasi ca in evidenta

    do{
        printf("Pret produs: ");
        scanf("%f",&add->pret);
        getchar();
        if(temp->pret!=add->pret) printf("Acesta nu este pretul produsului!\n");
    }while(temp->pret!=add->pret);

    nr_cos++;
    
    printf("\nProdusul a fost adaugat cu succes\n\n");
    }
    else
    if(tolower(choice)=='a' && nr_cos==nr) printf("Deja ai introdus toate produsele in cos!\n\n");

    //eliminarea unui produs din cos

    if(tolower(choice)=='e' && nr_cos>1){

     reintroduce_elim:

        //int elim;
        
        printf("\n");
        printf("Ce id are produsul pe care vrei il elimini?\n");
        scanf("%d",&elim);
        getchar();

        //verificare ca id-ul produsului exista in cos

        copy=cap_cos;
        count=1;

        while(copy!=NULL){

            if(copy->id==elim){
                printf("valoarea exista in cos!\n");
                break;
            }
            else
            copy=copy->next;

            count++;
    
        }

        if(count==nr_cos+1) 
        {
            printf("valoarea nu exista in cos!\n");
            goto reintroduce_elim;
        }

        temp=copy;

        //verifica cazul in care stergi pe prima pozitie!

        copy=cap_cos;
        erased=0;

        while(!erased){
            if(count==1 && copy->id==temp->id){
                aux=copy;
                cap_cos=copy->next;
                free(aux);
                erased=1;
            }
            else
            if(count==nr && copy->next->id==temp->id){
                aux=copy->next;
                copy->next=NULL;
                free(aux);
                erased=1;
            }
            else
            if(copy->next->id==temp->id){
                aux=copy->next;
                copy->next=copy->next->next;
                free(aux);
                erased=1;
            }
            else
            copy=copy->next;

        }

        nr_cos--;
        printf("\nProdusul a fost eliminat cu succes!\n\n");
    
    }
    else
    if(tolower(choice)=='e' && nr_cos<=1) printf("Nu mai poti elimina produse, deoarece cosul va fi gol!\n\n");


}

    }while(!out);

    copy=cap_cos;
    while(copy!=NULL){
        printf("ID: %d\nCantitate: %d\nPret: %3.2f\n\n",copy->id,copy->cant,copy->pret);
        copy=copy->next;
    }

    float pret=0.00;

    copy=cap_cos;
    while(copy!=NULL){
        pret+=(copy->cant*copy->pret);
        copy=copy->next;
    }

    printf("Pretul total al produselor din cosul de cumparaturi este: %3.2f\n\n",pret);

    return 0;

}

// se poate realiza o corelare intre stocul disponibil si pordusele din cos in privinta cantitatii;