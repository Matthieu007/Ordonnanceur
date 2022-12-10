#include "fonctions.c"


/////  ----------------------- Main ----------------------- /////


int main(void)
{

	File file = creerFile();
    int nb = 0; // Initialisation du processus
    int min = 0;
    printf("Combien de processus voulez vous entrer pour l'ordonnanceur ? \n");
    scanf("%d", &nb); // L'utilisateur entre le nombre de processus voulu

    ordonnanceur o; // Declaration de o de type ordonnanceur

    for(int i = 0; i < nb; i++){ // On remplie la file de  

        printf("Rentrez le nom de l'ordonnanceur : ");
        scanf("%s", o.nom);
        printf("Rentrez la duree de l'ordonnanceur : ");
        scanf("%d", &o.dureeExec);
        printf("Rentrez la priorite de l'ordonnanceur : ");
        scanf("%d", &o.priorite);
        while (o.priorite != 0 && o.priorite != 1 && o.priorite != 2 && o.priorite != 3 && o.priorite != 4 && o.priorite != 5){ 
            printf("\nLa Prio doit etre comprise entre  0 et 5");
            
            scanf("%d", &o.priorite);
        }
        file = ajout_activite(o, file);
    }

    printf("\nVoici la liste : \n");
    afficheFile(file);  

    printf("On repond a la question b :\n ");
    file = trierFileDuree(o, file);

    afficheFile(file);

    printf("\n Question d :\n");
    videFile(file);

    return 0;
    
}
