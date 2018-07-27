#include <iostream>
#include <cstring>
using namespace std;

class FootballPlayer{
public:
	FootballPlayer();
	FootballPlayer(string name);
	~FootballPlayer();
	string getName() const;
	void setName(string name);

private:
	string m_name;
};

FootballPlayer::FootballPlayer()
{
	m_name = "NO NAME";
}

FootballPlayer::FootballPlayer(string name)
{
	m_name = name;
}

FootballPlayer::~FootballPlayer()
{
	cout << "Tschuss, " << m_name << "!" << endl;
}

string FootballPlayer::getName() const
{
	return m_name;
}

void FootballPlayer::setName(string name)
{
	m_name = name;
}


int main()
{

	FootballPlayer schweini;
	schweini.setName("Bastian Schweinsteiger");

	cout << schweini.getName() << endl;

	return 0;
}
