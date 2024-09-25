//Nama    : Raka Aleandra
//NIM     : L0123146
//Program : Gojek
#include <iostream>
#include <windows.h>
#include <climits>
#include <iomanip>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#define map_gojek 10
#define map_gocar 7
using namespace std;

//Struct
struct menutoko{
    string nama;
    int harga;
    string categori;
};

//Struct Untuk Map
struct riwayat{
    string deskripsi;
    int harga;
};

//List Makanan
struct makanan{
    string nama;
    int harga;
};

//Struct List Gofood
struct resto{
    string nama;
    int harga;
    double jarak;
    double rating;
    vector<makanan> listmakanan;
    queue<int> antrian;
};

//Struct List Pesanan
struct pesan{
    string nama;
    int jumlah;
    int harga;
};

//Tree
struct tree{
    string nama;
    int angka;
    vector<tree> anak;

    tree(string a, int b){
        nama = a;
        angka = b;
    }

    void insert_tree(tree node) {
        anak.push_back(node);
    }

    void prorder(int depth = 0){
        cout << left << setfill('-') << ' ' << setw(35) << '-' << endl;
        cout << setfill(' ') << " | " << setw(12) << angka << "| " << setw(18) << nama << '|' << endl;
        for (int i = 0; i < anak.size(); i++) {
            anak[i].prorder(depth + 1);
        }
    }

    string pilihan(int a){
        if(a == angka)
            return nama;
        else{
            for(int i = 0; i < anak.size(); ++i){
                return anak[i].pilihan(a);
            }
        }
    }
};

//Binary Search Tree
struct node {
    string nama;
	double jarak;
    int rating;
	struct node *left, *right;
};

struct node* newNode(double item, string nama1, int rating1){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->jarak = item;
    temp->nama = nama1;
    temp->rating = rating1;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(struct node* root){
	if (root != NULL) {
		inorder(root->left);
        cout << left << setfill('-') << setw(60) << '-' << endl << setfill(' ');
        cout << " | "<< setw(27) << root->nama << "| "  << root->rating << setw(12) << "/5" << "| " << setw(3) << root->jarak << setw(10) << " km" << '|' << endl;
		inorder(root->right);
	}
}

struct node* insert(struct node* node, double jarak1, string nama1, int rating1){
	if (node == NULL)
		return newNode(jarak1, nama1, rating1);

	if (jarak1 < node->jarak)
		node->left = insert(node->left, jarak1, nama1, rating1);
	else
		node->right = insert(node->right, jarak1, nama1, rating1);

	return node;
}

struct node* search(struct node* root, int jarak1){
    if (root == NULL || root->jarak == jarak1)
        return root;
 
    if (root->jarak < jarak1)
        return search(root->right, jarak1);
 
    return search(root->left, jarak1);
}

//Enum Shortest Path
enum lokasi_gojek{
    mojosongo,
    jebres,
    puncang_sawit,
    jagalan,
    purwodiningrat,
    tegalharjo,
    kepatihan,
    sewu,
    gandekan,
    sudiroprajan
};

//Shortest Path
int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < map_gojek; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}

