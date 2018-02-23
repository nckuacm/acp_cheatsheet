date="20180223"

wget https://github.com/toolbuddy/acp_cheatsheet/raw/master/program/pc2/$date/pc2_$date.zip
wget https://github.com/toolbuddy/acp_cheatsheet/raw/master/program/pc2/$date/questions_$date.zip
unzip pc2_$date.zip -d pc2_$date
rm pc2_$date.zip
mv pc2_$date /home/$USER/Desktop/pc2_$date

mv questions_$date.zip /home/$USER/Desktop/questions_$date.zip

chmod +x /home/$USER/Desktop/pc2_$date/bin/pc2team

echo "/*************************************/"
echo "/                                     /"
echo "/             Success!                /"
echo "/                                     /"
echo "/      Now check your Desktop!        /"
echo "/                                     /"
echo "/*************************************/"
