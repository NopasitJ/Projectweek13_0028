#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
struct wc
{
    string c;
    int score = 0;
    int goaled = 0;
    int goals = 0;
};
bool game1(wc& x, wc& y)
{
    return x.score > y.score;
}
bool game2(wc& x, wc& y)
{
    if (x.score == y.score)
        return x.goaled > y.goaled;
    else return 0;
}

bool game3(wc& x, wc& y)
{
    if (x.score == y.score and x.goaled == y.goaled)
        return x.goals > y.goals;
    else return 0;
}

int main()
{
    wc team[4];
    int data[5][5];
    for (int i = 0; i < 4; i++)
        cin >> team[i].c;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> data[i][j];

    for (int i = 0; i < 3; i++)
        for (int j = i + 1; j < 4; j++)
        {
            if (data[i][j] > data[j][i])
                team[i].score += 3;
            else if (data[i][j] < data[j][i])
                team[j].score += 3;
            else
            {
                team[i].score += 1;
                team[j].score += 1;
            }
            team[i].goals += data[i][j];
            team[j].goals += data[j][i];
            team[i].goaled += data[i][j] - data[j][i];
            team[j].goaled += data[j][i] - data[i][j];
        }
    sort(team, team + 4, game1);
    sort(team, team + 4, game2);
    sort(team, team + 4, game3);

    for (int i = 0; i < 4; i++)
        cout << team[i].c << " " << team[i].score << endl;

}