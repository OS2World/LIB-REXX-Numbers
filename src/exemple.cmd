/* programa REXX que mostra el funcionament de la funci¢ NUMBER */

/* Registrar la funci¢, si no ho est… */
/* El fitxer NUMBERS.DLL ha d'estar en un directori incl•s a DPATH */
/* o b‚ cal incloure la unitat de disc i directori(s)  en el segon */
/* par…metre de RxFuncAdd */

if (RxFuncQuery("Number") == 1) then call RxFuncAdd "Number", "Numbers", "Number"

Do Numero = 1 to 100
   say Numero Number(Numero, 'm', 'a')
End

Do Numero = 1 to 100
   NumeroATraduir = Random(0, 100000)
   say NumeroATraduir Number(NumeroATraduir, 'm', 'a')
End
