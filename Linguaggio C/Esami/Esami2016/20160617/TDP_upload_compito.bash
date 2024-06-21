#!/bin/bash
# TDP_upload_compito.bash [IP] 


# Directory locale
LOCDIR=$HOME/TDP
ENAME=`date +%Y%m%d`

# Indirizzo di default
URL="192.168.49.137"

if [ "$1" ]; then
URL=$1
fi


# Spostamento nella directory locale
cd $LOCDIR/$ENAME

if [ ! -f "studente.txt" ]; then
echo "File studente.txt non presente. Upload interrotto. Eseguire 'java DatiStudenteGUI'"
exit 1
fi

# Composizione del nome del file tgz
ID=$(sed -n '1p' studente.txt | sed 's/[[:blank:]]*//g' | awk -F':' '{print $NF}')
NAME=$(sed -n '2p' studente.txt | sed 's/[[:blank:]]*//g' | awk -F':' '{print $NF}')
SURNAME=$(sed -n '3p' studente.txt | sed 's/[[:blank:]]*//g' | awk -F':' '{print $NF}')

if [ -z "$ID" ]; then
echo "Dati studente non validi. Upload interrotto. Eseguire 'java DatiStudenteGUI'"
exit 1
fi

OUTTGZ="$ENAME"_"$ID"_"$SURNAME"_"$NAME"_"$HOSTNAME".tgz

if [ -f $OUTTGZ ]; then
echo "File tgz già presente. Upload interrotto."
exit 1
fi

# Crea file tgz
tar --exclude='./' --exclude='../' -zcvf $OUTTGZ *

#* Upload del file tgz
ftp -p -v -n $URL << End-Of-Session
user anonymous "\n"
cd uploads
put $OUTTGZ 
bye
End-Of-Session


