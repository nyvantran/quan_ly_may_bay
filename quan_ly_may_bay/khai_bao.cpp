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
/*ghi file may bay*/
void DSMayBay::ghiFile(const char file[]) const
{
	fstream file1(file, ios::binary | ios::out|ios::trunc);
	for (int i = 0; i < so_MB; i++) {
		file1.write(reinterpret_cast<char*>(maybay[i]), sizeof(MayBay));
	}
	file1.close();
}
/*giai phong bo nho*/
void DSMayBay::xoa()
{
	for (int i = 0; i < so_MB; i++) {
		delete maybay[i];
	}
	this->so_MB = 0;;
}

/*doc file chuyen bay*/
//==========them may bay vao danh sach=======
void ThemMayBay(MayBay maybay,DSMayBay &DSMayBay)
{	
	if (DSMayBay.so_MB < MAX_MB) {
		MayBay* p = new MayBay;
		strcpy_s(p->sh_Mb, 16, maybay.sh_Mb);
		strcpy_s(p->loai_may_bay, 40, maybay.loai_may_bay);
		p->so_day = maybay.so_day;
		p->so_dong = maybay.so_dong;
	/*	*p = maybay;*/
		DSMayBay.maybay[DSMayBay.so_MB++] = p;
		///ghi file///
		DSMayBay.ghiFile(DLMAYBAY);
	}
}
//========xoa may bay khoi danh sach may bay====
void XoaMayBay(DSMayBay &DSMayBay,char sohieu[15])
{
	char x[15];
	strcpy_s(x, sohieu); 
	int so = 0;
	MayBay *temp =TimSoHieu(x, DSMayBay);
	if (temp != NULL) {
		for (int i = 0; i < DSMayBay.so_MB; i++) {
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
		///ghi file///
		DSMayBay.ghiFile(DLMAYBAY);
	}
}
//==========hieu chinh may bay trong danh sach=======

void HieuChinhMB(DSMayBay& DSMayBay, MayBay* maybay, char sohieu[], char loai[], int soday, int sodong)
{
	char check[1]{}; check[0] = '\0';
	if (strcmp(check, sohieu) != 0) {
		strcpy_s(maybay->sh_Mb,15, sohieu);
	}
	if (strcmp(check, loai) != 0) {
		strcpy_s(maybay->loai_may_bay,40, loai);
	}
	if (soday > 0) {
		maybay->so_day = soday;
	}
	if (sodong > 0) {
		maybay->so_dong = sodong;
	}
	///ghi file///
	DSMayBay.ghiFile(DLMAYBAY);
}
// ======search theo so hieu may bay=======
MayBay *TimSoHieu (char x[], DSMayBay DSmaybay) {
	for (int i = 0; i <DSmaybay.so_MB; i++) {
		if (strcmp(x, DSmaybay.maybay[i]->sh_Mb) == 0) {
			return DSmaybay.maybay[i];
		}
	}
	return NULL;
}

double truNgayGio(NgayGio x, NgayGio y)
{
	/*double ketqua = 0;
	NgayGio s;
	s.datNgayGio(x.gio_kh.gio - y.gio_kh.gio, x.gio_kh.phut - y.gio_kh.phut, x.ngay_kh.ngay - y.ngay_kh.ngay, x.ngay_kh.thang - y.ngay_kh.thang, x.ngay_kh.nam - y.ngay_kh.nam);
	cout << s.ngay_kh.nam << endl;
	ketqua = s.gio_kh.gio * (1 / 24) + s.gio_kh.phut * (1 / (60 * 24)) + s.ngay_kh.ngay + s.ngay_kh.thang * 30 + s.ngay_kh.nam * 365;
	return ketqua;*/
	return 0;
}

void napFileChuyenBay(const char file[], PTRChuyenBay &fist,DSMayBay ds)
{
	fstream file1(file, ios::binary | ios::in);
	ChuyenBay doc;
	MayBay *tam;
	int n;
	while (!file1.eof()) {
		file1.read(reinterpret_cast<char*>(&doc), sizeof(ChuyenBay));
		if (doc.trang_thai_cb != HUY_CHUYEN) {
			doc.trang_thai_cb = capNhapTT(doc.ngay_gio_kh);
		}
		tam = TimSoHieu(doc.sh_Mb, ds);
		if (tam != NULL) {
			n = tam->so_day * tam->so_dong;
			if (doc.trang_thai_cb == CON_VE) {
				if (doc.so_ve == n) {
					doc.trang_thai_cb = HET_VE;
				}
			}			
			doc.ds_ve = new Ve[n];
			for (int i = 0; i < doc.so_ve; i++) {
				file1.read(reinterpret_cast<char*>(&doc.ds_ve[i]), sizeof(Ve));
			}
			themChuyenBay(fist, doc);
		}
		else {

		}
		
	}
}
/*ghi file chuyen bay*/
void ghiFileChuyenBay(const char file[], PTRChuyenBay fist,DSMayBay ds)
{
	fstream file1(file, ios::binary | ios::out | ios::trunc);
	PTRChuyenBay p;
	for (p = fist; p != NULL; p = p->next) {
		if (p->cb.trang_thai_cb != HUY_CHUYEN) {
			p->capnhap(ds);
		}
		file1.write(reinterpret_cast<char*>(&p->cb), sizeof(ChuyenBay));
		for (int i = 0; i < p->cb.so_ve; i++) {
			file1.write(reinterpret_cast<char*>(&p->cb.ds_ve[i]), sizeof(Ve));
		}
	}
}
/*them chuyen bay*/
bool themChuyenBay(PTRChuyenBay &fist, ChuyenBay x)/*co sua them*/
{
	if (fist == NULL) {
		ThemDauCB(fist, x);
		return 1;
	}else
	if (strcmp(fist->cb.ma_cb, x.ma_cb) == 1) {
		ThemDauCB(fist, x);
		return 1;
	}
	if (strcmp(fist->cb.ma_cb, x.ma_cb) == 0) {
		return 0;
	}
	else {
		PTRChuyenBay p = fist;
		while (1) {
			if (p->next == NULL) {
				ThemSauCB(p, x);
				return 1;
			}else
			if ((strcmp(p->next->cb.ma_cb, x.ma_cb) == 1) ) {
				ThemSauCB(p, x);
				return 1;
			}else
			if(strcmp(p->next->cb.ma_cb, x.ma_cb) == 0) {
				return 0;
			}
			p = p->next;
		}
	}
}
/*giai phong bo nho*/
void xoahetChuyenBay(PTRChuyenBay& fist)
{
	while (fist != NULL) {
		delete fist->cb.ds_ve;
		xoadauNodeChuyenBay(fist);
	}
}
/*xoa 1 chuyen bay*/
bool xoaChuyenBay(PTRChuyenBay &fist, PTRChuyenBay p)
{
	PTRChuyenBay q = fist;
	if (fist == NULL) {
		return 0;
	}
	if (fist == p) {
		xoadauNodeChuyenBay(fist);
		return 1;
	}
	for (q = fist; q->next != NULL && q->next != p; q = q->next);
	if (q->next != NULL) {
		xoasauNodeChuyenBay(q);
		return 1;
	}
	return 0;
}
bool xoadauNodeChuyenBay(PTRChuyenBay& fist)
{
	PTRChuyenBay p;
	if (fist == NULL) {
		return 0;
	}
	p = fist;
	fist = fist->next;
	delete p;
	return 1;
}
bool xoasauNodeChuyenBay(PTRChuyenBay p)
{	
	PTRChuyenBay q;
	if ((p == NULL) || (p->next == NULL)) {
		return 0;
	}
	q = p->next;
	p->next = q->next;
	delete q;
	return 1;
}
/*tim chuyen bay*/
PTRChuyenBay timChuyenBay(PTRChuyenBay fist, char x[])
{	
	for (PTRChuyenBay i = fist; i != NULL; i = i->next) {
		if (strcmp(i->cb.ma_cb, x) == 0) {
			return i;
		}
	}
	return NULL;
}
int timCBtheoSHMB(PTRChuyenBay fist, char x[], int& m)
{
	int n1 = 0, n2 = 0;
	for (PTRChuyenBay i = fist; i != NULL; i = i->next) {
		if (strcmp(i->cb.sh_Mb, x) == 0) {
			n1++;
			if (i->cb.trang_thai_cb == HOAN_TAT) {
				n2++;
			}
		}
	}
	m = n2++;
	return n1;
}
/*chinh sua chuyen bay*/
void chinhsuaChuyenBay(PTRChuyenBay &p, NgayGio time, char sbd[], char shmb[])
{
	if (p != NULL) {
		if (time.gio_kh.gio >= 0) {
			p->cb.ngay_gio_kh.gio_kh.gio = time.gio_kh.gio;
		}
		if (time.gio_kh.phut >= 0) {
			p->cb.ngay_gio_kh.gio_kh.phut = time.gio_kh.phut;
		}
		if (time.ngay_kh.nam > 0) {
			p->cb.ngay_gio_kh.ngay_kh.nam = time.ngay_kh.nam;
		}
		if (time.ngay_kh.ngay > 0) {
			p->cb.ngay_gio_kh.ngay_kh.ngay = time.ngay_kh.ngay;
		}
		if (time.ngay_kh.thang > 0) {
			p->cb.ngay_gio_kh.ngay_kh.thang = time.ngay_kh.thang;
		}
		if (sbd[0] != '\0') {
			strcpy_s(p->cb.san_bay_den, 100, sbd);
		}
		if (shmb[0] != '\0') {
			strcpy_s(p->cb.sh_Mb, 15, shmb);
		}
	}
}

PTRChuyenBay KhoiTaoCB()
{
	PTRChuyenBay p = new NodeChuyenBay;
	return p;
}

void ThemDauCB(PTRChuyenBay& fist, ChuyenBay x)
{
	PTRChuyenBay p;
	p = new NodeChuyenBay;
	p->cb = x;
	p->next = fist;
	fist = p;
}

void ThemSauCB(PTRChuyenBay p, ChuyenBay x)
{
	PTRChuyenBay q;
	if (p == NULL) {
	}
	else {
		q = new NodeChuyenBay;
		q->cb = x;
		q->next = p->next;
		p->next = q;
	}
}

void Ve::DatVe(char cmnd[], char vt[])
{
	strcpy_s(this->cmnd, 13, cmnd);
	strcpy_s(this->vitri, 5, vt);
}

TrangThai capNhapTT(NgayGio thoigian)
{
	time_t now = time(0);
	tm th;
	localtime_s(&th, &now);
	if (th.tm_year + 1900 > thoigian.ngay_kh.nam) {
		return HOAN_TAT;
	}
	else if (th.tm_year + 1900 < thoigian.ngay_kh.nam) {
		return CON_VE;
	}
	else if (thoigian.ngay_kh.thang > th.tm_mon + 1) {
		return CON_VE;
	}
	else if (thoigian.ngay_kh.thang < th.tm_mon + 1) {
		return HOAN_TAT;
	}
	else if (thoigian.ngay_kh.ngay > th.tm_mday) {
		return CON_VE;
	}
	else if (thoigian.ngay_kh.ngay < th.tm_mday) {
		return HOAN_TAT;
	}
	else if (thoigian.gio_kh.gio > th.tm_hour) {
		return CON_VE;
	}
	else if (thoigian.gio_kh.gio < th.tm_hour) {
		return HOAN_TAT;
	}
	else if (thoigian.gio_kh.phut > th.tm_min) {
		return CON_VE;
	}
	else if (thoigian.gio_kh.phut < th.tm_min) {
		return HOAN_TAT;
	}
	return HOAN_TAT;
}
/*dat chuyen bay*/
void ChuyenBay::datChuyenBay(char macb[], NgayGio ngay, char sanbay[], char somb[], TrangThai trangthai,DSMayBay ds)
{
	if (TimSoHieu(somb, ds) != NULL) {	
		strcpy_s(this->ma_cb, 16, macb);
		this->ngay_gio_kh = ngay;
		strcpy_s(this->san_bay_den, 100, sanbay);
		strcpy_s(this->sh_Mb, 15, somb);
		MayBay *tam = TimSoHieu(somb, ds);
		this->ds_ve = new Ve[tam->so_day * tam->so_dong];
		this->trang_thai_cb = trangthai;
	}	
}
Ve* ChuyenBay::timVe(char cmnd[]) const
{
	for (int i = 0; i < this->so_ve; i++) {
		if (strcmp(cmnd, this->ds_ve[i].cmnd) == 0) {
			return this->ds_ve + i;
			break;
		}
	}
	return NULL;
}
bool ChuyenBay::huyVe(char cmnd[])
{
	Ve* xoa = this->timVe(cmnd);
	int xoa1 = 0;
	if (xoa == NULL) {
		return false;
	}
	for (int i = 0; i < this->so_ve; i++) {
		if (&this->ds_ve[i] == xoa) {
			xoa1 = i;
			break;
		}
	}
	for (int i = xoa1+1; i < this->so_ve; i++) {
		this->ds_ve[i-1] = this->ds_ve[i];
	}
	this->so_ve--;
	return true;
}
/*setup ngay gio*/
void NgayGio::datNgayGio(int gio, int phut, int ngay, int thang, int nam)
{
	if (gio >= 0) {
		this->gio_kh.gio = gio;
	}
	if (phut >= 0) {
		this->gio_kh.phut = phut;
	}
	if (ngay > 0) {
		this->ngay_kh.ngay = ngay;
	}
	if (thang > 0) {
		this->ngay_kh.thang = thang;
	}
	if (nam > 0) {
		this->ngay_kh.nam = nam;
	}
}
bool NgayGio::checkNgayGio() const
{

		switch (this->ngay_kh.thang)
		{
		case 1: {
			
		}
		case 3: {

		}
		case 5: {

		}
		case 7: {

		}
		case 8: {

		}
		case 10: {

		}
		case 12: {
			if (this->ngay_kh.ngay <= 31) { return 1; }
			else { return 0; }
			break;
		}
		case 2: {
			if (this->ngay_kh.nam % 4 != 0) {
				if (this->ngay_kh.ngay <= 28) { return 1; }
				else { return 0; }
			}
			else {
				if (this->ngay_kh.ngay <= 29) { return 1; }
				else { return 0; }
			}
			break;
		}
		case 4: {

		}
		case 6: {

		}
		case 9: {

		}
		case 11: {
			if (this->ngay_kh.ngay <= 30) { return 1; }
			else { return 0; }
			break;
		}
		}
}
//tao cccd ngau nhien
void CCCDNN(char cccd[])
{
	srand(time(NULL));
	cccd[0] = rand() % (90 - 65 + 1) + 65;
	for (int i = 1; i < 10; i++) {
		cccd[i] = rand() % (57 - 48 + 1) + 48;
	}
	cccd[10] = NULL;
}
// sap ve theo so day so dong
void SapVe(char ve[],int ghe_day,int ghe_dong)
{
	char day[22]{}, dong[22]{};
	int n, m;
	if (ghe_day <= 26) {
		ghe_day = ghe_day + 64;
		day[0] = (char)ghe_day;
	}
	else {
		n = ghe_day / 26;
		m = ghe_day % 26;
		n += 64;
		m += 64;
		day[0] = (char)n;
		day[1] = (char)m;
	}
	_itoa_s(ghe_dong, dong, 20, 10);
	strcpy_s(ve, 3, day);
	strcat_s(ve, 10, dong);
}
// chuan hoa ngay
void SuaNgay(Ngay& day) {
	if (day.nam % 4 == 0) {
		switch (day.thang) {
		case 1:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang++;
			}
			break;
		case 2:
			if (day.ngay > 29) {
				day.ngay = day.ngay - 29;
				day.thang++;
			}
			break;
		case 3:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang++;
			}
			break;
		case 4:
			if (day.ngay > 30) {
				day.ngay = day.ngay - 30;
				day.thang++;
			}
			break;
		case 5:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang++;
			}
			break;
		case 6:
			if (day.ngay > 30) {
				day.ngay = day.ngay - 30;
				day.thang++;
			}
			break;
		case 7:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang++;
			}
			break;
		case 8:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang++;
			}
			break;
		case 9:
			if (day.ngay > 30) {
				day.ngay = day.ngay - 30;
				day.thang++;
			}
			break;
		case 10:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang++;
			}
			break;
		case 11:
			if (day.ngay > 30) {
				day.ngay = day.ngay - 30;
				day.thang++;
			}
			break;
		case 12:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang = 1;
				day.nam = day.nam + 1;
			}
			break;
		}
	}
	else if (day.nam % 4 != 0) {
		switch (day.thang) {
		case 1:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang++;
			}
			break;
		case 2:
			if (day.ngay > 28) {
				day.ngay = day.ngay - 28;
				day.thang++;
			}
			break;
		case 3:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang++;
			}
			break;
		case 4:
			if (day.ngay > 30) {
				day.ngay = day.ngay - 30;
				day.thang++;
			}
			break;
		case 5:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang++;
			}
			break;
		case 6:
			if (day.ngay > 30) {
				day.ngay = day.ngay - 30;
				day.thang++;
			}
			break;
		case 7:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang++;
			}
			break;
		case 8:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang++;
			}
			break;
		case 9:
			if (day.ngay > 30) {
				day.ngay = day.ngay - 30;
				day.thang++;
			}
			break;
		case 10:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang++;
			}
			break;
		case 11:
			if (day.ngay > 30) {
				day.ngay = day.ngay - 30;
				day.thang++;
			}
			break;
		case 12:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang = 1;
				day.nam = day.nam + 1;
			}
			break;
		}
	}
}


