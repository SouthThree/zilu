#/bin.bash
option=$1
pre=$2
case $option in
	1)	
		## .c ===> .cfg
		allcfiles=`ls *.c`
		for cfile in $allcfiles; do
			basename=`basename -s .c $cfile`
			echo -n $basename"-->"
			cp $cfile $pre"_"$basename".cfg"
			cat template.cfg >> $pre"_"$basename".cfg"
			echo `wc -l $pre"_"$basename".cfg"`
		done
		;;
	2)
		## remove all the \r in the files
		## \r is introduced by windows system
		## remove redandunt \n in the files
		allfiles=`ls *`
		for file in $allfiles; do
			sed -i 's/\n\n/\n/g' $file
			sed -i 's/\r//g' $file
		done
		;;
	*)
		echo "Wrong arguments."
esac
