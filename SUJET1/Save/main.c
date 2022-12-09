/*!
\file main.c
\brief Fichier contenant le menu pour lancer les differentes partie de l'ennonce
\author Alzoubaidy Maxime (alzoubaidy@cy-tech.fr)
\version 0.5
\date 7 novembre 2022
*/

//--------------------------------
// Definition des includes
//--------------------------------
#include "Include/main.h"

/**
 * \fn int main(int argc, char** argv)
 * \brief Fonction principale.
 * \author Maxime Alzoubaidy (alzoubaidy@cy-tech.fr)
 * \version 0.2
 * \date 5 novembre 2022
 * \param argc Nombre d'argument de la ligne de commande
 * \param argv Paremètres de la ligne de commande
 * \return 0 tous le temps
*/
int main(int argc, char** argv)
{
    int int_menu = -1;
    printf("Bonjour, voici le TPNote sur les distances de similarite, le Sujet 1.\n");
    printf("Vous aurez le choix entre Partie 1 ou bien Partie 2 Bonus.\n");
    printf("\nVeuillez choisir :\n");
    printf("\t Entrer 1 pour la partie 1 (Implemantation de l'algorithme KNN)\n");
    printf("\t Entrer 2 pour la partie 2 (Evaluation de performance du modele de prediction)\n");
    printf("Votre choix : ");
    scanf("%d",&int_menu);
    switch(int_menu) 
    {
        case 1 : 
            partie1();
            break;
        case 2 :
            partie2Bonus();
            break;
        default :
            printf("\nExcusez moi, je n'ai pas compris votre choix.\n");
            sleep(1);
            break;
    }
    return 0;
}

//----------------------------------------------------------------------------------------------------------------
// PARTIE 1
//----------------------------------------------------------------------------------------------------------------

void partie1() {
    printf("\nVous avez choisis partie 1 : \n\n");
    Logement lgmt_x;
    Logement tlgmt_Data[NBLOGEMENTCSV];
    lgmt_x = infoLogement(lgmt_x);
    recuperationData(tlgmt_Data,lgmt_x);
    lgmt_x.flt_EstimatePrice = CalculeDistSim(tlgmt_Data,NBLOGEMENTCSV,lgmt_x,Partie1,0);
}
//----------------------------------------------------------------------------------------------------------------
// PARTIE 2 BONUS
//----------------------------------------------------------------------------------------------------------------

void partie2Bonus() {
    Logement tabEntrainement[NBLOGEMENTCSVENTRAINEMENT];
    Logement tabTest[NBLOGEMENTCSVTEST];
    float tabPrediction[NBLOGEMENTCSVTEST];
    int int_kPremierLogement;
    float flt_MAE = 0;
    creationTabLgmt("Csv/airbnbTest.csv",tabTest);
    creationTabLgmt("Csv/airbnbEntrainement.csv",tabEntrainement);
    printf("Veuillez choisir le nombre de k premiers logements necessaire au calcul : ");
    scanf("%d",&int_kPremierLogement);
    for(int i=0;i<NBLOGEMENTCSVTEST;i++) {
        tabPrediction[i] = CalculeDistSim(tabEntrainement,NBLOGEMENTCSVENTRAINEMENT,tabTest[i],Partie2,int_kPremierLogement);
        flt_MAE = flt_MAE + fabs(tabTest[i].flt_ReelPrice - tabPrediction[i])/NBLOGEMENTCSVTEST;
    }
    printf("Le MAE vaut : %lf\n",flt_MAE);

}
