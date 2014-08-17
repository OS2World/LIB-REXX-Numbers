/*****************************************************************************/
/* DLL per a REXX, que converteix un n£mero enter en una cadena de car…cters */
/* Documentaci¢ extreta de                                                   */
/*   RPP, n£mero 4 (febrer 1995), p…gs. 64-70                                */
/*   Dr. Dobb's Journal, n£mero 219 (setembre 1994), p…g. 36                 */
/*                                                                           */
/* Gabriel Massip, juny 1995                                                 */
/*****************************************************************************/

/* 'defines' trets de les revistes, encara no els entenc */

/* Versi¢ 1.2, corregeix alguns problemes amb l'anglŠs   */
/* juliol 1997                                           */

#define INCL_32
#define INCL_REXXSAA
#define INCL_BASE
#define INCL_RXHV

#include <string.h>
#include <rexxsaa.h>
#include <stdlib.h>
#include <ctype.h>

/* codis d'error */
#define ARGUMENTSERRONIS -1
#define NOERROR 0

/* funci¢ exportada */
RexxFunctionHandler Number;

void AfegirCaracter (char cadena[], char c)
{
   char aux[2];

   aux[0] = c;
   aux[1] = '\0';
   strcat (cadena, aux);
}

void AfegirEspai (char cadena[])
{
   /* afegeix un espai al final de la cadena */
   AfegirCaracter (cadena, ' ');
}


void UAMil (int N, int genere, char UAMLletres [])
{

  char UAVint [2][19][8] = {{"un", "dos", "tres", "quatre", "cinc", "sis",
                            "set", "vuit", "nou", "deu", "onze", "dotze",
                            "tretze", "catorze", "quinze", "setze", "disset",
                            "divuit", "dinou"},
                            {"una", "dues", "tres", "quatre", "cinc", "sis",
                            "set","vuit", "nou", "deu", "onze","dotze",
                            "tretze","catorze", "quinze", "setze", "disset",
                            "divuit", "dinou"}};

   char Cents [2][7] = {"cents", "centes"};

   char Desenes [8][10] = {"vint", "trenta", "quaranta", "cinquanta",
                         "seixanta", "setanta", "vuitanta", "noranta"};

   int centena, desena, unitat;
   char XLletres [255]="";

   /* separar les centenes, desenes i unitats */
   centena = N / 100;
   desena = (N % 100) / 10;
   unitat = N % 10;

   /* mirar si hi ha centenes */
   if (centena > 0)
   {
      if (centena == 1) strcpy (XLletres, "cent ");
      else
      {
         strcpy (XLletres, UAVint [genere][centena-1]);
         strcat (XLletres, "-");
         strcat (XLletres, Cents [genere]);
         AfegirEspai (XLletres);
      }
   }

   /* afegir-hi les desenes */
   if (desena > 0 )
   {
      if (desena == 1)
      {
         /* posar desena i unitat */
         strcat (XLletres, UAVint [genere][10*desena + unitat -1]);
      }
      else
      {
         strcat (XLletres, Desenes [desena - 2]);
         /* afegir-hi el gui¢ o el '-i-' si cal */
         if (unitat > 0)
         {
            if (desena == 2) strcat (XLletres, "-i-");
            else strcat (XLletres, "-");
         }
      }
   }

   /* afegir les unitats */
   if ((unitat > 0) && (desena != 1)) strcat (XLletres,UAVint[genere][unitat-1]);
   strcpy (UAMLletres, XLletres);
}


void XifraALletres (unsigned long N, int genere, char XLletres [])
{
   int milions, milers, unitats;
   char final[255]="", parcial [255]="";

   milions = N / 1000000;
   milers = (N % 1000000) / 1000;
   unitats = N % 1000;

   /* tractar els milions si n'hi ha */
   if (milions > 0)
   {
      XifraALletres (milions, 0, parcial);
      strcpy (final, parcial);
      if (milions == 1) strcat (final, " mili¢");
      else strcat (final, " milions");

      if ((milers != 0) || (unitats != 0)) AfegirEspai (final);
   }

   /* tractar els milers */
   if (milers > 0)
   {
      if (milers > 1)
      {
         UAMil (milers, genere, parcial);
         strcat (final, parcial);
         AfegirEspai (final);
      }
      strcat (final, "mil");
      if (unitats != 0) AfegirEspai (final);
   }

   /* tractar les unitats */
   {
      UAMil (unitats, genere, parcial);
      strcat (final, parcial);
   }
   strcpy (XLletres, final);

   /* tractar el zero, que ‚s un possible valor */
   if (N == 0) strcat (XLletres, "zero");
}


