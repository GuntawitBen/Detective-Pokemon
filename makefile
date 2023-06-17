compilemain: main.cpp 
	 g++  main.cpp -o main

compileranmain: randommain.cpp 
	 g++  radommain.cpp -o ranmain

runmain: main
	  ./main

runranmain: ranmain
	 ./ranmain

clean:
	 ./rm