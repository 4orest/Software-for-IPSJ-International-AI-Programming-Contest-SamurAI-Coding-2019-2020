import os
import re

maps = os.listdir('preliminary-fields/')
myPlayerWin = 0
enemyWin = 0
draw = 0
for i in maps:
    print(i)
    os.system("manager/manager preliminary-fields/" + i +
              " players/randomPlayer players/myPlayer >testlog/blue" + i)
    os.system("manager/manager preliminary-fields/" + i +
              " players/myPlayer players/randomPlayer >testlog/red" + i)

    result = open("testlog/blue" + i, 'r').read()
    index = result.rfind("scores")
    result = result[index : ]
    num = re.findall("[0-9]+", result)
    redWin = int(num[0])
    blueWin = int(num[1])
    if redWin > blueWin:
        enemyWin += 1
    elif redWin == blueWin:
      draw += 1
    else:
      myPlayerWin += 1

    result = open("testlog/red" + i, 'r').read()
    index = result.rfind("scores")
    result = result[index : ]
    num = re.findall("[0-9]+", result)
    redWin = int(num[0])
    blueWin = int(num[1])
    if redWin > blueWin:
        myPlayerWin += 1
    elif redWin == blueWin:
      draw += 1
    else:
      enemyWin += 1
    print()

print("myPlayer win:", format(myPlayerWin))
print("simplePlayer win:", format(enemyWin))
print("draw:", format(draw))