void UnoAMil (int N, int genere, char UAMLletres [])
{

  char UAVint [2][19][11] = {{"uno", "dos", "tres", "cuatro", "cinco", "seis",
                            "siete", "ocho", "nueve", "diez", "once", "doce",
                            "trece", "catorce", "quince", "diecis‚is", "diecisiete",
                            "dieciocho", "diecinueve"},
                            {"una", "dos", "tres", "cuatro", "cinco", "seis",
                            "siete", "ocho", "nueve", "diez", "once", "doce",
                            "trece", "catorce", "quince", "diecis‚is", "diecisiete",
                            "dieciocho", "diecinueve"}};

   char Cents [2][8] = {"cientos", "cientas"};

   char Desenes [8][10] = {"veint", "treinta", "cuarenta", "cincuenta",
                           "sesenta", "setenta", "ochenta", "noventa"};

   int centena, desena, unitat;
   char XLletres [255]="";

   /* separar les centenes, desenes i unitats */
   centena = N / 100;
   desena = (N % 100) / 10;
   unitat = N % 10;

   /* mirar si hi ha centenes */
   if (centena > 0)
   {
      switch (centena)
      {
         case 1:
            desena != 0 || unitat != 0 ? strcpy (XLletres, "ciento ") : strcpy (XLletres, "cien ");
            break;
         case 5:
            strcpy (XLletres, genere == 0 ? "quinientos " : "quinientas ");
            break;
         case 7:
            strcpy (XLletres, genere == 0 ? "setecientos ": "setecientas ");
            break;
         case 9:
            strcpy (XLletres, genere == 0 ? "novecientos " : "novecientas ");
            break;
         default:
            strcpy (XLletres, UAVint [genere][centena-1]);
            strcat (XLletres, Cents [genere]);
            AfegirEspai (XLletres);
            break;
      } /* endswitch */
   }

   /* afegir-hi les desenes */
   if (desena > 0 )
   {
      if (desena == 1)
      {
         /* posar desena i unitat */
         strcat (XLletres, UAVint [genere][10*desena + unitat -1]);
      }
      else
      {
         strcat (XLletres, Desenes [desena - 2]);
         if (unitat == 0 && desena == 2) strcat (XLletres, "e");
         /* afegir-hi el gui¢ o el 'y' si cal */
         if (unitat > 0)
         {
            if (desena == 2) strcat (XLletres, "i");
            else strcat (XLletres, " y ");
         }
      }
   }

   /* afegir les unitats */
   if ((unitat > 0) && (desena != 1)) strcat (XLletres,UAVint[genere][unitat-1]);
   strcpy (UAMLletres, XLletres);
}


void CifraALetras (unsigned long N, int genere, char XLletres [])
{
   int milions, milers, unitats;
   char final[255]="", parcial [255]="";

   milions = N / 1000000;
   milers = (N % 1000000) / 1000;
   unitats = N % 1000;

   /* tractar els milions si n'hi ha */
   if (milions > 0)
   {
      CifraALetras (milions, 0, parcial);
      strcpy (final, parcial);
      if (milions == 1) strcat (final, " mill¢n");
      else strcat (final, " millones");

      if ((milers != 0) || (unitats != 0)) AfegirEspai (final);
   }

   /* tractar els milers */
   if (milers > 0)
   {
      if (milers > 1)
      {
         UnoAMil (milers, genere, parcial);
         strcat (final, parcial);
         AfegirEspai (final);
      }
      strcat (final, "mil");
      if (unitats != 0) AfegirEspai (final);
   }

   /* tractar les unitats */
   {
      UnoAMil (unitats, genere, parcial);
      strcat (final, parcial);
   }
   strcpy (XLletres, final);

   /* tractar el zero, que ‚s un possible valor */
   if (N == 0) strcat (XLletres, "cero");
}

