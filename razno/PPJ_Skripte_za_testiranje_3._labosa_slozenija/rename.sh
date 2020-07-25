#!/bin/bash
cnt=1
for f in input/*.in
	do
	name=${f%.in}
	dest="input/"$cnt
	let "cnt = cnt + 1"
	mv $name".in" $dest".in"
	mv $name".c" $dest".c"
	mv $name".explain" $dest".explain"
	mv $name".lex" $dest".lex"
	name=${name#input/}
	dest=${dest#input/}
	mv "ocekivani_output/"$name".out" "ocekivani_output/"$dest".out"
done

