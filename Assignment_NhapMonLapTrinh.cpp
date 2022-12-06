#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

// Chuong trinh 1 : Kiem tra so nguyen//

void soChinhphuong(float x)
{ // Ham tim so chinh phuong
	int count = 0;
	int i;
	for (i = 0; i < x; i++)
	{
		if (i * i == x)
		{
			count++;
		}
	}
	if (count == 0)
	{
		printf("%.f khong la so chinh phuong.\n", x);
	}
	else
	{
		printf("%.f la so chinh phuong.\n", x);
	}
} // End of Ham timsoChinhphuong

void soNguyento(float x)
{ // Ham tim so nguyen to
	int count = 0;
	int i;
	if (x < 2)
	{
		printf("%.f Khong la so nguyen to.\n", x);
	}
	else
	{
		for (i = 2; i < x; i++)
		{
			if ((int)x % i == 0)
			{
				count++;
			}
		}
		if (count == 0)
		{
			printf("%.f La so nguyen to.\n", x);
		}
		else
		{
			printf("%.f Khong la so nguyen to.\n", x);
		}
	}
} // End of HamtimsoNguyento

void chucnang1()
{ // Ham kiem tra so nguyen

	float x;
	do
	{
		printf("Moi ban nhap so nguyen N muon kiem tra:");
		scanf("%f", &x);
	} while (x != (int)x);
	printf("%.f la so nguyen.\n", x);
	soNguyento(x);
	soChinhphuong(x);
} // End of Chucnang1

void chucnang2() // Ham tim UCLN-BCNN
{
	int a, b;
	do
	{
		printf("Nhap a , b > 0 :");
		scanf("%d%d", &a, &b);
	} while (a < 0 || b < 0);
	if (a == 0 && b == 0)
	{
		printf("Khong ton tai UCLN, BCNN \n");
	}
	else if (a == 0 || b == 0)
	{
		printf("Khong co BCNN, UCLN = %d", (a == 0) ? b : a); // Toan tu 3 ngoi
	}
	else
	{ // a , b > 0
		int bc = a * b;
		while (a != b)
		{
			if (a > b)
			{
				a = a - b;
			}
			else
			{
				b = b - a;
			}
		}
		printf("UCLN = %d\n", a);
		printf("BCNN = %d\n", bc / a);
	}

} // End Of chucnang2

// Chuong trinh 3:Tinh tien karaoke:
// Start	From Line88 to Line198
struct time nhap(char txt[100]);
int tinhStartToEnd(struct time start, struct time end);
int tinhMoney(int phut, struct time start);
bool dktimeHoatDong(struct time T);
bool dkNhap(struct time start, struct time end);

struct time
{
	int gio;
	int phut;
};

