#include<iostream>
#include<fstream>
#include<vector>
#include <stdlib.h>

//追加、検索、更新、削除、保存

struct Record{
    int id;
    std::string name;
    std::string password;
    int hash;
};

//データを追加
void addData(std::vector<Record>& transactions){
    Record newrecord;
    int hash = rand();
    //SHA256();

    int IDs = rand();
    IDs >> newrecord.id;

    std::cout << "名前を入力";
    std::cin >> newrecord.name;

    std::cout << "パスワードを入力";
    std::cin >> newrecord.password;

    hash >> newrecord.hash;

    transactions.push_back(newrecord);
};

//データベース読み込み
void loads(std::vector<Record>& transactions, const std::string& filename){
    std::ifstream file(filename);
    std::string line;

    while(std::getline(file, line)){
        Record t;
        size_t pos = 0;

        pos = line.find(",");
        t.id = std::stod(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find(",");
        t.name = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(",");
        t.password = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(",");
        t.hash = std::stod(line.substr(0, pos));
        line.erase(0, pos + 1);

        transactions.push_back(t);
    }
    file.close();
};

//IDで検索
void reserchid(const std::vector<Record>& records,const std::string ids){
    for(const auto& t : records){
        std::string id = std::to_string(t.id);
        if(id.find(ids) != std::string::npos){
        std::cout << t.id << "\n" << t.name << "\n";
        std::cout << "\n";
        }
    }
}

//名前で検索
void reserchname(const std::vector<Record>& records,const std::string names){
    for(const auto& t : records){
        if(t.name.find(names) != std::string::npos){
        std::cout << t.id << "\n" << t.name << "\n";
        std::cout << "\n";
        }
    }
}

//全データ表示
void shows(const std::vector<Record>& records){
    for(const auto& t : records){
        std::cout << t.id << "\n" << t.name << "\n";
        std::cout << "\n";
    }
};

void saves(const std::vector<Record>& record, const std::string& filename){
    std::ofstream file(filename);

    for(const auto& t : record){
        file << t.id << "," << t.name << "," << t.password << "," << t.hash << std::endl;
    }
    file.close();
}

int main(){
    std::vector<Record> record;
    std::string filename = "practice.csv";
    std::string x;

    loads(record, filename);

    while(true){
        std::cout << "アプリメニュー\n";

        std::cout << "1: データ追加\n";
        std::cout << "2: データを表示\n";
        std::cout << "3: IDで検索\n";
        std::cout << "4: 名前で検索\n";
        std::cout << "5: データを削除\n";
        std::cout << "6: 保存して終了\n";
        std::cout << "7: リストを表示\n";

        std::cout << "選択:";

        int choice;
        std::cin >> choice;
    
        if(choice == 1){
            addData(record);
        }else if (choice == 2){
            shows(record);
        }else if (choice == 3){
            std::cout << "IDを入力\n";
            std::cin >> x;
            reserchid(record, x);
            break;
        }else if(choice == 4){
            std::cout << "名前を入力\n";
            std::cin >> x;
            reserchname(record, x);
        }else if(choice == 5){
            //deleate(record);
        }else if(choice == 6){
            saves(record, filename);
        }else{
            std::cout << "無効な操作\n";
        }
    }
    return 0;
}