void NodeChuyenBay::capnhap(DSMayBay ds)
{
	MayBay* tam;
	if (this->cb.trang_thai_cb != HUY_CHUYEN) {
		this->cb.trang_thai_cb = capNhapTT(this->cb.ngay_gio_kh);
		if (this->cb.trang_thai_cb == CON_VE) {
			tam = TimSoHieu(this->cb.sh_Mb, ds);
			if (this->cb.so_ve < tam->so_day * tam->so_dong) {

			}
			else {
				this->cb.trang_thai_cb = HET_VE;
			}
		}
	}
	
}

void NodeChuyenBay::capNhapVe(DSMayBay ds, char shmb[], char shmbcu[], bool d)
{
	MayBay* n;
	if (strcmp(this->cb.sh_Mb, shmbcu) == 0 && shmb[0] != '\0') {
		strcpy_s(this->cb.sh_Mb, shmb);
	}
	if (d == 1) {
		n = TimSoHieu(this->cb.sh_Mb, ds);
		Ve* tam = new Ve[n->so_day * n->so_dong];
		for (int i = 0; i < this->cb.so_ve; i++) {
			tam[i] = this->cb.ds_ve[i];
		}
		delete[] this->cb.ds_ve;
		this->cb.ds_ve = tam;
	}
}
///======================Khach Hang===================================///
void KhachHang::datKhachHang(char cmnd[], char ho[], char ten[], bool phai)
{
	strcpy_s(this->cmnd, 13, cmnd);
	strcpy_s(this->ho, 25, ho);
	strcpy_s(this->ten, 10, ten);
	this->phai = phai;
}
void napFileKhachHang(PTRKhachhang& goc, const char file[])
{
	fstream file1(file, ios::binary | ios::in);
	KhachHang tam;
	do {
		file1.read(reinterpret_cast<char*>(&tam), sizeof(KhachHang));
		if(tam.cmnd[0]!='\0')themKhachHang(goc, tam);
	} while (!file1.eof());
}
void ghiFileKhangHang(PTRKhachhang goc,const char file[])
{
	fstream file1(file, ios::binary | ios::out | ios::trunc);
	const int	STAIZE = 1000;
	PTRKhachhang Stack[STAIZE]{};
	PTRKhachhang p = goc;
	int sp = -1;
	do {
		while (p != NULL) {
			Stack[++sp] = p;
			p = p->left;
		}
		if (sp != -1) {
			p = Stack[sp--];
			file1.write(reinterpret_cast<char*>(&p->info), sizeof(KhachHang));
			p = p->right;
		}
		else break;
	} while (1);
}
PTRKhachhang latTraiKhachHang(PTRKhachhang goc)
{
	PTRKhachhang p{};
	if (goc == NULL) {

	}
	else {
		if (goc->right == NULL) {
		}
		else {
			p = goc->right;
			goc->right = p->left;
			p->left = goc;
		}
	}
	return p;
}
PTRKhachhang latPhaiKhachHang(PTRKhachhang goc)
{
	PTRKhachhang p{};
	if (goc == NULL) {

	}
	else {
		if (goc->left == NULL) {
		}
		else {
			p = goc->left;
			goc->left = p->right;
			p->right = goc;
		}
	}
	return p;
}
void duyetLNR(PTRKhachhang goc)
{
	if (goc == NULL) {

	}
	else {
		cout <<goc->info.cmnd << goc->info.ten<< endl;
		duyetLNR(goc->left);
		duyetLNR(goc->right);
		
	}
}
void xoaHetKhachHang(PTRKhachhang& goc)
{
	if (goc != NULL) {
		xoaHetKhachHang(goc->left);
		xoaHetKhachHang(goc->right);
		delete goc;
	}
}
PTRKhachhang timKhachHang(PTRKhachhang goc, char cmnd[])
{
	PTRKhachhang p;
	p = goc;
	while (p != NULL && strcmp(cmnd, p->info.cmnd) != 0) {
		if (p != NULL) {
			if (strcmp(cmnd, p->info.cmnd) < 0) {
				p = p->left;
			}else
			if (strcmp(cmnd, p->info.cmnd) > 0) {
				p = p->right;
			}
		}
		else return NULL;
		
	}
	return p;
}
void themKhachHang(PTRKhachhang& goc, KhachHang x)
{
	PTRKhachhang fp, p, q, ya, fya, s;
	int imbal;
	///
	fp = NULL; p = goc;
	fya = NULL; ya = p;
	if (goc == NULL) {
		goc = new NodeKhachHang;
		goc->bf = 0;
		goc->info = x;
		goc->left = NULL;
		goc->right = NULL;
		return;
	}
	///tim vi tri them
	while (p != NULL) {
		if (strcmp(x.cmnd, p->info.cmnd) == 0) {
			return;
		}
		if (strcmp(x.cmnd, p->info.cmnd) < 0) {
			q = p->left;
		}
		else {
			q = p->right;
		}
		if (q != NULL) 
			if (q->bf != 0) {
				fya = p;
				ya = q;
			}
		fp = p;
		p = q;
	}
	///////
	q = new NodeKhachHang;
	q->info = x; q->bf = 0; 
	q->left = NULL; q->right = NULL;
	if (strcmp(x.cmnd, fp->info.cmnd) < 0)fp->left = q;
	else fp->right = q;
	////hieu chinh
	if (strcmp(x.cmnd, ya->info.cmnd) < 0) {
		p = ya->left;
	}
	else {
		p = ya->right; 
	}
	s = p; 
	while (p != q) {
		if (strcmp(x.cmnd, p->info.cmnd) < 0) {
			p->bf = 1;         
			p = p->left;
		}
		else {
			p->bf = -1; 	
			p = p->right;
		}
	}
	///xac dinh huong lenh
	if (strcmp(x.cmnd, ya->info.cmnd) < 0) {
		imbal = 1;
	}
	else {
		imbal = -1;
	}
	if (ya->bf == 0){
		ya->bf = imbal;
		return;
	}
	if (ya->bf != imbal){
		ya->bf = 0;
		return;
	}
	///cay mat can bang
	if (s->bf == imbal) {
		if (imbal == 1) {
			p = latPhaiKhachHang(ya);
		}
		else {	
			p = latTraiKhachHang(ya);	
		}
		ya->bf = 0;
		s->bf = 0;
	}
	else {
		if (imbal == 1) {
			ya->left = latTraiKhachHang(s);
			p = latPhaiKhachHang(ya);
		}
		else {
			ya->right = latPhaiKhachHang(s);
			p = latTraiKhachHang(ya);
		}
		if (p->bf == 0) {
			ya->bf = 0;
			s->bf = 0;
		}
		else if (p->bf == imbal) {
			ya->bf = -imbal;
			s->bf = 0;
		}
		else {
			ya->bf = 0;
			s->bf = imbal;
		}
		p->bf = 0;
	}
	if (fya == NULL) {
		goc = p;
	}
	else if (ya == fya->right) {
		fya->right = p;
	}
	else fya->left = p;
}
//////////