int* dijkstra(int graph[map_gojek][map_gojek], int src, vector<string> a)
{
    static int dist[map_gojek];
 
    bool sptSet[map_gojek];
 
    for (int i = 0; i < map_gojek; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
    dist[src] = 0;
 
    for (int count = 0; count < map_gojek - 1; count++) {
        int u = minDistance(dist, sptSet);
 
        sptSet[u] = true;
 
        for (int v = 0; v < map_gojek; v++)
            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    
    for (int i = 0; i < map_gojek; i++){
        cout << left << ' ' << setfill('-') << setw(45) << '-' << setfill(' ') << endl << setfill(' ');
        cout << " | " << setw(12) << i+1 << "| " << setw(18) << a[i] << "| " << dist[i] << setw(7) << " km" << '|' << endl;
    }
    return dist;
}

//MST Prim's
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < map_gocar; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}
 
void primMST(int graph[map_gocar][map_gocar], vector<string>a)
{
    int parent[map_gocar];
 
    int key[map_gocar];
 
    bool mstSet[map_gocar];
 
    for (int i = 0; i < map_gocar; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
    key[0] = 0;
   
    parent[0] = -1;
 
    for (int count = 0; count < map_gocar - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < map_gocar; v++)
            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
 
    // printMST(parent, graph);
    for (int i = 1; i < map_gocar; i++){
        // cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
        cout << left << ' ' << setfill('-') << setw(51) << '-' << setfill(' ') << endl << setfill(' ');
        cout << " | " << setw(17) << a[parent[i]] << "-> " << setw(17) << a[i] << "| " << setw(2) << graph[i][parent[i]] << setw(7) << " km" << '|' << endl;
    }

}

//Bubble Sort
vector<makanan> bubblesort(vector<makanan> a){
    vector<makanan> hold = a;
    
    for(int b = 0; b < hold.size() - 1; ++b){
        for(int c = 0; c < hold.size() - b - 1; ++c){
            if(hold[c].harga > hold[c+1].harga){
                swap(hold[c],hold[c+1]);
            }
        }
    }

    return hold;
}

//Disjoin
string verify(map<string,string> &perwakilan, string a){
    if(perwakilan[a] == a){
        return a;
    }
    return verify(perwakilan, perwakilan[a]);
}

void menggabungkan(string a, string b, map<string,string> &perwakilan){
    string A = verify (perwakilan, a);
    string B = verify (perwakilan, b);

    perwakilan[A] = B;
}

void cari(string a, map<string,string> &perwakilan){
    if(perwakilan[a] == a){
        cout << ' ' << a << endl;
        return;
    }
    cout << ' ' <<left << setw(5) << a << " <-";
    cari(perwakilan[a], perwakilan);
}

void pendahuluan(int &a){
    cout << "SEBELUM MASUK APLIKASI ISI DATA BERIKUT TERLEBIH DAHULU" << endl << left;
    // cout << setw(16) << "NAMA PANGGILAN" << ": ";
    // cin >> a;
    cout << setw(16) << "SALDO" << ": ";
    cin >> a;
    cout << endl << "TERIMA KASIH";
    Sleep(2000);
    system("cls");
}

void front_1(int a){
    cout << " SALDO ANDA Rp." << a << endl;
    cout << "  " << left << setfill('-') << setw(31) << '+' << setw(31) << '+' << setw(31) << '+' << '+' << endl << setfill(' ');
    cout << "  " << setw(31) << '|' << setw(31) << '|' << setw(31) << '|' << '|' << endl ;
    cout << "  " << setw(11) << '|' << setw(20) << "1. GOJEK" << setw(11) << '|' << setw(20) << "2. GOCAR" << setw(11) << '|' << setw(20) << "3. GOFOOD" << '|' << endl;
    cout << "  " << setw(31) << '|' << setw(31) << '|' << setw(31) << '|' << '|' << endl;
    cout << "  " << setfill('-') << setw(31) << '+' << setw(31) << '+' << setw(31) << '+' << '+' << endl << setfill(' ');
    cout << "  " << setw(31) << '|' << setw(31) << '|' << setw(31) << '|' << '|' << endl ;
    cout << "  " << setw(11) << '|' << setw(20) << "4. GOSEND" << setw(11) << '|' << setw(20) << "5. GOMART" << setw(11) << '|' << setw(20) << "6. TOP UP" << '|' << endl;
    cout << "  " << setw(31) << '|' << setw(31) << '|' << setw(31) << '|' << '|' << endl ;
    cout << "  " << setfill('-') << setw(31) << '+' << setw(31) << '+' << setw(31) << '+' << '+' << endl << setfill(' ');
    cout << "  " << setw(30) << "[7] RIWAYAT" << setw(30) << "[CTRL + C] KELUAR" << endl;
}

vector<makanan> list_makanan_1(){
    vector<makanan> hold;
    hold.push_back({"PAKET GEPREK MILKU", 25000});
    hold.push_back({"PAKET SAYAP AYAM", 11500});
    hold.push_back({"PAKET PAHA BAWAH AYAM", 14000});
    hold.push_back({"PAKET DADA AYAM", 20000});
    hold.push_back({"PAKET DADA LEMBUT AYAM", 18500});
    hold.push_back({"PAKET PAHA ATAS AYAM", 20000});
    hold.push_back({"CHICKEN STEAK", 18500});
    hold.push_back({"BEEF BURGER", 14000});
    hold.push_back({"CHEESE BURGER", 18500});
    hold.push_back({"FRENCH FRIES", 11500});
    hold.push_back({"SPAGHETTI", 11500});
    hold.push_back({"PAKET TEGEP", 11500});
    hold.push_back({"PAKET LAKOR", 25000});

    hold.push_back({"AIR MINERAL", 5500});
    hold.push_back({"TARO", 7000});
    hold.push_back({"TEH", 5500});

    return hold;
}

vector<makanan> list_makanan_2(){
    vector<makanan> hold;
    hold.push_back({"SEBLAK PREMIUM ODENG", 27000});
    hold.push_back({"SEBLAK SEAFOOD", 20000});
    hold.push_back({"SEBLAK PANGSIT AYAM", 17000});
    hold.push_back({"SEBLAK OTAK\" SINGAPORE (JUMBO)", 21000});
    hold.push_back({"SEBLAK DUMPLINGS MIX", 21000});
    hold.push_back({"SEBLAK PREMIUM SOSIS", 27000});
    hold.push_back({"SEBLAK PREMIUM SEAFOOD", 30000});
    hold.push_back({"SEBLAK SAYUR MIX", 15000});
    hold.push_back({"SEBLAK REGULER", 15000});
    hold.push_back({"SEBLAK KWETIAU", 16000});
    hold.push_back({"SEBLAK MIE", 16000});
    hold.push_back({"SEBLAK MIX", 18000});
    hold.push_back({"SEBLAK JAMUR MIX", 18000});
    hold.push_back({"SEBLAK BAKSO URAT", 17000});
    hold.push_back({"SEBLAK TEMPURA", 17000});
    hold.push_back({"SEBLAK OTAK-OTAK", 17000});
    hold.push_back({"SEBLAK TULANG AYAM", 20000});
    hold.push_back({"SEBLAK DADAR SOSIS", 18000});
    hold.push_back({"SEBLAK DADAR SAYUR", 17000});

    hold.push_back({"KWETIAU GORENG", 16000});
    hold.push_back({"KWETIAU KUAH", 16000});
    hold.push_back({"MIE NYEMEK", 16000});
    hold.push_back({"MIE DOK-DOK ALUMNI", 17000});
    hold.push_back({"INTEL GORENG", 15000});
    hold.push_back({"INTEL KUAH", 15000});

    hold.push_back({"AIR ES", 3000});
    hold.push_back({"TEH", 6000});
    hold.push_back({"NUTRISARI", 7000});
    return hold;
}

vector<makanan> list_makanan_3(){
    vector<makanan> hold;
    hold.push_back({"NASI AYAM PANGGUNG", 17000});
    hold.push_back({"NASI AYAM GORENG", 19000});
    hold.push_back({"NASI SAYAP GORENG", 18000});
    hold.push_back({"NASI KEPALA GORENG", 14000});
    hold.push_back({"NASI AMPELA ATI GORENG", 14000});
    hold.push_back({"NASI KULIT GORENG", 18000});
    hold.push_back({"NASI BANDENG PRESTO GORENG", 18000});
    hold.push_back({"NASI BAKSO GORENG", 13000});
    hold.push_back({"NASI TAHU GORENG", 11000});

    hold.push_back({"TEH HANGAT", 4000});
    hold.push_back({"JERUK HANGAT", 5000});
    hold.push_back({"LEMON TEA HANGAT", 5000});
    hold.push_back({"ES TEH", 4000});
    hold.push_back({"ES JERUK", 5000});
    hold.push_back({"ES LEMON TEA", 5000});

    return hold;
}

vector<makanan> list_makanan_4(){
    vector<makanan> hold;
    hold.push_back({"NASGOR ORI", 13500});
    hold.push_back({"NASGOR SOSIS", 16000});
    hold.push_back({"NASGOR BAKSO", 16000});
    hold.push_back({"NASGOR SPESIAL", 22000});
    hold.push_back({"NASGOR TELUR", 19500});
    hold.push_back({"BURJO CAMPUR", 9500});
    hold.push_back({"BUBUR KETAN HITAM", 9500});
    hold.push_back({"BURJO", 9500});
    hold.push_back({"BURJO + SUSU", 11000});
    hold.push_back({"KETAN HITAM + SUSU", 11000});
    hold.push_back({"BURJO CAMPUR + SUSU", 11000});

    hold.push_back({"NASI TELOR BALADO", 13500});
    hold.push_back({"NASI SARDEN", 16000});
    hold.push_back({"NASI AYAM OPOR", 16000});
    hold.push_back({"NASI AYAM BALADO", 16000});
    hold.push_back({"NASI AYAM RAGI", 16000});
    hold.push_back({"NASI AYAM KENTAKI", 18500});
    hold.push_back({"NASI SAYUR", 9500});
    hold.push_back({"NASGOR AYAM SUIR", 17000});
    hold.push_back({"NASGOR ISTIMEWA", 28500});
    hold.push_back({"MAGELANGAN", 14500});
    hold.push_back({"MAGELANGAN TELUR", 21000});
    hold.push_back({"MAGELANGAN BAKSO", 17000});
    hold.push_back({"MAGELANGAN SOSIS", 17000});
    hold.push_back({"MAGELANGAN ISTIMEWA", 29500});
    hold.push_back({"MAGELANGAN AYAM", 18500});
    hold.push_back({"MAGELANGAN RENDANG", 16000});
    hold.push_back({"MAGELANGAN GEPREK", 16000});
    hold.push_back({"NASGOR BULE", 13500});

    hold.push_back({"MIE OSENG", 18500});
    hold.push_back({"INTEL GORENG", 13500});
    hold.push_back({"INTEL REBUS", 13500});
    hold.push_back({"INTEL GORENG AYAM", 17000});
    hold.push_back({"INTEL REBUS AYAM", 17000});
    hold.push_back({"TANTE GORENG", 11000});
    hold.push_back({"TANTE GORENG AYAM", 14500});
    hold.push_back({"TANTE REBUS", 11000});
    hold.push_back({"TANTE REBUS AYAM", 14500});
    hold.push_back({"NASI ORAK ARIK", 13000});
    hold.push_back({"NASI ORAK ARIK AYAM", 17000});
    hold.push_back({"NASI TELOR", 13500});
    hold.push_back({"NASI TELOR AYAM", 17000});
    hold.push_back({"NASI AYAM PENYET", 19500});
    hold.push_back({"NASI AYAM GEPREK", 19500});
    hold.push_back({"NASI OMLET", 18500});
    hold.push_back({"NASI OMLET RENDANG", 18500});
    hold.push_back({"MIE DOK-DOK", 13500});

    hold.push_back({"ES TEH/PANAS", 5000});
    hold.push_back({"JERUS PERAS", 5000});
    hold.push_back({"KOPI", 5000});

    return hold;
}

vector<resto> list_resto(){
    vector<resto> hold;
    queue<int> hold1, hold2, hold3, hold4;

    hold1.push(1);
    hold1.push(2);

    hold2.push(1);
    hold2.push(2);
    hold2.push(3);
    hold2.push(4);
    hold2.push(5);

    hold3.push(1);
    hold3.push(2);
    hold3.push(3);

    hold4.push(1);
    hold4.push(2);
    hold4.push(3);
    hold4.push(4);
    hold4.push(5);
    hold4.push(6);
    hold4.push(7);
    hold4.push(8);

    hold.push_back({"OLIVE FRIED CHICKEN", 2, 2.3, 4.9, list_makanan_1(), hold1});
    hold.push_back({"SEBLAK ALUMNI", 2, 2.8, 4.7, list_makanan_2(), hold2});
    hold.push_back({"PENYETAN BU WARNI", 1, 2.8, 4.8, list_makanan_3(), hold3});
    hold.push_back({"BURJO SADULUR KUNINGAN", 1, 2.6, 4.8, list_makanan_4(), hold4});

    return hold;
}

vector<menutoko> toko(){
    vector<menutoko> hold;
    hold.push_back({"BISKUIT", 10000, "SNACKS"});
    hold.push_back({"KRIPIK", 9000, "SNACKS"});
    hold.push_back({"ES KRIM", 12000, "SNACKS"});
    hold.push_back({"ES KRIM", 12000, "SNACKS"});
    hold.push_back({"PERMEN", 12000, "SNACKS"});
    hold.push_back({"PERMEN", 12000, "SNACKS"});
    hold.push_back({"YUPI", 20000, "SNACKS"});
    hold.push_back({"BOLU", 10000, "SNACKS"});
    
    hold.push_back({"FRUIT TEA", 5000, "BEVERAGES"});
    hold.push_back({"AIR MINERAL", 3000, "BEVERAGES"});
    hold.push_back({"SODA", 6000, "BEVERAGES"});
    hold.push_back({"MARJAN", 25000, "BEVERAGES"});
    hold.push_back({"POCARI", 7000, "BEVERAGES"});
    hold.push_back({"TEH", 4000, "BEVERAGES"});
    hold.push_back({"KOPI BIASA", 7000, "BEVERAGES"});
    hold.push_back({"KOPI PREMIUM", 14000, "BEVERAGES"});
    hold.push_back({"ENERGY DRINK", 25000, "BEVERAGES"});
    hold.push_back({"SUSU", 6000, "BEVERAGES"});

    hold.push_back({"INDOMIE", 3000, "INSTANT FOOD"});
    hold.push_back({"SARIMIE", 3000, "INSTANT FOOD"});
    hold.push_back({"MIE SEDAP", 3000, "INSTANT FOOD"});
    hold.push_back({"MIE SUKSES", 3000, "INSTANT FOOD"});
    hold.push_back({"INDOMIE JUMBO", 4000, "INSTANT FOOD"});
    hold.push_back({"SARIMIE ISI 2", 4000, "INSTANT FOOD"});
    hold.push_back({"SAMYANG", 20000, "INSTANT FOOD"});

    return hold;
}

int gojek(tree a, int graph[map_gojek][map_gojek], vector<string> failsafe, map<int, riwayat> &riwayat_, set<int> num){
    system("cls");

    int lokasi, tujuan, total, persetujuan, hold;
    int *p;

    cout << endl << ' ' << left << setfill('=') << setw(35) << '=' << endl << setfill(' ');
    cout << " | " << setw(12) << "ID" << "| " << setw(18) << "LOKASI" << '|' << endl;
    a.prorder();
    cout << ' ' << setfill('=') << setw(35) << '=' << setfill(' ') << endl;
    cout << " > TEMPAT JEMPUT : ";
    cin >> lokasi;
    if(num.count(lokasi) == 1){
        cout << endl << " INPUT ANDA BENAR";
    } else {
        cout << endl << " INPUT ANDA SALAH, ANDA AKAN KEMBALI KE AWAL";
        Sleep(4000);
        return 0;
    }
    cout << endl << endl;

    cout << ' ' << setfill('=') << setw(45) << '=' << setfill(' ') << endl << setfill(' ');
    cout << " | " << setw(12) << "ID" << "| " << setw(18) << "LOKASI" << "| " << setw(8) << "JARAK" << '|' << endl;
    p = dijkstra(graph, lokasi-1, failsafe);
    cout << ' ' << setfill('=') << setw(45) << '=' << setfill(' ') << endl << setfill(' ');
    cout << " > PILIHAN : ";
    cin >> tujuan;
    if(num.count(tujuan) == 1){
        cout << endl << " INPUT ANDA BENAR" << endl;
    } else {
        cout << endl << " INPUT ANDA SALAH, ANDA AKAN KEMBALI KE AWAL";
        Sleep(4000);
        return 0;
    }

    total = 1500 * *(p+(tujuan-1));

    system("cls");
    cout << ' ' << failsafe[lokasi-1] << " -> " << failsafe[tujuan-1] << endl;
    cout << " HARGA Rp." << total << endl << endl;

    cout << ' ' << setw(20) << "[1] SETUJU" << setw(20) << "[2] TIDAK SETUJU" << endl;
    cout << ' ' << "> PILIHAN : ";
    cin >> persetujuan;
    if(persetujuan == 1){
        hold = riwayat_.size() + 1;
        riwayat_[hold] = {"gojek", total};
        return total;
    } else{
        return 0;
    }
}   

int gocar(vector<string> a, int graph[map_gocar][map_gocar], map<int, riwayat> &riwayat_, set<int> num){
    system("cls");

    int lokasi, tujuan, total, persetujuan, hold;

    cout << endl << ' ' << left << setfill('=') << setw(35) << '=' << endl << setfill(' ');
    cout << " | " << setw(12) << "ID" << "| " << setw(18) << "LOKASI" << '|' << endl;
    for(int i = 0; i < a.size(); ++i){
        cout << left << setfill('-') << ' ' << setw(35) << '-' << endl;
        cout << setfill(' ') << " | " << setw(12) << i+1 << "| " << setw(18) << a[i] << '|' << endl;
    }
    cout << ' ' << setfill('=') << setw(35) << '=' << setfill(' ') << endl;
    cout << " > TEMPAT JEMPUT : ";
    cin >> lokasi;
    if(num.count(lokasi) == 1){
        cout << endl << " INPUT ANDA BENAR";
    } else {
        cout << endl << " INPUT ANDA SALAH, ANDA AKAN KEMBALI KE AWAL";
        Sleep(4000);
        return 0;
    }
    cout << endl << endl;

    cout << ' ' << setfill('=') << setw(51) << '=' << setfill(' ') << endl << setfill(' ');
    cout << " | " << setw(17) << "TITIK" << "| " << setw(18) << "TUJUAN" << "| " << setw(9) << "JARAK" << '|' << endl;
    primMST(graph, a);
    cout << ' ' << setfill('=') << setw(51) << '=' << setfill(' ') << endl << setfill(' ');
    cout << endl;

    cout << endl << ' ' << left << setfill('=') << setw(35) << '=' << endl << setfill(' ');
    cout << " | " << setw(12) << "ID" << "| " << setw(18) << "LOKASI" << '|' << endl;
    for(int i = 0; i < a.size(); ++i){
        cout << left << setfill('-') << ' ' << setw(35) << '-' << endl;
        cout << setfill(' ') << " | " << setw(12) << i+1 << "| " << setw(18) << a[i] << '|' << endl;
    }
    cout << ' ' << setfill('=') << setw(35) << '=' << setfill(' ') << endl;
    cout << " > TEMPAT TUJUAN : ";
    cin >> tujuan;

    total = 35000;

    system("cls");
    cout << ' ' << a[lokasi-1] << " -> " << a[tujuan-1] << endl;
    cout << " HARGA Rp." << total << endl << endl;

    cout << ' ' << setw(20) << "[1] SETUJU" << setw(20) << "[2] TIDAK SETUJU" << endl;
    cout << ' ' << "> PILIHAN : ";
    cin >> persetujuan;
    if(persetujuan == 1){
        hold = riwayat_.size() + 1;
        riwayat_[hold] = {"gocar", total};
        return total;
    } else{
        return 0;
    }
}

void gofood2(vector<makanan> a, vector<makanan> original, string nama_resto, stack<pesan> &pesanan){
    system("cls");
    int pilihan_2, pilihan_jumlah;

    cout << " SELAMAT DATANG DI RESTO " << nama_resto << endl;
    cout << " BERIKUT ADALAH MENUNYA" << endl;
    cout << ' ' << setfill('=') << setw(65) << '=' << endl;
    cout << " | " << setfill(' ') << setw(7) << "ID" << "| " << setw(33) << "NAMA MAKANAN" << "| " << setw(18) << "HARGA MAKANAN" << '|' << endl;
    for(int j = 0; j < a.size(); ++j){
        cout << ' ' << setfill('-') << setw(65) << '-' << endl;
        cout << " | " << setfill(' ') << setw(7) << j+1 << "| " << setw(33) << a[j].nama << "| " << setw(18) << a[j].harga << '|'<< endl;
    }
    cout << ' ' << setfill('=') << setw(65) << '=' << endl;
    cout << ' ' << setfill(' ') << setw(20) <<"[0] SELESAI" << setw(20) << "[-1] SORT HARGA" << setw(20) << "[-2] DEFAULT" << endl;
    cout << " > PILIHAN : ";
    cin >> pilihan_2;

    if(pilihan_2 == 0)
        return;
    if(pilihan_2 == -1){
        gofood2(bubblesort(a), original, nama_resto, pesanan);
        return;
    }
    else if(pilihan_2 == -2){
        gofood2(original, original, nama_resto, pesanan);
        return;
    }
    cout << " > JUMLAH  : ";
    cin >> pilihan_jumlah;
    
    pesanan.push({a[pilihan_2-1].nama, pilihan_jumlah, a[pilihan_2-1].harga * pilihan_jumlah});
    gofood2(a, original, nama_resto, pesanan);
}

int gofood(vector<resto> &a, map<int, riwayat> &riwayat_){
    system("cls");
    int pilihan_1 = 0;
    stack<pesan> pesanan;
    int total = 0;
    int total1 = 0;
    int persetujuan, hold1;

    cout << ' ' << left << setfill('=') << setw(85) << '=' << endl;
    cout << " | " << setfill(' ') << setw(7) << "ID" << "| " << setw(38) << "NAMA" << "| "<< setw(8)
    << "HARGA" << "| " << setw(13) << "JARAK" << "| " << setw(8) << "RATING" << '|' << endl;
    for(int i=0; i<a.size();++i){
        cout << ' ' << setfill('-') << setw(85) << '-' << endl;
        cout << " | " << setfill(' ') <<  setw(7) << i+1 << "| " << setw(38) << a[i].nama << "| " << a[i].harga
        << setw(7) << "/4" << "| " << a[i].jarak << setw(10) << " km" << "| " << a[i].rating << setw(5) << "/5" << '|' << endl;
    }
    cout << ' ' << left << setfill('=') << setw(85) << '=' << endl;
    cout << " > PILIHAN ID : ";
    cin >> pilihan_1;

    gofood2(a[pilihan_1-1].listmakanan, a[pilihan_1-1].listmakanan, a[pilihan_1-1].nama, pesanan);

    system("cls");
    cout << " PESANAN ANDA" << endl;
    cout << ' ' << left << setfill('=') << setw(65) << '=' << endl;
    cout << " | " << setfill(' ') << setw(32) << "NAMA" << "| " << setw(8) << "JUMLAH" << "| " << setw(18) << "HARGA" << '|' << endl;
    while(!pesanan.empty()){
        cout << ' ' << setfill('-') << setw(65) << '-' << endl;
        cout << " | " << setfill(' ') << setw(32) << pesanan.top().nama << "| x" << setw(7) << pesanan.top().jumlah << "| " << setw(18) << pesanan.top().harga << '|' << endl;
        total += pesanan.top().harga;
        pesanan.pop();
    }
    cout << ' ' << setfill('=') << setw(65) << '=' << endl;

    total1 = a[pilihan_1-1].antrian.size() + 1;

    cout << " ANTRIAN KE " << total1 << endl;
    cout << " TOTAL : " << total << endl;
    cout << ' ' << setfill(' ') << setw(20) << "[1] SETUJU" << setw(20) << "[2] TIDAK SETUJU" << endl;
    cout << ' ' << "> PILIHAN : ";
    cin >> persetujuan;
    if(persetujuan == 1){
        hold1 = riwayat_.size() + 1;
        riwayat_[hold1] = {"gofood", total};
        a[pilihan_1-1].antrian.push(total1);
        return total;
    } else{
        return 0;
    }
}

int topup(int saldo){
    system("cls");
    int penambahan;
    cout << left << setfill('=') << setw(40) << '=' << endl << setfill(' ');
    cout << " SALDO TERSEDIA Rp." << saldo << endl;
    cout << " TOPUP Rp.";
    cin  >> penambahan;
    cout << endl << " MEMUAT";
    Sleep(600);
    cout << " . ";
    Sleep(600);
    cout << ". ";
    Sleep(600);
    cout << ". " << endl;
    Sleep(400);
    cout << endl << " SUKSES" << endl;
    cout << left << setfill('=') << setw(40) << '=' << endl << setfill(' ');
    Sleep(1500);
    system("cls");
    return saldo + penambahan;
}

int gosend(vector<string> mapgosend, map<string, string> perwakilan, map<int, riwayat> &riwayat_){
    system("cls");
    int pilihan_1, persetujuan, hold, total;

    cout << left << setfill('=') << ' ' << setw(40) << '='<< endl << setfill(' ');
    cout << " | " << setw(7) << "ID" << "| " << setw(28) << "NAMA TEMPAT" << '|' << endl;
    for(int i = 0; i < mapgosend.size(); ++i){
        cout << setfill('-') << ' ' << setw(40) << '-'<< endl << setfill(' ');
        cout << " | " << setw(7) << i + 1 << "| " << setw(28) << mapgosend[i] << '|' << endl;
    }
    cout << setfill('=') << ' ' << setw(40) << '='<< endl << setfill(' ');
    cout << " > PILIHAN TITIK KIRIM : ";
    cin >> pilihan_1;

    system("cls");
    cout << " BERIKUT ADALAH PROSES PERJALANAN UNTUK SAMPAI TUJUAN" << endl;
    cari(mapgosend[pilihan_1 - 1], perwakilan);

    total = 15000;
    cout << endl << " TOTAL : "<< total << endl;

    cout << ' ' << setw(20) << "[1] SETUJU" << setw(20) << "[2] TIDAK SETUJU" << endl;
    cout << ' ' << "> PILIHAN : ";
    cin >> persetujuan;
    if(persetujuan == 1){
        hold = riwayat_.size() + 1;
        riwayat_[hold] = {"gosend", total};
        return total;
    } else{
        return 0;
    }
}

int gomart(struct node* root, map<int, riwayat> &riwayat_){
    system("cls");
    vector<menutoko> menu_toko = toko();
    stack<pesan> pesanan;
    double pilihan_1;
    int pilihan_2, pilihan_jumlah, total, persetujuan, hold1;

    cout << left << setfill('=') << setw(60) << '=' << endl << setfill(' ');
    cout << " | "<< setw(27) << "NAMA" << "| " << setw(13) << "RATING" << "| " << setw(13) << "ID/JARAK" << '|' << endl;
    inorder(root);
    cout << left << setfill('=') << setw(60) << '=' << endl << setfill(' ');
    cout << " > PILIH ID NYA : ";
    cin >> pilihan_1;
    cout << endl;
    if (search(root, pilihan_1) == NULL){
        cout << pilihan_1 << " INPUT ANDA SALAH" << endl;
        Sleep(3000);
        // return 0;
    }
    else{
        cout << pilihan_1 << " INPUT ANDA BENAR" << endl;
        Sleep(3000);
    }

    for(;;){
        system("cls");
        cout << ' ' << setfill('=') << setw(80) << '=' << endl;
        cout << " | " << setfill(' ') << setw(7) << "ID" << "| " << setw(28) << "NAMA" << "| " << setw(18) << "HARGA" << "| " << setw(18) << "CATEGORI" << '|' << endl;
        for(int j = 0; j < menu_toko.size(); ++j){
            cout << ' ' << setfill('-') << setw(80) << '-' << endl;
            cout << " | " << setfill(' ') << setw(7) << j+1 << "| " << setw(28) << menu_toko[j].nama << "| " << setw(18) << menu_toko[j].harga << "| " << setw(18) << menu_toko[j].categori << '|'<< endl;
        }
        cout << ' ' << setfill('=') << setw(80) << '=' << endl;
        cout << ' ' << setfill(' ') << setw(20) <<"[0] SELESAI" << endl;
        cout << " > PILIHAN : ";
        cin >> pilihan_2;
        if(pilihan_2 == 0){
            break;
        }
        cout << " > JUMLAH  : ";
        cin >> pilihan_jumlah;

        pesanan.push({menu_toko[pilihan_2-1].nama, pilihan_jumlah, menu_toko[pilihan_2-1].harga * pilihan_jumlah});
    }

    system("cls");
    cout << " PESANAN ANDA" << endl;
    cout << ' ' << left << setfill('=') << setw(60) << '=' << endl;
    cout << " | " << setfill(' ') << setw(27) << "NAMA" << "| " << setw(8) << "JUMLAH" << "| " << setw(18) << "HARGA" << '|' << endl;
    while(!pesanan.empty()){
        cout << ' ' << setfill('-') << setw(60) << '-' << endl;
        cout << " | " << setfill(' ') << setw(27) << pesanan.top().nama << "| x" << setw(7) << pesanan.top().jumlah << "| " << setw(18) << pesanan.top().harga << '|' << endl;
        total += pesanan.top().harga;
        pesanan.pop();
    }
    cout << ' ' << setfill('=') << setw(60) << '=' << endl;
    cout << " TOTAL : " << total << endl;
    cout << ' ' << setfill(' ') << setw(20) << "[1] SETUJU" << setw(20) << "[2] TIDAK SETUJU" << endl;
    cout << ' ' << "> PILIHAN : ";
    cin >> persetujuan;
    if(persetujuan == 1){
        hold1 = riwayat_.size() + 1;
        riwayat_[hold1] = {"gomart", total};
        return total;
    } else{
        return 0;
    }
}

void RIWAYAT(map<int, riwayat> riwayat_){
    string blank;
    system("cls");
    cout << " BERIKUT RIWAYAT-RIWAYAT SEMUA PESANAN" << endl << endl << left << setfill(' ');
    for(int i = 1; i <= riwayat_.size(); ++i){
        cout << ' ' << setw(20) << "KODE" << ": " << i << endl;
        cout << ' ' << setw(20) << "DESKRIPSI" << ": " << riwayat_[i].deskripsi << endl;
        cout << ' ' << setw(20) << "TOTAL HARGA" << ": " << riwayat_[i].harga << endl << endl;
    }
    cout << " KEMBALI : ";
    cin >> blank;
}

int main(){
    system("cls");

    //vaaribel
    int saldo;
    int pilihan_menu;
    vector<resto> restoran = list_resto();
    map<int, riwayat> riwayat_;
    vector<string> failsafe_tree, mapgocar;
    map<string, string> perwakilan;
    vector<string> mapgosend;
    set<int> num_gojek, num_gocar;

    //Set Untuk Gojek dan Gocar
    num_gojek.insert({1,2,3,4,5,6,7,8,9,10});
    num_gocar.insert({1,2,3,4,5,6,7});
    
    //Failsafe Tree
    failsafe_tree.push_back("MOJOSONGO");
    failsafe_tree.push_back("JEBRES");
    failsafe_tree.push_back("PUNCANG SAWIT");
    failsafe_tree.push_back("JAGALAN");
    failsafe_tree.push_back("PURWODININGRAT");
    failsafe_tree.push_back("TEGALHARJO");
    failsafe_tree.push_back("KEPATIHAN");
    failsafe_tree.push_back("SEWU");
    failsafe_tree.push_back("GANDEKAN");
    failsafe_tree.push_back("SUDIROPRAJAN");
    
    //Map Untuk Gocar
    mapgocar.push_back("JEBRES");
    mapgocar.push_back("PASAR KLIWON");
    mapgocar.push_back("PASAR BANJARSARI");
    mapgocar.push_back("SERENGAN");
    mapgocar.push_back("LAWEYAN");
    mapgocar.push_back("BOYOLALI");
    mapgocar.push_back("SUKOHARJO");
    
    //implementasi tree
    tree akar("MOJOSONGO", 1);
    tree anak_1("TEGALHARJO", 6);
    tree anak_2("JEBRES", 2);
    tree anak_3("SEWU", 8);
    tree anak_4("KEPATIHAN", 7);
    tree anak_5("JAGALAN", 4);
    tree anak_6("PUNCANG SAWIT", 3);
    tree anak_7("SUDIROPRAJAN", 10);
    tree anak_8("GANDEKAN", 9);
    tree anak_9("PURWODININGRAT", 5);

    anak_5.insert_tree(anak_9);
    anak_3.insert_tree(anak_8);
    anak_3.insert_tree(anak_7);
    anak_2.insert_tree(anak_6);
    anak_2.insert_tree(anak_5);
    anak_1.insert_tree(anak_4);
    anak_1.insert_tree(anak_3);
    akar.insert_tree(anak_2);
    akar.insert_tree(anak_1);
    
    //Implementasi Binary Search Tree
    struct node *root = NULL;
	// root = insert(root, 1.5, "INDOMARET KARTIKA", 3);
	// root = insert(root, 2.4, "INDOMARET PEDARINGAN", 4);
	// root = insert(root, 3.3, "INDOMARET NGAWI", 4);
	// root = insert(root, 3.2, "INDOMARET KOL SUTARTO", 4);
	// root = insert(root, 3.0, "ALFAMIDI JEBRES", 4);
	// root = insert(root, 2.9, "ALFAMART JEBRES", 4);
	// root = insert(root, 1.4, "RED PALM MINIMARKET", 4);

    //Implementasi Shortest Path
    int graph[map_gojek][map_gojek] = {
        {0, 5, 0, 0, 0, 0, 0, 0, 0, 0},
        {5, 0, 2, 3, 3, 4, 0, 0, 0, 0},
        {0, 2, 0, 2, 0, 0, 0, 0, 0, 0},
        {0, 3, 2, 0, 2, 0, 0, 3, 0, 0},
        {0, 3, 0, 2, 0, 1, 0, 0, 0, 2},
        {0, 4, 0, 0, 1, 0, 1, 0, 0, 3},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 3, 0, 0, 0, 0, 2, 0},
        {0, 0, 0, 0, 0, 0, 0, 2, 0, 1},
        {0, 0, 0, 0, 2, 3, 0, 0, 1, 0},
    };

    //Implemntasi MST
    int graph2[map_gocar][map_gocar] = {
        {0,  7,  9,  0,  0,  0, 0 },
        {7,  0, 12,  4,  0,  0, 10},
        {9, 12,  0, 10,  8, 12, 0 },
        {0,  4, 10,  0,  8,  0, 10},
        {0,  0,  8,  8,  0,  7, 10},
        {0,  0, 12,  0,  7,  0, 15},
        {0, 10,  0, 10, 10, 10, 15}
    };
    
    //Implementasi DIsjoin
    perwakilan["JEBRES"] = "JEBRES";
    perwakilan["PASAR KLIWON"] = "PASAR KLIWON";
    perwakilan["BANJARSARI"] = "BANJARSARI";
    perwakilan["SERENGAN"] = "SERENGAN";
    perwakilan["LAWEYAN"] = "LAWEYAN";
    perwakilan["GDNG.JEBRES"] = "GDNG.JEBRES";
    perwakilan["GDNG.PASAR KLIWON"] = "GDNG.PASAR KLIWON";
    perwakilan["GDNG.BANJARSARI"] = "GDNG.BANJARSARI";
    perwakilan["GDNG.LAWEYAN"] = "GDNG.LAWEYAN";
    perwakilan["POS.SISIKANAN SOLO"] = "POS.SISIKANAN SOLO";
    perwakilan["POS.SISIKIRI SOLO"] = "POS.SISIKIRI SOLO";
    perwakilan["POS.UTAMA"] = "POS.UTAMA";

    menggabungkan("JEBRES", "GDNG.JEBRES", perwakilan);
    menggabungkan("PASAR KLIWON", "GDNG.PASAR KLIWON", perwakilan);
    menggabungkan("SERENGAN", "GDNG.PASAR KLIWON", perwakilan);
    menggabungkan("BANJARSARI", "GDNG.BANJARSARI", perwakilan);
    menggabungkan("LAWEYAN", "GDNG.LAWEYAN", perwakilan);
    menggabungkan("GDNG.JEBRES", "POS.SISIKANAN SOLO", perwakilan);
    menggabungkan("GDNG.PASAR KLIWON", "POS.SISIKANAN SOLO", perwakilan);
    menggabungkan("GDNG.BANJARSARI", "POS.SISIKIRI SOLO", perwakilan);
    menggabungkan("GDNG.LAWEYAN", "POS.SISIKIRI SOLO", perwakilan);
    menggabungkan("POS.SISIKIRI SOLO", "POS.UTAMA", perwakilan);
    menggabungkan("POS.SISIKANAN SOLO", "POS.UTAMA", perwakilan);
    
    //LIst Untuk Gosend
    mapgosend.push_back("JEBRES");
    mapgosend.push_back("PASAR KLIWON");
    mapgosend.push_back("BANJARSARI");
    mapgosend.push_back("SERENGAN");
    mapgosend.push_back("LAWEYAN");

    //dimulai
    pendahuluan(saldo);
    for(;;){
        system("cls");
        front_1(saldo);
        cout << " > PILIHAN : ";
        cin >> pilihan_menu;
        switch(pilihan_menu){
            case 1:
            saldo -= gojek(akar, graph, failsafe_tree, riwayat_, num_gojek);
            break;
            case 2:
            saldo -= gocar(mapgocar, graph2, riwayat_, num_gocar);
            break;
            case 3:
            saldo -= gofood(restoran, riwayat_);
            break;
            case 4:
            saldo -= gosend(mapgosend, perwakilan, riwayat_);
            break;
            case 5:
            saldo -= gomart(root, riwayat_);
            break;
            case 6:
            saldo = topup(saldo);
            break;
            case 7:
            RIWAYAT(riwayat_);
            break;
            default:
            break;
        }
    }
}