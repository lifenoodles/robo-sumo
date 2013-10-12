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
            debug="1"
            ;;
        *)
            sumo_id=$1
            ;;
    esac
    shift
done

path=""
case $sumo_id in
    "phobos")
        name="phobos"
        id="PHOBOS"
        ;;
    "titan")
        name="titan"
        id="TITAN"
        ;;
    *)
        echo "Unrecognised Sumo ID"
        exit 0
        ;;
esac

path="../build/make-$name"
if [ "$debug" == "1" ]; then
    EXTRA_FLAGS="-DDEBUG -D$id" OBJDIR="../build/bin/$name-debug" make -f "$path"
else
    EXTRA_FLAGS="-DDEBUG -D$id" OBJDIR="../build/bin/   $name" make -f "$path"
fi

if [ "$?" = "0" ]; then
    echo "Compiled OK!"
else
    echo "ERROR while compiling!"
fi

