testHC: slove/Controller.cpp slove/Controller.h slove/LocalSearch.cpp slove/LocalSearch.h slove/HillClimbing.cpp slove/HillClimbing.h map/Map.cpp map/Map.h map/Route.cpp map/Route.h test/testHC.cpp
	g++ test/testHC.cpp slove/Controller.cpp slove/Controller.h slove/LocalSearch.cpp slove/LocalSearch.h slove/HillClimbing.cpp slove/HillClimbing.h map/Route.cpp map/Route.h map/Map.cpp map/Map.h
	./a.out

testMap: map/Map.cpp map/Map.h map/Route.cpp map/Route.h test/testMap.cpp
	g++ test/testMap.cpp map/Map.cpp map/Map.h map/Route.cpp map/Route.h
	./a.out

cleanHC:
	rm map/*.gch
	rm slove/*.gch
	rm a.out

cleanMap:
	rm map/*.gch
	rm a.out

