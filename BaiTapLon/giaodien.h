#include<bits/stdc++.h>
#include <windows.h>
#include <Wincon.h>
#include <wchar.h>
#include <dir.h>
#include <dos.h>
#include <MMSystem.h>
#include <utility>
# define VIEN 176
# define VIEN2 219
#include<conio.h>
using namespace std;

//Thiet lap cac gia tri co ban
#define WIDTH 144
#define HEIGHT 40
#define blue 1
#define lightblue 9
#define lightblue2 3
#define aqua 11
#define white 15
#define black 0
#define purple 5
#define pink 13
#define yellow 6
#define lightyellow 14
#define red 4
#define lightred 12
#define green 2
#define lightgreen 10
#define gray 8
#define gotoend gotoxy(0,40)
#define ch1 (char)186
#define ch2 (char)187
#define ch3 (char)188
#define ch4 (char)200
#define ch5 (char)201
#define ch6 (char)205
#define ch7 (char)203
#define ch8 (char)204
#define ch9 (char)206
#define ch10 (char)202
#define ch11 (char)185
/*=============================================================================================================*/
/*=========================================NGUYÊN MẪU HÀM======================================================*/
void DoiMauChu(int ForgC, int BackC); //Doi mau chu va nen chu
void VeLogoChinh();  //Ve chu ai la trieu phu lon
void VeKhungChinh();  //Ve khung tro choi
void VeKhungPhu();  //Ve khung chia man hinh thanh 4 phan
void gotoxy(int x, int y);  //Di chuyen con tro den vi tri x y
void Click(int &x, int &y); //Bat vi tri click chuot
void XuatChuoiTiengViet(char str[]);  //Hien thi tieng Viet len man hinh
void VeMenuTrangChu(int x, int y, int loai);
void VeFormChinh();  //Ve giao dien 1
void VeKhungABCD(int x, int y, int mode);  //Ve khung cho 4 dap an ABCD
void VeHinhDoVang(char tenhinh[], int x, int y, int width, int height);
void VeFormPhu();  //Ve giao dien 2
void VeKhungCauHoi(int x, int y);
void VeBongBongChat(int x, int y, int huong, char noidung[]);
void VeQuyenTroGiup();
void VeThangDiem();
void FocusDiem(int stt);
void SuDungQuyenTroGiup(int stt, char dapan, int &da1, int &da2);
int XuatChu(int x, int y, int width, char noidung[]);
int Xuat_wchar_t(int x, int y, int width, wchar_t wnoidung[]);
void InCauHoi(CauHoi ch, int stt);
void XoaKhuVuc(int x, int y, int width, int height);  //Xoa khu vuc dien tich width*height, bat dau tai vi tri x,y
int XetViTriClick(int x, int y, int form);
void DoiMauDapAn(int dapanchon, int mode, CauHoi ch);
void DoiMauQuyenTroGiup(int stt, int mau);
void NamMuoiNamMuoi(char dapan, int &da1, int &da2);
void GoiNguoiThan(char dapan);
void TuVanTaiCho(char dapan);
void HoiYKienKhanGia(char dapan, int da1, int da2);
void ClearTroGiupCu();
void DungCuocChoi(int cauhientai);
void VeFormDiemCao();
void InChuCanhGiua(int x, int y, int width, char noidung[]);
void VeNutQuayLai(int x, int y);
void VeFormCaiDat();
void VeMenuCaiDat(int x, int y, int color, char noidung[]);
void HienDanhSachCauHoi(TREE t, int trang);
void MenuXuLyDanhSach(int &id, int &trang, int sotrang);
void XuLyThemCauHoi();
void KhoaConTroChuot();
void MoKhoaConTroChuot();
void XuLyXoaCauHoi(TREE &t, int goi);
void XuLySuaCauHoi(TREE &t, int goi);
void XuLyResetBangXepHang();
void NhapChuoiTiengViet(char str[]);
/*=============================================================================================================*/
/*========================================HIỆN THỰC HÀM========================================================*/
void DoiMauChu(int ForgC, int BackC)
{
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}
void VeLogoChinh()
{
    FILE *f = fopen("Design/logo.art","r");
    FILE *f2 = fopen("Design/logo.color","r");
    for(int i = 0; i < 8; i++){
        gotoxy(9,i+5);
        for(int j = 0; j < 126; j++)
        {
            char c = fgetc(f);
            char c2 = fgetc(f2);
            if(c2 == '1'){
                DoiMauChu(lightyellow,black);
            }
            else
                DoiMauChu(lightred,black);
            cout<<c;
        }
    }
    fclose(f2);
    fclose(f);
    gotoend;
}
void VeKhungChinh()
{

    //SetWindow(WIDTH,HEIGHT+5);
    DoiMauChu(lightred,black);
    cout<<ch5;
    for(int i = 0; i < WIDTH/2-2; i++){
        cout<<ch6<<ch7;
    }
    cout<<ch6<<ch2<<endl;
    cout<<ch8<<ch6<<ch9;
    cout<<ch6<<ch9<<ch6<<ch9;
    for(int i = 3; i < WIDTH/2-5; i++){
        cout<<ch6<<ch10;
    }
    cout<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch11;

    gotoxy(0,2);
    cout<<ch8<<ch6<<ch9<<ch6<<ch9<<ch6<<ch3;
    gotoxy(WIDTH - 8, 2);
    cout<<ch4<<ch6<<ch9<<ch6<<ch9<<ch6<<ch11;

    gotoxy(0,3);
    cout<<ch8<<ch6<<ch9<<ch6<<ch3;
    gotoxy(WIDTH - 6, 3);
    cout<<ch4<<ch6<<ch9<<ch6<<ch11;

    for(int i = 3; i < HEIGHT-2; i++){
        gotoxy(0,i+1);
        cout<<ch8<<ch6<<ch11;
        gotoxy(WIDTH - 4, i+1);
        cout<<ch8<<ch6<<ch11;
    }
    gotoxy(0,HEIGHT-1);
    cout<<ch8<<ch6<<ch9;
    for(int i = 0; i < WIDTH/2-4; i++){
        cout<<ch6<<ch7;
    }
    cout<<ch6<<ch9<<ch6<<ch11<<endl;
    cout<<ch4;
    for(int i = 1; i < WIDTH/2-1; i++){
        cout<<ch6<<ch10;
    }
    cout<<ch6<<ch3<<endl;

    gotoxy(2,HEIGHT - 3);
    cout<<ch9<<ch6<<ch2;
    gotoxy(2,HEIGHT - 2);
    cout<<ch9<<ch6<<ch9<<ch6<<ch2;
    gotoxy(2,HEIGHT - 1);
    cout<<ch9<<ch6<<ch9<<ch6<<ch9;

    gotoxy(WIDTH - 8, HEIGHT - 1);
    cout<<ch9<<ch6<<ch9;
    gotoxy(WIDTH - 8, HEIGHT - 2);
    cout<<ch5<<ch6<<ch9<<ch6<<ch9;
    gotoxy(WIDTH - 6, HEIGHT - 3);
    cout<<ch5<<ch6<<ch9;
}
void VeKhungPhu()
{
    for(int i = 5; i < 11; i++){
        gotoxy(2,i); cout<<ch9<<ch6;
    }
    gotoxy(4,5); cout<<ch2;
    for(int i = 6; i < 10; i++){
        gotoxy(4,i); cout<<ch9<<ch6;
    }
    gotoxy(6,6);cout<<ch2;
    for(int i = 7; i < 9; i++){
        gotoxy(6,i); cout<<ch9<<ch6;
    }
    gotoxy(8,7); cout<<ch7<<ch6;
    for(int i = 0; i < WIDTH/2 - 8; i++){
        cout<<ch7<<ch6;
    }
    gotoxy(8,8); cout<<ch10<<ch6;
    for(int i = 0; i < WIDTH/2 - 8; i++){
        cout<<ch10<<ch6;
    }
    gotoxy(6,9); cout<<ch3;
    gotoxy(4,10); cout<<ch3;
    gotoxy(WIDTH-8,7); cout<<ch9<<ch6<<ch9<<ch6<<ch9;
    gotoxy(WIDTH-8,8); cout<<ch9<<ch6<<ch9<<ch6<<ch9;
    gotoxy(WIDTH-8,6); cout<<ch5<<ch6<<ch9<<ch6<<ch9;
    gotoxy(WIDTH-6,5); cout<<ch5<<ch6<<ch9;
    gotoxy(WIDTH-8,9); cout<<ch4<<ch6<<ch9<<ch6<<ch9;
    gotoxy(WIDTH-6,10); cout<<ch4<<ch6<<ch9;

    for (int i = 1; i < HEIGHT; i++){
        gotoxy(WIDTH - 40,i);
        cout<<ch8<<ch6<<ch11;
    }
    gotoxy(WIDTH - 44, 1);
    cout<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9;
    gotoxy(WIDTH - 44, 2);
    cout<<ch4<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch3;
    gotoxy(WIDTH - 42, 3);
    cout<<ch4<<ch6<<ch9<<ch6<<ch9<<ch6<<ch3;

    gotoxy(WIDTH - 44, 8);
    cout<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9;
    gotoxy(WIDTH - 44, 9);
    cout<<ch4<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch3;
    gotoxy(WIDTH - 42, 10);
    cout<<ch4<<ch6<<ch9<<ch6<<ch9<<ch6<<ch3;

    gotoxy(WIDTH - 44, 7);
    cout<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9;
    gotoxy(WIDTH - 44, 6);
    cout<<ch5<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch2;
    gotoxy(WIDTH - 42, 5);
    cout<<ch5<<ch6<<ch9<<ch6<<ch9<<ch6<<ch2;

    gotoxy(WIDTH-44,HEIGHT-1);
    cout<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9;
    gotoxy(WIDTH - 44, HEIGHT-2);
    cout<<ch5<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch2;
    gotoxy(WIDTH - 42, HEIGHT-3);
    cout<<ch5<<ch6<<ch9<<ch6<<ch9<<ch6<<ch2;
    gotoend;
}
void gotoxy(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
}
void Click(int &x, int &y)
{
    HANDLE hout= GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD fdwMode, fdwSaveOldMode, Events;
    INPUT_RECORD InputRecord;
    GetConsoleMode(hStdin, &fdwSaveOldMode);
    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    SetConsoleMode(hStdin, fdwMode);

    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 25;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hout, &cci);

    while(1){
        ReadConsoleInput(hStdin, &InputRecord, 1, &Events);
        if(InputRecord.EventType == MOUSE_EVENT){
            if(InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED){
                x = InputRecord.Event.MouseEvent.dwMousePosition.X;
                y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
                break;
            }
        }
    }
    SetConsoleMode(hStdin, fdwSaveOldMode);
}
void XuatChuoiTiengViet(char str[])
{
    UINT def = GetConsoleOutputCP();
    SetConsoleOutputCP( 65001 );
    cout << str;
    SetConsoleOutputCP(def);
}
void VeMenuTrangChu(int x, int y, int loai)
{
    FILE *f;
    if(loai == 1){
        f = fopen("Design/choi.txt","r");
        for(int i = 0; i < 4; i++){
            gotoxy(x,y+i);
            for(int j = 0; j < 21; j++){
                char c = fgetc(f);
                DoiMauChu(lightyellow,black);
                cout<<c;
            }
        }
    }
    else
    if(loai == 2){
        f = fopen("Design/diemcao.txt","r");
        for(int i = 0; i < 4; i++){
            gotoxy(x,y+i);
            for(int j = 0; j < 40; j++){
                char c = fgetc(f);
                DoiMauChu(lightyellow,black);
                cout<<c;
            }
        }
    }
    else
    {
        f = fopen("Design/caidat.txt","r");
        for(int i = 0; i < 4; i++){
            gotoxy(x,y+i);
            for(int j = 0; j < 34; j++){
                char c = fgetc(f);
                DoiMauChu(lightyellow,black);
                cout<<c;
            }
        }
    }
    fclose(f);
    gotoend;
}
void VeFormChinh()
{
    system("cls");
    VeKhungChinh();
    VeLogoChinh();
    char gau[5];
    char gau2[5];
    strcpy(gau,"gau");
    strcpy(gau2,"gau2");

    VeHinhDoVang(gau,51,17,10,4);
    VeMenuTrangChu(61,17,1);
    VeHinhDoVang(gau2,82,17,10,4);

    VeHinhDoVang(gau,41,23,10,4);
    VeMenuTrangChu(51,23,2);
    VeHinhDoVang(gau2,91,23,10,4);

    VeHinhDoVang(gau,44,29,10,4);
    VeMenuTrangChu(54,29,3);
    VeHinhDoVang(gau2,88,29,10,4);
}
void VeKhungABCD(int x, int y, int mode)
{
    FILE *f = fopen("Design/cautraloi.art","r");
    FILE *f2 = fopen("Design/cautraloi.color","r");
    for(int i = 0; i < 6; i++){
        gotoxy(x,y+i);
        for(int j = 0; j < 40; j++){
            char c = fgetc(f);
            if(mode == 1){
                if(fgetc(f2) == '1') DoiMauChu(lightyellow,black);
                else DoiMauChu(lightred,black);
            }
            else if(mode == 2){
                if(fgetc(f2) == '1') DoiMauChu(lightyellow,black);
                else DoiMauChu(lightyellow,black);
            }
            else if(mode == 3){
                if(fgetc(f2) == '1') DoiMauChu(lightyellow,black);
                else DoiMauChu(green,black);
            }
            else if(mode == 4){
                if(fgetc(f2) == '1') DoiMauChu(gray,black);
                else DoiMauChu(gray,black);
            }
            switch(c){
            case '1':
                cout<<ch1; break;
            case '2':
                cout<<ch2; break;
            case '3':
                cout<<ch3; break;
            case '4':
                cout<<ch4; break;
            case '5':
                cout<<ch5; break;
            case '6':
                cout<<ch6; break;
            case '7':
                cout<<ch7; break;
            case '9':
                cout<<ch9; break;
            case '0':
                cout<<ch10; break;
            default:
                cout<<c;
            }
        }
    }
    fclose(f2);
    fclose(f);
    gotoend;
}
void VeHinhDoVang(char tenhinh[], int x, int y, int width, int height)
{
    char *s1 = new char;
    char *s2 = new char;
    strcpy(s1,"Design/");
    strcat(s1,tenhinh);
    strcat(s1,".art");
    strcpy(s2,"Design/");
    strcat(s2,tenhinh);
    strcat(s2,".color");
    FILE *f = fopen(s1,"r");
    FILE *f2 = fopen(s2,"r");
    for(int i = 0; i < height; i++){
        gotoxy(x,y+i);
        for(int j = 0; j < width; j++){
            char c = fgetc(f);
            if(fgetc(f2) == '1') DoiMauChu(lightyellow,black);
            else DoiMauChu(lightred,black);
            cout<<c;
        }
    }
    fclose(f2);
    fclose(f);
    gotoend;
}
void VeFormPhu()
{
    system("cls");
    VeKhungChinh();
    VeKhungPhu();
    char logophu[8]; strcpy(logophu,"logophu");
    VeHinhDoVang(logophu,21,2,67,4);
    VeQuyenTroGiup();
    VeThangDiem();
    VeNutQuayLai(8,3);
    gotoend;
}
void VeKhungCauHoi(int x, int y)
{
    FILE *f = fopen("Design/khungcauhoi.art","r");
    FILE *f2 = fopen("Design/khungcauhoi.color","r");
    for(int i = 0; i < 11; i++){
        gotoxy(x,y+i);
        for(int j = 0; j < 88; j++){
            char c = fgetc(f);
            if(fgetc(f2) == 'z') DoiMauChu(lightyellow,black);
                else DoiMauChu(lightyellow,black);
            switch(c){
            case '1':
                cout<<ch1; break;
            case '2':
                cout<<ch2; break;
            case '3':
                cout<<ch3; break;
            case '4':
                cout<<ch4; break;
            case '5':
                cout<<ch5; break;
            case '6':
                cout<<ch6; break;
            case '7':
                cout<<ch7; break;
            case '9':
                cout<<ch9; break;
            case '8':
                cout<<ch8; break;
            case '0':
                cout<<ch10; break;
            case 'a':
                cout<<ch11; break;
            default:
                cout<<c;
            }
        }
    }
    fclose(f2);
    fclose(f);
}
void VeBongBongChat(int x, int y, int huong, char noidung[])
{
    DoiMauChu(aqua,black);
    gotoxy(x,y); cout<<'.';
    for(int i = 0; i < 11; i++) cout<<(char)196;
    cout<<'.';
    gotoxy(x,y+1);
    cout<<(char)179;
    int l = strlen(noidung);
    for(int i = 0; i < (13-l)/2-1; i++) cout<<" ";
    XuatChuoiTiengViet(noidung);
    gotoxy(x+12,y+1); cout<<(char)179;
    gotoxy(x,y+2); cout<<'\'';
    for(int i = 0; i < 11; i++) cout<<(char)196;
    cout<<'\'';
    if(huong == 1){
        gotoxy(x+2, y+2);
        cout<<"//";
    }
    else if(huong == 2){
        gotoxy(x+9,y+2);
        cout<<"\\\\";
    }
    else{
        gotoxy(x+2,y);
        cout<<"\\\\";
    }
}
void VeQuyenTroGiup()
{
    gotoxy(118,2);
    char text[256];
    DoiMauChu(lightyellow,black);
    cout<<">> 50/50 <<";
    gotoxy(114,3);
    strcpy(text,">> Gọi người thân <<");
    XuatChuoiTiengViet(text);
    gotoxy(112,4);
    strcpy(text,">> Hỏi ý kiến khán giả <<");
    XuatChuoiTiengViet(text);
    gotoxy(114,5);
    strcpy(text,">> Tư vấn tại chỗ <<");
    XuatChuoiTiengViet(text);
    gotoxy(114,6);
    strcpy(text,">> Dừng cuộc chơi <<");
    XuatChuoiTiengViet(text);
}
void VeThangDiem()
{
    XoaKhuVuc(112,9,24,29);
    DoiMauChu(lightyellow,black);
    gotoxy(114,11); cout<<"14 > 85.000.000  VND";
    gotoxy(114,13); cout<<"13 > 60.000.000  VND";
    gotoxy(114,15); cout<<"12 > 40.000.000  VND";
    gotoxy(114,17); cout<<"11 > 30.000.000  VND";
    gotoxy(114,21); cout<<"9  > 14.000.000  VND";
    gotoxy(114,23); cout<<"8  > 10.000.000  VND";
    gotoxy(115,25); cout<<"7  > 6.000.000 VND";
    gotoxy(115,27); cout<<"6  > 3.000.000 VND";
    gotoxy(116,33); cout<<"3  > 600.000 VND";
    gotoxy(115,31); cout<<"4  > 1.000.000 VND";
    gotoxy(116,35); cout<<"2  > 400.000 VND";
    gotoxy(116,37); cout<<"1  > 200.000 VND";
    DoiMauChu(aqua,black);
    gotoxy(114,9); cout<<"15 > 150.000.000 VND";
    gotoxy(114,19); cout<<"10 > 22.000.000  VND";
    gotoxy(115,29); cout<<"5  > 2.000.000 VND";
}
void FocusDiem(int stt)
{
    switch(stt){
        case 1:
        {
            DoiMauChu(lightyellow,gray);
            gotoxy(112,37);
            cout<<"    ";
            cout<<"1  > 200.000 VND";
            cout<<"    ";break;
        }
        case 2:
        {
            DoiMauChu(lightyellow,gray);
            gotoxy(112,35);
            cout<<"    ";
            cout<<"2  > 400.000 VND";
            cout<<"    ";break;
        }
        case 3:
        {
            DoiMauChu(lightyellow,gray);
            gotoxy(112,33);
            cout<<"    ";
            cout<<"3  > 600.000 VND";
            cout<<"    ";break;
        }
        case 4:
        {
            DoiMauChu(lightyellow,gray);
            gotoxy(112,31);
            cout<<"   ";
            cout<<"4  > 1.000.000 VND";
            cout<<"   ";break;
        }
        case 5:
        {
            DoiMauChu(aqua,gray);
            gotoxy(112,29);
            cout<<"   ";
            cout<<"5  > 2.000.000 VND";
            cout<<"   ";break;
        }
        case 6:
        {
            DoiMauChu(lightyellow,gray);
            gotoxy(112,27);
            cout<<"   ";
            cout<<"6  > 3.000.000 VND";
            cout<<"   ";break;
        }
        case 7:
        {
            DoiMauChu(lightyellow,gray);
            gotoxy(112,25);
            cout<<"   ";
            cout<<"7  > 6.000.000 VND";
            cout<<"   ";break;
        }
        case 8:
        {
            DoiMauChu(lightyellow,gray);
            gotoxy(112,23);
            cout<<"  ";
            cout<<"8  > 10.000.000  VND";
            cout<<"  ";break;
        }
        case 9:
        {
            DoiMauChu(lightyellow,gray);
            gotoxy(112,21);
            cout<<"  ";
            cout<<"9  > 14.000.000  VND";
            cout<<"  ";break;
        }
        case 10:
        {
            DoiMauChu(aqua,gray);
            gotoxy(112,19);
            cout<<"  ";
            cout<<"10 > 22.000.000  VND";
            cout<<"  ";break;
        }
        case 11:
        {
            DoiMauChu(lightyellow,gray);
            gotoxy(112,17);
            cout<<"  ";
            cout<<"11 > 30.000.000  VND";
            cout<<"  ";break;
        }
        case 12:
        {
            DoiMauChu(lightyellow,gray);
            gotoxy(112,15);
            cout<<"  ";
            cout<<"12 > 40.000.000  VND";
            cout<<"  ";break;
        }
        case 13:
        {
            DoiMauChu(lightyellow,gray);
            gotoxy(112,13);
            cout<<"  ";
            cout<<"13 > 60.000.000  VND";
            cout<<"  ";break;
        }
        case 14:
        {
            DoiMauChu(lightyellow,gray);
            gotoxy(112,11);
            cout<<"  ";
            cout<<"14 > 85.000.000  VND";
            cout<<"  ";break;
        }
        case 15:
        {
            DoiMauChu(aqua,gray);
            gotoxy(112,9);
            cout<<"  ";
            cout<<"15 > 150.000.000 VND";
            cout<<"  ";break;
        }
    }
}
void SuDungQuyenTroGiup(int stt, char dapan, int &da1, int &da2)
{
    srand(time(NULL));
    DoiMauChu(gray,black);
    switch(stt){
        case 2:
        {
            GoiNguoiThan(dapan);
            break;
        }
        case 3:
        {
            HoiYKienKhanGia(dapan,da1,da2);
            break;
        }
        case 4:
        {
            TuVanTaiCho(dapan);
            break;
        }
        case 1:
        {
            NamMuoiNamMuoi(dapan,da1,da2);
            break;
        }
        default:
        {
            DoiMauQuyenTroGiup(5,gray);
            //DungCuocChoi(cauhientai);
        }
    }
}
int XuatChu(int x, int y, int width, char noidung[])
{
    wchar_t *wnoidung;
    int sodong=0;
    int nChars = MultiByteToWideChar(CP_UTF8, 0, noidung, -1, NULL, 0);
    wnoidung = new wchar_t[nChars];
    MultiByteToWideChar(CP_UTF8, 0, noidung, -1, (LPWSTR)wnoidung, nChars);
    int length = char_traits<wchar_t>::length (wnoidung);
    if(length <= width){
        gotoxy(x,y);
        _setmode(_fileno(stdout), 0x00020000);
        wcout<<wnoidung;
        _setmode(_fileno(stdout), _O_TEXT);
        return 1;
    }
    sodong = Xuat_wchar_t(x,y,width,wnoidung);
    delete[]wnoidung;
    return sodong;
}
int Xuat_wchar_t(int x, int y, int width, wchar_t wnoidung[])
{
    _setmode(_fileno(stdout), 0x00020000);
    int length = char_traits<wchar_t>::length (wnoidung);
    if(length > width){
        int i = width-1;
        while(wnoidung[i] != 32 && i > 0) i--;
        gotoxy(x,y);
        for(int j = 0; j < i; j++){
            wcout<<wnoidung[j];
        }
        return Xuat_wchar_t(x,y+1,width,wnoidung+i+1) + 1;
    }
    else{
        gotoxy(x,y);
        wcout<<wnoidung;
        _setmode(_fileno(stdout), _O_TEXT);
        return 1;
    }
}
void InCauHoi(CauHoi ch, int stt)
{
    int temp;
    VeKhungCauHoi(11,10);
    VeKhungABCD(12,23,2);
    VeKhungABCD(58,23,2);
    VeKhungABCD(12,32,2);
    VeKhungABCD(58,32,2);
    DoiMauChu(white,black);
    char nd[1000];
    switch(stt){
    case 1:
        strcpy(nd,"Câu 1: ");
        strcat(nd,ch.NoiDung);
        break;
    case 2:
        strcpy(nd,"Câu 2: ");
        strcat(nd,ch.NoiDung);
        break;
    case 3:
        strcpy(nd,"Câu 3: ");
        strcat(nd,ch.NoiDung);
        break;
    case 4:
        strcpy(nd,"Câu 4: ");
        strcat(nd,ch.NoiDung);
        break;
    case 5:
        strcpy(nd,"Câu 5: ");
        strcat(nd,ch.NoiDung);
        break;
    case 6:
        strcpy(nd,"Câu 6: ");
        strcat(nd,ch.NoiDung);
        break;
    case 7:
        strcpy(nd,"Câu 7: ");
        strcat(nd,ch.NoiDung);
        break;
    case 8:
        strcpy(nd,"Câu 8: ");
        strcat(nd,ch.NoiDung);
        break;
    case 9:
        strcpy(nd,"Câu 9: ");
        strcat(nd,ch.NoiDung);
        break;
    case 10:
        strcpy(nd,"Câu 10: ");
        strcat(nd,ch.NoiDung);
        break;
    case 11:
        strcpy(nd,"Câu 11: ");
        strcat(nd,ch.NoiDung);
        break;
    case 12:
        strcpy(nd,"Câu 12: ");
        strcat(nd,ch.NoiDung);
        break;
    case 13:
        strcpy(nd,"Câu 13: ");
        strcat(nd,ch.NoiDung);
        break;
    case 14:
        strcpy(nd,"Câu 14: ");
        strcat(nd,ch.NoiDung);
        break;
    case 15:
        strcpy(nd,"Câu 15: ");
        strcat(nd,ch.NoiDung);
        break;
    }
    XuatChu(23,15,64,nd);
    XuatChu(14,25,28,ch.A);
    XuatChu(60,25,28,ch.B);
    XuatChu(14,34,28,ch.C);
    XuatChu(60,34,28,ch.D);
    gotoend;
}
void XoaKhuVuc(int x, int y, int width, int height)
{
    DoiMauChu(white,black);
    for(int i = 0; i < height; i++){
        gotoxy(x,y+i);
        for(int j =0; j< width; j++) cout<<" ";
    }
}
int XetViTriClick(int x, int y, int form)
{
    if(form == 1){
        if(x>=51 && x <= 91 && y >= 17 && y <= 20) return 1;
        if(x>=41 && x <= 100 && y >= 23 && y <= 26) return 2;
        if(x>=44 && x <= 97 && y >= 29 && y <= 32) return 3;
        return -1;
    }
    if(form == 2){
        if(x>=12 && x <= 43 && y >= 23 && y <= 27) return 4; //nut a
        if(x>=58 && x <= 89 && y >= 23 && y <= 27) return 5; //nut b
        if(x>=12 && x <= 43 && y >= 32 && y <= 36) return 6; //nut c
        if(x>=58 && x <= 89 && y >= 32 && y <= 36) return 7; //nut d
        if(x>=118 && x <= 128 && y == 2) return 8; //50/50
        if(x>=114 && x <= 133 && y == 3) return 9; //goi nguoi than
        if(x>=112 && x <= 136 && y == 4) return 10; //hoi y kien khan gia
        if(x>=114 && x <= 133 && y == 5) return 11; //tu van tai cho
        if(x>=114 && x <= 133 && y == 6) return 12; //dung cuoc choi
        if(x>=8 && x <= 16 && y >= 4 && y <= 6) return 13; // quay lai
        if(x>=116 && x<=132 && y>= 35 ) return 50;
        return -1;
    }
    if(form == 3){
        if(x>=8 && x <= 16 && y >= 35 && y <= 37) return 14; //nut back
        return -1;
    }
    if(form == 4){
        if(x>=8 && x <= 16 && y >= 35 && y <= 37) return 15; //nut back

        if(x>=9 && x <= 33 && y >= 4 && y <= 6) return 16;  //them cau hoi
        if(x>=9 && x <= 33 && y >= 9 && y <= 11) return 17; //xoa cau hoi
        if(x>=9 && x <= 33 && y >= 14 && y <= 16) return 18; //sua cau hoi
        if(x>=9 && x <= 33 && y >= 19 && y <= 21) return 19; //reset diem

        if(x>=47 && x <= 72 && y >= 4 && y <= 6) return 20; //nut cau hoi de
        if(x>=77 && x <= 101 && y >= 4 && y <= 6) return 21; // cau hoi trung binh
        if(x>=106 && x <= 130 && y >= 4 && y <= 6) return 22; //cau hoi kho
        return -1;
    }
    return -1;
}
void DoiMauDapAn(int dapanchon, int mode, CauHoi ch)
{
    if(dapanchon == 3){
        VeKhungABCD(12,32,mode);
        XuatChu(14,34,28,ch.C);
    }
    if(dapanchon == 4){
         VeKhungABCD(58,32,mode);
         XuatChu(60,34,28,ch.D);
    }
    if(dapanchon == 1){
        VeKhungABCD(12,23,mode);
        XuatChu(14,25,28,ch.A);
    }
    if(dapanchon == 2){
        VeKhungABCD(58,23,mode);
        XuatChu(60,25,28,ch.B);
    }
    gotoend;
}
void DoiMauQuyenTroGiup(int stt, int mau)
{
    char text[256];
    if(mau == yellow){
        DoiMauChu(yellow,black);
    }
    else{
        DoiMauChu(gray, black);
    }
    switch(stt){
        case 2:
            gotoxy(114,3);
            strcpy(text,">> Gọi người thân <<");
            XuatChuoiTiengViet(text);
            break;
        case 3:
            gotoxy(112,4);
            strcpy(text,">> Hỏi ý kiến khán giả <<");
            XuatChuoiTiengViet(text);
            break;
        case 4:
            gotoxy(114,5);
            strcpy(text,">> Tư vấn tại chỗ <<");
            XuatChuoiTiengViet(text);
            break;
        case 1:
            gotoxy(118,2);
            cout<<">> 50/50 <<";
            break;
        default:
            gotoxy(114,6);
            strcpy(text,">> Dừng cuộc chơi <<");
            XuatChuoiTiengViet(text);
    }
}
void NamMuoiNamMuoi(char dapan, int &da1, int &da2)
{
    DoiMauQuyenTroGiup(1,gray);
    if(dapan == 'A'){
        int t = rand()%3;
        if(t == 0){
            VeKhungABCD(12,32,4); //C
            VeKhungABCD(58,32,4); //D
            da1 = 1;
            da2 = 2;
        }
        else if(t == 1){
            VeKhungABCD(58,23,4); //B
            VeKhungABCD(58,32,4); //D
            da1 = 1;
            da2 = 3;
        }
        else if(t == 2){
            VeKhungABCD(12,32,4); //C
            VeKhungABCD(58,23,4); //B
            da1 = 1;
            da2 = 4;
        }
    }
    if(dapan == 'B'){
        int t = rand()%3;
        if(t == 0){
            VeKhungABCD(12,32,4); //C
            VeKhungABCD(58,32,4); //D
            da1 = 1;
            da2 = 2;
        }
        else if(t == 1){
            VeKhungABCD(58,32,4); //D
            VeKhungABCD(12,23,4); //A
            da1 = 2;
            da2 = 3;
        }
        else if(t == 2){
            VeKhungABCD(12,32,4); //C
            VeKhungABCD(12,23,4); //A
            da1 = 2;
            da2 = 4;
        }
    }
    if(dapan == 'C'){
        int t = rand()%3;
        if(t == 0){
            VeKhungABCD(58,23,4); //B
            VeKhungABCD(58,32,4); //D
            da1 = 1;
            da2 = 3;
        }
        else if(t == 1){
            VeKhungABCD(58,32,4); //D
            VeKhungABCD(12,23,4); //A
            da1 = 2;
            da2 = 3;
        }
        else if(t == 2){
            VeKhungABCD(58,23,4); //B
            VeKhungABCD(12,23,4); //A
            da1 = 3;
            da2 = 4;
        }
    }
    if(dapan == 'D'){
        int t = rand()%3;
        if(t == 0){
            VeKhungABCD(12,32,4); //C
            VeKhungABCD(58,23,4); //B
            da1 = 1;
            da2 = 4;
        }
        else if(t == 1){
            VeKhungABCD(12,32,4); //C
            VeKhungABCD(12,23,4); //A
            da1 = 2;
            da2 = 4;
        }
        else if(t == 2){
            VeKhungABCD(58,23,4); //B
            VeKhungABCD(12,23,4); //A
            da1 = 3;
            da2 = 4;
        }
    }
}
void GoiNguoiThan(char dapan)
{
    DoiMauQuyenTroGiup(2,gray);
    DoiMauChu(aqua,black);
    MoKhoaConTroChuot();
    char nguoithan[1000];
    gotoxy(44,10);
    char text[256];strcpy(text,"- Bạn muốn gọi ai?");
    XuatChuoiTiengViet(text);
    gotoxy(44,11);
    cout<<"- ";
    gets(nguoithan);
    KhoaConTroChuot();
    int t = rand()%10;
    XoaKhuVuc(28,10,60,2);
    DoiMauChu(aqua,black);
    gotoxy(42,10);
    if(t <= 7){
        strcat(nguoithan," chọn đáp án ");
        if(dapan == 'A') strcat(nguoithan,"A");
        if(dapan == 'B') strcat(nguoithan,"B");
        if(dapan == 'C') strcat(nguoithan,"C");
        if(dapan == 'D') strcat(nguoithan,"D");
        XuatChuoiTiengViet(nguoithan);
    }
    else{
        strcpy(nguoithan," chọn đáp án ");
        if(dapan == 'A') strcat(nguoithan,"D");
        if(dapan == 'B') strcat(nguoithan,"C");
        if(dapan == 'C') strcat(nguoithan,"B");
        if(dapan == 'D') strcat(nguoithan,"A");
        XuatChuoiTiengViet(nguoithan);
    }

}
void TuVanTaiCho(char dapan)
{
    char a[10],b[10],c[10],d[10];
    strcpy(a,"Chọn A");strcpy(b,"Chọn B");strcpy(c,"Chọn C");strcpy(d,"Chọn D");
    DoiMauQuyenTroGiup(4,gray);
    if(dapan =='A')
    {
        VeBongBongChat(20,9,1,a);
        VeBongBongChat(81,9,2,a);
        VeBongBongChat(21,20,3,c);
    }
    if(dapan =='B')
    {
        VeBongBongChat(20,9,1,b);
        VeBongBongChat(81,9,2,a);
        VeBongBongChat(21,20,3,b);
    }
    if(dapan =='C')
    {
        VeBongBongChat(20,9,1,d);
        VeBongBongChat(81,9,2,c);
        VeBongBongChat(21,20,3,c);
    }
    if(dapan =='D')
    {
        VeBongBongChat(20,9,1,a);
        VeBongBongChat(81,9,2,d);
        VeBongBongChat(21,20,3,d);
    }
}
void HoiYKienKhanGia(char dapan, int da1, int da2)
{
    gotoxy(112,4);
    char text[256];
    strcpy(text,">> Hỏi ý kiến khán giả <<");
    XuatChuoiTiengViet(text);
    int a,b,c,d;
    a = rand()%100;
    b = rand()%100;
    c = rand()%100;
    d = rand()%100;
    if(dapan == 'A') a*=2;
    else if(dapan == 'B') b*=2;
    else if(dapan == 'C') c*=2;
    else d*=2;
    if(da1 == 1){
        if(da2 == 2){c=0;d=0;}
        if(da2 == 3){b=0;d=0;}
        if(da2 == 4){b=0;c=0;}
    }else if(da1 == 2){
        if(da2 == 1){c=0;d=0;}
        if(da2 == 3){a=0;d=0;}
        if(da2 == 4){a=0;c=0;}
    }else if(da1 == 3){
        if(da2 == 1){b=0;d=0;}
        if(da2 == 2){a=0;d=0;}
        if(da2 == 4){a=0;b=0;}
    }else if(da1 == 4){
        if(da2 == 1){b=0;c=0;}
        if(da2 == 2){a=0;c=0;}
        if(da2 == 3){a=0;b=0;}
    }
    int sum = a+b+c+d;
    int phantramA = 100*a/sum;
    int phantramB = 100*b/sum;
    int phantramC = 100*c/sum;
    int phantramD = 100 - phantramA - phantramB - phantramC;
    char noidung[50];
    itoa(phantramA,noidung,10);
    strcat(noidung,"% Chọn A");
    VeBongBongChat(44,21,1,noidung);
    itoa(phantramB,noidung,10);
    strcat(noidung,"% Chọn B");
    VeBongBongChat(90,21,1,noidung);
    itoa(phantramC,noidung,10);
    strcat(noidung,"% Chọn C");
    VeBongBongChat(44,30,1,noidung);
    itoa(phantramD,noidung,10);
    strcat(noidung,"% Chọn D");
    VeBongBongChat(90,30,1,noidung);
}
void ClearTroGiupCu()
{
    XoaKhuVuc(44,21,13,3);
    XoaKhuVuc(90,21,13,3);
    XoaKhuVuc(20,9,13,3);
    XoaKhuVuc(81,9,13,3);
    XoaKhuVuc(21,20,13,3);
    XoaKhuVuc(44,30,13,3);
    XoaKhuVuc(90,30,13,3);
    XoaKhuVuc(28,10,60,2);
}
void DungCuocChoi(int cauhientai)
{
    XoaKhuVuc(8,9,91,29);
    VeKhungCauHoi(11,14);
    char cauhoi[3];
    itoa(cauhientai,cauhoi,10);
    char tienthuong[100];
    char noidung[1000];
    char name[100];
    switch(cauhientai){
    case 5: strcpy(tienthuong,"2.000.000"); break;
    case 6: strcpy(tienthuong,"3.000.000"); break;
    case 7: strcpy(tienthuong,"6.000.000"); break;
    case 8: strcpy(tienthuong,"10.000.000"); break;
    case 9: strcpy(tienthuong,"14.000.000"); break;
    case 10: strcpy(tienthuong,"22.000.000"); break;
    case 11: strcpy(tienthuong,"30.000.000"); break;
    case 12: strcpy(tienthuong,"40.000.000"); break;
    case 13: strcpy(tienthuong,"60.000.000"); break;
    case 14: strcpy(tienthuong,"85.000.000"); break;
    case 15: strcpy(tienthuong,"150.000.000"); break;
    default: strcpy(tienthuong,"0");
    }
    if(cauhientai >= 5)
    {
        strcpy(noidung,"Chúc mừng bạn đã chiến thắng ở câu số ");
        strcat(noidung,cauhoi);
        strcat(noidung,"!!");
    }
    else
    {
        strcpy(noidung,"Rất tiếc, bạn đã trả lời sai ở câu số ");
        strcat(noidung,cauhoi);
        strcat(noidung,"!!");
    }
    gotoxy(24,19);
    DoiMauChu(aqua,black);
    XuatChuoiTiengViet(noidung);
    strcpy(noidung,"Tổng số tiền thưởng bạn nhận được là ");
    strcat(noidung,tienthuong);
    strcat(noidung," VNĐ.");
    gotoxy(24,20);
    XuatChuoiTiengViet(noidung);
    if(cauhientai > 0){
        gotoxy(24,21);
        XuatChuoiTiengViet("Mời bạn nhập tên: ");
        MoKhoaConTroChuot();
        gets(name);
        KhoaConTroChuot();
        User user;
        user.Diem =cauhientai;
        strcpy(user.Name, name);
        strcat(user.Name,"\n");
        User users[10];
        LoadFileNguoiChoi("Users.dat", users);
        ThemNguoiChoi(users,user);
    }
    else Sleep(2500);
}
void VeFormDiemCao()
{
    system("cls");
    VeKhungChinh();
    VeLogoChinh();
    VeNutQuayLai(8,34);
    User users[10];
    LoadFileNguoiChoi("Users.dat",users);
    for(int i = 0; i < 5; i++){
        char *name=new char;
        strcpy(name,"-------");
        strcat(name,users[i].Name);
        int strl = strlen(name);
        name[strl-1] = '-';
        strcat(name,"------");
        if(strlen(users[i].Name)%2 == 0) strcat(name,"-");
        InChuCanhGiua(3,16 + 4*i,135,name);
        switch(users[i].Diem){
            case 5: InChuCanhGiua(3,17 + 4*i,135,"2.000.000 VND"); break;
            case 6: InChuCanhGiua(3,17 + 4*i,135,"3.000.000 VND"); break;
            case 7: InChuCanhGiua(3,17 + 4*i,135,"6.000.000 VND"); break;
            case 8: InChuCanhGiua(3,17 + 4*i,135,"10.000.000  VND"); break;
            case 9: InChuCanhGiua(3,17 + 4*i,135,"14.000.000  VND"); break;
            case 10: InChuCanhGiua(3,17 + 4*i,135,"22.000.000  VND"); break;
            case 11: InChuCanhGiua(3,17 + 4*i,135,"30.000.000  VND"); break;
            case 12: InChuCanhGiua(3,17 + 4*i,135,"40.000.000  VND"); break;
            case 13: InChuCanhGiua(3,17 + 4*i,135,"60.000.000  VND"); break;
            case 14: InChuCanhGiua(3,17 + 4*i,135,"85.000.000  VND"); break;
            case 15: InChuCanhGiua(3,17 + 4*i,135,"150.000.000 VND"); break;
            default: InChuCanhGiua(3,17 + 4*i,135,"0 VND");
        }
    }
}
void InChuCanhGiua(int x, int y, int width, char noidung[])
{
    int vitri = (width - strlen(noidung))/2;
    gotoxy(x+vitri,y);
    XuatChuoiTiengViet(noidung);
}
void VeNutQuayLai(int x, int y)
{
    DoiMauChu(lightyellow,black);
    gotoxy(x+2,y-1); cout<<"__";
    gotoxy(x+1,y); cout<<"/ /____";
    gotoxy(x,y+1); cout<<"< < ____|";
    gotoxy(x+1,y+2); cout<<"\\_\\";
    gotoxy(x+4,y+2); cout<<"Back";
}
void VeFormCaiDat()
{
    system("cls");
    VeKhungChinh();
    VeNutQuayLai(8,34);
    VeMenuCaiDat(8,4,lightyellow,"  THÊM CÂU HỎI MỚI");
    VeMenuCaiDat(8,9,lightyellow,"    XÓA CÂU HỎI");
    VeMenuCaiDat(8,14,lightyellow,"    SỬA CÂU HỎI");
    VeMenuCaiDat(8,19,lightyellow," RESET BẢNG XẾP HẠNG");
    VeMenuCaiDat(47,4,lightyellow,"     CÂU HỎI DỄ");
    VeMenuCaiDat(76,4,lightyellow," CÂU HỎI TRUNG BÌNH");
    VeMenuCaiDat(105,4,lightyellow,"     CÂU HỎI KHÓ");
    gotoxy(34,1);
    DoiMauChu(lightred,black);
    cout<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9;
    gotoxy(34,2);
    cout<<ch4<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch3;
    gotoxy(36,3);
    cout<<ch4<<ch6<<ch9<<ch6<<ch9<<ch6<<ch3;
    for(int i = 0; i < HEIGHT - 6; i++){
        gotoxy(38,i+4);
        cout<<ch8<<ch6<<ch11;
    }
    gotoxy(34,HEIGHT-1);cout<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9;
    gotoxy(34,HEIGHT-2);cout<<ch5<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch9<<ch6<<ch2;
    gotoxy(36,HEIGHT-3);cout<<ch5<<ch6<<ch9<<ch6<<ch9<<ch6<<ch2;

}
void VeMenuCaiDat(int x, int y, int color, char noidung[])
{
    DoiMauChu(color,black);
    gotoxy(x+2,y); cout<<"//";
    for(int i = 0; i < 20; i++) cout<<ch6; cout<<"//";
    gotoxy(x+1,y+1); cout<<"//";
    XuatChuoiTiengViet(noidung);
    gotoxy(x+23,y+1); cout<<"//";
    gotoxy(x,y+2); cout<<"//";
    for(int i = 0; i < 20; i++) cout<<ch6;
    cout<<"//";
}
void HienDanhSachCauHoi(TREE t, int trang)
{
    XoaKhuVuc(47,8,89,31);
    DoiMauChu(white,black);
    int x=47, y=8;
    for(int i = 1; i <= 10; i++){
        char noidung[1000];
        Node *p = TimKiemCauHoi(t,trang*10 + i);
        if(p != NULL){
            itoa(p->data.so,noidung,10);
            strcat(noidung," - ");
            strcat(noidung,p->data.NoiDung);
            int sodong = XuatChu(x,y,86,noidung);
            y+=sodong+1;
        }
    }
    gotoxy(x+80,y+1);
    int dem = demnode(t);
    int sotrang = dem/10;
    if(dem%10!=0) sotrang+=1;
    cout<<"Trang "<<trang+1<<"/"<<sotrang;
}
void MenuXuLyDanhSach(int &id, int &trang, int sotrang)
{
    DoiMauChu(aqua,black);
    gotoxy(47,37);
    XuatChuoiTiengViet("Nhập mã câu hỏi hoặc '0'để xem trang kế tiếp '-1' để quay lại trang trước:");
    MoKhoaConTroChuot();
    scanf("%d",&id);
    KhoaConTroChuot();
    fflush(stdin);
    if(id == 0 && trang < sotrang) trang++;
    if(id == -1 && trang > 0) trang--;
}
void XuLyThemCauHoi()
{
    VeMenuCaiDat(8,4,lightgreen,"  THÊM CÂU HỎI MỚI");
    XoaKhuVuc(47,8,88,29);
    int dokho = 1;
    DoiMauChu(aqua,black);
    XuatChu(72,8,85,"========[ NHẬP CÂU HỎI MỚI ]========");
    //gotoxy(72,8); XuatChuoiTiengViet("========[ NHẬP CÂU HỎI MỚI ]========");
    CauHoi cauhoi;
    XuatChu(47,10,85,"Nhập nội dung câu hỏi: ");
    gotoxy(47,11);
    DoiMauChu(white,black);
    NhapChuoiTiengViet(cauhoi.NoiDung);
    strcat(cauhoi.NoiDung,"\n");

    DoiMauChu(aqua,black);
    XuatChu(47,13,85,"Nhập đáp án A (Bắt đầu bằng 'A. '): ");
    DoiMauChu(white,black);
    gotoxy(47,14);
    NhapChuoiTiengViet(cauhoi.A);
    strcat(cauhoi.A,"\n");

    DoiMauChu(aqua,black);
    XuatChu(47,16,85,"Nhập đáp án B (Bắt đầu bằng 'B. '): ");
    DoiMauChu(white,black);
    gotoxy(47,17);
    NhapChuoiTiengViet(cauhoi.B);
    strcat(cauhoi.B,"\n");

    DoiMauChu(aqua,black);
    XuatChu(47,19,85,"Nhập đáp án C (Bắt đầu bằng 'C. '): ");
    DoiMauChu(white,black);
    gotoxy(47,20);
    NhapChuoiTiengViet(cauhoi.C);
    strcat(cauhoi.C,"\n");

    DoiMauChu(aqua,black);
    XuatChu(47,22,85,"Nhập đáp án D (Bắt đầu bằng 'D. '): ");
    DoiMauChu(white,black);
    gotoxy(47,23);
    NhapChuoiTiengViet(cauhoi.D);
    strcat(cauhoi.D,"\n");

    DoiMauChu(aqua,black);
    XuatChu(47,25,85,"Nhập đáp án đúng (Chỉ nhập 1 ký tự 'A','B','C' hoặc 'D'): ");
    DoiMauChu(white,black);
    gotoxy(47,26);
    scanf("%c",&cauhoi.DapAn);

    DoiMauChu(aqua,black);
    XuatChu(47,28,85,"Nhập độ khó (1.Dễ, 2.Trung bình, 3.Khó):");
    DoiMauChu(white,black);
    gotoxy(47,29);
    scanf("%d",&dokho);
    fflush(stdin);

    DoiMauChu(aqua,black);
    XuatChu(47,31,85,"Lưu câu hỏi?(nhập 'yes' hoặc 'no'): ");
    DoiMauChu(white,black);
    gotoxy(47,32);
    char luu[5];
    gets(luu);
    KhoaConTroChuot();

    TREE t = NULL;
    if(strcmpi(luu,"yes") == 0){
        char filename[20];
        if(dokho == 1)strcpy(filename,"Goi1.dat");
        else if(dokho == 2) strcpy(filename,"Goi2.dat");
        else strcpy(filename,"Goi3.dat");
        LoadFileCauHoi(t,filename);
        int n = demnode(t);
        cauhoi.so = n+1;
        if(InsertNode(t,cauhoi) >= 1){
            if(GhiFileCauHoi(t,filename)){
                DoiMauChu(yellow,black);
                XuatChu(47,34,85,"Thêm thành công!! Bấm phím bất kỳ để tiếp tục.");
            }
            else{
                DoiMauChu(lightred,black);
                XuatChu(47,34,85,"Lỗi ghi file!! Bấm phím bất kỳ để tiếp tục.");
            }
        }
        else{
            DoiMauChu(lightred,black);
            XuatChu(47,34,85,"Xảy ra lỗi trong quá trình thêm!! Bấm phím bất kỳ để tiếp tục.");
        }
    }
    else{
        DoiMauChu(yellow,black);
        XuatChu(47,34,85,"Câu hỏi mới không được thêm! Bấm phím bất kỳ để tiếp tục.");
    }
    getch();
    VeMenuCaiDat(8,4,lightyellow,"  THÊM CÂU HỎI MỚI");
}
void KhoaConTroChuot()
{
    HANDLE hout= GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 25;
    cci.bVisible = FALSE; //hiện con trỏ chuột
    SetConsoleCursorInfo(hout, &cci); //thiết lập hiển thị con trỏ chuột để nhập dữ liệu
}
void MoKhoaConTroChuot()
{
    HANDLE hout= GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 25;
    cci.bVisible = TRUE; //hiện con trỏ chuột
    SetConsoleCursorInfo(hout, &cci); //thiết lập hiển thị con trỏ chuột để nhập dữ liệu
}
void XuLySuaCauHoi(TREE &t, int goi)
{

    int dem = demnode(t);
    int sotrang = dem/10;
    if(dem%10!=0) sotrang+=1;
    int id = 0, trang = 0;
    do{
        HienDanhSachCauHoi(t,trang);
        MenuXuLyDanhSach(id, trang, sotrang);
    }while(id <= 0);
    Node *p = TimKiemCauHoi(t,id);
    if(p != NULL){
        int tt=0,chon = 0;
        XoaKhuVuc(47,8,89,29);
        tt += XuatChu(47,8,88,p->data.NoiDung);
        XuatChu(50,10+tt-1,86,p->data.A);
        tt += XuatChu(80,10+tt-1,86,p->data.B);
        XuatChu(50,11+tt-1,86,p->data.C);
        tt += XuatChu(80,11+tt-1,86,p->data.D);
        tt += XuatChu(49,12+tt-1,86," Đáp án: ");
        printf("%c",p->data.DapAn);

        DoiMauChu(aqua,black);
        tt += XuatChu(47,14+tt,86,"Chọn phần muốn sửa:");
        XuatChu(50,15+tt,86,"1.Nội Dung.");
        XuatChu(90,15+tt,86,"7.Thoát.");
        tt += XuatChu(70,15+tt,86,"4.Câu C.");
        XuatChu(50,16+tt,86,"2.Câu A.");
        tt += XuatChu(70,16+tt,86,"5.Câu D.");
        XuatChu(50,17+tt,86,"3.Câu B.");
        tt += XuatChu(70,17+tt,86,"6.Đáp án.");
        XoaKhuVuc(47,37,86,1);
        MoKhoaConTroChuot();
        gotoxy(50,18+tt);
        scanf("%d",&chon);
        fflush(stdin);
        if(chon == 1){
            tt += XuatChu(50,20+tt,40,"Nhập nội dung mới:");
            gotoxy(50,20+tt);
            NhapChuoiTiengViet(p->data.NoiDung);
            strcat(p->data.NoiDung,"\n");
        }
        else if(chon == 2){
            tt += XuatChu(50,20+tt,80,"Nhập nội dung câu A(Bắt đầu bằng 'A. '): ");
            gotoxy(50,20+tt);
            NhapChuoiTiengViet(p->data.A);
            strcat(p->data.A,"\n");
        }
        else if(chon == 3){
            tt += XuatChu(50,20+tt,80,"Nhập nội dung câu B (Bắt đầu bằng 'B. '): ");
            gotoxy(50,20+tt);
            NhapChuoiTiengViet(p->data.B);
            strcat(p->data.B,"\n");
        }
        else if(chon == 4){
            tt += XuatChu(50,20+tt,80,"Nhập nội dung câu C (Bắt đầu bằng 'C. '): ");
            gotoxy(50,20+tt);
            NhapChuoiTiengViet(p->data.C);
            strcat(p->data.C,"\n");
        }
        else if(chon == 5){
            tt += XuatChu(50,20+tt,80,"Nhập nội dung câu D (Bắt đầu bằng 'D. '): ");
            gotoxy(50,20+tt);
            NhapChuoiTiengViet(p->data.D);
            strcat(p->data.D,"\n");
        }
        else if(chon == 6){
            tt += XuatChu(50,20+tt,80,"Nhập đáp án mới (chỉ nhập một trong các ký tự 'A','B','C' hoặc 'D'): ");
            gotoxy(50,20+tt);
            scanf("%c",&p->data.DapAn);
            fflush(stdin);
        }
        if(chon != 7){
            char luu[10];
            int status=0;
            XuatChu(50,21+tt,80,"Nhập 'yes' để lưu, 'no' để thoát: ");
            gets(luu);
            if(strcmpi(luu,"yes")==0){
                if(goi == 1)
                {
                    Update(t,p->data);
                    if(GhiFileCauHoi(t,"Goi1.dat")) status = 1;
                }
                else if(goi == 2)
                {
                    Update(t,p->data);
                    if(GhiFileCauHoi(t,"Goi2.dat")) status = 1;
                }
                else if(goi == 3){
                    Update(t,p->data);
                    if(GhiFileCauHoi(t,"Goi3.dat")) status = 1;
                }
            }
            if(status == 1){
                DoiMauChu(yellow,black);
                XuatChu(50,22+tt,80,"Đã cập nhật thành công! Nhấn phím bất kỳ để tiếp tục.");
            }
            else{
                DoiMauChu(lightred,black);
                XuatChu(50,22+tt,80,"Lỗi trong quá trình cập nhật! Nhấn phím bất kỳ để tiếp tục.");
            }
        }
        else{
            DoiMauChu(lightred,black);
            XuatChu(50,22+tt,80,"Câu hỏi không được cập nhật! Nhấn phím bất kỳ để tiếp tục.");
        }
        getch();
        KhoaConTroChuot();
    }
    else
    {
        XoaKhuVuc(47,8,89,29);
        DoiMauChu(lightred,black);
        XuatChu(50,9,80,"Câu hỏi không tồn tại! Nhấn phím bất kỳ để tiếp tục.");
        getch();
    }
}
void XuLyXoaCauHoi(TREE &t, int goi)
{
    int dem = demnode(t);
    int sotrang = dem/10;
    if(dem%10!=0) sotrang+=1;
    int id = 0, trang = 0;
    do{
        HienDanhSachCauHoi(t,trang);
        MenuXuLyDanhSach(id, trang, sotrang);
    }while(id <= 0);
    Node *p = TimKiemCauHoi(t,id);
    if(p != NULL){

        int tt=0,chon = 0;
        XoaKhuVuc(47,8,89,29);
        tt += XuatChu(47,8,88,p->data.NoiDung);
        XuatChu(50,10+tt-1,86,p->data.A);
        tt += XuatChu(80,10+tt-1,86,p->data.B);
        XuatChu(50,11+tt-1,86,p->data.C);
        tt += XuatChu(80,11+tt-1,86,p->data.D);
        tt += XuatChu(49,12+tt-1,86," Đáp án: ");
        printf("%c",p->data.DapAn);

        MoKhoaConTroChuot();
        char luu[10];
        DoiMauChu(aqua,black);
        XuatChu(50,14+tt,86,"Nhập 'yes' để xoá, 'no' để thoát: ");
        gets(luu);
        if(strcmpi(luu,"yes")==0){
            DeleteNode(t,id);
            char filename[100];
            if(goi == 1)        strcpy(filename,"Goi1.dat");
            else if(goi == 2)   strcpy(filename,"Goi2.dat");
            else if(goi == 3)   strcpy(filename,"Goi3.dat");

            if(GhiFileCauHoi(t,filename)){
                DoiMauChu(yellow,black);
                XuatChu(50,16+tt,85,"Đã cập nhật thành công! Nhấn phím bất kỳ để tiếp tục.");
            }
            else{
                DoiMauChu(lightred,black);
                XuatChu(50,16+tt,85,"Lỗi trong quá trình cập nhật! Nhấn phím bất kỳ để tiếp tục.");
            }
        }
        else{
            DoiMauChu(lightred,black);
            XuatChu(50,16+tt,85,"Câu hỏi không được cập nhật! Nhấn phím bất kỳ để tiếp tục.");
        }
        getch();
        KhoaConTroChuot();
    }
}
void XuLyResetBangXepHang()
{
    User users[6];
    users[0].Diem = 0;
    strcpy(users[0].Name,"N/A\n");
    users[1].Diem = 0;
    strcpy(users[1].Name,"N/A\n");
    users[2].Diem = 0;
    strcpy(users[2].Name,"N/A\n");
    users[3].Diem = 0;
    strcpy(users[3].Name,"N/A\n");
    users[4].Diem = 0;
    strcpy(users[4].Name,"N/A\n");
    if(GhiFileNguoiChoi("Users.dat",users)){
        gotoxy(47,8);
        DoiMauChu(yellow,black);
        XuatChuoiTiengViet(" Đã cập nhật danh sách. Bấm phím bất kỳ để tiếp tục.");
        getch();
    }
    else{
        gotoxy(47,8);
        DoiMauChu(lightred,black);
        XuatChuoiTiengViet("Lỗi cập nhật file. Bấm phím bất kỳ để tiếp tục.");
        getch();
    }
}
void NhapChuoiTiengViet(char str[])
{
    MoKhoaConTroChuot();
    wstring text;
    _setmode(_fileno(stdin), 0x00020000);
    getline(wcin,text);
    wcin.ignore();
    string temp = to_utf8(text);
    strcpy(str,temp.c_str());
    _setmode(_fileno(stdin), _O_TEXT);
    KhoaConTroChuot();
}



