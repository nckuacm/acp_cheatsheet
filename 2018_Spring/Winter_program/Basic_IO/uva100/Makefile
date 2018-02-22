run:
	g++ main.cc -lm -lcrypt -O2 -pipe -DONLINE_JUDGE
	# run test 1
	./a.out < input_normal > test1
	# run test 2
	./a.out < input_without_order > test2 
	# run compare
	chmod +x compare.sh && ./compare.sh