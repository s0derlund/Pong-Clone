Pong: main.cpp Game.cpp Entity.cpp Paddle.cpp Ball.cpp ScoreBoard.cpp Game.h Entity.h Paddle.h Ball.h ScoreBoard.h global.h
	g++ main.cpp Game.cpp Entity.cpp Paddle.cpp Ball.cpp ScoreBoard.cpp -o Pong -lsfml-graphics -lsfml-window -lsfml-system
run: Pong
	./Pong
clean:
	rm -rf *o Pong
