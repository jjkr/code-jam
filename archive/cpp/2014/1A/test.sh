LOWER_NAME=$(echo $1|awk '{print tolower($0)}')
UPPER_NAME=$(echo $1|awk '{print toupper($0)}')

g++ -std=c++11 -O3 -o ${LOWER_NAME} ${LOWER_NAME}.cpp

IN_FILES=$(ls ${UPPER_NAME}-*.in 2> /dev/null)
for f in ${IN_FILES}
do
    echo Testing input:  $f
    cat $f
    echo --
    cat $f | ./${LOWER_NAME} | tee $(basename $f in)out
done
