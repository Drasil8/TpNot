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
 * \brief Menu du choix de sujet.
 * \author Maxime Alzoubaidy (alzoubaidy@cy-tech.fr)
 * \version 0.2
 * \date 5 novembre 2022
 * \param argc Nombre d'argument de la ligne de commande
 * \param argv Paremètres de la ligne de commande
 * \return 0 tous le temps
 * 
 * Cette fonction est un menu permettant a l'utilisateur de choisir entre le sujet 1 et le bonus.
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

/**
 * \fn void partie1()
 * \brief fonction qui execute le sujet 1
 * \author Alzoubaidy Maxime (alzoubaidy@cy-tech.fr), Bardasarian Dianna
 * \version 0.2
 * \date 6 novembre 2022
 * 
 * Cette fonction est la fonction qui s'occupe de gérer le sujet 1. Elle va appeler toutes les fonctions necessaire a l'execution.
*/
void partie1() {
    printf("\nVous avez choisis partie 1 : \n\n");
    Logement lgmt_x;
    Logement tlgmt_Data[NBLOGEMENTCSV];
    int tint_tabChoix[4] = {0};
    lgmt_x = infoLogement(lgmt_x);
    recuperationData(tlgmt_Data,lgmt_x);
    choixDistSim(tint_tabChoix);
    lgmt_x.flt_EstimatePrice = CalculeDistSim(tlgmt_Data,NBLOGEMENTCSV,lgmt_x,Partie1,tint_tabChoix,0);
}
//----------------------------------------------------------------------------------------------------------------
// PARTIE 2 BONUS
//----------------------------------------------------------------------------------------------------------------

/**
 * \fn partie2Bonus()
 * \brief fonction qui execute le sujet 1 Bonus.
 * \author Alzoubaidy Maxime (alzoubaidy@cy-tech.fr), Bardasarian Dianna
 * \version 0.3
 * \date 6 novembre 2022
 * 
 * Cette fonction s'occupe de gérer le Bonus du sujet 1. Dans un premiers temps elle va faire appelle aux fonction necessaire a la création des tabEntrainement
 * et tabTest. Elle permet ensuite a l"utilisateur de choisir avec quoi calculer la distances de similarite ainsi que le nombre k pour les k voisins.
 * On lance ensuite un boucle qui va lancer les fonctions necessaire au calcul de distances de similarite de chaque logements tabTest avec chaque logements tabEntrainement
 * De plus cette boucle calcul le MAE pour l'écrire dans le fichier Data/dataKLogement.txt.
*/
void partie2Bonus() {
    FILE *dataK = fopen("Data/dataKLogement.txt","a+");
    Logement tabEntrainement[NBLOGEMENTCSVENTRAINEMENT];
    Logement tabTest[NBLOGEMENTCSVTEST];
    int tint_tabChoix[4] = {0};
    char chaine[500];
    float tabPrediction[NBLOGEMENTCSVTEST];
    int int_kPremierLogement;
    float flt_MAE = 0;
    choixDistSim(tint_tabChoix);
    creationTabLgmt("Csv/airbnbTest.csv",tabTest);
    creationTabLgmt("Csv/airbnbEntrainement.csv",tabEntrainement);
    printf("Veuillez choisir le nombre de k premiers logements necessaire au calcul : ");
    scanf("%d",&int_kPremierLogement);
    for(int i=0;i<NBLOGEMENTCSVTEST;i++) {
        tabPrediction[i] = CalculeDistSim(tabEntrainement,NBLOGEMENTCSVENTRAINEMENT,tabTest[i],Partie2,tint_tabChoix,int_kPremierLogement);
        flt_MAE = flt_MAE + fabs(tabTest[i].flt_ReelPrice - tabPrediction[i])/NBLOGEMENTCSVTEST;
    }
    printf("Le MAE vaut : %lf\n",flt_MAE);
    sprintf(chaine,"%d %d %d %d %d %f",tint_tabChoix[0],tint_tabChoix[1],tint_tabChoix[2],tint_tabChoix[3],int_kPremierLogement,flt_MAE);
    fputs(chaine,dataK);
    fclose(dataK);
}



