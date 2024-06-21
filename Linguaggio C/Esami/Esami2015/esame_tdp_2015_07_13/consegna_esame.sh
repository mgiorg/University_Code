#!/bin/bash

ID=$(sed -n '1p' studente.txt | sed 's/[[:blank:]]*//g' | awk -F':' '{print $NF}')
NAME=$(sed -n '2p' studente.txt | sed 's/[[:blank:]]*//g' | awk -F':' '{print $NF}')
SURNAME=$(sed -n '3p' studente.txt | sed 's/[[:blank:]]*//g' | awk -F':' '{print $NF}')

TARGZ_PREFIX="$ID"_"$SURNAME"_"$NAME"_"$HOSTNAME"

echo $ID
echo $NAME
echo $SURNAME
echo $TARGZ_PREFIX

tar --exclude='./' --exclude='../' -zcvf $TARGZ_PREFIX.tar.gz *

ftp -v -n 192.168.49.95 << End-Of-Session
user anonymous "\n"
put $TARGZ_PREFIX.tar.gz uploads/$TARGZ_PREFIX.tar.gz
bye
End-Of-Session

rm $TARGZ_PREFIX.tar.gz