bool dktimeHoatDong(struct time T)
{ // Ham Bool kiem tra dieu kien hoat dong from 12h to 23h
	int timeOpen = 12;
	int timeClose = 23;
	if (T.gio > 0 && T.phut >= 0)
	{
		if (T.gio >= timeOpen && T.gio < timeClose)
		{
			if (T.phut >= 0 && T.phut < 60)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (T.gio >= timeOpen && T.gio == timeClose && T.phut == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
} // Dieu kien hoat dong cua quan

struct time nhap(char txt[100])
{
	do
	{
		struct time T;
		printf("\nNhap vao gio va phut:\n");
		printf("Nhap gio %s: ", txt);
		scanf("%d", &T.gio);
		printf("Nhap phut %s: ", txt);
		scanf("%d", &T.phut);
		if (dktimeHoatDong(T) == false)
		{
			printf("\nBan da nhap sai, moi ban nhap lai:");
		}
		else
		{
			return T;
			break;
		}
	} while (true);
}

void printfTime(struct time T)
{
	printf("Thoi gian: Gio %d Phut %d", T.gio, T.phut);
}

bool dkNhap(struct time start, struct time end)
{ // Ham bool kiem tra dieu kien nhap vao cua thoi gian! From Start to End!
	if (start.gio <= end.gio)
	{
		if (start.gio < end.gio)
		{
			return true;
		}
		else
		{
			if (start.phut < end.phut)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
} // dieu kien nhap vao bat dau va ket thuc

int calcTimeStartToTimeEnd(struct time start, struct time end)
{ // Ham tra ve gia tri thoi gian theo phut
	int hours = end.gio - start.gio;
	int minutes = end.phut - start.phut;
	return ((hours * 60) + minutes);
}

int calcMoney(int minutes, struct time start)
{ // Ham tinh tien hat theo phut
	int price = 150000;
	int saleOffTime4h = 30;
	int saleOffTime14h_17h = 10;
	float priceSale = 0;
	int moneySale = price;
	if (minutes <= (3 * 60))
	{
		priceSale = minutes * (price / 60);
	}
	else
	{
		moneySale = price - ((price * saleOffTime4h) / 100);
		priceSale = (3 * price) + ((minutes - (3 * 60)) * moneySale);
	}
	if (start.gio >= 14 && start.gio <= 17)
	{
		priceSale = priceSale - ((priceSale * saleOffTime14h_17h) / 100);
	}
	return priceSale;
}
void chucnang3()
{
	struct time start, end;
	int minutes = 0;
	int priceSale = 0;
	// Nhap gio bat dau
	start = nhap("bat dau");
	// Nhap gio ket thuc
	end = nhap("ket thuc");
	if (dkNhap(start, end) == false)
	{
		printf("\nThoi gian bat dau va ket thuc khong hop le");
	}
	else
	{
		minutes = calcTimeStartToTimeEnd(start, end);
		priceSale = calcMoney(minutes, start);
		printf("\nPhut : %d", minutes);
		printf("\nTong so tien phai thanh toan la : %d VND", priceSale);
	}

} // End Of Chucnang3

// Chuong trinh 4:Tinh tien dien
void chucnang4()
{
	float sodien, tiendien;
	int bac1 = 1678, bac2 = 1734, bac3 = 2014, bac4 = 2536, bac5 = 2834, bac6 = 2927;
	do
	{
		printf("Nhap vao so dien cua ban (kWh): ");
		scanf("%f", &sodien);
	} while (sodien < 0);
	if (sodien <= 50)
	{
		tiendien = sodien * bac1;
		printf("\nBan da dung dien trong khoang 0 - 50 kWh so tien ban phai tra la: %.2f\n", tiendien);
	}
	else if (sodien <= 100)
	{
		tiendien = 50 * bac1 + ((sodien - 50) * bac2);
		printf("\nBan da dung dien trong khoang 51 - 100 kWh so tien ban phai tra la: %.2f\n", tiendien);
	}
	else if (sodien <= 200)
	{
		tiendien = 50 * bac1 + (50 * bac2) + ((sodien - 100) * bac3);
		printf("\nBan da dung dien trong khoang 101 - 200 kWh so tien ban phai tra la: %.2f\n", tiendien);
	}
	else if (sodien <= 300)
	{
		tiendien = 50 * bac1 + (50 * bac2) + (100 * bac3) + ((sodien - 200) * bac4);
		printf("\nBan da dung dien trong khoang 201 - 300 kWh so tien ban phai tra la: %.2f\n", tiendien);
	}
	else if (sodien <= 400)
	{
		tiendien = 50 * bac1 + (50 * bac2) + (100 * bac3) + (100 * bac4) + ((sodien - 300) * bac5);
		printf("\nBan da dung dien trong khoang 301 - 400 kWh so tien ban phai tra la: %.2f\n", tiendien);
	}
	else if (sodien > 400)
	{
		tiendien = 50 * bac1 + (50 * bac2) + (100 * bac3) + (100 * bac4) + (100 * bac5) + ((sodien - 400) * bac6);
		printf("\nBan da dung dien tren 400 kWh so tien ban phai tra la: %.2f\n", tiendien);
	}
} // End of chucnang4

// Chuong trinh 5:Doi tien
void chucnang5()
{
	unsigned long long n;
	int menhGia[9] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
	int cout[9] = {0};
	int tien;
	do
	{
		printf("Moi ban nhap so tien can doi la 'nghin dong(VND)':");
		scanf("%d", &tien);
	} while (tien < 0);
	int i = 0;
	while (tien > 0)
	{
		if (tien < menhGia[i])
		{
			i++;
		}
		else
		{
			tien = tien - menhGia[i];
			cout[i]++;
			i = 0;
		}
	}
	printf("So tien cua ban doi duoc  :\n");
	for (i = 0; i < 9; i++)
	{
		if (cout[i] > 0)
		{
			printf("\t%d to %d nghin dong (VND).\n", cout[i], menhGia[i]);
		}
	}

} // End of chucnang5

// Chuong trinh 6:Tinh lai suat vay ngan hang
void chucnang6()
{

	unsigned long long tienVay, goc, lai, tienTra, tienConlai;
	do
	{
		printf("Moi ban nhap so tien ban can vay la :");
		scanf("%llu", &tienVay);
	} while (tienVay <= 0);
	tienConlai = tienVay;
	goc = tienVay / 12; // tien goc tra trong thang thu 1
	int n;
	printf("|  Ky han  |  Lai phai tra  |  Goc phai tra  |  So tien phai tra  |  So tien con lai  |\n");
	printf("---------------------------------------------------------------------------------------\n");
	for (n = 1; n <= 12; n++)
	{
		lai = tienConlai * 5 / 100;
		tienTra = goc + lai;
		tienConlai = tienConlai - goc;
		printf("|%7llu%15llu%20llu%20llu%20llu   |\n", n, lai, goc, tienTra, tienConlai);
	}
} // End Off chucnang6

// Chuong trinh 7:Vay tien mua Xe
// From Line 286 to Line 320
void laiSuat(int tienVay)
{
	int goc, lai, tienTra, tienConlai;
	tienConlai = tienVay;
	goc = tienVay / 288; // tien goc phai tra trong 24 nam
	int n;
	printf("|  Ky han  |  Lai phai tra  |  Goc phai tra  |  So tien phai tra  |  So tien con lai  |\n");
	printf("---------------------------------------------------------------------------------------\n");
	for (n = 1; n <= 288; n++)
	{
		lai = tienConlai * 6 / 100;
		tienTra = goc + lai;
		tienConlai = tienConlai - goc;
		printf("|%7d%15d$%20d$%20d$%20d$   |\n", n, lai, goc, tienTra, tienConlai);
		if (n % 12 == 0)
		{
			printf("----------------------------------Het ky han 1 nam------------------------------------------\n");
		}
	}
	printf("-----------------------------------------------------------------------------");
}

void chucnang7()
{
	int tienXe;
	printf("Chuong trinh tra gop mua xe :\n");
	printf("So tien ban muon vay de mua xe la : ");
	scanf("%d", &tienXe);
	int tienVay = 0;
	tienVay = tienXe * 80 / 100;
	printf("Tien vay : %d \n", tienVay);
	if (tienVay > 500000000)
	{
		printf("So tien vay cua ban vuot han muc quy dinh.");
	}
	else
	{
		laiSuat(tienVay);
	}
} // End of chucnang7

// Chuong trinh 8:Sap xep thong tin sinh vien
// From Line 287 to Line 354
struct sinhVien
{
	char tenSV[100];
	float diemTB;
};

void nhapsv(struct sinhVien sv[], int a)
{
	for (int i = 0; i < a; i++)
	{
		printf("Sinh vien thu %d \n", i + 1);
		fflush(stdin);
		printf("Moi ban nhap ho va ten sinh vien la: ");
		gets(sv[i].tenSV);
		fflush(stdin);
		printf("Moi ban nhap diem trung binh la: ");
		scanf("%f", &sv[i].diemTB);
		fflush(stdin);
		printf("\n");
	}
} // end of nhap

void xuatsv(struct sinhVien sv)
{
	fflush(stdin);
	printf("Ho ten sinh vien la: %s\n", sv.tenSV);
	printf("Diem trung binh la: %.2f\n", sv.diemTB);
	if (sv.diemTB >= 9)
	{
		printf("Hoc luc: Xuat sac.\n");
	}
	else if (sv.diemTB >= 8)
	{
		printf("Hoc luc: Gioi.\n");
	}
	else if (sv.diemTB >= 6.5)
	{
		printf("Hoc luc: Kha.\n");
	}
	else if (sv.diemTB >= 5)
	{
		printf("Hoc luc : Trung binh.\n");
	}
	else
	{
		printf("Hoc luc : Yeu.");
	}
	printf("\n");
} // end of xuat

void sapxepsv(struct sinhVien sv[], int a)
{
	for (int i = 0; i < a - 1; i++)
	{
		for (int j = i + 1; j < a; j++)
		{
			if (sv[i].diemTB > sv[j].diemTB)
			{
				struct sinhVien temp;
				temp = sv[i];
				sv[i] = sv[j];
				sv[j] = temp;
			}
		}
	}
} // end of sapxep

void chucnang8()
{
	int n;
	struct sinhVien sv[1000];
	do
	{
		printf("Nhap vao so luong sinh vien > 0 la:");
		scanf("%d", &n);
		nhapsv(sv, n);
	} while (n <= 0 || n > 1000);
	printf("Thong tin sinh vien sau khi da sap xep la: \n");
	sapxepsv(sv, n);
	for (int i = 0; i < n; i++)
	{
		printf("Sinh vien thu %d \n", i + 1);
		xuatsv(sv[i]);
	}
} // END of chucnang8

// Chuong trinh :Game FPOLY-LOTT !
// From Line 356 to Line 397
int myRand(int min, int max)
{ // Ramdom Function from MIN to MAX
	int temp;
	if (min > max)
	{
		temp = min;
		min = max;
		max = temp;
	}
	return temp = min + rand() % (max + 1 - min);
} // end of Ramdom Function

void chucnang9()
{
	int so1, so2;
	do
	{
		printf("- Moi ban nhap vao 2 so muon mua tu 01 ==>> 15 la :\n");
		printf("+ So thu nhat la : ");
		scanf("%d", &so1);
		printf("+ So thu hai la: ");
		scanf("%d", &so2);
	} while (so1 < 1 || so2 > 15 || so2 < 1 || so1 > 15);
	int x, i;
	int count = 0;
	srand(time(0));
	for (i = 1; i <= 2; i++)
	{
		int x = myRand(1, 15);
		printf("So trung thuong la so : %d\n", x);
		if (so1 == x)
		{
			count++;
		}
		if (so2 == x)
		{
			count++;
		}
	}
	if (count == 1)
	{
		printf("Ban da trung 1 so\n\a");
		printf("Chuc mung ban da trung giai nhi.");
	}
	else if (count == 2)
	{
		printf("Ban da trung 2 so\n\a");
		printf("Chuc mung ban da trung giai nhat.");
	}
	else
	{
		printf("Rat tiec! So ban chon khong trung.\n");
		printf("Chuc ban may man lan sau.");
	}
}

// Chuong trinh :Tinh tong ;hieu; tich; thuong hai phan so!
// From Line 401 to Line 470
int UCLN(int x, int y)
{
	if (x == 0 || y == 0)
	{
		return (x == 0) ? y : x;
	}
	else
	{
		while (x != y)
		{
			if (x > y)
			{
				x = x - y;
			}
			else
			{
				y = y - x;
			}
		}
		return x;
	}
}
void tong(int tu, int mau)
{
	int tuSo = tu / UCLN(abs(tu), abs(mau));
	int mauSo = mau / UCLN(abs(tu), abs(mau));
	printf("Tong = %d/%d\n", tuSo, mauSo);
}
void hieu(int tu, int mau)
{
	int tuSo = tu / UCLN(abs(tu), abs(mau));
	int mauSo = mau / UCLN(abs(tu), abs(mau));
	printf("Hieu = %d/%d\n", tuSo, mauSo);
}
void tich(int tu, int mau)
{
	int tuSo = tu / UCLN(abs(tu), abs(mau));
	int mauSo = mau / UCLN(abs(tu), abs(mau));
	printf("Tich = %d/%d\n", tuSo, mauSo);
}
void thuong(int tu, int mau)
{
	int tuSo = tu / UCLN(abs(tu), abs(mau));
	int mauSo = mau / UCLN(abs(tu), abs(mau));
	printf("Thuong = %d/%d\n", tuSo, mauSo);
}
void chucnang10()
{
	int tuST1, mauST1, tuST2, mauST2;
	printf("Moi ban nhap vao 2 so :\n");
	printf("\tSo thu 1 la :\n");
	printf("Tu so la :");
	scanf("%d", &tuST1);
	do
	{
		printf("Mau so != 0 la :");
		scanf("%d", &mauST1);
	} while (mauST1 == 0);
	printf("\tSo thu 2 la :\n");
	printf("Tu so la :");
	scanf("%d", &tuST2);
	do
	{
		printf("Mau so != 0 la :");
		scanf("%d", &mauST2);
	} while (mauST2 == 0);
	// Phan so thu 1 la a/b
	// Phan so thu 2 la x/y
	int ay = tuST1 * mauST2;
	int ax = tuST1 * tuST2;
	int bx = mauST1 * tuST2;
	int by = mauST1 * mauST2;
	int tuSoOffTong = tuST1 * mauST2 + mauST1 * tuST2;
	int tuSoOffHieu = tuST1 * mauST2 - mauST1 * tuST2;
	printf("Tong cua 2 phan so la:\n");
	tong(tuSoOffTong, by);
	printf("Hieu cua 2 phan so la:\n");
	hieu(tuSoOffHieu, by);
	printf("Tich cua 2 phan so la:\n");
	tich(ax, by);
	printf("Thuong cua 2 phan so la:\n");
	thuong(ay, bx);
} // End of chucnang10

// Main FUll Option Chose//
int main()
{
	int chon = 0; // Khai bao bien chon

	do
	{
		printf("\n");
		printf("++==================(Assignment-Nguyen Duc Khai-PH44630)================++\n");
		printf("|#|1.Chuc nang so 1: Kiem tra so nguyen.                                |#|\n");
		printf("|#|2.Chuc nang so 2: Tim uoc so chung va boi so chung cua 2 so.         |#|\n");
		printf("|#|3.Chuc nang so 3: Tinh tien cho quan karaoke.                        |#|\n");
		printf("|#|4.Chuc nang so 4: Tinh tien dien.                                    |#|\n");
		printf("|#|5.Chuc nang so 5: Doi tien.                                          |#|\n");
		printf("|#|6.Chuc nang so 6: Tinh lai suat vay ngan hang vay tra gop.           |#|\n");
		printf("|#|7.Chuc nang so 7: Vay tien mua xe.                                   |#|\n");
		printf("|#|8.Chuc nang so 8: Sap xep thong tin sinh vien.                       |#|\n");
		printf("|#|9.Chuc nang so 9: Xay dung game FPOLY-LOT.                           |#|\n");
		printf("|#|10.Chuc nang so 10: Tinh toan phan so.                               |#|\n");
		printf("|#|0.Thoat khoi chuong trinh.                                           |#|\n");
		printf("|##=====================*===*===*===*===*===*===*===*===================##|\n");
		printf("Moi bam phim tuong ung de chon chuc nang: ");
		scanf("%d", &chon);
		system("cls"); // Clean man hinh !
		// su dung Switch case
		switch (chon)
		{
		case 1:
			chucnang1();
			break;
		case 2:
			chucnang2();
			break;
		case 3:
			chucnang3();
			break;
		case 4:
			chucnang4();
			break;
		case 5:
			chucnang5();
			break;
		case 6:
			chucnang6();
			break;
		case 7:
			chucnang7();
			break;
		case 8:
			chucnang8();
			break;
		case 9:
			chucnang9();
			break;
		case 10:
			chucnang10();
			break;
		case 0:
			printf("*~~*~~*~~*~~Good Bye! and See you again soon!~~*~~*~~*~~*");
			break;
		default:
			printf("Moi ban chon lai chuong trinh tu 1 =>> 10 :");
		}
	} while (chon != 0);
	return 0;
}
