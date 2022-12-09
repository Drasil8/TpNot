/*!
\file main.h
\brief fichier de prototypes et de structures
\author Alzoubaidy Maxime (alzoubaidy@cy-tech.fr)
\version 0.3
\date 27 octobre 2022

Le module suivant va contenir l'ensemble des prototypes de fonction ainsi que des structures utilisées dans le fichier main.c
*/

#ifndef MAIN_H_

//---------------------
// Definition include
//---------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Manipulation de string
#include <math.h> // Fonction sqrt
#include <unistd.h> // Pour le sleep, meilleur visibilite de l'execution
#include <time.h> // Rand pour randomiser le tableau

//---------------------
// Definition define
//---------------------
#define MAIN_H_
#define NBLOGEMENTCSV 7917
#define NBLOGEMENTCSVTEST 1587
#define NBLOGEMENTCSVENTRAINEMENT 6330

//---------------------
//Definition Structures et Enumerations
//---------------------
typedef enum Mode Mode; // Utilisé pour savoir si on doit permettre de choisir les modalités ou les faires avec tous.
enum Mode {
    Partie1, // L'utilisateur peut choisir
    Partie2 // Toute les elements pour le calcul choisi de base.
};

typedef struct DistSim DistSim;
struct DistSim
{
    float flt_distSim;
    float flt_prix;
};

typedef struct Logement Logement;
struct Logement
{
    float flt_nbAccomodates;
    float flt_nbBedrooms;
    float flt_nbBathrooms;
    float flt_nbBeds;
    float flt_ReelPrice;
    float flt_EstimatePrice;
};

//----------------------
// Definition Prototypes
//----------------------

void partie1();
Logement infoLogement(Logement lgmt_x);
void recuperationData(Logement tlgmt_Data[], Logement lgmt_x);
float CalculeDistSim(Logement tlgmt_Data[],int int_SizeDataTab, Logement lgmt_x, Mode mode_Partie, int int_kPremierLogement);
void choixDistSim(int tint_tabChoix[]);
void randomiserTableau(DistSim dsts_DistanceSimilarite[]);
void triInsertion(DistSim tdsts_tabDisSim[]);
float calculPrix(Logement lgmt_x, DistSim tdsts_tabDisSim[], Mode mode_Partie, int int_kPremierLogement);

void partie2Bonus();
void creationTabLgmt(char *char_file,Logement tabLogement[]);

#endif