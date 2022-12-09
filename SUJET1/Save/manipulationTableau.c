/*!
\file manipulationTableau.c
\brief Fichier contenant toutes les fonctions du programme permettant de manipuler des tableaux.
\author Alzoubaidy Maxime (alzoubaidy@cy-tech.fr)
\version 0.5
\date 5 novembre 2022
*/

#include "Include/main.h"

/**
 * \fn triInsertion(float tfloat_tabDisSim[])
 * \brief Fonction de tri pour un tableau
 * \author Maxime Alzoubaidy (alzoubaidy@cy-tech.fr)
 * \version 0.2
 * \date 5 novembre 2022
 * \param lgmt_x Structure contenant le logement et les distances de similarite
 * \return Retourne le logement et les distances de similarite
 * 
 * Fonction utilisant le tri par insertion pour trier le tableau par rapport a la distance de similarité.
 * 
*/
void triInsertion(DistSim tdsts_tabDisSim[]) 
{
    for(int i=0;i<NBLOGEMENTCSV;i++) {
        float flt_tmp = tdsts_tabDisSim[i].flt_distSim;
        int j = i;
        while(j>0 && tdsts_tabDisSim[j-1].flt_distSim>flt_tmp) {
            tdsts_tabDisSim[j].flt_distSim = tdsts_tabDisSim[j-1].flt_distSim;
            j--;
        }
        tdsts_tabDisSim[j].flt_distSim = flt_tmp;
    }
}

/**
 * \fn randomiserTableau(float tfloat_tabDisSim[])
 * \brief Randomise le tableau contenant les distances de similarité
 * \author Maxime Alzoubaidy (alzoubaidy@cy-tech.fr)
 * \version 0.2
 * \date 5 novembre 2022
 * \param lgmt_x Structure contenant le logement et les distances de similarite
 * \return Retourne le logement et les distances de similarité
 * 
 * Cette fonction va effectuer une boucle de la taille du tableau.
 * On va choisir de facon aléatoire 2 indices. On inverse ensuite la case du tableau
 * a l'indice 1 avec la case a l'indice 2.
 * 
*/
void randomiserTableau(DistSim tdsts_tabDisSim[]) 
{
    int int_index1;
    int int_index2;
    DistSim flt_tmp;
    srand(time(0));
    for(int i=0 ;i<NBLOGEMENTCSV;i++)
    {
        int_index1 = (rand() % (NBLOGEMENTCSV-1));
        int_index2 = (rand() % (NBLOGEMENTCSV-1));
        flt_tmp=tdsts_tabDisSim[int_index1];
        tdsts_tabDisSim[int_index1] = tdsts_tabDisSim[int_index2];
        tdsts_tabDisSim[int_index2] = flt_tmp;
    }
}