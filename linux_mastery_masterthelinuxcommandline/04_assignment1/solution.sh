#Task 1
ls /etc > file1.txt
ls /run > file2.txt

#Task 2
cat file1.txt file2.txt | tee unsorted.txt | sort -r > reversed.txt
