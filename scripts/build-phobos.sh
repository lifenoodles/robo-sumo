#!/usr/bin/env bash

CURRENT=$(pwd)
BASENAME=$(basename $CURRENT)
echo $BASENAME

while [ $BASENAME != "robo-sumo" ]; do
    cd ..
    CURRENT=$(pwd)
    BASENAME=$(basename $CURRENT)
done
cd src
mv Sumo.cpp Sumo.ino
make -f ../scripts/make-phobos
mv Sumo.ino Sumo.cpp

if [ "$?" = "0" ]; then
    echo "Compiled OK!"
else
    echo "ERROR while compiling!"
fi
