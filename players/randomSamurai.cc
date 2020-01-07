#include "players.hh"

const int MovePercentage = 80;

int planSamurai(GameInfo &info) {
  if (info.step == 0) initFieldMap(info);
  Cell pos = info.positions[info.id];
  CellInfo myCell = cells[pos.x][pos.y];
  int plan = -1;
  int trials = 10;
  while (--trials > 0) {
    // RAND_MAX: 2147483647
    auto n = myCell.fourNeighbors[rand() % myCell.fourNeighbors.size()];
    int dir = directionOf(myCell.position, n->position);
    bool noHole = noHolesIn(n->position, info);
    if (noAgentsIn(n->position, info)) {
      if (rand() % 100 < MovePercentage && noHole) {
        plan = dir;
        break;
      } else if (noHole) {
        plan = dir + 8;
        break;
      } else {
        plan = dir + 16;
        break;
      }
    }
  }
  return plan;
}
