all: count radix_v radix_l sort_v sort_l radix_v_bin radix_l_bin

count: count.cpp
	g++ -std=c++11 count.cpp -Wall -O2 -o count

radix_v: radix_v.cpp
	g++ -std=c++11 radix_v.cpp -Wall -O2 -o radix_v
	
radix_l: radix_l.cpp
	g++ -std=c++11 radix_l.cpp -Wall -O2 -o radix_l
	
sort_v: sort_v.cpp
	g++ -std=c++11 sort_v.cpp -Wall -O2 -o sort_v
	
sort_l: sort_l.cpp
	g++ -std=c++11 sort_l.cpp -Wall -O2 -o sort_l

radix_v_bin: radix_v_bin.cpp
	g++ -std=c++11 radix_v_bin.cpp -Wall -O2 -o radix_v_bin
	
radix_l_bin: radix_l_bin.cpp
	g++ -std=c++11 radix_l_bin.cpp -Wall -O2 -o radix_l_bin

limpiar:
	rm count
	rm radix_v
	rm radix_l
	rm sort_v
	rm sort_l
	rm radix_v_bin
	rm radix_l_bin