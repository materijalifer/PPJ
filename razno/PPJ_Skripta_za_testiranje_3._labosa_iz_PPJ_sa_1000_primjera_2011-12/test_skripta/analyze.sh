echo "Malo pricekaj"
for f in input/*.in
do
    name=${f:6:32}
    myfile="tvoj_output/"$name".out"
    ./analizator < $f > $myfile
done
echo "Analiza gotova: sada pokreni compare.sh"
