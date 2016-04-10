testHC: slove/Controller.cpp slove/Controller.h slove/LocalSearch.cpp slove/LocalSearch.h slove/HillClimbing.cpp slove/HillClimbing.h slove/TabuSearch.cpp slove/TabuSearch.h slove/SimulatedAnnealing.cpp slove/SimulatedAnnealing.h map/Map.cpp map/Map.h map/Route.cpp map/Route.h test/testHC.cpp
	g++ -o hc test/testHC.cpp slove/Controller.cpp slove/Controller.h slove/LocalSearch.cpp slove/LocalSearch.h slove/HillClimbing.cpp slove/HillClimbing.h slove/TabuSearch.cpp slove/TabuSearch.h slove/SimulatedAnnealing.cpp slove/SimulatedAnnealing.h map/Route.cpp map/Route.h map/Map.cpp map/Map.h
	./hc

testHC10: slove/Controller.cpp slove/Controller.h slove/LocalSearch.cpp slove/LocalSearch.h slove/HillClimbing.cpp slove/HillClimbing.h slove/TabuSearch.cpp slove/TabuSearch.h slove/SimulatedAnnealing.cpp slove/SimulatedAnnealing.h map/Map.cpp map/Map.h map/Route.cpp map/Route.h test/testHC.cpp
	g++ -o hc test/testHC.cpp slove/Controller.cpp slove/Controller.h slove/LocalSearch.cpp slove/LocalSearch.h slove/HillClimbing.cpp slove/HillClimbing.h slove/TabuSearch.cpp slove/TabuSearch.h slove/SimulatedAnnealing.cpp slove/SimulatedAnnealing.h map/Route.cpp map/Route.h map/Map.cpp map/Map.h
	./hc
	./hc
	./hc
	./hc
	./hc
	./hc
	./hc
	./hc
	./hc
	./hc

testTS: slove/Controller.cpp slove/Controller.h slove/LocalSearch.cpp slove/LocalSearch.h slove/HillClimbing.cpp slove/HillClimbing.h slove/TabuSearch.cpp slove/TabuSearch.h slove/SimulatedAnnealing.cpp slove/SimulatedAnnealing.h map/Map.cpp map/Map.h map/Route.cpp map/Route.h test/testTS.cpp
	g++ -o ts test/testTS.cpp slove/Controller.cpp slove/Controller.h slove/LocalSearch.cpp slove/LocalSearch.h slove/HillClimbing.cpp slove/HillClimbing.h slove/TabuSearch.cpp slove/TabuSearch.h slove/SimulatedAnnealing.cpp slove/SimulatedAnnealing.h map/Route.cpp map/Route.h map/Map.cpp map/Map.h
	./ts

testTS10: slove/Controller.cpp slove/Controller.h slove/LocalSearch.cpp slove/LocalSearch.h slove/HillClimbing.cpp slove/HillClimbing.h slove/TabuSearch.cpp slove/TabuSearch.h slove/SimulatedAnnealing.cpp slove/SimulatedAnnealing.h map/Map.cpp map/Map.h map/Route.cpp map/Route.h test/testTS.cpp
	g++ -o ts test/testTS.cpp slove/Controller.cpp slove/Controller.h slove/LocalSearch.cpp slove/LocalSearch.h slove/HillClimbing.cpp slove/HillClimbing.h slove/TabuSearch.cpp slove/TabuSearch.h slove/SimulatedAnnealing.cpp slove/SimulatedAnnealing.h map/Route.cpp map/Route.h map/Map.cpp map/Map.h
	./ts
	./ts
	./ts
	./ts
	./ts
	./ts
	./ts
	./ts
	./ts
	./ts

testSA: slove/Controller.cpp slove/Controller.h slove/LocalSearch.cpp slove/LocalSearch.h slove/HillClimbing.cpp slove/HillClimbing.h slove/TabuSearch.cpp slove/TabuSearch.h slove/SimulatedAnnealing.cpp slove/SimulatedAnnealing.h map/Map.cpp map/Map.h map/Route.cpp map/Route.h test/testSA.cpp
	g++ -o sa test/testSA.cpp slove/Controller.cpp slove/Controller.h slove/LocalSearch.cpp slove/LocalSearch.h slove/HillClimbing.cpp slove/HillClimbing.h slove/TabuSearch.cpp slove/TabuSearch.h slove/SimulatedAnnealing.cpp slove/SimulatedAnnealing.h map/Route.cpp map/Route.h map/Map.cpp map/Map.h
	./sa

testMap: map/Map.cpp map/Map.h map/Route.cpp map/Route.h test/testMap.cpp
	g++ test/testMap.cpp map/Map.cpp map/Map.h map/Route.cpp map/Route.h
	./a.out

cleanHC:
	rm map/*.gch
	rm slove/*.gch
	rm hc

cleanTS:
	rm map/*.gch
	rm slove/*.gch
	rm ts

cleanSA:
	rm map/*.gch
	rm slove/*.gch
	rm sa

cleanMap:
	rm map/*.gch
	rm a.out

