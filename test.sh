if [[ -z "$1" ]]; then
    echo "Missing test name argument" 1>&2
    exit 1
fi
TEST_NAME=$1

#echo $TEST_NAME
#echo "clang++-3.5 -std=c++14 -O3 -o ${TEST_NAME} ${TEST_NAME}.cpp"

if ! clang++-3.5 -std=c++14 -O3 -o ${TEST_NAME} ${TEST_NAME}.cpp; then
    exit 1
fi

IN_FILES=$(ls ${TEST_NAME}-*.in 2> /dev/null)
for f in ${IN_FILES}
do
    echo Testing input:  $f
    cat $f
    echo --
    cat $f | ${TEST_NAME} | tee $(dirname $f)/$(basename $f in)out
done
