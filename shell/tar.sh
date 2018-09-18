echo "Please Input the Package Name:"
read name
packge=${name}".tar.bz"
all=`ls`
for file in $all
do
if test -f $file
then
document=${document}" $file"
fi
done 
tar -jcvf $packge $document
