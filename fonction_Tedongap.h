typedef struct
{
    int id;
    int nbr_pion_plateau;
    int nbr_pion_manger;
}joueur;
void dessin_plateauTE(int tabTE[3][7]);
void affichage_tableau(int tabTE[3][7]);
int jouer(int tabTE[3][7],int pos_yTE,int joueur_actuelTE,joueur playerTE[2]);//idenetifiant sont 1 et 2
 int choix_colonne(int tabTE[3][7],int pos_yTE,int joueur_actuelTE,joueur playerTE[2]);//renvoie 1 si le choix est possible 0 sinon ici on gere l'interdit 1
int  gagne_jeu(int joueur_actuelTE,joueur joueurTE[2]);