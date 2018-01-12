#include <iostream>
#include <vector>
using namespace std;

class Spell {
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell {
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell {
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell {
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
};
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

//custom start


//cout << spell->s << endl;
if(dynamic_cast<Frostbite*>(spell)){
    Frostbite *ff = static_cast<Frostbite *>(spell);
    ff ->revealFrostpower();
}else if(dynamic_cast<Waterbolt*>(spell)){
    Waterbolt *ff = static_cast<Waterbolt *>(spell);
    ff->revealWaterpower();
}else if(dynamic_cast<Thunderstorm*>(spell)){
    Thunderstorm *ff = static_cast<Thunderstorm *>(spell);
    ff->revealThunderpower();
}else if(dynamic_cast<Fireball*>(spell)){
    Fireball *ff = static_cast<Fireball *>(spell);
    ff ->revealFirepower();
}else{
    SpellJournal jj;

    string str1 = spell -> revealScrollName(), str2 = jj.read();
    //cout << str1 << endl << str2 << endl;
    int i,j,counter = 0,jstartpoint = 0;
    for(i=0;str1[i];i++){
        for(j=0;str2[j];j++){
            if(str1[i] == str2[j]){
                counter++;
                //jstartpoint = j+1;
                str2[j] = ' ';
                break;
            }
        }
    }
    cout << counter << endl;
}
/*
if(dynamic_cast<Frostbite*>(spell)){
    spell ->revealFrostpower();
}else if(dynamic_cast<Waterbolt*>(spell)){
    spell->revealWaterpower();
}else if(dynamic_cast<Thunderstorm*>(spell)){
    spell->revealThunderpower();
}else if(dynamic_cast<Fireball*>(spell)){
    spell ->Fireball::revealFirepower();
}
*/

/*
cout << dynamic_cast<Frostbite*>(spell) << endl;
cout << dynamic_cast<Waterbolt*>(spell) << endl;
cout << dynamic_cast<Thunderstorm*>(spell) << endl;
cout << dynamic_cast<Fireball*>(spell) << endl;

*/
/*
cout << spell -> revealScrollName();
cout << SpellJournal::journal << endl;

*/
//custom end
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            }
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}

