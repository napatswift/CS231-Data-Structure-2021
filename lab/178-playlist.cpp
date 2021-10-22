#include <iostream>
#include <string>
using namespace std;

class Song{
    public:
        string name;
        string artist;
        bool isActive;

        Song(){
            isActive = true;
        }
        string toString(){
            return name + " - " + artist;
        }
};

class Playlist{
    private:
        Song *songs[64];
        size_t curr;
    public:

        Playlist(){
            curr = 0;
        }

        void add(Song *newSong){
            if (curr < 64){
                songs[curr] = newSong;
                curr++;
            }
        }

        void print(){
            cout << "----------" << endl;
            size_t num = 1;
            for (size_t i = 0; i < curr; i++)
                if (songs[i]->isActive)
                    cout << num++ << ". " << songs[i]->toString() << endl;
            cout << "----------" << endl;
        }

        void remove(size_t index){
            if (index - 1 < curr)
                songs[index - 1]->isActive = false;
        }
};
            

int main(){
    Playlist pl;
    int user;
    string resp;

    getline(cin, resp);
    user = stoi(resp);
    while(user < 4 && user > 0){
        if (user == 1){
            Song *newSong = new Song();
            getline(cin, newSong->name);
            getline(cin, newSong->artist);
            pl.add(newSong);
        } else if(user == 2){
            string idx;
            getline(cin, idx);
            pl.remove(stoi(idx));
        } else if (user == 3){
            pl.print();
        }
        getline(cin, resp);
        user = stoi(resp);
    }
}
