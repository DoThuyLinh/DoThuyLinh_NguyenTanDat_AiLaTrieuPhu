/*
* Code by: Đỗ Thùy Linh
* Last Update: 14/11/2018
* Version: 1.5
*/
#include<bits/stdc++.h>
#include<windows.h>
#include <fcntl.h>
#include <io.h>
#include <locale>
#include <codecvt>
using namespace std;
#define LH -1
#define EH 0
#define RH 1

/*=============================================================================================================*/
/*========================================ĐỊNH NGHĨA CẤU TRÚC==================================================*/

struct CauHoi{
    int so;
    char NoiDung[1000];
    char A[1000],B[1000],C[1000],D[1000];
    char DapAn;
};
struct User{
    char Name[100];
    int Diem;
};
struct Node{
    CauHoi data;
    char balFactor;
    Node *left, *right;
};
typedef Node *TREE;

/*=============================================================================================================*/
/*===========================================NGUYÊN MẪU HÀM====================================================*/

int LoadFileCauHoi(TREE &t, char*filename); //Load dữ liệu từ file lên cây
bool GhiFileCauHoi(TREE t, char*filename); //Ghi toàn bộ câu hỏi từ cây xuống file
bool LoadFileNguoiChoi(char *filename, User users[]); //Load dữ liệu từ file người chơi
bool GhiFileNguoiChoi(char *filename, User users[]); //Ghi danh sách người chơi điểm cao xuống file
void ThemNguoiChoi(User users[], User user); //Thêm người chơi vào danh sách điểm cao
int InsertNode(TREE &t, CauHoi cauhoi); //Thêm node vào cây cân bằng
Node *TimKiemCauHoi(TREE t, int id); //Tìm kiếm câu hỏi theo ID
int DeleteNode(TREE &t, int id); //Xóa node trên cây
bool Update(TREE &t,CauHoi cauhoi); //Cập nhật câu hỏi
void DuyetCayGhiXuongFile(FILE*file, TREE t); //Ghi từng phần tử của cây xuống file
int demnode(TREE t); //Đếm số node trong cây
void TimUpdate(TREE t, CauHoi cauhoi); //Tìm và sửa câu hỏi trên cây
string to_utf8(const wchar_t* buffer, int len); //Chuyển wchar_t sang chuỗi
string to_utf8(const wstring& str); //Chuyển wchar_t sang chuỗi
bool compareuser(User u1, User u2); //So sánh 2 người chơi theo điểm (hỗ trợ hàm sort)
void Random5SoKhongTrung(int a[], int n); //Random 5 số không trùng nhau trong khoảng từ 1 đến n

//Các hàm hỗ trợ tạo cây cân bằng
void RotateLL(TREE &t);
void RotateRR(TREE &t);
void RotateLR(TREE &t);
void RotateRL(TREE &t);
int BalanceLeft(TREE &t);
int BalanceRight(TREE &t);


/*=============================================================================================================*/
/*============================================HIỆN THỰC HÀM====================================================*/

