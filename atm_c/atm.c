#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int nosto (int saldo);
int talletus(int saldo);
void naytaSaldo(int saldo);
void lueRoskat(void);
int lueInt(void);
int main (void) {

	FILE * tili;
	char tiliNumero[256];
	char pinKoodi[256];
	char tarkistusPin[256];
	int result;
	int saldo;
	int valinta;

	do {
		printf("\nRosvo automaatti\n\n");
		printf("Tilinumero >");
		fgets(tiliNumero, 256, stdin);
		if(tiliNumero[ strlen(tiliNumero) -1] == '\n') {
				tiliNumero[ strlen(tiliNumero) -1] = '\0';
		} else {
			lueRoskat();
		}
		strcat(tiliNumero, ".tili");

		if ((tili = fopen(tiliNumero, "r")) != NULL) {
			printf("Anna pin >");
			fgets(pinKoodi, 256, stdin);

			if(pinKoodi[ strlen(pinKoodi) -1] == '\n') {
				pinKoodi[ strlen(pinKoodi) -1] = '\0';
			} else {
				lueRoskat();
			}
			do {	
				fgets(tarkistusPin, 256, tili);

				if(tarkistusPin[ strlen(tarkistusPin) -1] == '\n') {
				tarkistusPin[ strlen(tarkistusPin) -1] = '\0';
				}

				if ((result = strcmp(pinKoodi, tarkistusPin)) == 0) {
				fscanf(tili, "%d", &saldo);
				fclose(tili);
				printf("\n1 Nosta : 2 Talleta : 3 Saldo : 0 Kirjaudu ulos \nValinta >");
				valinta = lueInt();
						switch(valinta) {
							case 1:
								saldo = nosto(saldo);
								tili = fopen(tiliNumero, "w");
								fprintf(tili , "%s\n%d" , pinKoodi , saldo);
								fclose(tili);
								result = 1;					
								break;
							case 2:				
								saldo = talletus(saldo);
								tili = fopen(tiliNumero, "w");
								fprintf(tili , "%s\n%d" , pinKoodi , saldo);
								fclose(tili);
								break;
							case 3:
								naytaSaldo(saldo);
								break;
							case 0:
								printf("\nKiitos hei ja tervetuloa uudestaan\n\n");
								result = 1;
								break;
							default:
								printf("Väärä valinta\n");
						}

				} else {
					printf("Väärä pin-koodi\n");
				}
			} while (!result);

		} else {
			printf("Tili lukittu\n");
		}

	} while(1);
	return 0;		
}

//Nayttaa tilin saldon. 
//Parametrina int saldo, arvo saadaan mainissa olevasta saldo muuttujasta
void naytaSaldo(int saldo) {
	printf("\nTilisi saldo on %d€\n", saldo);
}

//Kysyy käyttäjältä paljonko nostetaan ja algoritmin avulla laskee mitä seteleitä käyttäjä saa.
//While -loopin ehtona; maara  ei ole jaollinen 50:lla, 
//maara -muuttujasta miinustetaan 20 ja kaksyt korotetaan niin monta kertaa kuin ehto on voimassa.
//Tämän jälkeen lasketaan montako viiskyt annetaan jakamalla jäljellä oleva maara 50:llä.
//
//ESIM. 120 ei ole jaollinen 50:llä, joten 120 miinustetaan 20 ja kaksyt = 1
//nyt maara on 100 eikä se täytä whilen ehtoa. 100 jaetaan 50:llä ja saadaan viiskyt = 2
//Käyttäjä saa 1kpl 20eur seteliä ja 2kpl 50eur seteliä
//
//Parametrina int saldo, arvo tulee mainista
//Palautetaan muutettu saldo takaisin kutsujalleen, joka on mainissa.
int nosto (int saldo) {
	int maara;
	int kakskyt = 0, viiskyt = 0;
	while (1) {
		printf("\nSyötä nostettava määrä min. 20€ (0 kirjaa ulos) >");
		maara = lueInt();

		if (maara == 0) {
			printf("\nKirjaudutaan ulos\n");
			break;
		}

		if (maara  % 10 != 0 || maara < 20 || maara > 1000 || maara == 30) {
			printf("\nEpäkelpo syöte\n");
		} else if ( maara > saldo) {
			printf("Tilillä ei katetta\n");
		} else {
			saldo -= maara;
			while (maara % 50 != 0){
        		maara -= 20;
        		kakskyt++;
    		}		

		viiskyt = maara / 50;	
		printf("Saat 20€ seteleitä %d kpl\nSaat 50€ seteleitä %d kpl\n\n", kakskyt, viiskyt);
		printf("Tilin saldo on %d€\n\nKiitos käynnistä\n\n", saldo);
		break;
		}
	}
	
	return saldo;
}

//Kysyy käyttäjältä paljonkon talletetaan tilille
//Syote tarkistetaan ja tulostetaan asianmukaiset virheilmoitukset
//Parametrina int saldo, jonka arvo saadaan mainista
//Palauttaa muuttuneen saldon takaisin kutsujalleen mainiin
int talletus (int saldo) {
	int maara;
	while (1) {
		printf("Syötä talletettava määrä (0 lopettaa) >");
		maara = lueInt();

		if (maara == 0) {
			break;
		}

		if (maara < 0 || maara > 1000) {
			printf("Ei sallittu\n");
		} else {
			saldo += maara;
			printf("\nTilille tallettu %d€\n", maara);
			printf("Tilin saldo nyt %d€\n", saldo);
			break;
		}
	}
	

	return saldo;
}

//Vastaa syötteentarkistusesta ja jos syöte ei ole kokonaisluku kysytään uudestaan
//Palauttaa kutsujalleen syötetyn kokonaisluvun
int lueInt(void){
   
   int luku;
   char mki;
   int status;
   
   while((status = scanf("%d%c", &luku, &mki))==0  || (2 == status && mki != '\n') ){
      lueRoskat();
      printf("Virheellinen syöte. Syötä uudestaan > ");
   }
   
   return luku;
}

//tyhjentää syötepuskurin
void lueRoskat(void){
   
   while(fgetc(stdin) != '\n');
   
}
