#pragma once

#include <string>
#include <map>

#define ROCK_CHARS "AX"
#define PAPER_CHARS "BY"
#define SCISSOR_CHARS "CZ"

#define WIN_CHAR 'Z'
#define LOSE_CHAR 'X'
#define DRAW_CHAR 'Y'

#define WIN_SCORE 6
#define LOSE_SCORE 0
#define DRAW_SCORE 3
#define ROCK_SCORE 1
#define PAPER_SCORE 2
#define SCISSOR_SCORE 3

enum MoveType {
  Rock,
  Paper,
  Scissor
};

enum Result {
  Win,
  Lose,
  Draw
};

typedef std::pair<MoveType, MoveType> Game;
typedef const std::map<Game, int> PossibleGameMap;
PossibleGameMap possibleGames = {
  { Game(Rock, Rock), DRAW_SCORE + ROCK_SCORE },
  { Game(Rock, Paper), WIN_SCORE + PAPER_SCORE },
  { Game(Rock, Scissor), LOSE_SCORE + SCISSOR_SCORE },
  { Game(Paper, Rock), LOSE_SCORE + ROCK_SCORE },
  { Game(Paper, Paper), DRAW_SCORE + PAPER_SCORE },
  { Game(Paper, Scissor), WIN_SCORE + SCISSOR_SCORE },
  { Game(Scissor, Rock), WIN_SCORE + ROCK_SCORE },
  { Game(Scissor, Paper), LOSE_SCORE + PAPER_SCORE },
  { Game(Scissor, Scissor), DRAW_SCORE + SCISSOR_SCORE },
};

typedef std::pair<MoveType, Result> Outcome;
typedef const std::map<Outcome, MoveType> PossibleMoves;
PossibleMoves myPossibleMoves = {
  { Outcome(Rock, Win), Paper },
  { Outcome(Rock, Lose), Scissor },
  { Outcome(Rock, Draw), Rock },
  { Outcome(Paper, Win), Scissor },
  { Outcome(Paper, Lose), Rock },
  { Outcome(Paper, Draw), Paper },
  { Outcome(Scissor, Win), Rock },
  { Outcome(Scissor, Lose), Paper },
  { Outcome(Scissor, Draw), Scissor },
};

class RockPaperScissorInput {
public:
  RockPaperScissorInput(std::string input);
  int getScore();
private:
  std::string _input;
  MoveType elfMove; //LEFT, ABC
  MoveType myMove; //RIGHT, XYZ

  MoveType getMoveType(char move);
  Result getResultType(char result);
  MoveType getMyMove(MoveType theirMove, Result result);
};