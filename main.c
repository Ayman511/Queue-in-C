#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element{
    int nombre;
    Element *next;
};

typedef struct File File;
struct File{
    Element *premier;
};

File *initialisation();
void enfiler(File *file, int nvNombre);
int defiler(File *file);
void afficherFile(File *file);

int main(){
    File *maFile = initialisation();

    enfiler(maFile, 1);
    enfiler(maFile, 2);
    enfiler(maFile, 3);
    enfiler(maFile, 4);
    enfiler(maFile, 5);
    enfiler(maFile, 6);
    enfiler(maFile, 7);

    printf("Etat de la file:\n");
    afficherFile(maFile);

    printf("Je defile : %d\n", defiler(maFile));
    printf("Je defile : %d\n", defiler(maFile));

    printf("Etat de la file:\n");
    afficherFile(maFile);
}

File *initialisation(){
    File *file = malloc(sizeof(*file));
    file->premier = NULL;

    return file;
}

void enfiler(File *file, int nvNombre){
    Element *nouveau = (int)malloc(sizeof(*nouveau));
    if(file == NULL || nouveau == NULL)
        exit(EXIT_FAILURE);

    nouveau->nombre = nvNombre;
    nouveau->next = NULL;

    if(file->premier != NULL)
    {
        Element *elementActuel = file->premier;

        while(elementActuel->next != NULL){
            elementActuel = elementActuel->next;
        }
        elementActuel->next = nouveau;
    }
    else{
        file->premier = nouveau;
    }
}

int defiler(File *file){
    if(file == NULL){
        exit(EXIT_FAILURE);
    }

    int nombreDefile = 0;
    Element *elementDefile = file->premier;

    /* On vérifie s'il y a quelque chose a defiler */
    if(file->premier != NULL){
        nombreDefile = elementDefile->nombre;
        file->premier = elementDefile->next;
        free(elementDefile);
    }
    return nombreDefile;
}

void afficherFile(File *file){
    if(file == NULL)
        exit(EXIT_FAILURE);

    Element *actuel = file->premier;
    while(actuel != NULL){
        printf(" %d -> ", actuel->nombre);
        actuel = actuel->next;
    }
    printf("NULL\n");
}