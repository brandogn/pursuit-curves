build_and_run_program:
	g++ -o program src/Main.cpp src/global.cpp -lSDL2 
	./program
