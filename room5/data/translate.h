// Generated by MSXgl on 2024-04-14 22:47:54
#pragma once
#include "core.h"

// Language definition
#define LANG_EN 0
#define LANG_FR 1
#define LANG_MAX 2

// Text ID definition
#define TEXT_TITLE 0
#define TEXT_TITLE_TWITCH 1
#define TEXT_PRESS_ESC 2
#define TEXT_ROOM1 3
#define TEXT_ROOM7 4
#define TEXT_ROOM11 5
#define TEXT_ROOM15 6
#define TEXT_ROOM19 7
#define TEXT_ROOM23 8
#define TEXT_ROOM25 9
#define TEXT_END_HOSPITAL 10
#define TEXT_END_MATRIX 11
#define TEXT_END_ALIEN 12
#define TEXT_THANKS 13
#define TEXT_MAX 14

// Localization data table
const c8* const g_TransData[LANG_MAX][TEXT_MAX] =
{
	// EN
	{
		"MSXgl - Localization sample", // TEXT_TITLE
		"THIS GAME IS MADE LIVE\n ON TWITCH\n\nTWITCH.TV/MO5ASSORETRO", // TEXT_TITLE_TWITCH
		"HOLD 'ESC' TO RESET", // TEXT_PRESS_ESC
		"...YOU NEED...TO REACH\n...ROOM 5.\n\n1.IS THAT WHERE I'LL\n  WAKE UP ?\n\n2.IT'S IMPORTANT FOR YOU?\n\n3.IT'S A SAVE POINT!", // TEXT_ROOM1
		"ROOM 5 WILL BRING YOU CLOSER... TO...THE TRUTH.\n\n1.FOR ME OR YOU?\n\n2.BONUS STAGE?\n\n3.FOR MY MEMORIES?", // TEXT_ROOM7
		"...REMINDER...ROOM 5...IS THE KEY.\n\nFOR YOUR WEIRD GAME\n\nI KNOW, I READ THE MANUAL\n\nMY BODY IS A TRAP", // TEXT_ROOM11
		"...ROOM 5 IS DIFFERENT FROM...THE OTHERS.\n\nIS IT A SECRET?\n\nWHAT HAVE YOU DONE IN THAT ROOM?\n\nIS THAT WHERE EVERYTHING WILL BECOM?", // TEXT_ROOM15
		"...ROOM 5...WILL GIVE YOU ANSWERS.\n\nABOUT MY CONDITION?\n\nABOUT THE OBJECTIVE?\n\nABOUT YOUR MISSION?", // TEXT_ROOM19
		"...ROOM 5...IS NEAR...DONT LOSE HOPE...\n\nI JUST WANT TO UNDERSTAND.\n\nWHY IS IT SO IMPORTANT TO YOU?\n\nNEXT LEVEL?", // TEXT_ROOM23
		"...ROOM 5...IS YOUR DESTINY...\n\nMY DESTINY OR YOURS?\n\nMY DESTINY TO WAKE UP?\n\nDESTINY FOR A PLAYER?", // TEXT_ROOM25
		"YOU'RE FINALLY AWAKE. YOU WHERE IN COMA, BUT YOU MANAGED TO FIGHT AND COME BACK TO US. YOUR MIND CREATED THIS PLACE TO HELP YOU TO WAKE UP. WELCOME BACK TO REALITY.", // TEXT_END_HOSPITAL
		"CONGRATULATIONS! YOU'VE COMPLETED THE GAME. EVERYTHING YOU EXPERIENCED WAS A SIMULATION, A CREATION OF OUR TEAM. YOU'VE BEEN AN EXCELLENT PLAYER. SEE YOU SOON IN ANOTHER GAME.", // TEXT_END_MATRIX
		"YOU DID WELL, HUMAN. YOU WHERE A VALUABLE SUBJECT FOR OUR STUDY. WE WANTED TO UNDERSTAND THE HUMAN MIND. YOU ARE FREE NOW, WITH MEMORIES OF UNIQUE EXPERIENCES.", // TEXT_END_ALIEN
		"THANKS FOR PLAYING!\n\nKAZERLELUTIN\nAOINEKO\nMOKONA", // TEXT_THANKS
	},
	// FR
	{
		"MSXgl - Sample de traduction", // TEXT_TITLE
		"    CE JEU EST FAIT\nEN LIVE SUR TWITCH\n\nTWITCH.TV/MO5ASSORETRO", // TEXT_TITLE_TWITCH
		"MAINTENIR 'ESC'\n POUR RELANCER", // TEXT_PRESS_ESC
		"...TU DOIS...ATTEINDRE\n...LA CHAMBRE 5.\n\n1.C'EST LA QUE JE\nME REVEILLERAI ?\n\n2.C'EST IMPORTANT POUR VOUS ?\n\n3.C'EST UN POINT DE SAUVEGARDE !", // TEXT_ROOM1
		"...LA CHAMBRE 5...TE RAPPROCHERA...DE...LA VERITE.\n\nPOUR MOI OU POUR VOUS ?\n\nNIVEAU BONUS ?\n\nPOUR MES SOUVENIRS ?", // TEXT_ROOM7
		"...RAPPEL...LA CHAMBRE 5...EST LA CLE.\n\nPOUR TON JEU BIZARRE\n\nJE SAIS, J'AI LU LA NOTICE\n\nMON CORPS EST UN PIEGE", // TEXT_ROOM11
		"...LA CHAMBRE 5 EST DIFFERENTE DES...AUTRES.\n\nEST-CE UN SECRET ?\n\nQUE FAITES-VOUS DANS CETTE CHAMBRE ?\n\nEST-CE LA OU TOUT VA BASCULER ?", // TEXT_ROOM15
		"...LA CHAMBRE 5...TE DONNERA DES REPONSES.\n\nSUR MON ETAT ?\n\nSUR L'OBJECTIF ?\n\nSUR TA MISSION ?", // TEXT_ROOM19
		"...LA CHAMBRE 5...EST PROCHE...NE PERDS PAS ESPOIR...\n\nJE VEUX JUSTE COMPRENDRE.\n\nPOURQUOI EST-CE SI IMPORTANT POUR TOI ?\n\nNIVEAU SUIVANT ?", // TEXT_ROOM23
		"...LA CHAMBRE 5...EST TON DESTIN...\n\nMON DESTIN OU LE VOTRE ?\n\nMON DESTIN DE ME REVEILLER ?\n\nDESTIN POUR UN JOUEUR ?", // TEXT_ROOM25
		"VOUS ETES ENFIN REVEILLE. VOUS ETIEZ DANS LE COMA, MAIS VOUS AVEZ REUSSI A VOUS BATTRE ET A REVENIR VERS NOUS. VOTRE ESPRIT A CREE CET ENDROIT POUR VOUS AIDER A VOUS REVEILLER. BIENVENUE DANS LA REALITE.", // TEXT_END_HOSPITAL
		"FELICITATIONS ! VOUS AVEZ TERMINE LE JEU. TOUT CE QUE VOUS AVEZ VECU ETAIT UNE SIMULATION, UNE CREATION DE NOTRE EQUIPE. VOUS AVEZ ETE UN EXCELLENT JOUEUR. A BIENTOT DANS UN AUTRE JEU.", // TEXT_END_MATRIX
		"VOUS AVEZ BIEN FAIT, HUMAIN. VOUS ETIEZ UN SUJET DE VALEUR POUR NOTRE ETUDE. NOUS VOULIONS COMPRENDRE L'ESPRIT HUMAIN. VOUS ETES LIBRE MAINTENANT, AVEC DES SOUVENIRS D'EXPERIENCES UNIQUES.", // TEXT_END_ALIEN
		"MERCI D'AVOIR JOUE !\n\nKAZERLELUTIN\nAOINEKO\nMOKONA", // TEXT_THANKS
	},
};