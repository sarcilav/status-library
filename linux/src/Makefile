# Makefile for gen the linux library version of status-library
LIBSO=libso-eafit.so
CPP=g++
CXXFLAGS= -shared
SRC=so-eafit.cc
HEADER=so-eafit.h

install: all mv_lib cp_h

all: $(SRC)
	$(CPP) $(CXXFLAGS) $(SRC) -o $(LIBSO)

cp_h: $(HEADER)
	cp $(HEADER) /usr/include/

mv_lib: $(LIBSO)
	mv $(LIBSO) /usr/lib/