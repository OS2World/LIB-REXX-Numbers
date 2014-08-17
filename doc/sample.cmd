/* program REXX that shows how to use the function NUMBER */

/* Register the function, if necessary */
/* The file NUMBERS.DLL must be in a directory listed in DPATH */
/* otherwise you must include the full drive and directory in the second */
/* parameter of RxFuncAdd */

if (RxFuncQuery("Number") == 1) then call RxFuncAdd "Number", "Numbers", "Number"

/* get the number, the gender and the language */
/* number to convert */
Say 'Enter the number'
Pull Number

/* gender */
Say 'Enter the gender (m = masculine, f = feminine)'
Pull Gender

/* language */
Say 'Enter the language (a = English, e = Spanish, c = Catalan)'
Pull Language

/* call the function using these parameters */
OneNumber = Number(Number, Gender, Language)

/* show the result */
say OneNumber
