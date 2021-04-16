#!/bin/sh
cat /etc/passwd | cut -d':' -f1 | sed -n '2~2p' | rev | sort -r | sed -n "$FT_LINE1,$FT_LINE2 p" | awk -vORS=', ' '{ print $1 }' |  sed -r 's/, $/./'
