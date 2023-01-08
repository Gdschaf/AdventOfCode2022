#pragma once

struct Operation
{
  Operation() { }
  Operation(int c, int x) : cycles(c), value(x) { }
  int cycles = 1;
  int value = 0;
};