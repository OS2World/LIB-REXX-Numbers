/* programet REXX */
FuncioRegistrada = RxFuncQuery("Number")
Say FuncioRegistrada "  (0 = registrada, 1 = no registrada)"

if FuncioRegistrada = 0 then do
   call RxFuncDrop "Number"
   say result (" Resultat de deregistrar la funci¢")
end

