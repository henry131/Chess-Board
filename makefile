OBJ=ChessMain.o ChessBoard.o Piece.o King.o Queen.o Bishop.o Castle.o Knight.o Pawn.o
EXE=chess
CXX=g++
CPPFLAGS=-Wall -g -MMD

$(EXE): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(EXE)

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $<

-include $(OBJ:.o=.d)

.PHONY: clean

clean:
	rm -f $(OBJ) $(OBJ:.o=.d)
