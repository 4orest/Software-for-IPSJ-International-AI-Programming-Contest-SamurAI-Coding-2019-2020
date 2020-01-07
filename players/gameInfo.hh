#include <iostream>
#include <map>
#include <set>

using namespace std;

struct Cell {
  int x, y;
  Cell() {}
  Cell(int x, int y);
  Cell(istream &in);
  bool operator<(const Cell &another) const;
  bool operator==(const Cell &another) const;
};

ostream &operator<<(ostream &out, const Cell &cell);

struct GameInfo {
  int id;                           // エージェントの番号
  int size;                         // 競技場のサイズ
  int step;                         // ステップ番号(0始まり)
  int maxSteps;                     // 最大ステップ番号
  set<Cell> holes;                  // 穴のあるセルの位置のリスト
  map<Cell, int> revealedTreasure;  // 公知の埋蔵金
  map<Cell, int> sensedTreasure;    // 感知した埋蔵金
  Cell positions[4];  // エージェントの位置 (0: 侍(Aチーム), 1: 侍(Bチーム), 2:
                      // 犬(Aチーム), 3: 犬(Bチーム))
  int plans[4];    // 直前ステップでのプレイプラン
  int actions[4];  // 直前ステップでの行動
  int scores[2];   // スコア
  int remaining;   // 残る埋蔵金
  int thinkTime;   // 残る考慮時間
  GameInfo(istream &in);
};

ostream &operator<<(ostream &out, const GameInfo &gameinfo);
