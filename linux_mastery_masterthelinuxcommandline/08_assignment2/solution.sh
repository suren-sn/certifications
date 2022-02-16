#Task 1
mkdir super_secret_stuff
cd super_secret_stuff
echo "Shhhhhhhhhh" > top_secret.txt
sudo updatedb
locate top_secret.txt > ~/secret_place.txt


#Task 2
sudo find / -maxdepth 4 -type f -size +1M -exec ls -lh {} \; | sort -k 5 -hr > ~/filesizes.txt
