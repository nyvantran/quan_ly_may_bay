#include"khai_bao.h"
//#include<fstream>
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
		p->sh_Mb[15	] = maybay.sh_Mb[15];
		p->loai_may_bay[40] = maybay.loai_may_bay[40];
		p->so_day = maybay.so_day;
		p->so_dong = maybay.so_dong;
		int temp = DSMayBay.so_MB++;
		DSMayBay.maybay[temp] = p;
		DSMayBay.so_MB++;
	}
}
//========xoa may bay khoi danh sach may bay====


void XoaMayBay(DSMayBay &DSMayBay,int i)
{
	delete DSMayBay.maybay[i];
}
//==========hieu chinh may bay trong danh sach=======

void HieuChinhMB(DSMayBay &DSMayBay,int i,MayBay maybay)
{
	MayBay* p = new MayBay;

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



