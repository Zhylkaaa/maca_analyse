#!/usr/bin/env bash

#TODO: Use CMake to build wrappers
swig -python -c++ maca_analyse.i
g++ -fPIC -c $(pkg-config --cflags --libs python3) maca_analyse.cpp maca_analyse_wrap.cxx
g++ -shared -o _maca_analyse.so maca_analyse.o maca_analyse_wrap.o /usr/lib/x86_64-linux-gnu/libboost_program_options.so /usr/lib/x86_64-linux-gnu/libicuuc.so /usr/local/lib/libpwrutils.so /usr/local/lib/libtoki.so /usr/local/lib/libcorpus2.so /usr/local/lib/libmaca.so

Python_Path=$(python3 -c "import sys; print('/usr/local/lib/python' + sys.version[:3] + '/dist-packages/')")

cp _maca_analyse.so ${Python_Path}
cp maca_analyse.py ${Python_Path}