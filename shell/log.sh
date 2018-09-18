echo "Please input your uesrname"
read name
while test "$name" != "root"
	do
		echo "Invaild username,Please input again"
		read name
	done
a=5
while test $a -gt 0
	do
	echo "Please input your password"
	read pass
	if test "$pass" = "ubantu"
		then
			echo "Log in success."
			exit
		else
		a=`expr $a - 1`
		echo "!Error Password,The User Will Be Locked after $a times"
	fi
	done
		 
	


