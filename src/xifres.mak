# IBM Developer's Workframe/2 Make File Creation run at 20:00:48 on 06/23/95

# Make File Creation run in directory:
#   D:\IBMCPP\PROJECT\XIFRES;

.SUFFIXES:

.SUFFIXES: .c .cpp .cxx

Numbers.dll:  \
  xifres.OBJ \
  XIFRES.MAK
   ICC.EXE @<<
 /B" /st:8192"
 /Fe"Numbers.dll" xifres.def
xifres.OBJ
<<
  IMPLIB XIFRES.LIB NUMBERS.DLL

{.}.c.obj:
   ICC.EXE /V"Xifres a lletres 1.2 - Gabriel Massip, octubre 1997" /Ge- /C   .\$*.c

!include XIFRES.DEP
