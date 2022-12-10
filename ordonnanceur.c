#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>


/// Structure de l'ordonnanceur ///

typedef struct ordonnanceur
{
    char nom[40]; 
    int dureeExec;
    int priorite;
}ordonnanceur;

/// Structure de la file ///

typedef struct typeFile
{
    ordonnanceur donnee; // La valeur de la case de la file comporte les 3 caractetistiques du processus
    struct typeFile *suivant;
}typeFile, *File;

/// Boleen ///

typedef enum
{
    FALSE,
    TRUE
}Booleen;


///// ----- Fonction Preliminaire ----- /////

//Creer une nouvelle Liste ( vide )

File creerFile(void)
{
	return NULL;
}


// Check si une file est vide ou non
Booleen estVide(File file)
{ 
    if(file == NULL){
        return true; // Cas d'une file vide
    }
    else{
        return false; // Cas d'une file non vide 
    }
}


// Affiche une liste et son contenue
void afficheFile(File file)
{
	if(estVide(file)) 
	{
		printf("Rien a afficher, la Liste est vide.\n");
		return;
	}
	while(file != NULL) // On parcours la file et on retourne toute les valeurs presentes dedans 
	{
		printf("( nom : %s , duree : %d , priorite : %d ) |  ", file->donnee.nom, file->donnee.dureeExec, file->donnee.priorite);
		file = file->suivant;
	}
	printf("\n");
}

// Retourne la taille d'une liste 
int tailleFile(File file)
{
	int size;
    size = 0;
	if(estVide(file))
		return size;
	while(file != NULL)
	{
		size++;
		file = file->suivant;
	}
	return size;
}

// Retire l'element en tête de file et l'execute
File supprimeFile(File file)
{
	typeFile *element = malloc(sizeof(*element));

	if(element == NULL)
	{
		exit(EXIT_FAILURE);
	}
	printf("\n\n On affiche le processus qui viens d'être depile :\n");
    printf("( nom : %s , dureeExec : %d , priorite : %d )  | ", file->donnee.nom, file->donnee.dureeExec, file->donnee.priorite);
    printf("\n\n"); 

	if(estVide(file)){
		return creerFile();
	}
	element = file->suivant;
	free(file);

	return element;
}



// Supprime tous les éléments d'une file et renvoie ses éléments
File videFile(File file)
{
	if(estVide(file))
		return creerFile();

	while(file != NULL){
		file = supprimeFile(file);
	}
	return file;
}



///// ---------- Question b ---------- /////

File ajout_activite(ordonnanceur o, File file)
{
    typeFile *new = malloc(sizeof (*new));
    if (new != NULL)
    {
        new->donnee = o;
        new->suivant = NULL;
        if (file == NULL)
        {
            file = new;
            return file;
        }
        else
        {
            typeFile * tmp = file;
            while (tmp->suivant != NULL)
            {
                tmp = tmp->suivant;
            }
            tmp->suivant = new;

            return file;
        }
    }
}

/*
File Step(File file)
{
    if(file == NULL)
    {
        printf("La liste est vide donc aucun tour d'ordonnanceur n'est à faire");
    }
    else{ // Si la file est non vide on execute le processus en affichant ses caractéristiques
        file = supprimeFile(file);
		return file;
    }
}*/

int dureeMin (File file){
    typeFile * tmp = file;
    
    int min = tmp->donnee.dureeExec;
    while (tmp != NULL){ 
        if(min > tmp->donnee.dureeExec){
            min = tmp->donnee.dureeExec;
        }
        tmp = tmp->suivant;
    }  
    return min;
}



///// ---------- Trie de la file ---------- /////

// Quand on a ajouté dans la liste, on n'a pas verifié si les programmes qui demandent du temps de calcul sont insérés 
// en bout de file, et ceux qui seront défilés pour obtenir effectivement du temps processeur 
//sont ceux qui attendent depuis le plus longtemps. On le fait donc. Puis on repond a la question c.
File trierFileDuree(ordonnanceur o, File file)
{
    if(estVide(file)){ // On l'indique et on ne fait rien si la file est vide
        printf("La file est vide\n");
    }

    typeFile * tmp = file; // On met le premier element 
   
    printf("\n Le premier element de la file est :\n");
    printf("( nom : %s , dureeExec : %d , priorite : %d )", tmp->donnee.nom, tmp->donnee.dureeExec, tmp->donnee.priorite);
    printf("\n\n");   
    while(tmp != NULL)
    {
        if(tmp->donnee.dureeExec == dureeMin(tmp))
        { 
            tmp = supprimeFile(tmp);
        }
        else
        {
            tmp = ajout_activite(tmp->donnee, tmp); 
            printf("\n La tete n'est pas la plus petite duree, on enfile a la queue\n"); 
            tmp = supprimeFile(file);
        }
        
        afficheFile(tmp);
    }
    return tmp;
    free(tmp);
    
}




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
        while (o.priorite != 1 && o.priorite != 2 && o.priorite != 3 && o.priorite != 4 && o.priorite != 5){ 
            printf("\nLa Prio doit etre comprise entre  1 et 5");
            
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
