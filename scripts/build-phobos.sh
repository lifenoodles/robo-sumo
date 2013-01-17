CURRENT=`pwd`
BASENAME=`basename $CURRENT`

while [ $BASENAME != "robo-sumo" ]; do
    cd ..
    CURRENT=`pwd`
    BASENAME=`basename $CURRENT`
done
cd src
make upload -f ../scripts/make-phobos
