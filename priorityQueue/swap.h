#pragma once

template<typename ElumType>
void swap(ElumType &_a, ElumType &_b) {
	ElumType _c = _a;
	_a = _b;
	_b = _c;
}