void OneToThousand (int N, int genere, char UAMLletres [])
{
   char OneToNineteen [19][10] = {"one", "two", "three", "four", "five", "six",
                                 "seven", "eight", "nine", "ten", "eleven",
                                 "twelve", "thirteen", "fourteen", "fifteen",
                                 "sixteen", "seventeen", "eighteen", "nineteen"};

   char TwentyToNinety [8][8] = {"twenty", "thirty", "forty", "fifty", "sixty",
                                 "seventy", "eighty", "ninety"};

   int centena, desena, unitat;
   char XLletres [255]="";

   /* separar les centenes, desenes i unitats */
   centena = N / 100;
   desena = (N % 100) / 10;
   unitat = N % 10;

   /* mirar si hi ha centenes */
   if (centena > 0)
   {
      strcpy (XLletres, OneToNineteen [centena - 1]);
      strcat (XLletres, " hundred");
   }

   /* afegir-hi les desenes */
   if (desena > 0 )
   {
      if (centena != 0) AfegirEspai (XLletres);
      if (desena == 1) strcat (XLletres, OneToNineteen [10*desena + unitat - 1]);
      else strcat (XLletres, TwentyToNinety [desena - 2]);
   }

   /* afegir les unitats */
   if ((unitat > 0) && (desena != 1))
   {
      if (desena != 0) strcat (XLletres, "-");
      /*
      La l¡nia anterior s'ha de substituir per la segent si volem deixar-ho amb espai
      if (desena != 0) strcat (XLletres, " ");
      12/10/1997
      */
      else if (centena != 0) AfegirEspai (XLletres);
      strcat (XLletres, OneToNineteen [unitat-1]);
   }
   strcpy (UAMLletres, XLletres);
}


void NumberToLetter (unsigned long N, int genere, char XLletres [])
{
   /* atenci¢, els bilions s¢n "bilions" americans, ‚s a dir, milers de milions */
   int bilions, milions, milers, unitats;
   char final[255]="", parcial [255]="";

   bilions = N / 1000000000;
   milions = (N % 1000000000) / 1000000;
   milers = (N % 1000000) / 1000;
   unitats = N % 1000;

   /* tractar els bilions, si n'hi ha */
   if (bilions > 0)
   {
      OneToThousand (bilions, genere, parcial);
      strcpy (final, parcial);
      strcat (final, " billion");
      if (N % 1000000000) AfegirEspai (final);
   }

   /* tractar els milions si n'hi ha */
   if (milions > 0)
   {
      NumberToLetter (milions, 0, parcial);
      strcat (final, parcial);
      strcat (final, " million");
      if (N % 1000000) AfegirEspai (final);
   }

   /* tractar els milers */
   if (milers > 0)
   {
      OneToThousand (milers, genere, parcial);
      strcat (final, parcial);
      AfegirEspai (final);
      strcat (final, "thousand");
      if (unitats != 0) AfegirEspai (final);
   }

   /* tractar les unitats */
   {
      OneToThousand (unitats, genere, parcial);
      strcat (final, parcial);
   }
   strcpy (XLletres, final);

   /* tractar el zero, que ‚s un possible valor */
   if (N == 0) strcat (XLletres, "zero");
}


ULONG Number (CHAR *nom, ULONG numarguments, RXSTRING arguments[], CHAR
*nomcua, RXSTRING *retorn)
{
   unsigned long Numero;
   char Genere, XLletres [255], *error, Idioma;

   if (numarguments != 3) return ARGUMENTSERRONIS;
   else
   {
      /* esbrinar el valor dels dos arguments */
      Numero = strtoul(arguments[0].strptr, &error, 10);
      Genere = toupper (arguments[1].strptr[0]);
      Idioma = toupper (arguments[2].strptr[0]);

      if ((Genere != 'M') && (Genere != 'F')) return ARGUMENTSERRONIS;
      if ((Idioma != 'C') && (Idioma != 'E') && (Idioma != 'A')) return ARGUMENTSERRONIS;


      /* seguim endavant, no hi ha errors */
      /* fer el c…lcul */
      if (Idioma == 'C') XifraALletres (Numero, Genere == 'M' ? 0 : 1, XLletres);
      if (Idioma == 'E') CifraALetras (Numero, Genere == 'M' ? 0 : 1, XLletres);
      if (Idioma == 'A') NumberToLetter (Numero, 0, XLletres);

      /* retornar el valor */
      retorn->strlength = strlen (XLletres);
      strcpy (retorn->strptr, XLletres);
      return NOERROR;
   }
}
