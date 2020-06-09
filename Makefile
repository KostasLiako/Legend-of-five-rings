
project:
	@echo "Compiling LEGEND OF 5 RINGS ...";
	g++ -std=c++11 main.cpp Personality.cpp Item.cpp Follower.cpp Card.cpp Holding.cpp player.cpp DeckBuilder.cpp gameBoard.cpp TypeConverter.cpp -o main
