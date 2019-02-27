#/bin/sh
################################################################################
# change encode to utf-8
# author: luo wei biao
# date: 2018-8-6 
################################################################################

for i in `find ./ -type f -regex ".*\.c\|.*\.h|.*\.hpp|.*\.cpp"`
do
    if [ ! -d ${i} ]
    then
        fileInfo=`file -i ${i}`
        encode=${fileInfo##*=}
        # echo ${encode}
        if [ "$encode" != "utf-8" ]
        then
            `iconv -f gbk -t utf-8 $i > ${i}.tmp` 
            mv ${i}.tmp $i
        fi
    fi 
done