echo "\nCompare with answer ... \n"

# test1
diff test1 ans > /dev/null 2>&1
error=$?
if [ $error -eq 0 ]
then 
    echo "Accepted!"
else
    echo "Wrong Answer!"
fi

# test2
diff test2 ans_without_order > /dev/null 2>&1
if [ $error -eq 0 ]
then 
    echo "Accepted!"
else
    echo "Wrong Answer!"
fi

# clean all
rm test1 test2