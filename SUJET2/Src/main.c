#include "Include/main.h"

/**
 * \fn main(int argc, char** argv)
 * \brief fonction de "simulation" de l'ordonnanceur
 * \author Alzoubaidy Maxime (alzoubaidy@cy-tech.fr), Bardasarian Dianna
 * \version 0.2
 * \date 15 novembre 2022
 * \param argc Nombre d'argument de la ligne de commande
 * \param argv Paremètres de la ligne de commande
 * \return 0 tous le temps
 * 
 * Cette fonction va créer une file de processus. L'utilisateur peut ensuite rentrer autant d'élément qu'il le souhaite.
 * Une fois la liste créer, on lance la simulation.
*/
int main(int argc, char** argv) {
    char char_choix[25];
    File maFile = newFile();
    proc nouveauProcessus;
    int int_cptTest = 0;
    do{
        printf("\nVoulez-vous ajouter un processus ? [y/n]\n");
        printf("Votre choix : ");
        scanf("%s",char_choix);
        if(*char_choix == 'y') {
            printf("\nEntrer les donnees de votre processus : \n");
            printf("\tNom : ");
            scanf("%s",nouveauProcessus.str_nomProc);
            printf("\tTemps execution : ");
            scanf("%d",&nouveauProcessus.int_tpsExec);
            printf("\tPriorite : ");
            scanf("%d",&nouveauProcessus.int_priorite);
            maFile = ajout_activite(maFile,nouveauProcessus);
            int_cptTest = 1;
        }
    }while(*char_choix == 'y');
    if(int_cptTest != 0) {
        run(maFile);
    }
    else 
        printf("Vous n'avez rien rentre, fin du programme.\n");
    return 0;
}

/**
 * \fn ajout_activite(File maFile, proc nouveauProcessus)
 * \brief ajoute un processus a notre ordonnancer
 * \author Alzoubaidy Maxime (alzoubaidy@cy-tech.fr)
 * \version 0.1
 * \date 15 novembre 2022
 * \param maFile file qui represente un ordonnanceur
 * \param nouveauProcessus processus a ajouter
 * 
*/
File ajout_activite(File maFile, proc nouveauProcessus) {
    return enfile(maFile,nouveauProcessus);
}

/**
 * \fn step(File maFile, int *int_runTime)
 * \brief Simule un tour d'ordonnancement
 * \author Alzoubaidy Maxime (alzoubaidy@cy-tech.fr), Bardasarian Dianna
 * \version 0.1
 * \date 15 novembre 2022
 * \param maFile simulateur d'ordonnanceur
 * \param int_runTime pointeur pour savoir le temps total d'execution de tout les processus (nous permet de recuperer 2 valeurs file et le temps)
 * \return renvoie la file apres le tour
 * 
 * Cette fonction vérifie la priorité d'un processus. Si il est prioritaire il est alors exécuté. Sinon il retourne en bout de file.
 * 
*/
File step(File maFile, int *int_runTime) {
    proc recupProc;
    recupProc = premierElement(maFile);
    maFile = defile(maFile);
    if(verifPrio(recupProc.int_priorite,maFile) == false) {
        maFile = enfile(maFile,recupProc);
    } else {
        *int_runTime+=recupProc.int_tpsExec;
        printf("Processus execute : \n");
        printf("\tNom : %s\n",recupProc.str_nomProc);
        printf("\tTemps execution : %d\n",recupProc.int_tpsExec);
        printf("\tTemps d'attente : %d\n",*int_runTime);
    }
    if(isEmpty(maFile)) 
        printf("\nIl n'y a plus aucun processus dans la file.\n");
    return maFile; 
}

/**
 * \fn run(File maFile)
 * \brief simule l'ordonnanceur jusqu'a ce qu'il soit vide
 * \author Alzoubaidy Maxime (alzoubaidy@cy-tech.fr)
 * \version 0.1
 * \date 15 novembre 2022
 * 
*/
void run(File maFile) {
    int int_runTime = 0;
    printf("\n--------------------------------\n\n");
    while(maFile != NULL) {
        maFile = step(maFile,&int_runTime);
    }
}

/**
 * \fn verifPrio(int int_prio,File maFile)
 * \brief verifie la priorité d'un processus
 * \author Alzoubaidy Maxime (alzoubaidy@cy-tech.fr)
 * \version 0.1
 * \date 15 novembre 2022
 * \param int_prio valeur de priorité du processus a exécuter
 * \param maFile ordonnanceur, file des processus a exécuter
 * \return true si le processus est prioritaire, false sinon
 * 
 * On parcourt l'ordonnanceur a la recherche d'un processus ayant un priorité plus faible (donc plus importante).
*/
Bool verifPrio(int int_prio,File maFile) {
    if(isEmpty(maFile)) {
        return true;
    }
    while(maFile != NULL) {
        if(maFile->proces.int_priorite < int_prio) {
            return false;
        }
        maFile=maFile->next;
    }
    return true;
}
