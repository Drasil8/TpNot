/*!
\file partie1.c
\brief Fichier contenant l'execution de la partie 1 de l'ennoncé.
\author Alzoubaidy Maxime (alzoubaidy@cy-tech.fr)
\version 0.4
\date 7 novembre 2022
*/

#include "Include/main.h"

/**
 * \fn infoLogement(Logement lgmt_x)
 * \brief Recupère les informations du logement que le client veut mettre en ventes
 * \author Maxime Alzoubaidy (alzoubaidy@cy-tech.fr), Bardasarian Dianna
 * \version 0.1
 * \date 27 octobre 2022
 * \param lgmt_x Variable qui contient toutes les informations utiles du logement
 * \return Renvoie les données entrées par l'utilisateur
 * 
 * Cette fonction permet au client de rentrer chaque champ de son logement afin d'effectuer les estimations du prix.
*/
Logement infoLogement(Logement lgmt_x)
{
    printf("Veuillez rentrer les caractéristique de votre logement :\n");
    printf("\t Nombres de commodite : ");
    scanf("%f",&lgmt_x.flt_nbAccomodates);
    printf("\t Nombres de chambres : ");
    scanf("%f",&lgmt_x.flt_nbBedrooms);
    printf("\t Nombres de salle de bain : ");
    scanf("%f",&lgmt_x.flt_nbBathrooms);
    printf("\t Nombres de lit : ");
    scanf("%f",&lgmt_x.flt_nbBeds);
    printf("Merci !\n");
    return (lgmt_x);
}

/**
 * \fn calculDistanceSimilarite(Logement lgmt_x)
 * \brief Calcule la distance de similarité entre le logement x et ceux du csv
 * \author Maxime Alzoubaidy (alzoubaidy@cy-tech.fr), Bardasarian Dianna
 * \version 0.3
 * \date 5 novembre 2022
 * \param lgmt_x Logement que l'on souhaite évaluer et des distances de similarité
 * \return retourne le logement
 * 
 * Cette fonction va ouvrir le fichier csv contenant les logements references
 * Nous allons ensuite recuperer ligne par ligne le csv.
 * Chaque ligne sera decomposée grace a strtok.
 * En fonction de la colonne on effectue un calcul pour trouver la distance
 * de similarité
 * Enfin en met a l'indice du tableau la valeur souhaité.
*/
void recuperationData(Logement tlgmt_Data[], Logement lgmt_x) 
{
    FILE *file_dataCSV = fopen("Csv/airbnb_donnees_propres.csv","r");
    if(file_dataCSV == NULL) {
        printf("Erreur de chargement de fichier\n");
        exit(-1);
    }
    char char_buffer[200];
    int int_ligne=1;
    int int_colone=0;
    int int_index=0;
    while(fgets(char_buffer,200,file_dataCSV) != NULL) {
        int_colone=0;
        if(int_ligne == 1) {
            int_ligne++;
            continue;
        }

        char* char_value=strtok(char_buffer, ",");

        while(char_value) {
            switch(int_colone) 
            {
                case 1:
                    tlgmt_Data[int_index].flt_nbAccomodates = atoi(char_value);
                    break;
                case 2:
                    tlgmt_Data[int_index].flt_nbBedrooms = atoi(char_value);
                    break;
                case 3:
                    tlgmt_Data[int_index].flt_nbBathrooms = atoi(char_value);
                    break;
                case 4:
                    tlgmt_Data[int_index].flt_nbBeds = atoi(char_value);
                    break;
                case 5:
                    tlgmt_Data[int_index].flt_ReelPrice = atoi(char_value);
                    break;
                default :
                    break;
            }
            char_value = strtok(NULL,",");
            int_colone++;
        }
        int_index++;
    }
    fclose(file_dataCSV);
}

