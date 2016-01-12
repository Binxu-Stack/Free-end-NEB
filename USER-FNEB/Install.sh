# Install/unInstall package classes in LAMMPS

if (test $1 = 1) then

  cp fix_fneb.cpp  fix_fneb.h  fneb.cpp  fneb.h ..

elif (test $1 = 0) then

  rm ../fix_fneb.cpp ../fix_fneb.h ../fneb.cpp ../fneb.h

fi
