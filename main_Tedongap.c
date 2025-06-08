#include<stdio.h>
#include<stdlib.h>
#include "fonction_Tedongap.h"
int main()
{
    int songoTE[3][7];
    int resTE=0;
    int *joueur_actuelTE=malloc(sizeof(int)),pos_yTE;
    *joueur_actuelTE=0;
    joueur playerTE[2];
    playerTE[0].id=1;
    playerTE[1].id=2;
    playerTE[0].nbr_pion_manger=0;
    playerTE[1].nbr_pion_manger=0;
    dessin_plateauTE(songoTE);
    while(gagne_jeu(*joueur_actuelTE,playerTE)==0)
    {
        system("clear");
        affichage_tableau(songoTE);
        printf("joueur %d allez y\n",*joueur_actuelTE+1);
        printf("colonne:");
        scanf("%d",&pos_yTE);
        printf("\n");
        while(choix_colonne(songoTE,pos_yTE,*joueur_actuelTE,playerTE)==0)
        {
            system("clear");
            affichage_tableau(songoTE);
            printf("colonne:");
            scanf("%d",&pos_yTE);
            printf("\n");
        }
        pos_yTE--;
        resTE=jouer(songoTE,pos_yTE,*joueur_actuelTE,playerTE);
        if(resTE==1)
        {
            *joueur_actuelTE=*joueur_actuelTE;
        }
        else
        {
            *joueur_actuelTE=(*joueur_actuelTE+1)%2;
        }
    }
    

} 