#include <iostream>
#include <stack>
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
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int T = 60; // ¬рем€ действи€ сервиса

    int countOfCurrentClients = 15; //  оличество клиентов, которые могут одновременно
    // находитс€€ в активной сессии

    int t = 2; // ѕоток.  оличество вошедших пользователей в каждую минуту

    int id = 1;

    cout << "¬ведите врем€ действи€ сервиса (целое число минут): "; cin >> T; cout << endl;
    cout << "¬ведите количество клиентов, которые могут одновременно \nнаходитс€ в сессии (целое число клиентов): "; cin >> countOfCurrentClients; cout << endl;
    cout << "¬ведите поток клиентов(целое число пользователей, заход€щих каждую минуту): "; cin >> t; cout << endl;
    cout << "—ейчас введите диапазон времени работы клиентов(в минутах)\n Ќапример: каждый клиент может работать от 10 до 45 минут (случайное число в этом диапазоне)\n ¬ данном примере: 10 - начало диапазона, 45 - конец" << endl;
    cout << "¬ведите начало диапазона(целое число минут): "; cin >> workTimeStart; 
    cout << "¬ведите конец диапазона(целое число минут): "; cin >> workTimeEnd;
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
        cout << i + 1 << "-а€ минута. " << "Ќомера клиентов в активной сессии: "; PrintClientVector(clientsInWork); cout<<" оличество клиентов в очереди : " << clientsInQueue.size()<< endl;
        cout << "Ќомера клиентов в очереди: "; PrintClientQueue(clientsInQueue);
    }
}


void PrintClientQueue(queue<Client> que) {
    queue<Client> que1;
    cout << endl;
    while (!que.empty()) {
        cout << "\t лиент с номером " << que.front().Id << " будет работать " << que.front().WorkTime << " минут" << endl;
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
}