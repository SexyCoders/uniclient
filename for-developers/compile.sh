#!/bin/bash

TEMPDIR=$(mktemp -d)
DESTDIR=$(mktemp -d)

for file in $(find -type f | grep [^\..] | awk '{ print substr( $0, 3 ) }' | grep [^compile.sh])
	do
		tempfile=$TEMPDIR"/"$file
			if [[ "$file" = */* ]]; then
				mkdir -p "${tempfile%/*}";
			fi;

		awk -v tempfile="$tempfile" '{if ($0 ~ /^#/) k++} {print > tempfile k}' "$file" 

		for tempfile in $(find $TEMPDIR -type f | grep [^\..])
		do
			echo "$tempfile";
		done
	done

tree $TEMPDIR
