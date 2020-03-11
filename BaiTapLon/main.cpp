#include "xuly.h"
#include "giaodien.h"
int main()
{
    while(true){
        TREE t = NULL;
        int trogiup[] = {1,1,1,0,0};
        int x,y, cauhientai = 1, vitri = -1, form = 1, moc1 = 0, moc2 = 0, moc3 = 0, check = 0;
        bool traloisai = false;
        VeFormChinh();
        while(vitri < 0){
            Click(x,y);
            vitri = XetViTriClick(x,y,form);
        }
        if(vitri == 1){
            form = 2;
            bool thuacuoc = false;
            int a[10];
            int n,i, da1 = 0, da2 = 0;
            VeFormPhu();
            while(!thuacuoc){
                srand(time(NULL));
                if(cauhientai == 1)
                {
                    if(moc1 == 0){

                        n = LoadFileCauHoi(t,"Goi1.dat");
                        Random5SoKhongTrung(a,n);
                        i=0;
                        DoiMauQuyenTroGiup(4,gray);
                        DoiMauQuyenTroGiup(5,gray);
                        moc1 = 1;
                    }
                }
                else if(cauhientai == 6)
                {
                    if(moc2 == 0){
                        t = NULL;
                        n = LoadFileCauHoi(t,"Goi2.dat");
                        Random5SoKhongTrung(a,n);
                        i=0;
                        trogiup[3] = 1;
                        trogiup[4] = 1;
                        VeQuyenTroGiup();
                        for(int i = 0; i < 5; i++){
                            if(trogiup[i] == 0) DoiMauQuyenTroGiup(i+1,gray);
                        }
                        moc2 = 1;
                    }
                }
                else if(cauhientai == 11)
                {
                    if(moc3 == 0){
                        t = NULL;
                        n = LoadFileCauHoi(t,"Goi3.dat");
                        Random5SoKhongTrung(a,n);
                        i=0;
                        moc3 = 1;
                    }
                }
                Node *p;
                if(check == 0){
                    ClearTroGiupCu();
                    VeThangDiem();
                    FocusDiem(cauhientai);
                    p = TimKiemCauHoi(t,a[i]);
                    InCauHoi(p->data,cauhientai);
                    check = 1;
                }
                int chondapan = 0, chontrogiup = 0;
                do{
                    Click(x,y);
                    vitri = XetViTriClick(x,y,form);
                    if(vitri >= 4 && vitri <= 7){
                        chondapan = vitri - 3;
                    }
                    else if(vitri >= 8 && vitri <= 12){
                        if(trogiup[vitri-8] == 1){
                            chontrogiup = vitri - 7;
                            trogiup[vitri-8] = 0;
                        }
                    }
                    else if(vitri == 13){
                        thuacuoc = true;
                        form = 1;
                    }
                    else if(vitri == 50)
                    {
                        DoiMauChu(yellow,red);
                        gotoxy(116,35); cout<<"2  > 400.000 VND";
                    }
                }while(chondapan == 0 && chontrogiup == 0 && vitri != 13);
                if(chontrogiup == 0){
                    DoiMauDapAn(chondapan,3,p->data);
                    Sleep(100);
                    thuacuoc = !XetDungSai(p->data, chondapan);
                    if(!thuacuoc)cauhientai++;
                    else
                    {
                        DoiMauDapAn(chondapan,1,p->data);
                        thuacuoc = true;
                        traloisai = true;
                        form = 1;
                    }
                    Sleep(100);
                    i++;
                    check = 0;
                }
                else if(chondapan == 0){
                    if(chontrogiup == 5)
                    {
                        form = 1;
                        thuacuoc = true;
                    }
                    SuDungQuyenTroGiup(chontrogiup, p->data.DapAn, da1, da2);
                }
                if(cauhientai == 16) thuacuoc = true;
            }
            if(traloisai == true){
                if(cauhientai > 5 && cauhientai < 10) cauhientai = 5;
                else if(cauhientai > 10) cauhientai = 10;
                if(cauhientai >= 5)
                    DungCuocChoi(cauhientai);
                //else DungCuocChoi(0);
            }
            else{
                if(cauhientai == 16)
                    DungCuocChoi(15);
                else DungCuocChoi(cauhientai - 1);
            }
        }
        else if(vitri == 2){
            form = 3;
            VeFormDiemCao();
            do{
                Click(x,y);
                vitri = XetViTriClick(x,y,form);
            }while(vitri < 0);
            if(vitri == 14){
                form = 1;
            }
        }
        else if(vitri == 3){
            form = 4;
            while(true){
                VeFormCaiDat();
                do{
                    Click(x,y);
                    vitri = XetViTriClick(x,y,form);
                }while(vitri < 0);
                if(vitri == 15){
                    form = 1;
                    break;
                }
                else if(vitri == 16){
                    XuLyThemCauHoi();
                }
                else if(vitri == 18){
                    DoiMauChu(yellow,black);
                    gotoxy(47,8); XuatChuoiTiengViet("Chọn 1 gói câu hỏi dễ, khó hoặc trung bình!!");
                    t=NULL;
                    VeMenuCaiDat(8,14,lightgreen,"    SỬA CÂU HỎI");
                    do{
                        Click(x,y);
                        vitri = XetViTriClick(x,y,form);
                    }while(vitri != 21 && vitri != 22 && vitri != 20);
                    if(vitri == 20){
                        VeMenuCaiDat(47,4,lightgreen,"     CÂU HỎI DỄ");
                        LoadFileCauHoi(t,"Goi1.dat");
                        XuLySuaCauHoi(t,1);
                    }
                    else if(vitri == 21){
                        VeMenuCaiDat(76,4,lightgreen," CÂU HỎI TRUNG BÌNH");
                        LoadFileCauHoi(t,"Goi2.dat");
                        XuLySuaCauHoi(t,2);
                    }
                    else if(vitri == 22){
                        VeMenuCaiDat(105,4,lightgreen,"     CÂU HỎI KHÓ");
                        LoadFileCauHoi(t,"Goi3.dat");
                        XuLySuaCauHoi(t,3);
                    }
                }
                else if(vitri == 17){
                    DoiMauChu(yellow,black);
                    gotoxy(47,8); XuatChuoiTiengViet("Chọn 1 gói câu hỏi dễ, khó hoặc trung bình!!");
                    t=NULL;
                    VeMenuCaiDat(8,9,lightgreen,"    XÓA CÂU HỎI");
                    do{
                        Click(x,y);
                        vitri = XetViTriClick(x,y,form);
                    }while(vitri != 21 && vitri != 22 && vitri != 20);
                    if(vitri == 20){
                        VeMenuCaiDat(47,4,lightgreen,"     CÂU HỎI DỄ");
                        LoadFileCauHoi(t,"Goi1.dat");
                        XuLyXoaCauHoi(t,1);
                    }
                    else if(vitri == 21){
                        VeMenuCaiDat(76,4,lightgreen," CÂU HỎI TRUNG BÌNH");
                        LoadFileCauHoi(t,"Goi2.dat");
                        XuLyXoaCauHoi(t,2);
                    }
                    else if(vitri == 22){
                        VeMenuCaiDat(105,4,lightgreen,"     CÂU HỎI KHÓ");
                        LoadFileCauHoi(t,"Goi3.dat");
                        XuLyXoaCauHoi(t,3);
                    }
                }
                else if(vitri == 19){
                    VeMenuCaiDat(8,19,lightgreen," RESET BẢNG XẾP HẠNG");
                    XuLyResetBangXepHang();
                }
            }
        }
    }

    return 0;
}
