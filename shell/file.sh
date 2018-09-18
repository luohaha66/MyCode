echo "If you want to quit,please input q"
echo "Please input filename:"
read name
while test "$name" != "q"
	do
		if test -s $name
			then
			if test -d $name
				then
					echo "$name is dir"
			fi
			if test -f $name
				then
					echo "$name is a normal file"
			fi
		else
			echo "$name is empyt,Please reselect"
		fi
		read name
	done

