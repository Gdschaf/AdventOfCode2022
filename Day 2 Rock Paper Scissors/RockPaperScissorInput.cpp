#include "RockPaperScissorInput.h"

RockPaperScissorInput::RockPaperScissorInput(std::string input)
{
  //index 0 is left move, index 2 is right move.
  elfMove = getMoveType(input[0]);
  // myMove = getMoveType(input[2]); // part 1
  myMove = getMyMove(elfMove, getResultType(input[2])); // part 2
  _input = input; //maybe for debugging purposes
}

int RockPaperScissorInput::getScore()
{
  PossibleGameMap::const_iterator itFind = possibleGames.find(Game(elfMove, myMove));
  PossibleGameMap::const_iterator itEnd = possibleGames.cend();
  if (itFind != itEnd) {
    return itFind->second;
  }
  return 0;
}

MoveType RockPaperScissorInput::getMoveType(char move)
{
  if (std::string(ROCK_CHARS).find(move) != std::string::npos)
    return Rock;
  if (std::string(PAPER_CHARS).find(move) != std::string::npos)
    return Paper;
  //if (std::string(SCISSOR).find(move) != std::string::npos)
  return Scissor;
}

Result RockPaperScissorInput::getResultType(char result)
{
  switch (result) 
  {
    case WIN_CHAR:
      return Win;
    case LOSE_CHAR:
      return Lose;
    case DRAW_CHAR:
      return Draw;
  };
}

MoveType RockPaperScissorInput::getMyMove(MoveType theirMove, Result result)
{
  PossibleMoves::const_iterator itFind = myPossibleMoves.find(Outcome(theirMove, result));
  PossibleMoves::const_iterator itEnd = myPossibleMoves.cend();
  if (itFind != itEnd) {
    return itFind->second;
  }
}
