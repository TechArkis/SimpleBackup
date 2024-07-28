#include <iostream>
#include <cstdlib>

using namespace std;

string Pos, BackupPos;

void Line() {
    cout<<endl;

    for(int i=0; i < 80; i++) {
        cout<<"=";
    }

    cout<<endl;
}

void Title() {
    system("clear && figlet -f slant SimpleBackup && sleep 1");
    cout<<endl;
}

void CaricaDati() {
    cout<<endl<<"Files position: ";
    cin>>Pos;

    cout<<endl<<"Backup position: ";
    cin>>BackupPos;
}

void Execute() {
    Line();

    int S;

    cout<<endl<<"Choose: \n" << "1) One file\n" << "2) Directory\n";
    cout<<"> ";
    cin>>S;

    while (S != 1 && S != 2) {
        cout<<endl<<"Error! choose 1 or 2 > ";
        cin>>S;
    }

    if (S == 1) {
        const string CP = "sudo cp " + Pos + " " + BackupPos;
        system(CP.c_str());
    } else {
        // -r is for directory
        const string CP = "sudo cp -r " + Pos + " " + BackupPos;
        system(CP.c_str());
    }

    Line();

    cout<<endl<<"Done."<<endl;
}

int main() {
    Title();
    CaricaDati();
    Execute();

    return 0;
}
