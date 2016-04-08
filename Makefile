testMap: map/Map.cpp map/Map.h map/Route.cpp map/Route.h test/testMap.cpp
	g++ test/testMap.cpp map/Map.cpp map/Map.h map/Route.cpp map/Route.h
	./a.out

clean:
	rm map/*.gch
	rm a.out