void RotateLL(TREE &t)
{
    Node * t1= t->left;
    t->left=t1->right;
    t1->right=t;
    switch(t1->balFactor)
    {
        case LH: t->balFactor =EH;
            t1->balFactor = EH;
            break;
        case EH: t->balFactor = LH;
            t1->balFactor=RH;
            break;
    }
    t=t1;
}
void RotateRR(TREE &t)
{
    Node * t1= t->right;
    t->right=t1->left;
    t1->left=t;
    switch(t1->balFactor)
    {
        case RH: t->balFactor =EH;
            t1->balFactor = EH;
            break;
        case EH: t->balFactor = RH;
            t1->balFactor=LH;
            break;
    }
    t=t1;
}
void RotateLR(TREE &t)
{
    Node *t1= t->left;
    Node *t2= t1->right;
    t->left = t2->right;
    t2->right=t;
    t1->right=t2->left;
    t2->left=t1;
    switch(t2->balFactor)
    {
        case LH: t->balFactor = RH;
            t1->balFactor = EH;
            break;
        case EH: t->balFactor = EH;
            t1->balFactor = EH;
            break;
        case RH: t->balFactor = EH;
            t1->balFactor = LH;
            break;
    }
    t2->balFactor = EH;
    t=t2;
}
void RotateRL(TREE &t)
{
    Node *t1= t->right;
    Node *t2= t1->left;
    t->right = t2->left;
    t2->left=t;
    t1->left=t2->right;
    t2->right=t1;
    switch(t2->balFactor)
    {
        case RH: t->balFactor = LH;
            t1->balFactor = EH;
            break;
        case EH: t->balFactor = EH;
            t1->balFactor = EH;
            break;
        case LH: t->balFactor = EH;
            t1->balFactor = RH;
            break;
    }
    t2->balFactor = EH;
    t=t2;
}
int BalanceLeft(TREE &t)
{
    Node* t1 =t->left;
    switch(t1->balFactor)
    {
        case LH: RotateLL(t);
        return 2;
        case EH: RotateLL(t);
        return 1;
        case RH: RotateLR(t);
        return 2;
    }
    return 0;
}
int BalanceRight(TREE &t)
{
    Node *t1=t->right;
    switch(t1->balFactor)
    {
        case LH: RotateRL(t);
        return 2;
        case EH: RotateRR(t);
        return 1;
        case RH: RotateRR(t);
        return 2;
    }
    return 0;
}
int InsertNode(TREE &t, CauHoi cauhoi)
{
    int res;
    if(t)
    {
        if(t->data.so ==cauhoi.so)
            return 0;
        if(t->data.so > cauhoi.so)
        {
            res =InsertNode(t->left,cauhoi);
            if(res<2)
                return res;
            switch(t->balFactor)
            {
                case RH: t->balFactor = EH;
                    return 1;
                case EH: t->balFactor = LH;
                    return 2;
                case LH: t->balFactor = BalanceLeft(t);
                    return 1;
            }
        }
        else
        {
            res = InsertNode(t->right,cauhoi);
            if(res<2)
                return res;
            switch(t->balFactor)
            {
                case LH: t->balFactor = EH;
                    return 1;
                case EH: t->balFactor =RH;
                    return 2;
                case RH: BalanceRight(t);
                return 1;
            }
        }
    }
    t = new Node;
    if(t==NULL)
        return -1;
    t->data = cauhoi;
    t->balFactor = EH;
    t->left =t->right =NULL;
    return 2;
}
bool compareuser(User u1, User u2)
{
    return u1.Diem > u2.Diem;
}
void ThemNguoiChoi(User users[], User user)
{
    users[5] = user;
    sort(users,users+6,compareuser);
    char filename[100]; strcpy(filename,"Users.dat");
    GhiFileNguoiChoi(filename,users);
}
int LoadFileCauHoi(TREE &t, char*filename)
{
    FILE*file;
    char x[10];
    int n;
    file = fopen(filename,"r");
    if(file == NULL) return -1;
    int i = 1;
    fscanf(file,"%d",&n);
    fgets(x,10,file);
    while(i<=n){
        CauHoi cauhoi;
        cauhoi.so = i;
        fgets(cauhoi.NoiDung,256,file);
        fgets(cauhoi.A,256,file);
        fgets(cauhoi.B,256,file);
        fgets(cauhoi.C,256,file);
        fgets(cauhoi.D,256,file);
        fscanf(file,"%c",&cauhoi.DapAn);
        fgets(x,10,file);
        InsertNode(t,cauhoi);
        i++;
    }
    fclose(file);
    return n;
}
void DuyetCayGhiXuongFile(FILE *file, TREE t)
{
    if(t!=NULL){
        DuyetCayGhiXuongFile(file,t->left);
        fputs(t->data.NoiDung,file);
        fputs(t->data.A,file);
        fputs(t->data.B,file);
        fputs(t->data.C,file);
        fputs(t->data.D,file);
        fprintf(file,"%c\n",t->data.DapAn);
        DuyetCayGhiXuongFile(file,t->right);
    }
}
int demnode(TREE t)
{
    if(!t) return 0;
    return demnode(t->left) + demnode(t->right) + 1;
}
bool GhiFileCauHoi(TREE t, char*filename)
{
    FILE*file;
    file = fopen(filename,"w");
    if(file == NULL) return false;
    fprintf(file,"%d\n",demnode(t));
    DuyetCayGhiXuongFile(file,t);
    fclose(file);
    return true;
}
bool LoadFileNguoiChoi(char *filename, User users[])
{
    FILE *file;
    file = fopen(filename,"r");
    if(file == NULL) return false;
    int i=0;
    while(!feof(file)){
        fgets(users[i].Name,100,file);
        fscanf(file,"%d",&users[i].Diem);
        fgetc(file);
        i++;
    }
    fclose(file);
    return true;
}
bool GhiFileNguoiChoi(char *filename, User users[])
{
    FILE *file;
    file = fopen(filename,"w");
    if(file == NULL)  return false;
    for(int i = 0; i < 5; i++){
        fputs(users[i].Name,file);
        fprintf(file,"%d",users[i].Diem);
        if(i < 4) fprintf(file,"\n");
    }
    fclose(file);
    return true;
}
int SearchStandFor(TREE &p, TREE &q)
{
    int res;
    if(q->left)
    {
        res=SearchStandFor(p,q->left);
        if(res <2) return res;
        switch(q->balFactor)
        {
            case LH: q->balFactor = EH;
                return 2;
            case EH: q->balFactor = RH;
                return 1;
            case RH: return BalanceRight(q);
        }
    }
    else
    {
        p->data = q->data;
        p=q;
        q=q->right;
        return 2;
    }
}
int DeleteNode(TREE &t, int id)
{
    int res;
    if(t==NULL)
        return 0;
    if(t->data.so > id)
    {
        res = DeleteNode(t->left,id);
        if(res<2) return res;
        switch(t->balFactor)
        {
            case LH: t->balFactor = EH;
                return 2;
            case EH: t->balFactor = RH;
                return 1;
            case RH: return BalanceRight(t);
        }
    }
    if(t->data.so < id)
    {
        res = DeleteNode(t->right,id);
        if(res<2)
            return res;
        switch(t->balFactor)
        {
            case RH: t->balFactor = EH;
                return 2;
            case EH: t->balFactor = LH;
                return 1;
            case LH: return BalanceLeft(t);
        }
    }
    else
    {
        Node *p=t;
        if(t->left == NULL)
        {
            t=t->right;
            res =2;
        }
        else if(t->right == NULL)
        {
            t=t->left;
            res =2;
        }
        else
        {
            res=SearchStandFor(p,t->right);
            if(res < 2) return res;
            switch(t->balFactor)
            {
                case RH: t->balFactor = EH;
                    return 2;
                case EH: t->balFactor = LH;
                    return 1;
                case LH: return BalanceLeft(t);
            }
        }
        delete p;
        return res;
    }
}
Node *TimKiemCauHoi(TREE t, int id)
{
    if(t)
    {
        if(t->data.so == id)
            return t;
        if(t->data.so > id)
            return TimKiemCauHoi(t->left,id);
        else
            return TimKiemCauHoi(t->right,id);
    }
    return NULL;
}
void TimUpdate(TREE t, CauHoi cauhoi)
{
    if(t)
    {
        if(t->data.so == cauhoi.so)
        {
            strcpy(t->data.NoiDung,cauhoi.NoiDung);
            strcpy(t->data.A,cauhoi.A);
            strcpy(t->data.B,cauhoi.B);
            strcpy(t->data.C,cauhoi.C);
            strcpy(t->data.D,cauhoi.D);
            t->data.DapAn = cauhoi.DapAn;
            return;
        }
        if(t->data.so > cauhoi.so)
            return TimUpdate(t->left,cauhoi);
        else
            return TimUpdate(t->right,cauhoi);
    }
}
bool Update(TREE &t,CauHoi cauhoi)
{
    Node *p = TimKiemCauHoi(t,cauhoi.so);
    if(!p) return false;
    TimUpdate(t,cauhoi);
    return true;
}
void Random5SoKhongTrung(int a[], int n)
{
    int arr[n+1];
    for(int i = 0; i < n; i++) arr[i] = i+1;

    for(int i = 0; i < 5; i++){
        int vitri = rand()%n;
        a[i] = arr[vitri];
        for(int j = vitri; j < n-1; j++){
            arr[j] = arr[j+1];
        }
        n--;
    }
}
bool XetDungSai(CauHoi cauhoi, int dapan)
{
    if(cauhoi.DapAn == 'A' && dapan == 1) return true;
    if(cauhoi.DapAn == 'B' && dapan == 2) return true;
    if(cauhoi.DapAn == 'C' && dapan == 3) return true;
    if(cauhoi.DapAn == 'D' && dapan == 4) return true;
    return false;
}
string to_utf8(const wchar_t* buffer, int len) //copy mạng
{
   int nChars = WideCharToMultiByte(CP_UTF8,0,buffer,len,NULL,0,NULL,NULL);
   if (nChars == 0) return "";
   string newbuffer;
   newbuffer.resize(nChars);
   WideCharToMultiByte(CP_UTF8,0,buffer,len,const_cast<char*>(newbuffer.c_str()),nChars,NULL,NULL);
   return newbuffer;
}
string to_utf8(const wstring& str) //copy mạng
{
   return to_utf8(str.c_str(), (int)str.size());
}
