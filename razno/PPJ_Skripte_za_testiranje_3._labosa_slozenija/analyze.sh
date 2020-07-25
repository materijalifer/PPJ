#!/bin/bash

echo "Kompajliram..."
echo "NOTE: ulazna klasa se mora zvati SemantickiAnalizator.java"
javac *.java
echo "Pokrecem analizu"
echo "NOTE: ima 1231 primjer za analizu!"
sleep 1.5

cnt=1 # counter za broj primjera koji se trenutno obraduje
for f in input/*.in
do
    name=${f%.in} #ime trenutnog primjera (zapravo njegov broj)
    name=${name#input/}
    myfile="tvoj_output/"$name".out"
    echo $cnt #ispis progressa
    let "cnt = cnt + 1"
    java SemantickiAnalizator < $f &> $myfile #poziv 
done

echo "Analiza gotova: sada pokreni compare.sh"
