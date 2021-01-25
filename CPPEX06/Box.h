#pragma once

class Pack {
public:
	virtual double GetPackSize() = 0;
	virtual void InputSize() = 0;
};

class Box :public Pack {
public:
	double width;
	double height;
	double depth;
	double GetPackSize() override {
		return width + height + depth;
	}
	Box(double w = 0, double h = 0, double d = 0) {
		width = w;
		height = h;
		depth = d;
	}
	void InputSize() override {
		std::cout << "幅を入力：";
		std::cin >> width;
		std::cout << "高さを入力：";
		std::cin >> height;
		std::cout << "奥行きを入力：";
		std::cin >> depth;
	}
};

class Cylinder :public Pack {
public:
	double radius;
	double height;
	double GetPackSize() override {
		return radius * 4 + height;
	}
	void InputSize() override {
		std::cout << "半径を入力：";
		std::cin >> radius;
		std::cout << "高さを入力：";
		std::cin >> height;
	}
};


class PackSizeList {
public:
	double* size;
	unsigned int length;
	PackSizeList(double s[], unsigned int l) {
		size = s;
		length = l;
	}
};


class Takuhai {
public:
	Pack* pack;
	PackSizeList* packSizeList;
	double GetPackSize() {
		double judge = 0;
		for (int i = 0; i < packSizeList->length; i++) {
			if (pack->GetPackSize() <= packSizeList->size[i]) {
				judge = packSizeList->size[i];
				break;
			}
		}
		return judge;
	}
};

