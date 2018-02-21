UTIL=../random_gen_phonebook.py

run:
	# format 
	astyle --style=kr --indent=tab main.c
	# compile
	gcc main.c
	# call outside program to gen testdata
	# - l -> location 
	# - s -> maximum strlen range
	$(UTIL) -l . -s 30
	# run
	./a.out phonebook.txt