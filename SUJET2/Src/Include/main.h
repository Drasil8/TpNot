#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definition enumeration
typedef enum
{
    false,
    true
}Bool;

//Definition Structure
typedef struct proc proc;
struct proc {
    char str_nomProc[30];
    int int_tpsExec;
    int int_priorite;
};

typedef struct fileElement
{
    proc proces;
    struct fileElement *next;
}fileElement,*File;

//Definition prototype de file
File newFile(void);
Bool isEmpty(File maFile);
void affichageFile(File maFile);
File enfile(File maFile,proc newProcessus);
File defile(File maFile);
proc premierElement(File maFile);
File clearFile(File maFile);

//Definition prototype de simulation
File ajout_activite(File maFile, proc nouveauProcessus);
File step(File maFile,  int *int_runTime);
void run(File maFile);
Bool verifPrio(int int_prio,File maFile);



#endif