#include<stdio.h>
#include"fonction_Tedongap.h"
void dessin_plateauTE(int tabTE[3][7])
{
    for(int i=0;i<7;i++)
    {
        tabTE[0][i]=5;
        tabTE[2][i]=5;
    }
    tabTE[1][0]=0;
    tabTE[1][1]=0;
    tabTE[1][5]=0;
    tabTE[1][6]=0;
}
void affichage_tableau(int tabTE[3][7])
{
    printf("     PLAYER 1\n");
    printf("    ----------------------------------------------------\n");
    for(int i=0;i<7;i++)
    {
    
    printf("    |%d |",tabTE[0][i]);
    }
    printf("\n");
    printf("    ----------------------------------------------------\n");
    printf("    |  %d  |                                  ",tabTE[1][0]+tabTE[1][1]);
    printf("    |  %d  |\n",tabTE[1][5]+tabTE[1][6]);
     printf("    ----------------------------------------------------\n");
    for(int i=0;i<7;i++)
    {
        printf("    |%d |",tabTE[2][i]);
    }
    printf("\n");
    printf("    ----------------------------------------------------\n");
     printf("                                               PLAYER 2\n");
}
int jouer(int tabTE[3][7],int pos_yTE,int joueur_actuelTE,joueur joueurTE[2])//idenetifiant sont 1 et 2
{
    int flagTE;
    int flagTE2=0;
    int nbrTE;
    if(joueurTE[joueur_actuelTE].id==2)
    {
        nbrTE=tabTE[2][pos_yTE];
        tabTE[2][pos_yTE]=0;
        while(nbrTE>0)
        {
            while(nbrTE>0&&pos_yTE>0)
            {
                pos_yTE--;
                tabTE[2][pos_yTE]++;
                nbrTE--;
                flagTE=0;
            }
            if(nbrTE!=0&&pos_yTE==0)
            {
                tabTE[0][pos_yTE]++;
                nbrTE--;
                while(nbrTE>0&&pos_yTE<6)
                {
                    pos_yTE++;
                    tabTE[0][pos_yTE]++;
                    nbrTE--;
                    flagTE=1;
                }
                if(nbrTE!=0&&pos_yTE==6)
                {
                     tabTE[2][pos_yTE]++;
                    nbrTE--;
                    flagTE=0;
                }
            }
        }
        if(flagTE==1)
        {
            if(2<=tabTE[0][0]&&tabTE[0][0]<=4&&2<=tabTE[0][1]&&tabTE[0][1]<=4&&2<=tabTE[0][2]&&tabTE[0][2]<=4&&2<=tabTE[0][3]&&2<=tabTE[0][3]<=4&&2<=tabTE[0][4]&&tabTE[0][4]<=4&&2<=tabTE[0][5]&&tabTE[0][5]<=4&&2<=tabTE[0][6]&&tabTE[0][6]<=4)//interdit2
            {
                    return 0;
            }
            else
            {
            if(tabTE[0][pos_yTE]==2||tabTE[0][pos_yTE]==4)
            {
                int val=tabTE[0][pos_yTE];
                tabTE[0][pos_yTE]=0;
                tabTE[1][5]+=val/2;
                tabTE[1][6]+=val-(val/2);
                flagTE2=1;
            }
            else if((tabTE[0][pos_yTE]==2&&tabTE[0][pos_yTE-1]==2)||(tabTE[0][pos_yTE]==4&&tabTE[0][pos_yTE-1]==4))
            {
                if(2<=tabTE[0][0]==tabTE[0][1]==tabTE[0][2]==tabTE[0][3]==tabTE[0][4]==tabTE[0][5]==tabTE[0][6]<=4)
                {
                    return 0;
                }
                else
                {
                int val=tabTE[0][pos_yTE]+tabTE[0][pos_yTE-1];
                tabTE[0][pos_yTE]=0;
                tabTE[0][pos_yTE-1]=0;
                tabTE[1][5]+=val/2;
                tabTE[1][6]+=val-(val/2);
                flagTE2=1;
                }
            }
        }
        }
        joueurTE[joueur_actuelTE].nbr_pion_plateau=0;
         joueurTE[joueur_actuelTE].nbr_pion_manger=0;
        for(int i=0;i<7;i++)
        {
            joueurTE[joueur_actuelTE].nbr_pion_plateau+=tabTE[2][i];
        }
        int res=tabTE[1][5]+tabTE[1][6];
        joueurTE[joueur_actuelTE].nbr_pion_manger+=res;
        if(flagTE2==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if(joueurTE[joueur_actuelTE].id==1)
    {
        nbrTE=tabTE[0][pos_yTE];
        tabTE[0][pos_yTE]=0;
        while(nbrTE>0)
        {
            while(nbrTE>0&&pos_yTE<6)
            {
                pos_yTE++;
                tabTE[0][pos_yTE]++;
                nbrTE--;
                flagTE=0;
            }
            if(nbrTE!=0&&pos_yTE==6)
            {
                tabTE[2][pos_yTE]++;
                nbrTE--;
                while(nbrTE>0&&pos_yTE>0)
                {
                    pos_yTE--;
                    tabTE[2][pos_yTE]++;
                    nbrTE--;
                    flagTE=1;
                }
                if(nbrTE!=0&&pos_yTE==0)
                {
                     tabTE[0][pos_yTE]++;
                    nbrTE--;
                    flagTE=0;
                }
            }
        }
         if(flagTE==1)
        {
            if(2<=tabTE[2][0]&&tabTE[2][0]<=4&&2<=tabTE[2][1]&&tabTE[2][1]<=4&&2<=tabTE[2][2]&&tabTE[2][2]<=4&&2<=tabTE[2][3]&&2<=tabTE[2][3]<=4&&2<=tabTE[2][4]&&tabTE[2][4]<=4&&2<=tabTE[2][5]&&tabTE[2][5]<=4&&2<=tabTE[2][6]&&tabTE[2][6]<=4)//interdit 2
            {
                    return 0;
            }
            else
            {
            if(tabTE[2][pos_yTE]==2||tabTE[2][pos_yTE]==4)
            {
                if( 2<=tabTE[2][0]==tabTE[2][1]==tabTE[2][2]==tabTE[2][3]==tabTE[2][4]==tabTE[2][5]==tabTE[2][6]<=4)//interdit 2
                {
                    return 0;
                }
                else
                {
                int val=tabTE[2][pos_yTE];
                tabTE[2][pos_yTE]=0;
                tabTE[1][0]+=val/2;
                tabTE[1][1]+=val-(val/2);
                flagTE2=1;
                }
            }
            else if((tabTE[2][pos_yTE]==2&&tabTE[2][pos_yTE+1]==2)||(tabTE[2][pos_yTE]==4&&tabTE[2][pos_yTE+1]==4))
            {
                 if( 2<=tabTE[2][0]==tabTE[2][1]==tabTE[2][2]==tabTE[2][3]==tabTE[2][4]==tabTE[2][5]==tabTE[2][6]<=4)//interdit 2
                {
                    return 0;
                }
                else
                {
                int val=tabTE[2][pos_yTE]+tabTE[2][pos_yTE+1];
                tabTE[2][pos_yTE]=0;
                tabTE[2][pos_yTE+1]=0;
                tabTE[1][0]+=val/2;
                tabTE[1][1]+=val-(val/2);
                flagTE2=1;
                }
            }
        }
        }
        joueurTE[joueur_actuelTE].nbr_pion_plateau=0;
         joueurTE[joueur_actuelTE].nbr_pion_manger=0;
        for(int i=0;i<7;i++)
        {
            joueurTE[joueur_actuelTE].nbr_pion_plateau+=tabTE[0][i];
        }
        int res=tabTE[1][0]+tabTE[1][1];
        joueurTE[joueur_actuelTE].nbr_pion_manger+=res;
        if(flagTE2==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}
 int choix_colonne(int tabTE[3][7],int pos_yTE,int joueur_actuelTE,joueur playerTE[2])//renvoie 1 si le choix est possible 0 sinon ici on gere l'interdit 1
 {
    if(playerTE[joueur_actuelTE].id==1)
    {
        if(pos_yTE-1==6)
        {
            if(tabTE[0][pos_yTE]==1)
            {
                return 1;
            }
            else if(tabTE[0][pos_yTE]==2)
            {
                if((tabTE[2][5]+1)==2||(tabTE[2][5]+1)==4||(tabTE[0][0]==tabTE[0][1]==tabTE[0][2]==tabTE[0][3]==tabTE[0][4]==tabTE[0][5]==0&&tabTE[0][6]!=0))
                {
                    return 1;
                }
            }
        }
        else if(0<=pos_yTE<=7)
        {
            return 1;
        }
        return 0;
    }
    else if(playerTE[joueur_actuelTE].id==2)
    {
        if(pos_yTE-1==0)
        {
            if(tabTE[2][pos_yTE]==1)
            {
                return 1;
            }
            else if(tabTE[2][pos_yTE]==2)
            {
                if((tabTE[2][1]+1)==2||(tabTE[2][1]+1)==4||(tabTE[2][1]==tabTE[2][2]==tabTE[2][3]==tabTE[2][4]==tabTE[2][5]==tabTE[2][6]&&tabTE[2][0]!=0))
                {
                    return 1;
                }
            }
        }
        else if(1<=pos_yTE<=7)
        {
            return 1;
        }
        return 0;
    }
 }
 int  gagne_jeu(int joueur_actuelTE,joueur joueurTE[2])
 {
    if(joueurTE[joueur_actuelTE].nbr_pion_manger>35)
    {
        printf("victoire du joueur %d\n",joueur_actuelTE);
        return 1;
    } 
    else if(joueurTE[0].nbr_pion_plateau<10&&joueurTE[1].nbr_pion_plateau<10)
    {
        int val1=joueurTE[0].nbr_pion_manger+joueurTE[0].nbr_pion_plateau;
        int val2=joueurTE[2].nbr_pion_manger+joueurTE[2].nbr_pion_plateau;
        if(val1>35)
        {
            printf("Victoire du joueur 1\n");
            return 1;
        }
        else if(val2>35)
        {
            printf("victoire du joueur 2\n");
            return 1;
        }
    }
    return 0;
 }