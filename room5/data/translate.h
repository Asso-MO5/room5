// Generated by MSXgl on 2024-04-29 00:06:05
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
#define TEXT_LANG_LABEL 3
#define TEXT_ROOM1 4
#define TEXT_ROOM7 5
#define TEXT_ROOM11 6
#define TEXT_ROOM15 7
#define TEXT_ROOM19 8
#define TEXT_ROOM23 9
#define TEXT_ROOM25 10
#define TEXT_END_HOSPITAL 11
#define TEXT_END_MATRIX 12
#define TEXT_END_ALIEN 13
#define TEXT_THANKS 14
#define TEXT_MAX 15

// Localization data table
const c8* const g_TransData[LANG_MAX][TEXT_MAX] =
{
	// EN
	{
		"MSXgl - Localization sample", // TEXT_TITLE
		"THIS GAME IS MADE LIVE\nON TWITCH\n\nTWITCH.TV/MO5ASSORETRO", // TEXT_TITLE_TWITCH
		"HOLD 'ESC' TO RESET", // TEXT_PRESS_ESC
		"ENGLISH", // TEXT_LANG_LABEL
		"...YOU NEED...TO REACH\n...ROOM 5.\n\n1.IS THAT WHERE I'LL\n  WAKE UP?\n\n2.IT'S IMPORTANT FOR YOU?\n\n3.IT'S A SAVE POINT!", // TEXT_ROOM1
		"ROOM 5 WILL BRING YOU\nCLOSER... TO...\nTHE TRUTH.\n\n1.FOR ME OR YOU?\n\n2.BONUS STAGE?\n\n3.FOR MY MEMORIES?", // TEXT_ROOM7
		"...REMINDER...ROOM 5\n...IS THE KEY.\n\n1.FOR YOUR WEIRD GAME\n\n2.I KNOW,\n  I READ THE MANUAL\n\n3.MY BODY IS A TRAP", // TEXT_ROOM11
		"...ROOM 5 IS DIFFERENT\nFROM...THE OTHERS.\n\n1.IS IT A SECRET?\n\n2.WHAT HAVE YOU DONE\n  IN THAT ROOM?\n\n3.IS THAT WHERE\n  EVERYTHING WILL BECOM?", // TEXT_ROOM15
		"...ROOM 5...WILL GIVE\nYOU ANSWERS.\n\n1.ABOUT MY CONDITION?\n\n2.ABOUT THE OBJECTIVE?\n\n3.ABOUT YOUR MISSION?", // TEXT_ROOM19
		"...ROOM 5...IS NEAR\n...DONT LOSE HOPE...\n\n1.I JUST WANT\n  TO UNDERSTAND.\n\n2.WHY IS IT SO\n  IMPORTANT TO YOU?\n\n3.NEXT LEVEL?", // TEXT_ROOM23
		"...ROOM 5...IS\nYOUR DESTINY...\n\n1.MY DESTINY OR YOURS?\n\n2.MY DESTINY TO WAKE UP?\n\n3.DESTINY FOR A PLAYER?", // TEXT_ROOM25
		"YOU'RE FINALLY AWAKE.\nYOU WHERE IN COMA,\nBUT YOU MANAGED TO FIGHT\nAND COME BACK TO US.\n\nYOUR MIND CREATED THIS PLACE\nTO HELP YOU TO WAKE UP.n\nWELCOME BACK TO REALITY.", // TEXT_END_HOSPITAL
		"CONGRATULATIONS!\nYOU'VE COMPLETED THE GAME.\nEVERYTHING YOU EXPERIENCED\nWAS A SIMULATION,\nA CREATION OF OUR TEAM.\nYOU'VE BEEN AN\nEXCELLENT PLAYER.\n\nSEE YOU SOON IN ANOTHER GAME.", // TEXT_END_MATRIX
		"YOU DID WELL, HUMAN.\nYOU WHERE A VALUABLE\nSUBJECT FOR OUR STUDY.\nWE WANTED TO UNDERSTAND\nTHE HUMAN MIND.\n\nYOU ARE FREE NOW,\nWITH MEMORIES OF\nUNIQUE EXPERIENCES.", // TEXT_END_ALIEN
		"  THANKS FOR PLAYING!\n\n\n     KAZERLELUTIN\n\n     AOINEKO\n\n     MOKONA", // TEXT_THANKS
	},
	// FR
	{
		"MSXgl - Sample de traduction", // TEXT_TITLE
		"CE JEU EST FAIT EN LIVE\nSUR TWITCH\n\nTWITCH.TV/MO5ASSORETRO", // TEXT_TITLE_TWITCH
		"  MAINTENIR 'ESC'\n   POUR RELANCER", // TEXT_PRESS_ESC
		"FRANCAIS", // TEXT_LANG_LABEL
		"...TU DOIS...ATTEINDRE\n...LA CHAMBRE 5.\n\n1.C'EST LA QUE JE\n  ME REVEILLERAI?\n\n2.C'EST IMPORTANT\n  POUR VOUS?\n\n3.C'EST UN POINT\n  DE SAUVEGARDE !", // TEXT_ROOM1
		"...LA CHAMBRE 5...\nTE RAPPROCHERA...\nDE...LA VERITE.\n\n1.POUR MOI OU POUR VOUS?\n\n2.NIVEAU BONUS?\n\n3.POUR MES SOUVENIRS?", // TEXT_ROOM7
		"...RAPPEL...\nLA CHAMBRE 5...\nEST LA CLE.\n\n1.POUR TON JEU BIZARRE\n\n2.JE SAIS,\n  J'AI LU LA NOTICE\n\n3.MON CORPS EST UN PIEGE", // TEXT_ROOM11
		"...LA CHAMBRE 5\nEST DIFFERENTE\nDES...AUTRES.\n\n1.EST-CE UN SECRET?\n\n2.QUE FAITES-VOUS\n  DANS CETTE CHAMBRE?\n\n3.EST-CE LA OU\n  TOUT VA BASCULER?", // TEXT_ROOM15
		"...LA CHAMBRE 5\n...TE DONNERA\nDES REPONSES.\n\n1.SUR MON ETAT?\n\n2.SUR L'OBJECTIF?\n\n3.SUR VOTRE MISSION?", // TEXT_ROOM19
		"...LA CHAMBRE 5\n...EST PROCHE...\nNE PERDS PAS ESPOIR...\n\n1.JE VEUX JUSTE COMPRENDRE.\n\n2.POURQUOI EST-CE SI\n  IMPORTANT POUR VOUS?\n\n3.NIVEAU SUIVANT?", // TEXT_ROOM23
		"...LA CHAMBRE 5\n...EST TON DESTIN...\n\n1.MON DESTIN OU LE VOTRE?\n\n2.MON DESTIN POUR\n  ME REVEILLER?\n\n3.DESTIN POUR UN JOUEUR?", // TEXT_ROOM25
		"VOUS ETES ENFIN REVEILLE.\nVOUS ETIEZ DANS LE COMA,\nMAIS VOUS AVEZ REUSSI\nA VOUS BATTRE\nET A REVENIR VERS NOUS.\nVOTRE ESPRIT A CREE CET ENDROIT\nPOUR VOUS AIDER A\nVOUS REVEILLER.\n\nBIENVENUE DANS LA REALITE.", // TEXT_END_HOSPITAL
		"FELICITATIONS !\nVOUS AVEZ TERMINE LE JEU.\nTOUT CE QUE VOUS AVEZ VECU\nETAIT UNE SIMULATION,\nUNE CREATION DE NOTRE EQUIPE.\nVOUS AVEZ ETE UN\nEXCELLENT JOUEUR.\n\nA BIENTOT DANS UN AUTRE JEU.", // TEXT_END_MATRIX
		"VOUS AVEZ BIEN FAIT, HUMAIN.\nVOUS ETIEZ UN SUJET DE\nVALEUR POUR NOTRE ETUDE.\nNOUS VOULIONS COMPRENDRE\nL'ESPRIT HUMAIN.\nVOUS ETES LIBRE MAINTENANT,\nAVEC DES SOUVENIRS\nD'EXPERIENCES UNIQUES.", // TEXT_END_ALIEN
		" MERCI D'AVOIR JOUE !\n\n\n     KAZERLELUTIN\n\n     AOINEKO\n\n     MOKONA", // TEXT_THANKS
	},
};