//chuan hoa ten
void SuaTen(char ten[])
{
	int dem = 0;
	while (ten[dem] == ' ') {
		dem++;
	}
	
	for (int i = 0; (unsigned)i < strlen(ten); i++) {
		ten[i] = ten[dem + i];
	}

	dem = 0;
	for (int i = 0; i < strlen(ten); i++) {
		if (ten[i] == ' ' && ten[i + 1] == ' ') {
			dem = i + 1;
			while (ten[dem] == ' ') {
				dem = dem + 1;
			}
			dem = dem - i - 1;
			for (int j = i + 1; j < strlen(ten); j++) {
				ten[j] = ten[dem + j];
			}
		}
	}
	if (ten[strlen(ten) - 1] == ' ') {
		ten[strlen(ten) - 1] = '\0';
	}
	if (ten[0] >= 97 && ten[0] <= 122) {
		ten[0] = toupper(ten[0]);
	}
	for (int i = 0; i < strlen(ten); i++) {
		if (ten[i] == ' ') {
			if (ten[i + 1] >= 97 && ten[i + 1] <= 122) {
				ten[i + 1] = toupper(ten[i + 1]);
			}
		}
	}

	for (int i = strlen(ten) - 1; i >= 0; i--) {
		if (ten[i - 1] != ' ') {
			if (ten[i] > 65 && ten[i] < 90) {
				ten[i] = tolower(ten[i]);
			}
		}
	}
	ten[0] = toupper(ten[0]);
}
/////////
void SapVeNguoc(char ve[], int& x, int& y)
{
	int i = 0, ix = 0, iy = 0;
	char day[3]{}, dong[3]{};
	while (i < strlen(ve) && 'A' <= ve[i] && ve[i] <= 'Z') {
		if (ix + 1 > 2) {
			x = 0; y = 0;
			return;
		}
		day[ix++] = ve[i++];
	}
	while (i < strlen(ve) && '0' <= ve[i] && ve[i] <= '9') {
		if (iy + 1 > 2) {
			x = 0; y = 0;
			return;
		}
		dong[iy++] = ve[i++];
	}
	if (i != strlen(ve)) {
		x = 0; y = 0;
		return;
	}
	x = 0; y = 0;
	for (i = 0; i < strlen(day); i++) {
		x += (int)pow(26, strlen(day) - i - 1) * ((int)day[i] - 64);
	}
	y=atoi(dong);
}

