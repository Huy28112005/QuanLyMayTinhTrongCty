#pragma once
#include "MayTinh.h"
using namespace toLower;

class LapTop : public MayTinh
{
private:
	string mauSac;
public:
	LapTop() : MayTinh(), mauSac("") {}
	LapTop(string mauSac, unsigned int maMay, string nhanHieu, string hangSanXuat,
		unsigned short namSanXuat, double giaTien, unsigned int soLuong) :
		MayTinh(maMay, nhanHieu, hangSanXuat, namSanXuat, giaTien, soLuong), mauSac(mauSac) {
	}
	~LapTop() = default;
	// getter setter
	void setMauSac(const string& mau) { mauSac = mau; }
	string getMauSac() const { return mauSac; }
	// nhap xuat
	void nhap() {
		MayTinh::nhap();
		cin.ignore();
		cout << "\nNhap mau sac Lap top: ";
		getline(cin, mauSac);
	}
	void xuat() const {
		MayTinh::xuat();
		cout << "Mau sac LapTop: " << mauSac << rows2;
		cout << "Thanh tien: " << thanhTien() << " VND" << rows2;
	}
	double thanhTien() const {
		if (toLowerStr(mauSac) == "bac")
			return (soLuong * giaTien) * 1.03;
		return soLuong * giaTien;
	}
	LapTop* clone() const override {
		return new LapTop(*this);
	}
};

