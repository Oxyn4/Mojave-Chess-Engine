version = 1.0.0
SOURCE = src/*.cpp

engine: 
	@echo "\nBuilding Mojave engine version: $(version) \n"

	g++ -march=native -std=c++20 -lstdc++ -O3 $(SOURCE) -flto -o bin/Mojave

	@echo "\nTo run this binary: make run or ./bin/mojave"

engine-without-flags:
	@echo "\nBuilding Mojave engine version: $(version) \n"
	
	g++ $(SOURCE) -o bin/Mojave
	
	@echo "\nTo run this binary: make run or ./bin/mojave"
	
	@echo "Running Build: \n"
	
	make run


run:
	@echo "\n Running the compiled binary:"

	./bin/Mojave

	@echo "\n"


