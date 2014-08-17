/* programa REXX que mostra el funcionament de la funci¢ NUMBER */

/* Registrar la funci¢, si no ho est… */
/* El fitxer NUMBERS.DLL ha d'estar en un directori incl•s a DPATH */
/* o b‚ cal incloure la unitat de disc i directori(s)  en el segon */
/* par…metre de RxFuncAdd */

if (RxFuncQuery("Number") == 1) then call RxFuncAdd "Number", "Numbers", "Number"
Say RxFuncQuery("Number")

say Number(1500, 'm', 'c')
say Number(1500, 'm', 'e')
say Number(1500, 'm', 'a')
