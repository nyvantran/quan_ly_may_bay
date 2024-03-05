#include"khai_bao.h"
#include<fstream>
void DSMayBay::napFile(const char file[])
{
	fstream file1(file, ios::binary | ios::in);
	while (!file1.eof()) {
		maybay[so_MB] = new MayBay;
		file1.read(reinterpret_cast<char*>(maybay[so_MB++]), sizeof(MayBay));
	}
	so_MB--;
	delete maybay[so_MB];
	file1.close();
}

void DSMayBay::ghiFile(const char file[])
{
	fstream file1(file, ios::binary | ios::out);
	for (int i = 0; i < so_MB; i++) {
		file1.write(reinterpret_cast<char*>(maybay[i]), sizeof(MayBay));
	}
	file1.close();
}

void DSMayBay::xoa()
{
	for (int i = 0; i < so_MB; i++) {
		delete maybay[i];
	}
}
//==========them may bay vao danh sach=======

void ThemMayBay(MayBay maybay,DSMayBay &DSMayBay)
{	
	if (DSMayBay.so_MB < MAX_MB) {
		MayBay* p = new MayBay;
		strcpy_s(p->sh_Mb, maybay.sh_Mb);
		strcpy_s(p->loai_may_bay,maybay.loai_may_bay);
		p->so_day = maybay.so_day;
		p->so_dong = maybay.so_dong;
		DSMayBay.so_MB++;
		DSMayBay.maybay[DSMayBay.so_MB] = p;
		
	}
}
//========xoa may bay khoi danh sach may bay====

void XoaMayBay(DSMayBay &DSMayBay,char sohieu[15])
{
	char x[15];
	strcpy_s(x, sohieu); 
	int so;
	MayBay *temp =TimSoHieu(x, DSMayBay);
	for (int i=0;i<DSMayBay.so_MB;i++){
		if (DSMayBay.maybay[i] == temp) {
			so = i;
			delete temp;
			break;
		}
	}
	DSMayBay.so_MB--;
	while (so < DSMayBay.so_MB) {
		DSMayBay.maybay[so] = DSMayBay.maybay[so + 1];
		so++;
	}
}
//==========hieu chinh may bay trong danh sach=======

void HieuChinhMB(MayBay* maybay,char sohieu[15],char loai[40],int soday,int sodong)
{
	char check[1];	
	if (strcmp(check, sohieu) != 0) {
		strcpy_s(maybay->sh_Mb, sohieu);
	}
	if (strcmp(check, loai) != 0) {
		strcpy_s(maybay->loai_may_bay, loai);
	}
	if (soday > 0) {
		maybay->so_day = soday;
	}
	if (sodong > 0) {
		maybay->so_dong = sodong;
	}
}

// ======search theo so hieu may bay=======
MayBay *TimSoHieu (char x[15], DSMayBay DSmaybay) {
	for (int i = 0; i <DSmaybay.so_MB; i++) {
		if (strcmp(x, DSmaybay.maybay[i]->sh_Mb) == 0) {
			return DSmaybay.maybay[i];
		}
	}
	return NULL;
}


void napFileChuyenBay(const char file[], PTRChuyenBay &fist)/*se sua them*/
{
	fstream file1(file, ios::binary | ios::in);
	ChuyenBay doc;
	PTRChuyenBay here = NULL;
}

void ghiFileChuyenBay(const char file[], PTRChuyenBay fist)
{
	fstream file1(file, ios::binary | ios::out);
	PTRChuyenBay p;
	for (p = fist; p->next != NULL; p = p->next) {
		file1.write(reinterpret_cast<char*>(p->cb.ma_cb), sizeof(char*));
		file1.write(reinterpret_cast<char*>(&p->cb.ngay_gio_kh), sizeof(NgayGio));
		file1.write(reinterpret_cast<char*>(p->cb.san_bay_den), sizeof(char*));
		file1.write(reinterpret_cast<char*>(p->cb.sh_Mb), sizeof(char*));
		file1.write(reinterpret_cast<char*>(&p->cb.trang_thai_cb), sizeof(TrangThai));
	}
}

PTRChuyenBay KhoiTaoCB()
{
	PTRChuyenBay p = new NodeChuyenBay;
	return p;
}



