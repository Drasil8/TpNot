#include "Include/main.h"

/**
 * \fn File newFile(void)
 * \brief renvoie une file vide
 * \author Alzoubaidy Maxime (alzoubaidy@cy-tech.fr)
 * \version 0.1
 * \date 14 novembre 2022
 * \return NULL 
*/
File newFile(void) {
    return NULL;
}

/**
 * \fn isEmpty(File maFile)
 * \brief Cherche si une file est vide
 * \author Alzoubaidy Maxime (alzoubaidy@cy-tech.fr)
 * \version 0.1
 * \date 14 novembre 2022
 * \param maFile file a verifier
 * \return true si la file est vide False sinon
 * 
*/
Bool isEmpty(File maFile) {
    if(maFile  == NULL) {
        return true;
    }
    return false;
}

/**
 * \fn affichageFile(File maFile)
 * \brief affichage la file
 * \author Alzoubaidy Maxime (alzoubaidy@cy-tech.fr)
 * \version 0.1
 * \date 14 novembre 2022
 * \param maFile file à afficher
 * 
 * Parcours la file en affichant chaque élément de la file jusqu'a ce qu'elle soit vide
 * 
*/
void affichageFile(File maFile) {
    if(maFile  == NULL) {
        printf("La file est vide.\n");
        return;
    }
    while(maFile != NULL) {
        printf("Processus : \n");
        printf("\tNom : %s\n",maFile->proces.str_nomProc);
        printf("\tTemps execution : %d\n",maFile->proces.int_tpsExec);
        printf("\tPriorite : %d\n\n",maFile->proces.int_priorite);
        maFile = maFile->next;
    }   
}

/**
 * \fn enfile(File maFile,proc newProcessus)
 * \brief ajoute un élément au début de la file
 * \author Alzoubaidy Maxime (alzoubaidy@cy-tech.fr)
 * \version 0.1
 * \date 14 novembre 2022
 * \param maFile file ou l'on veut ajouter un élement
 * \param newProcessus nouvelle élément a ajouter a la file
 * \return retourne la file avec le nouvelle élément
 * 
 * On créer un nouveau noeud. Si la file est vide, on renvoie le noeud. Sinon on se déplace jusqu'a bout de la file et on fait pointer le dernier element sur
 * le nouveau noeud.
 * 
*/
File enfile(File maFile,proc newProcessus) {
    fileElement *newElement;

    newElement = malloc(sizeof(*newElement));
    if(newElement == NULL) {
        printf("Probleme Allocation\n");
        exit(EXIT_FAILURE);
    }

    newElement->proces = newProcessus;
    newElement->next = NULL;

    if(isEmpty(maFile)) 
        return newElement;
    
    fileElement *tmp;
    tmp = maFile;

    while(tmp->next!= NULL) 
        tmp = tmp->next;
    
    tmp->next = newElement;

    return maFile;
}

/**
 * \fn defile(File maFile)
 * \brief retire le premier element de la file
 * \author Alzoubaidy Maxime (alzoubaidy@cy-tech.fr)
 * \version 0.1
 * \date 14 novembre 2022
 * \param maFile file a modifier
 * \return on retourne la file modifié
 * 
 * On créer une file temporaire qui pointe sur la maFile.
 * On fait pointer maFile sur le second noeud puis on free tmp pour liberer la mémoire du premier noeud a supprimer
 * On retourne ensuite la file modifier
 * 
*/
File defile(File maFile) {
    if(isEmpty(maFile))
        return maFile;
    
    fileElement *tmp = maFile;
    maFile = maFile->next;

    free(tmp);
    return maFile;
}

/**
 * \fn premierElement(File maFile)
 * \brief Renvoie le premier element de la file
 * \author Alzoubaidy Maxime (alzoubaidy@cy-tech.fr)
 * \version 0.1
 * \date 14 novembre 2022
 * \param maFile file dont on veut le premier element
 * \return premier element de la file
 * 
*/
proc premierElement(File maFile) {
    return maFile->proces;
}

/**
 * \fn clearFile(File maFile)
 * \brief supprime la file
 * \author Alzoubaidy Maxime (alzoubaidy@cy-tech.fr)
 * \version 0.1
 * \date 14 novembre 2022
 * \return return la file vide
 * 
 * On appelle defile jusqu'a ce que la file soit vide.
 * 
*/
File clearFile(File maFile) {
    if(isEmpty(maFile)) {
        return newFile();
    }
    while(maFile != NULL) {
        maFile = defile(maFile);
    }
}