int SSNgayThang(NgayGio t1, NgayGio t2)
{
	int tn1, tn2, tg1, tg2;
	tn1 = t1.ngay_kh.ngay;
	tn2 = t2.ngay_kh.ngay;
	//
	tn1 += t1.ngay_kh.thang * pow(10, 2);
	tn2 += t2.ngay_kh.thang * pow(10, 2);
	//
	tn1 += t1.ngay_kh.nam * pow(10, 4);
	tn2 += t2.ngay_kh.nam * pow(10, 4);
	if (tn1 > tn2) return 1;
	if (tn1 < tn2) return -1;
	if (tn1 == tn2) {
		tg1 = t1.gio_kh.phut;
		tg2 = t2.gio_kh.phut;
		//
		tg1 += t1.gio_kh.gio * pow(10, 2);
		tg2 += t2.gio_kh.gio * pow(10, 2);
		if (tg1 > tg2) return 1;
		if (tg1 < tg2) return -1;
		if (tg1 == tg2) return -1;
	}
}

bool checkNgayGio(NgayGio t1, NgayGio t2)
{
	NgayGio t;
	if (SSNgayThang(t1, t2) == 0)return 1;
	if (SSNgayThang(t1, t2) == 1) {
		t = t2;
		t.gio_kh.gio += 6;
		if (t.gio_kh.gio > 23) {
			t.gio_kh.gio -= 24;
			t.ngay_kh.ngay++;
			SuaNgay(t.ngay_kh);
		}
		if (SSNgayThang(t1, t) == -1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (SSNgayThang(t1, t2) == -1) {
		t = t1;
		t.gio_kh.gio += 6;
		if (t.gio_kh.gio > 23) {
			t.gio_kh.gio -= 24;
			t.ngay_kh.ngay++;
			SuaNgay(t.ngay_kh);
		}
		if (SSNgayThang(t2, t) == -1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	

}

// ghe tra dong day 
void TraDongDay(char ve[], int& day, int& dong) {
	day = ve[0] - 64;
	if (ve[1] >= 49 && ve[1] <= 57) {
		dong = ve[1] - 48;
	}
	else if (ve[1] >= 65 && ve[1] <= 90) {
		dong = ve[1] - 55;
	}
}

// in so chuyen bay hoan tat
//void demChuyenBayHT (PTRChuyenBay dau_chuyen_bay) 
//{
//	PTRChuyenBay tam1 = dau_chuyen_bay;
//	PTRChuyenBay tam = dau_chuyen_bay;
//	while (dau_chuyen_bay != NULL) {
//		while (tam != NULL) { 
//			if (strcmp(dau_chuyen_bay->cb.sh_Mb, tam->cb.sh_Mb) == 0 && tam->cb.trang_thai_cb == 3) {
//				dau_chuyen_bay->dem++;
//			}
//			tam = tam->next;
//		}
//		tam = tam1;
//		dau_chuyen_bay = dau_chuyen_bay->next;
//	}
//	dau_chuyen_bay = tam1;
//
//
//}
// Bublesort
void Bublesort(PTRChuyenBay chuyenBay, DSMayBay &DsMayBay)
{
	MayBay* MBtemp;
	int max;
	int ss;
	for (int i = 0; i < DsMayBay.so_MB; i++) {
		timCBtheoSHMB(chuyenBay, DsMayBay.maybay[i]->sh_Mb, max);
		for (int j = 0; j < DsMayBay.so_MB; j++) {
			timCBtheoSHMB(chuyenBay, DsMayBay.maybay[j]->sh_Mb, ss);
			if (max > ss) {
				MBtemp = DsMayBay.maybay[i];
				DsMayBay.maybay[i] = DsMayBay.maybay[j];
				DsMayBay.maybay[j] = MBtemp;
			}
		}
		
	}
	
	
}
//=============================
int demCBBL(PTRChuyenBay chuyenbay, int gio, int phut, int ngay, int thang, int nam) {
	int n = 0;
	PTRChuyenBay q = chuyenbay;
	//
	if (gio != 0&&phut==0) {
		while (q!=NULL) {
			if (q->cb.ngay_gio_kh.gio_kh.gio == gio) {
				n++;
			}
			q = q->next;
		}
		return n;
	}
	//
	if (gio == 0 && phut != 0) {
		while (q != NULL) {
			if (q->cb.ngay_gio_kh.gio_kh.phut == phut) {
				n++;
			}
			q = q->next;
		}
		return n;
	}
	//
	if (gio != 0 && phut != 0) {
		while (q != NULL) {
			if (q->cb.ngay_gio_kh.gio_kh.phut == phut&& q->cb.ngay_gio_kh.gio_kh.gio == gio) {
				n++;
			}
			q = q->next;
		}
		return n;
	}
	//
	if (ngay != 0 && thang == 0 && nam == 0) {
		while (q != NULL) {
			if (q->cb.ngay_gio_kh.ngay_kh.ngay==ngay) {
				n++;
			}
			q = q->next;
		}
		return n;
	}
	//
	if (ngay == 0 && thang != 0 && nam == 0) {
		while (q != NULL) {
			if (q->cb.ngay_gio_kh.ngay_kh.thang == thang) {
				n++;
			}
			q = q->next;
		}
		return n;
	}
	//
	if (ngay == 0 && thang == 0 && nam != 0) {
		while (q != NULL) {
			if (q->cb.ngay_gio_kh.ngay_kh.nam == nam) {
				n++;
			}
			q = q->next;
		}
		return n;
	}
	//
	if (ngay != 0 && thang != 0 && nam == 0) {
		while (q != NULL) {
			if (q->cb.ngay_gio_kh.ngay_kh.thang == thang&& q->cb.ngay_gio_kh.ngay_kh.ngay==ngay) {
				n++;
			}
			q = q->next;
		}
		return n;
	}
	//
	if (ngay != 0 && thang == 0 && nam != 0) {
		while (q != NULL) {
			if (q->cb.ngay_gio_kh.ngay_kh.nam == nam && q->cb.ngay_gio_kh.ngay_kh.ngay == ngay) {
				n++;
			}
			q = q->next;
		}
		return n;
	}
	//
	if (ngay == 0 && thang != 0 && nam != 0) {
		while (q != NULL) {
			if (q->cb.ngay_gio_kh.ngay_kh.thang == thang && q->cb.ngay_gio_kh.ngay_kh.nam == nam) {
				n++;
			}
			q = q->next;
		}
		return n;
	}
}

