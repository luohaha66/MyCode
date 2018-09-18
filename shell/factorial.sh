echo "Please input a number:"
read number
sum=1
for num in `seq 1 1 $number`
	do
		sum=`expr $num \* $sum`
	done
echo "$num! is  $sum"

sum=0
for ((num=1;num<=$number;num++))
	do
		sum=`expr $num + $sum`
	done
echo "from 1 to $number is $sum"
