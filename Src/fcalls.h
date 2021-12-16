#pragma once

template<typename R, typename F, typename ...A>
inline R stdcall(F function, A...args) {
	return reinterpret_cast<R(__stdcall*)(A...)>(function)(args...);
}

template<typename R, typename F, typename ...A>
inline R fastcall(F function, A...args) {
	return reinterpret_cast<R(__fastcall*)(A...)>(function)(args...);
}

template<typename R, typename F, typename T, typename ...A>
inline R thiscall(F function, T _this, A...args) {
	return reinterpret_cast<R(__fastcall*)(T, LPVOID, A...)>(function)(_this, NULL, args...);
}