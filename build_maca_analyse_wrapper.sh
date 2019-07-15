#!/usr/bin/env bash

#TODO: Use CMake to build wrappers
swig -python -c++ maca_analyse.i
g++ -fPIC -c $(pkg-config --cflags --libs python3) maca_analyse.cpp maca_analyse_wrap.cxx

LIB_Boost=$(ldconfig -p | grep libboost_program_options.so$ | awk '{print $4}')
LIB_Icuuc=$(ldconfig -p | grep libicuuc.so$ | awk '{print $4}')
LIB_PwrUtils=$(ldconfig -p | grep libpwrutils.so$ | awk '{print $4}')
LIB_Toki=$(ldconfig -p | grep libtoki.so$ | awk '{print $4}')
LIB_Corpus2=$(ldconfig -p | grep libcorpus2.so$ | awk '{print $4}')
LIB_Maca=$(ldconfig -p | grep libmaca.so$ | awk '{print $4}')

if [ -z $LIB_Boost ];
then
        echo 'Boost library has not been found!'
        exit 1
fi

if [ -z $LIB_Icuuc ];
then
        echo 'Icuuc library has not been found!'
        exit 1
fi

if [ -z $LIB_PwrUtils ];
then
        echo 'Pwr_Utils library has not been found!'
        exit 1
fi

if [ -z $LIB_Toki ];
then
        echo 'Toki library has not been found!'
        exit 1
fi

if [ -z $LIB_Corpus2 ];
then
        echo 'Corpus2 library has not been found!'
        exit 1
fi

if [ -z $LIB_Maca ];
then
        echo 'Maca library has not been found!'
        exit 1
fi

LIBS=$( echo $LIB_Boost $LIB_Icuuc $LIB_PwrUtils $LIB_Toki $LIB_Corpus2 $LIB_Maca )

g++ -shared -o _maca_analyse.so maca_analyse.o maca_analyse_wrap.o $LIBS
Python_Path=$(python3 -c "import sys; print('/usr/local/lib/python' + sys.version[:3] + '/dist-packages/')")

cp _maca_analyse.so ${Python_Path}
cp maca_analyse.py ${Python_Path}