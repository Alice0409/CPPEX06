#include <iostream>
using namespace std;
#include "Box.h"

unsigned int InputUINT(string message, unsigned int max) {
	unsigned int i;
	while (true) {
		cout << message;
		cin >> i;
		if (i < max) {
			break;
		}
		else {
			cout << "���̓G���[" << endl;
		}
	}
	return i;
}

int main()
{
	//�N���l�R�̃T�C�Y https://www.kuronekoyamato.co.jp/ytc/search/payment/size/
	double kuronekoSize[] = { 60,80,100,120,160 };

	//JP�̃T�C�Y https://www.post.japanpost.jp/send/fee/kokunai/parcel.html#01
	double jpSize[] = { 60,80,100,120,140,160,170 };

	//����̃T�C�Y https://www.sagawa-exp.co.jp/send/fare/list/sagawa_faretable/attention.html
	double sagawaSize[] = { 60,80,100,140,160 };

	double Weight[] = { 25,30 };
	double MaxWeight = 0;
	double weight;

	unsigned int i = InputUINT("�`��?(0.���^ 1.�~��)�F", 2);
	Pack* pack = nullptr;
	switch (i) {
	case 0:
		pack = new Box();
		break;
	case 1:
		pack = new Cylinder();
		break;
	default:
		break;
	}
	pack->InputSize();

	Takuhai takuhai = Takuhai();
	takuhai.pack = pack;

	cout << "�d������́F";
	cin >> weight;

	i = InputUINT("�Ǝ҂�?(0.�N���l�R 1.JP 2.����)�F", 3);
	switch (i) {
	case 0:
		takuhai.packSizeList = new PackSizeList(kuronekoSize, _countof(kuronekoSize));
		MaxWeight = Weight[0];
		break;
	case 1:
		takuhai.packSizeList = new PackSizeList(jpSize, _countof(jpSize));
		MaxWeight = Weight[0];
		break;
	case 2:
		takuhai.packSizeList = new PackSizeList(sagawaSize, _countof(sagawaSize));
		MaxWeight = Weight[1];
		break;
	default:
		break;
	}
	double packSize = takuhai.GetPackSize();
	if (packSize != 0 && weight <= MaxWeight) {
		cout << packSize << "�T�C�Y�ő���܂�";
	}
	else {
		cout << "��z�ł͑���܂���";
	}

	delete(pack);
	return 0;
}