EXEC=$1
TMP_OUT=$2

for i in {0..7..1}; do
  testname=$(printf "ct0%01d" $i)
  $EXEC < testes/$testname.txt > $TMP_OUT
  if ! diff -qwB testes/$testname-output.txt $TMP_OUT &>/dev/null; then
    echo "Test $testname failed"
  else
    echo "Test $testname passed"
  fi
done
rm $TMP_OUT