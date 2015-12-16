awk '{print $3$4$5$6$7$8$9$10}' $1 > temp.txt; sed -i 's/0x/\\x/g' temp.txt;
cat temp.txt | tr -d '\n'> $2;
rm temp.txt;
