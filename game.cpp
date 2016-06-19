#include <game.h>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <algorithm>
#include <sstream>

Game::Game (int w, int h, std::array <std::string,2> clubs)
    : width(w), height(h), teams(clubs)
{
        court.reserve(width);
        for (int i=0; i<width; ++i)
        {
            if (i==width/2) //net
            {
                court.push_back(std::vector<char> (height,'=') );
            }
            else if(i==(width/3)-1 || i==(2*width/3) || i == width-1)   //3rd and 9th meter lines
            {
                court.push_back(std::vector<char> (height,'_') );
            }
            else
            {
                court.push_back(std::vector<char> (height,' ') );
            }
        }
}

std::ostream& operator << (std::ostream& output, const Game& gameclass)
{
    output << gameclass.teams[0] << "\t\t\t" << gameclass.teams[1] <<"\n";
    output << "\n";

    for(std::size_t i=0; i<gameclass.players.size(); i+=2)  //printing teams
    {
        output << gameclass.players[i] << "\t\t" << gameclass.players[i+1] << '\n';
    }
    output << "\t ";    //indent for 9th meter line
    for (int i=0; i<gameclass.width/2-3; ++i)
    { //upper 9th meter line
        output << ' ' << '_';
    }
    output << std::endl;
    for (int i=0; i<gameclass.width; ++i)
    {
        for (int j=0; j<gameclass.height; ++j)
        {
            if (j==0 && i!=gameclass.width/2)
            {
                output << "\t|" << " ";
            }
            else if (j == gameclass.height-1 && i!=gameclass.width/2)
            {
                output << "|" << " ";
            }
            else if (j==0 && i==gameclass.width/2)
            {
                output << "\t=" << " ";
            }
            else
            {
                output << gameclass.court[i][j] << " ";
            }
        }
        output << std::endl;
    }
    return output;
}

void Game::setposition (int x, int y, char sym)
{
    court[x][y] = sym;
}

void Game::addplayer (int d, int s, std::string sur, std::string newteam, char sym)
{
    players.push_back(Player(d,s,sur,newteam,sym));
}

void Game::update ()
{
    std::cout << "\033[2J\033[1;1H";    //clearing terminal in Linux
    for (std::size_t i=0; i<players.size(); ++i)
    {
        setposition(players[i].getx(), players[i].gety(), players[i].getsymbol());
    }
    std::cout << *this;     //pointer na obiekt akutalnie uzywany
    usleep(1000000);        //delay (us)
}


void Game::sortplayers()
{
    std::sort(players.begin(),players.end());
}
