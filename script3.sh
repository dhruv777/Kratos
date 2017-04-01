#!/bin/bash
HOST='192.168.19.17'
USER='user'
PASSWD='password'

ftp -n -v $HOST << EOT
ascii
user $USER $PASSWD
prompt
put $1
EOT
