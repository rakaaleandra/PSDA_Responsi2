
# Responsi 2 Praktikum Struktur Data dan Algoritma

Terbuatnya code c++ ini karena adanya penugasan Responsi dari **praktikum struktur data dan algoritma** yang dimana kode tersebut berisi struktur data yaitu :

* List : 5 poin
* Stack : 5 poin
* Queue : 5 poin
* Set : 5 poin
* Map : 5 poin
* Tree : 5 poin
* Graph : 5 poin
* Disjoint Set: 5 poin
* Sorting : 5 poin
* Binary Tree : 10 poin
* Binary Search Tree : 15 poin
* MST (Kruskal's, Prim's Pilih Salah Satu) : 15 poin
* Shortest Path : 15 poin 

pada responsi ini saya berhasil memasukkan semua struktur data tersebut pada code, tetapi untuk struktur data **binary search tree** masih tidak bisa ter-compile dibeberapa laptop maka dari itu saya mengkomentar code **binary search tree** supaya semua code bisa berjalan.

## Masalah

line algoritma **binary search tree** : line 89

```c++
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
```

line input **binary search tree** : line 900

```c++
struct node *root = NULL;
root = insert(root, 1.5, "INDOMARET KARTIKA", 3);
root = insert(root, 2.4, "INDOMARET PEDARINGAN", 4);
root = insert(root, 3.3, "INDOMARET NGAWI", 4);
root = insert(root, 3.2, "INDOMARET KOL SUTARTO", 4);
root = insert(root, 3.0, "ALFAMIDI JEBRES", 4);
root = insert(root, 2.9, "ALFAMART JEBRES", 4);
root = insert(root, 1.4, "RED PALM MINIMARKET", 4);
```

<br>

**Bila ada yang bisa membantu, berikan ulasan di issues atau `pull request` jika mau membenarkan codenya**

Bisa hubungi saya lewat email : raka.aleandra@student.uns.ac.id 