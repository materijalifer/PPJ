#!/bin/bash

touch razlike.txt
echo "RAZLIKE:" > razlike.txt
cnt=1
total=1231 #hardcodireani broj primjera!
correct=0
for f in input/*.in
do
    name=${f%.in}
    name=${name#input/}
    myfile="tvoj_output/"$name".out"
    hisfile="ocekivani_output/"$name".out"
    difference=$(diff $myfile $hisfile)
    echo $name >> razlike.txt
    echo "-------------------------------------------" >> razlike.txt
    diff $myfile $hisfile >> razlike.txt
    echo "===========================================" >> razlike.txt
    echo >> razlike.txt
    echo >> razlike.txt
    let "cnt = cnt + 1"
    if [[ -z $difference ]];
	then
	let "correct = correct + 1";
	fi
done
echo "======================================================"
echo "Broj polozenih primjera / broj ukupnih primjera:"
echo "$correct / $total"
echo "Usporedba je zavrsena, pogledaj file razlike.txt"
echo "za pregled ispisa po pojedinacnim primjerima"
echo "------------------------------------------------------"
echo "NOTE: Broj ukupnih primjera je hardcodeiran u skriptu,"
echo "tako da ako se dodaju novi primjeri u mape moguce je da ce vrijediti"
echo "Broj polozenih primjera > broj ukupnih primjera"
echo "======================================================"
