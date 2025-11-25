#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int workTimeStart;
int workTimeEnd;

class Client {
public:
    int Id;
    int WorkTime;

    Client(int id) {
        Id = id;
        WorkTime = rand() % (workTimeEnd - workTimeStart) + workTimeStart;
    }
};

void PrintClientVector(vector<Client> v);
void PrintClientQueue(queue<Client> que);

int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int T = 60; // Âðåìÿ äåéñòâèÿ ñåðâèñà

    int countOfCurrentClients = 15; // Êîëè÷åñòâî êëèåíòîâ, êîòîðûå ìîãóò îäíîâðåìåííî
    // íàõîäèòñÿÿ â àêòèâíîé ñåññèè

    int t = 2; // Ïîòîê. Êîëè÷åñòâî âîøåäøèõ ïîëüçîâàòåëåé â êàæäóþ ìèíóòó

    int id = 1;

    cout << "Ââåäèòå âðåìÿ äåéñòâèÿ ñåðâèñà (öåëîå ÷èñëî ìèíóò): "; cin >> T; cout << endl;
    cout << "Ââåäèòå êîëè÷åñòâî êëèåíòîâ, êîòîðûå ìîãóò îäíîâðåìåííî \níàõîäèòñÿ â ñåññèè (öåëîå ÷èñëî êëèåíòîâ): "; cin >> countOfCurrentClients; cout << endl;
    cout << "Ââåäèòå ïîòîê êëèåíòîâ(öåëîå ÷èñëî ïîëüçîâàòåëåé, çàõîäÿùèõ êàæäóþ ìèíóòó): "; cin >> t; cout << endl;
    cout << "Ñåé÷àñ ââåäèòå äèàïàçîí âðåìåíè ðàáîòû êëèåíòîâ(â ìèíóòàõ)\n Íàïðèìåð: êàæäûé êëèåíò ìîæåò ðàáîòàòü îò 10 äî 45 ìèíóò (ñëó÷àéíîå ÷èñëî â ýòîì äèàïàçîíå)\n Â äàííîì ïðèìåðå: 10 - íà÷àëî äèàïàçîíà, 45 - êîíåö" << endl;
    cout << "Ââåäèòå íà÷àëî äèàïàçîíà(öåëîå ÷èñëî ìèíóò): "; cin >> workTimeStart; 
    cout << "Ââåäèòå êîíåö äèàïàçîíà(öåëîå ÷èñëî ìèíóò): "; cin >> workTimeEnd;
    system("cls");

    vector<Client> clientsInWork;
    queue<Client> clientsInQueue;


    for (int i = 0; i < T; i++) {

        for (int k = 0; k < clientsInWork.size(); k++) {
            clientsInWork[k].WorkTime--;
            if (clientsInWork[k].WorkTime == 0) {
                clientsInWork.erase(clientsInWork.begin() + k);
                k--;
            }
        }

        for (int j = 0; j < t; j++) {
            clientsInQueue.push(Client(id++));
            if (clientsInWork.size() < countOfCurrentClients) {
                clientsInWork.push_back(clientsInQueue.front());
                clientsInQueue.pop();
            }
        }
        cout << i + 1 << "-àÿ ìèíóòà. " << "Íîìåðà êëèåíòîâ â àêòèâíîé ñåññèè: "; PrintClientVector(clientsInWork); cout<<"Êîëè÷åñòâî êëèåíòîâ â î÷åðåäè : " << clientsInQueue.size()<< endl;
        cout << "Êëèåíòû â î÷åðåäè: "; PrintClientQueue(clientsInQueue);
    }
}


void PrintClientQueue(queue<Client> que) {
    queue<Client> que1;
    cout << endl;
    while (!que.empty()) {
        cout << "\tÊëèåíò ñ íîìåðîì " << que.front().Id << " áóäåò ðàáîòàòü " << que.front().WorkTime << " ìèíóò" << endl;
        que1.push(que.front());
        que.pop();
    }
    while (!que1.empty()) {
        que.push(que1.front());
        que1.pop();
    }
    cout << endl;
}

void PrintClientVector(vector<Client> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].Id << " ";
    }
    cout << endl;
}
