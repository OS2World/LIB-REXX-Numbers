/* programa REXX que mostra el funcionament de la funci� NUMBER */

/* Registrar la funci�, si no ho est� */
/* El fitxer NUMBERS.DLL ha d'estar en un directori incl�s a DPATH */
/* o b� cal incloure la unitat de disc i directori(s)  en el segon */
/* par�metre de RxFuncAdd */

if (RxFuncQuery("Number") == 1) then call RxFuncAdd "Number", "numbers", "Number"

/* obtenir els n�mero, el g�nere i l'idioma */
/* n�mero a convertir */
Say 'Entreu el n�mero'
Pull Numero

/* g�nere */
Say 'Entreu el g�nere (m = mascul�, f = femen�)'
Pull Genere

/* idioma */
Say 'Entreu l''idioma (c = catal�, e = espanyol, a = angl�s)'
Pull Idioma

/* cridar la funci� amb aquests par�metres */
UnNumero = Number(Numero, Genere, Idioma)

/* treure el resultat */
say UnNumero
