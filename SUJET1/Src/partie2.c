/*!
\file partie2.c
\brief Fichier contenant l'execution de la partie 1 de l'ennoncé.
\author Alzoubaidy Maxime (alzoubaidy@cy-tech.fr), Bardasarian Dianna
\version 0.4
\date 5 novembre 2022
*/

#include "Include/main.h"

/**
 * \fn creationTabLgmt(char *char_file,Logement tabLogement[])
 * \brief créer un tableau de données 
 * \author Alzoubaidy Maxime (alzoubaidy@cy-tech.fr), Bardasarian Dianna
 * \version 0.3
 * \date 6 novembre 2022
 * \param char_file contient le nom du fichier que le vont récuperer
 * \param tabLogement tableau contenant les données du fichier
 * 
 * Cette fonction ouvre le fichier entré en parametre et range les données dans un tableau. Cette fonction marche comme calculDistanceSimilarite.
 * 
*/
void creationTabLgmt(char *char_file,Logement tabLogement[]) {
    FILE *file_Data = fopen(char_file,"r");
    if (file_Data == NULL) {
        printf("Erreur ouverture fichier");
        exit(-3);
    }
    char char_buffer[200];
    int int_index = 0;
    int int_ligne = 0;
    int int_colone;
    while(fgets(char_buffer,200,file_Data) != NULL) {
        int_ligne++;
        int_colone = 0;
        if(int_ligne == 1)
            continue;

        char* char_value=strtok(char_buffer, ",");

        while(char_value) {
            switch(int_colone) 
            {
                case 1 : //accomodate
                    tabLogement[int_index].flt_nbAccomodates = strtof(char_value,NULL);
                    break;
                case 2 : //bedrooms
                    tabLogement[int_index].flt_nbBedrooms = strtof(char_value,NULL);
                    break;
                case 3 : //bathrooms
                    tabLogement[int_index].flt_nbBathrooms = strtof(char_value,NULL);
                    break;
                case 4 : //bed
                    tabLogement[int_index].flt_nbBeds = strtof(char_value,NULL);
                    break;
                case 8 : //prix
                    tabLogement[int_index].flt_ReelPrice = strtof(char_value,NULL);
                    break;
                default :
                    break;
            }
            char_value = strtok(NULL,",");
            int_colone++;
        }
        int_index++;
    }
    fclose(file_Data);
}