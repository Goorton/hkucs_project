FLAGS = -pedantic-errors -std=c++11 -I ~/snake/include -I ~/snake/ncursestw -L ~/snake/lib

map.o: map.cpp map.h screen.h
	g++ $(FLAGS) -c $< -lncursestw -ldl -pthread

snake.o: snake.cpp snake.h screen.h
	g++ $(FLAGS) -c $< -lncursestw -ldl -pthread

controller.o: controller.cpp controller.h screen.h
	g++ $(FLAGS) -c $< -lncursestw -ldl -pthread

screen.o: screen.cpp screen.h
	g++ $(FLAGS) -c $< -lncursestw -ldl -pthread

main.o: main.cpp map.h controller.h screen.h snake.h
	g++ $(FLAGS) -c $< -lncursestw -ldl -pthread

main: main.o map.o snake.o controller.o screen.o
	g++ $(FLAGS) $^ -o $@ -lncursestw -ldl -pthread
