#include <bits/stdc++.h>

using namespace std;

struct sv {
    int id, age;
    string name;
    bool operator > (const sv &foo) {
        return id > foo.id;
    }
    bool operator == (const sv &foo) {
        return id == foo.id;
    }
    sv() {}
    sv(int _id, int _age, string _name) {
        id = _id;
        age = _age;
        name = _name;
    }
};

struct node {
    sv val;
    node *left, *right;
} *T;

node *newnode(sv x) {
    node *res = new node;
    (*res).val = x;
    res->left = res->right = NULL;
    return res;
}

node *add(node *root, sv x) {
    if (root == NULL) {
        root = newnode(x);
        return root;
    }
    if (root->val == x) return root;
    if (root->val > x)
        root->left = add(root->left, x);
    else
        root->right = add(root->right, x);
    return root;
}

///tra ve node trai nhat
node *LeftMostNode(node *root) {
  while (root->left != NULL) {
    root = root->left;
  }
  return root;
}

node *Remove(node *root, sv x) {
    if (root == NULL) return root;
    if (root->val == x) {
        if (root->left == NULL) {
            node *bak = root->right;
            delete root;
            return bak;
        }
        if (root->right == NULL) {
            node *bak = root->left;
            delete root;
            return bak;
        }

        ///lay node trai nhat va doi cho len node root dang xet
        node *bak = LeftMostNode(root->right);
        root->val = bak->val;
        root->right = Remove(root->right, bak->val);
    }
    if (root->val > x)
        root->left = Remove(root->left, x);
    else
        root->right = Remove(root->right, x);
    return root;
}

sv Search(node *root, sv x) {
    if (root == NULL) return sv(0, 0, "*");
    if (root->val == x) return root->val;
    if (root->val > x)
        return Search(root->left, x);
    else
        return Search(root->right, x);
}

void List(node *root) { ///liet ke
    if (root == NULL) return;
    List(root->left);
    cout<< "--------------------\n";
    cout << "MSSV: "<< (root->val).id<< "\nHO VA TEN: " << (root->val).name << "\nTUOI: "<< (root->val).age << endl<< endl;
    List(root->right);
}

void menu() {
    cout<< "\n========QUAN LY SINH VIEN========\n\n";
    cout << "1.NHAP DU LIEU CUA SINH VIEN\n\n";
    cout << "2.TIM KIEM SINH VIEN\n\n";
    cout << "3.THEM SINH VIEN\n\n";
    cout << "4.XOA SINH VIEN KHOI DANH SACH\n\n";
    cout << "5.IN RA DANH SACH SINH VIEN\n\n";
}

void Nhap() {
    sv x;
    system("cls");
    while (1) {
        cout<< "nhan q de thoat\n\n";
        cout << "Nhap HO VA TEN: "; fflush(stdin); getline(cin, x.name);
        if( x.name == "q"|| x.name== "Q")
        {
            system("cls");
            break;
        }
        cout << "Nhap MSSV: "; cin >> x.id;
        cout << "Nhap TUOI:"; cin >> x.age;
        if (T == NULL) T = add(T, x);
        else add(T, x);
        system("cls");
        cout<< "nhap thanh cong\n";
    }

}

void Tim_kiem() {
    system("cls");
    if( T == NULL)
    {
        cout<< "ban can nhap du lieu truoc\n";
    }
    else{
        int id;
        cout << "Nhap MSSV cua sinh vien can tim kiem: "; cin >> id;
        sv result = Search(T, sv(id, 0, "*"));
        if (result.id){
            printf("MSSV : %d \nTen: %s \nTuoi: %d\n", result.id, &(result.name[0]), result.age);
        }
        else cout << "Sinh vien khong ton tai.\n";
    }
}

void Them() {
    system("cls");
    sv x;
    cout << "Nhap HO VA TEN: "; fflush(stdin); getline(cin, x.name);
    cout << "Nhap MSSV: "; cin >> x.id;
    cout << "Nhap TUOI: "; cin >> x.age;
    if (T == NULL) T = add(T, x);
    else add(T, x);
    system("cls");
    cout<< " them thanh cong";
}

void Xoa() {
    system("cls");
    if( T == NULL)
    {
        cout<< "ban can nhap du lieu truoc\n";
    }
    else{
        int id;
        cout << "Nhap MSSV cua sinh vien can xoa: "; cin >> id;
        sv result = Search(T, sv(id, 0, "*"));
        if( result.id)
        {
           Remove(T, sv(id, 0, "*"));
           cout<< "xoa thanh cong";
        }
        else cout<< "sinh vien khong ton tai";
    }
}

void Liet_ke() {
    system("cls");
    List(T);
    if( T == NULL)
    {
        cout<< "chua co du lieu ";
        cout<< "ban can nhap du lieu truoc\n";
    }
}

int main() {
    while (1) {
        menu();
        int opt = 0;
        cin >> opt;
        
        switch(opt) {
            case 1: Nhap(); break;
            case 2: Tim_kiem(); break;
            case 3: Them(); break;
            case 4: Xoa(); break;
            case 5: Liet_ke(); break;
            default: system("cls");
                     cout<< "lua chon khong thoa man xin hay chon lai\n";
                     break;
        }
        
    }
}
