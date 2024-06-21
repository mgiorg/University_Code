#!/bin/bash
# TDP_download_compito.bash [ftp|www] [IP|URL] [data]


# Directory locale
LOCDIR=$HOME/TDP

# Comandi di download e indirizzi di default
CMD="wget -N ftp://"
URL="192.168.49.137"
WWWURL="www.dis.uniroma1.it/~iocchi/Didattica/tp_2015_16/Esercitazioni"


# Nome directory (formato yyyymmdd, es. 20160421)
if [ "$3" ]; then
ENAME=$3
else
ENAME=`date +%Y%m%d`
fi


# Spostamento nella directory locale
mkdir -p $LOCDIR
cd $LOCDIR

if [ -f $ENAME.tgz ]; then
echo "File $ENAME.tgz già presente. Download interrotto."
exit 1
fi

# Download del file tgz

if [ "$1" = "www" ]; then
CMD="wget -N "
URL=$WWWURL
fi

if [ "$2" ]; then
URL=$2
fi

echo "$CMD$URL/$ENAME.tgz"
$CMD$URL/$ENAME.tgz

if [ ! -f $ENAME.tgz ]; then
echo "File $ENAME.tgz non trovato. Script interrotto."
exit 1
fi


# Estrazione del file tgz

rm -rf $ENAME
tar xzvf $ENAME.tgz
cd $ENAME

echo "******************************************"
echo "File scaricati nella cartella"
pwd
echo "******************************************"

# Form di registrazione 

java DatiStudenteGUI &

# Esecuzione del terminale nella directory in cui sono stati estratti i file

if [ -a `which roxterm` ]; then
USERTERM=roxterm
else
USERTERM=$TERM
fi

$USERTERM -T "Compito $ENAME" --color-scheme="Default" -e $SHELL -c "cat README.txt; $SHELL" &






