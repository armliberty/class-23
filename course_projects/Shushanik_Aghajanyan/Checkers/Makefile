CXX = g++
CXXFLAGS = -std=c++17 -g
SRCS = Game.cpp InputHandler.cpp Player.cpp Board.cpp Menu.cpp main.cpp Piece.cpp 
OBJS = $(SRCS:.cpp=.o)
EXEC = checkers
RM = rm -f

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC) -lncurses

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(EXEC)
