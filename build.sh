# gcc src/game.c -lm -lraylib -o game.o && ./game.o && rm game.o
cmake -B ./build
cd build
make pokemon_like
./pokemon_like
cd ..
