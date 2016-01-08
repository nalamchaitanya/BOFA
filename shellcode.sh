# Leave the first two columns from the file, also removes spaces between.
awk '{print $3$4$5$6$7$8$9$10}' $1 > temp.txt;

# Replace 0x in the file with \x
sed -i 's/0x/\\x/g' temp.txt;

# Removes all new line characters and makes a single line.
cat temp.txt | tr -d '\n'> $2;

# Remove the temporary file used.
rm temp.txt;
