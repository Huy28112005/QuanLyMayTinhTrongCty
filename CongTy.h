#pragma once
#include "LapTop.h"
#include "Desktop.h"
#include "MayTinh.h"
#include "algorithm"
#include <vector>

namespace Utility {
	static Desktop* toDesktop(MayTinh* may) {
		return dynamic_cast<Desktop*>(may);
	}
	static LapTop* toLapTop(MayTinh* may) {
		return dynamic_cast<LapTop*>(may);
	}
}
using namespace Utility;

class CongTy
{
private:
	unsigned int soLuongMT;
	MayTinh** dsMayTinh;

	void clear() {
		for (unsigned int i = 0; i < soLuongMT; ++i)
			delete dsMayTinh[i];
		delete[] dsMayTinh;
		dsMayTinh = nullptr;
	}

	double minDouble(double a, double b) const {
		return (a < b) ? a : b;
	}
public:
	CongTy() : soLuongMT(0), dsMayTinh(nullptr){}
	CongTy(unsigned int soLuongMT, MayTinh** dsMay) : soLuongMT(soLuongMT) {
		dsMayTinh = new MayTinh * [soLuongMT];
		transform(dsMay, dsMay + soLuongMT, dsMayTinh, [](MayTinh* may) {
			return may->clone();
			});
	}
	// copy
	CongTy(const CongTy& cty) : soLuongMT(cty.soLuongMT) {
		dsMayTinh = new MayTinh * [soLuongMT];
		transform(cty.dsMayTinh, cty.dsMayTinh + cty.soLuongMT, dsMayTinh,
			[](MayTinh* may) {
				return may->clone();
			});
	}
	// operator =
	CongTy& operator=(const CongTy& cty) {
		if (this != &cty) {
			clear();
			soLuongMT = cty.soLuongMT;
			dsMayTinh = new MayTinh * [soLuongMT];
			transform(cty.dsMayTinh, cty.dsMayTinh + cty.soLuongMT, dsMayTinh,
				[](MayTinh* may) {
					return may->clone();
				});
		}
		return *this;
	}
	// hàm huỷ
	~CongTy() {
		clear();
	}
	// getter setter
	unsigned int getSoLuongMT() const { return soLuongMT; } 
	void setSoLuongMT(unsigned int soLuong) { soLuongMT = soLuong; }
	// nhập xuất
	void nhap() {
		cout << "\nNhap so Luong May tinh trong cong ty: "; cin >> soLuongMT;
		cin.ignore();
		if (soLuongMT == 0) return;
		dsMayTinh = new MayTinh * [soLuongMT];
		for (int i = 0; unsigned int(i) < soLuongMT; ++i) {
			string loai;
			cout << "\nNhap loai May Tinh (desktop / laptop): ";
			getline(cin, loai);
			loai = toLowerStr(loai);
			if (loai == "desktop") { dsMayTinh[i] = new Desktop(); }
			else if (loai == "laptop") { dsMayTinh[i] = new LapTop(); }
			else {
				cout << "\nNhap loai sai! vui long nhap lai.";
				--i;
				continue;
			}
			dsMayTinh[i]->nhap();
		}
	}
	void xuat() const {
		cout << "\nSo luong may tinh co trong cong ty: " << soLuongMT << rows2;
		for (unsigned int i = 0; i < soLuongMT; ++i) {
			dsMayTinh[i]->xuat();
			cout << "------------" << rows2;
		}
	}
	// tính tổng thành tiền cho từng loại
	double tongThanhTienDesktop() const {
		if (soLuongMT == 0) return 0.0;
		double tong = 0.0;
		for (unsigned int i = 0; i < soLuongMT; ++i) {
			Desktop* dsk = toDesktop(dsMayTinh[i]);
			if (dsk) { tong += dsMayTinh[i]->thanhTien(); }
		}
		return tong;
	}
	double tongThanhTienLapTop() const {
		if (soLuongMT == 0) return 0.0;
		double tong = 0.0;
		for (unsigned int i = 0; i < soLuongMT; ++i) {
			LapTop* lap = toLapTop(dsMayTinh[i]);
			if (lap) { tong += dsMayTinh[i]->thanhTien(); }
		}
		return tong;
	}
	double trungBinhCongDonGiaDesktop() const {
		if (soLuongMT == 0) return 0.0;
		double tong = 0.0;
		unsigned int dem = 0;
		for (unsigned int i = 0; i < soLuongMT; ++i) {
			Desktop* dsk = toDesktop(dsMayTinh[i]);
			if (dsk) {
				++dem;
				tong += dsMayTinh[i]->getGiaTien();
			}
		}
		return tong / dem;
	}
	double minLapTopDellBac() const {
		double thanhTienMax = numeric_limits<double>::max();
		bool kiemTra = false;
		
		for (unsigned int i = 0; i < soLuongMT; ++i) {
			LapTop* lap = toLapTop(dsMayTinh[i]);
			if (lap && toLowerStr(lap->getHangSanXuat()) == "dell") {
				if (toLowerStr(lap->getMauSac()) == "bac") {
					thanhTienMax = minDouble(thanhTienMax, lap->thanhTien());
					kiemTra = true;
				}
			}
		}
		if (!kiemTra) return 0.0;
		return thanhTienMax;
	}

	MayTinh** listLapTopTimThay(unsigned int& slNew) const {
		if (soLuongMT == 0) return nullptr;
		double minLapDellBac = minLapTopDellBac();
		vector<MayTinh*> list;
		for (unsigned int i = 0; i < soLuongMT; ++i) {
			LapTop* lap = toLapTop(dsMayTinh[i]);
			if (lap && toLowerStr(lap->getHangSanXuat()) == "dell") {
				if (toLowerStr(lap->getMauSac()) == "bac" 
					&& lap->thanhTien() == minLapDellBac)
				{
					list.push_back(dsMayTinh[i]);
				}
			}
		}
		slNew = static_cast<unsigned int>(list.size());
		MayTinh** listNew = new MayTinh * [slNew];
		transform(list.begin(), list.end(), listNew, [](MayTinh* may) {
			return may->clone();
			});
		return listNew;
	}
};

