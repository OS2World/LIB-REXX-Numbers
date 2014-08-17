/* programa REXX que muestra el funcionamiento de la funci¢n NUMBER */

/* Registrar la funci¢n, si hace falta */
/* El fichero NUMBERS.DLL tiene que estar en un directorio de DPATH */
/* o bien hay que incluir el la unidad y el directorio en el segundo */
/* par metro de RxFuncAdd */

if (RxFuncQuery("Number") == 1) then call RxFuncAdd "Number", "numbers", "Number"

/* obtener los n£mero, el g‚nere y el idioma */
/* n£mero a convertir */
Say 'Entre el n£mero'
Pull Numero

/* g‚nero */
Say 'Entre el g‚nero (m = masculino, f = femenino)'
Pull Genero

/* idioma */
Say 'Entre el idioma (e = espa¤ol, a = ingl‚s, c = catal n)'
Pull Idioma

/* llamar a la funci¢n con estos par metros */
UnNumero = Number(Numero, Genero, Idioma)

/* mostrar el resultado */
say UnNumero
