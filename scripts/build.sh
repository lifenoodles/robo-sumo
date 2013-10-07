#!/usr/bin/env bash

if [ "$#" == "0" ] || [ "$#" -gt "2" ]; then
    echo "Usage: build [robot-id]"
    exit 0
fi

CURRENT=$(pwd)
BASENAME=$(basename $CURRENT)

while [ $BASENAME != "robo-sumo" ]; do
    cd ..
    CURRENT=$(pwd)
    BASENAME=$(basename $CURRENT)
done
cd src

debug="0"
sumo_id=""
flags=
while [ "$#" -gt 0 ]; do
    case "$1" in
        "-d")
            flags="-DDEBUG"
            debug="1"
            ;;
        *)
            sumo_id=$1
            ;;
    esac
    shift
done

doclean=0
last_debug=$(head -n 1 ../scripts/LAST_BUILD)
last_sumo=$(head -n 2 ../scripts/LAST_BUILD | tail -1)
if [ "$last_debug" != "$debug" ] || [ "$last_sumo" != "$sumo_id" ]; then
    doclean=1
fi
path=""

echo $debug > ../scripts/LAST_BUILD
echo $sumo_id >> ../scripts/LAST_BUILD

mv Sumo.cpp Sumo.ino
case $sumo_id in
    "phobos")
        flags=$(echo "$flags" "-DPHOBOS")
        path="make-phobos"
        ;;
    "titan")
        flags=$(echo "$flags" "-DTITAN")
        path="make-titan"
        ;;
    *)
        echo "Unrecognised Sumo ID"
        exit 0
        ;;
esac

if [ "$doclean" == "1" ]; then
  make clean -f "../scripts/$path"
fi
SUMO_ID=$flags make -f "../scripts/$path"
if [ "$?" = "0" ]; then
    echo "Compiled OK!"
else
    echo "ERROR while compiling!"
fi
mv Sumo.ino Sumo.cpp