/**
 * \fn float CalculeDistSim(Logement tlgmt_Data[],int int_SizeDataTab, Logement lgmt_x,Mode mode_Partie,int tint_tabChoix[], int int_kPremierLogement)
 * \brief Calcule la distance de similarite entre 2 logement
 * \author Alzoubaid Maxime (alzoubaidy@cy-tech.fr), Bardasarian Dianna
 * \version 0.5
 * \date 6 novembre 2022
 * \param tlgmt_Data tableau de logement contenant les logements connue
 * \param int_SizeDataTab Nombre de données connue
 * \param lgmt_x logement dont on veut trouver le prix
 * \param mode_Partie Booléen permettant de savoir si on fait le bonus ou pas (pour des fonctions supplémentaire ou non)
 * \param tint_tabChoix tableau contenant les choix concernant le calcul de distance de similarite
 * \param int_kPremierLogement nombre de k premier logement
 * 
 * Cette fonction va créer un tableau qui contiendra a distance de similarité du logement y avec notre logement x dont on veut le prix. Chaque indice du tableau
 * va contenir la distance de similarite ainsi que le prix du logement y. On effectue une boucle puis en fonction de nos choix on les inclus dans le calcul ou non.
 * On appelle ensuite randomiserTableau puis triInsertion pour le calcul du prix final. On appelle ensuite calculPrix pour calculer le prix final.
 * Soit on est en partie 1 a ce moment en permettra a l'utilisateur de rentrer les données k logement après. Sinon (partie 2 bonus) on envoit le nombre de k logement
 * defini plus tot.
 * 
*/
float CalculeDistSim(Logement tlgmt_Data[],int int_SizeDataTab, Logement lgmt_x,Mode mode_Partie,int tint_tabChoix[], int int_kPremierLogement) {
    DistSim tdsts_tabDisSim[NBLOGEMENTCSV];
    DistSim dsts_tmp;
    float flt_sum;
    for(int i=0; i<int_SizeDataTab;i++) {
        flt_sum = 0;
        if(tint_tabChoix[0] == 1)
            flt_sum = flt_sum + (lgmt_x.flt_nbAccomodates-tlgmt_Data[i].flt_nbAccomodates)*(lgmt_x.flt_nbAccomodates-tlgmt_Data[i].flt_nbAccomodates);
        if(tint_tabChoix[1] == 1)
            flt_sum = flt_sum + (lgmt_x.flt_nbBedrooms-tlgmt_Data[i].flt_nbBedrooms)*(lgmt_x.flt_nbBedrooms-tlgmt_Data[i].flt_nbBedrooms);
        if(tint_tabChoix[2] == 1)
            flt_sum = flt_sum + (lgmt_x.flt_nbBathrooms-tlgmt_Data[i].flt_nbBathrooms)*(lgmt_x.flt_nbBathrooms-tlgmt_Data[i].flt_nbBathrooms);
        if(tint_tabChoix[3] == 1)
            flt_sum = flt_sum + (lgmt_x.flt_nbBeds-tlgmt_Data[i].flt_nbBeds)*(lgmt_x.flt_nbBeds-tlgmt_Data[i].flt_nbBeds);
        tdsts_tabDisSim[i].flt_distSim = sqrt(flt_sum);
        tdsts_tabDisSim[i].flt_prix = tlgmt_Data[i].flt_ReelPrice;
    }
    randomiserTableau(tdsts_tabDisSim);
    triInsertion(tdsts_tabDisSim);
    if (mode_Partie == Partie1)
        lgmt_x.flt_EstimatePrice = calculPrix(lgmt_x,tdsts_tabDisSim,Partie1,0);
    else
        lgmt_x.flt_EstimatePrice = calculPrix(lgmt_x,tdsts_tabDisSim,Partie2,int_kPremierLogement);
    return (lgmt_x.flt_EstimatePrice);
}

/**
 * \fn choixDistSim(int tint_tabChoix[])
 * \brief Recupere les choix utilisateur
 * \author Maxime Alzoubaidy (alzoubaidy@cy-tech.fr)
 * \version 0.1
 * \date 5 novembre 2022
 * \param tint_tabChoix tableau contenant les choix
 * \return Ne retourne rien
 * 
 * Demande à l'utilisateur de choisir avec quel option il veut calculer la distance de similarite
*/
void choixDistSim(int tint_tabChoix[])
{
    char char_choix[25];
    char *furniture[4] = {"commodite","chambre","salle de bain","lit"};

    printf("\nVous allez maintenant choisir sur quelle facteur voulez vous calculer le prix de votre logement\n");
    printf("Un logement peut posseder jusqu'a 4 information :\n");
    printf("\t le nombre de commodite\n");
    printf("\t le nombre de chambre\n");
    printf("\t le nombre de salle de bain\n");
    printf("\t le nombre de lit\n\n");

    for(int i=0;i<4;i++) {
        printf("Voulez vous ajouter les %s [y/n] : ",furniture[i]);
        scanf("%s",char_choix);
        if(*char_choix == 'y') {
            tint_tabChoix[i] = 1;
        } else {
            tint_tabChoix[i] = 0;
        }
    }
}

/**
 * \fn calculPrix(Logement lgmt_x)
 * \brief Calcule le prix theorique du logement x
 * \author Maxime Alzoubaidy (alzoubaidy@cy-tech.fr)
 * \version 0.1
 * \date 5 novembre 2022
 * \param lgmt_x Structure contenant le logement et les distances de similarite
 * \return Retourne le logement lgmt_x et les infos qui vont avec (ici le prix)
 * 
 * Recupere la somme des prix des k premiers logement et calcul la moyenne pour donner un nouveau prix.
*/
float calculPrix(Logement lgmt_x, DistSim tdsts_tabDisSim[], Mode mode_Partie, int int_kPremierLogement)
{
    if( mode_Partie == Partie1) {
        printf("\nLes distances de similarite on ete calculee.\n");
        printf("Veuillez choisir les k premiers logements : ");
        scanf("%d",&int_kPremierLogement);
    }
    float sum = 0;
    for(int i=0;i<int_kPremierLogement;i++)
    {
        sum = sum + tdsts_tabDisSim[i].flt_prix;
    }
    lgmt_x.flt_EstimatePrice = sum/int_kPremierLogement;
    if(mode_Partie == Partie1)
        printf("Votre appart vaut %.2lf€ a la location.\n",lgmt_x.flt_EstimatePrice);
    return (lgmt_x.flt_EstimatePrice);
}

