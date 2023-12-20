#pragma once

#include "core.h"

// Initialize les thèmes des portes, à appeler au début du jeu
void initializeDoors();

// doorIdx: numéro de la porte entre 0 et 2
// theme: le thème associé à la porte lors de la génération de la salle
void setDoorTheme(u8 doorIdx, u8 theme);

// tile: numéro de la tuile de la porte qui a été activée
// x, y: coordonnées de l'action du joueur sur la porte
// currentRoom: numéro de la salle dans laquelle on se trouve
// Renvoie le numéro de la salle dans laquelle on se rend en activant la porte
u8 activateDoor(u8 tile, u8 x, u8 y, u8 currentRoom);

// Renvoie le numéro de la salle dans laquelle on se rend en activant la porte de fin
// La porte est choisie en fonction des thèmes choisis
u8 activateEndDoor();
