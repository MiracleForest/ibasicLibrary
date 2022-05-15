/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:type.hpp
* @creation time:2022.4.30.12:06
* @created by:Lovelylavender4
* -----------------------------------------------------------------------------
* type
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I_TYPE___
#define ___MIRACLEFOREST_I_TYPE___

#include "../../family/imacrofamily.h"
#include <windows.h>
#include <string>
#include <stringapiset.h>
#include <atlstr.h>

/// <summary>
/// 
/// </summary>
namespace i::core {

	/// <summary>
	/// 
	/// </summary>
	enum class typeList {
		unkType,
		itype,
		number,
		numberArray_const_iterator,
		numberArray_iterator,
		numberArray
	};
	using iType = typeList;

	/// <summary>
	/// 
	/// </summary>
	class itype {
	public:
		itype() :mType(iType::unkType) { }

		itype(iType t) :mType(t) { }

		itype(const itype&) = delete;

		void operator=(const itype&) = delete;

		~itype() {}
	public:

		/// <summary>
		/// get type
		/// </summary>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>type enum</returns>
		itype getType()const {
			return typeList::itype;
		}

		/// <summary>
		/// get data
		/// </summary>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>data</returns>
		iType data()const { return mType; }

		/// <summary>
		/// set data
		/// </summary>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <param name="t">new data</param>
		void setdata(iType t) { mType = t; }

		/// <summary>
		/// Get the name of the type enum
		/// </summary>
		/// <param name="t">type enum</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>Type Name</returns>
		static const char* getString(iType t) {
			switch (t) {
			case iType::unkType: {

			}
			case iType::itype: {

			}
			case iType::number: {

			}
			case iType::numberArray_const_iterator: {

			}
			case iType::numberArray_iterator: {

			}
			case iType::numberArray: {

			}
			default: {

			}
			}
		}

		/// <summary>
		/// Get the name of the type
		/// </summary>
		/// <typeparam name="Type">type</typeparam>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>Type Name</returns>
		template<typename Type>
		static const char* getTypeString() {
			return typeid(Type).name();
		}

		/// <summary>
		/// Get the name of the type
		/// </summary>
		/// <typeparam name="Type">-</typeparam>
		/// <param name="t">type</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>Type Name</returns>
		template<typename Type>
		static const char* getTypeString(Type t) {
			return typeid(t).name();
		}

		/// <summary>
		/// other2string
		/// </summary>
		/// <param name="value">Value</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>string</returns>
		template<typename Type>
		static std::string toStdString(Type value) {
			return std::to_string(value);
		}

		/// <summary>
		/// const char* 2string
		/// </summary>
		/// <param name="s">const char* value</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>string</returns>
		static std::string toStdString(const char* value) {
			return std::string(value);
		}
				
		/// <summary>
		/// char2string
		/// </summary>
		/// <param name="s">char value</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>string</returns>
		static std::string toStdString(char value) {
			return std::string(1, value);
		}


		/// <summary>
		/// string2string
		/// </summary>
		/// <param name="value">string value</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>string</returns>
		static std::string toStdString(const std::string& value) {
			return value;
		}

		/// <summary>
		/// wchar_t2string
		/// </summary>
		/// <param name="value">wchar_t</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>string</returns>
		static std::string toStdString(const wchar_t value) {
			return wideChar2UTF8(std::wstring(1, value));
		}

		/// <summary>
		/// const wchar_t* 2string
		/// </summary>
		/// <param name="value">const wchar_t* value</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>string</returns>
		static std::string toStdString(const wchar_t* value) {
			return wideChar2UTF8(value);
		}

		/// <summary>
		/// wstring2string
		/// </summary>
		/// <param name="value">wstring value</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>string</returns>
		static std::string toStdString(const std::wstring& value) {
			return wideChar2UTF8(value);
		}

		/// <summary>
		/// toWideChar
		/// </summary>
		/// <param name="code_page">code_page</param>
		/// <param name="src_str">src_str</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>wstring</returns>
		static std::wstring toWideChar(std::uint32_t code_page, const std::string& src_str) {
			if (src_str.empty()) {
				return L"";
			}
			auto len = MultiByteToWideChar(code_page, 0, src_str.c_str(), -1, nullptr, 0);
			if (!len) {
				return L"";
			}
			auto wstr_c = new wchar_t[len + 1];
			if (!wstr_c) {
				return L"";
			}
			memset(wstr_c, 0, len + 1);
			MultiByteToWideChar(code_page, 0, src_str.c_str(), -1, wstr_c, len);
			std::wstring wstr(wstr_c);
			delete[] wstr_c;
			return wstr;
		}

		/// <summary>
		/// wideChar2string
		/// </summary>
		/// <param name="code_page">code_page</param>
		/// <param name="src_wstr">src_wstr</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>string</returns>
		static std::string fromWideChar(std::uint32_t code_page, const std::wstring& src_wstr) {
			if (src_wstr.empty()) {
				return "";
			}
			auto len = WideCharToMultiByte(code_page, 0, src_wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
			if (!len) {
				return "";
			}
			auto str_c = new char[len + 1];
			if (!str_c) {
				return "";
			}
			memset(str_c, 0, len + 1);
			WideCharToMultiByte(code_page, 0, src_wstr.c_str(), -1, str_c, len, nullptr, nullptr);
			std::string str(str_c);
			delete[] str_c;
			return str;
		}

		/// <summary>
		/// isWideCharHex
		/// </summary>
		/// <param name="wch">wchar_t value</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>isWideCharHex</returns>
		static bool isWideCharHex(wchar_t wch) {
			return (wch >= L'0' && wch <= L'9') || (wch >= L'a' && wch <= L'f') || (wch >= L'A' && wch <= L'F');
		}

		/// <summary>
		/// wideChar2hex
		/// </summary>
		/// <param name="wch">wchar_t value</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>hex</returns>
		static std::uint8_t wideChar2hex(wchar_t wch) {
			if (wch >= L'0' && wch <= L'9') {
				return wch - L'0';
			}
			else if (wch >= L'a' && wch <= L'f') {
				return wch - L'a' + 10;
			}
			else {// wch >= L'A' && wch <= L'F'
				return wch - L'A' + 10;
			}
		}

		/// <summary>
		/// hex2char
		/// </summary>
		/// <param name="hex">hex value</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>char</returns>
		static char hex2char(uint8_t hex) {
			if (hex <= 9) {
				return '0' + hex;
			}
			else { // hex >= 10 && hex <= 15
				return 'a' + hex - 10;
			}
		}

		/// <summary>
		/// wideChar2UCS2
		/// </summary>
		/// <param name="wch">wchar_t value</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>string</returns>
		static std::string wideChar2UCS2(wchar_t wch) {
			auto wch_value = static_cast<uint16_t>(wch);
			std::string ucs2;
			ucs2.reserve(6);
			ucs2 += "\\u";
			ucs2 += hex2char(wch_value >> 12);
			ucs2 += hex2char((wch_value >> 8) & 0xf);
			ucs2 += hex2char((wch_value >> 4) & 0xf);
			ucs2 += hex2char(wch_value & 0xf);
			return ucs2;
		}

		/// <summary>
		/// hex2wideChar
		/// </summary>
		/// <param name="hex">hex value</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>char</returns>
		static char hex2wideChar(uint8_t hex) {
			if (hex <= 9) {
				return L'0' + hex;
			}
			else {
				return L'a' + hex - 10;
			}
		}

		/// <summary>
		/// wideChar2wideCharUCS2
		/// </summary>
		/// <param name="wch">wchar_t value</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>wstring</returns>
		static std::wstring wideChar2wideCharUCS2(wchar_t wch) {
			auto wch_value = static_cast<uint16_t>(wch);
			std::wstring ucs2;
			ucs2.reserve(6);
			ucs2 += L"\\u";
			ucs2 += hex2wideChar(wch_value >> 12);
			ucs2 += hex2wideChar((wch_value >> 8) & 0xf);
			ucs2 += hex2wideChar((wch_value >> 4) & 0xf);
			ucs2 += hex2wideChar(wch_value & 0xf);
			return ucs2;
		}

		/// <summary>
		/// Convert a UTF8 encoded string to a wide string
		/// </summary>
		/// <param name="utf8" The UTF8 encoded string to be converted</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>The converted wide string</returns>
		static std::wstring UTF82wideChar(const std::string& utf8) {
			return toWideChar(CP_UTF8, utf8);
		}

		/// <summary>
		/// Convert wide strings to UTF8-encoded strings
		/// </summary>
		/// <param name="wstr">The wide string to be converted into an encoding</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>The converted UTF8 encoded string</returns>
		static std::string wideChar2UTF8(const std::wstring& wstr) {
			return fromWideChar(CP_UTF8, wstr);
		}

		/// <summary>
		/// Convert ANSI-encoded strings to wide strings
		/// </summary>
		/// <param name="ansi">ANSI-encoded string to be converted</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>The converted wide string</returns>
		static std::wstring ANSI2wideChar(const std::string& ansi) {
			return toWideChar(CP_ACP, ansi);
		}

		/// <summary>
		/// Convert wide strings to ANSI-encoded strings
		/// </summary>
		/// <param name="wstr">The wide string to be converted into an encoding</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>Converted ANSI-encoded string</returns>
		static std::string wideChar2ANSI(const std::wstring& wstr) {
			return fromWideChar(CP_ACP, wstr);
		}

		/// <summary>
		/// Convert ANSI-encoded mixed UCS2 encoded strings to wide strings
		/// </summary>
		/// <param name="ansi_with_ucs2">ANSI-encoded mixed UCS2 encoded strings to be converted</param>
		/// <param name="not_unescape_wide_chars">Wide character set without inverse escaping</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>The converted wide string</returns>
		static std::wstring ANSIWithUCS22WideChar(const std::string& ansi_with_ucs2, const std::wstring& not_unescape_wide_chars) {
			return unescapeWideChar(ANSI2wideChar(ansi_with_ucs2), not_unescape_wide_chars);
		}

		/// <summary>
		/// Convert wide strings to ANSI-encoded mixed UCS2 encoded strings
		/// </summary>
		/// <param name="wstr">Wide string of codes to be converted</param>
		/// <param name="force_escape_wide_chars">Wide set of characters to be forcibly escaped</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>Converted ANSI-encoded mixed UCS2 encoded strings</returns>
		static std::string wideChar2ANSIWithUCS2(const std::wstring& wstr, const std::wstring& force_escape_wide_chars) {
			if (wstr.empty()) {
				return "";
			}
			BOOL need_escape = FALSE;
			if (!force_escape_wide_chars.empty()) {
				for (auto wch : wstr) {
					if (force_escape_wide_chars.find(wch) != std::wstring::npos) {
						need_escape = TRUE;
						break;
					}
				}
			}
			int len;
			if (need_escape == FALSE) {
				need_escape = FALSE;
				len = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, nullptr, 0, nullptr, &need_escape);
				if (!len) {
					return "";
				}
			}
			if (!need_escape) {
				auto ansi_c = new char[len + 1];
				if (!ansi_c) {
					return "";
				}
				memset(ansi_c, 0, len + 1);
				WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, ansi_c, len, nullptr, nullptr);
				std::string ansi(ansi_c);
				delete[] ansi_c;
				return ansi;
			}
			else {
				auto wstr_c_tmp = new wchar_t[2];
				if (!wstr_c_tmp) {
					return "";
				}
				wstr_c_tmp[1] = L'\0';
				auto ansi_c_tmp = new char[8];
				if (!ansi_c_tmp) {
					delete[] wstr_c_tmp;
					return "";
				}
				std::string ansi_with_ucs2;
				for (auto it : wstr) {
					if (force_escape_wide_chars.find(it) == std::wstring::npos) {
						if (static_cast<uint16_t>(it) <= 0x7f) {
							ansi_with_ucs2 += static_cast<char>(it);
							continue;
						}
						else if ((uint16_t)(it) >> 11 != 0b11011) {
							need_escape = FALSE;
							wstr_c_tmp[0] = it;
							auto len = WideCharToMultiByte(CP_ACP, 0, wstr_c_tmp, -1, nullptr, 0, nullptr, &need_escape);
							if (!len) {
								delete[] wstr_c_tmp;
								delete[] ansi_c_tmp;
								return "";
							}
							if (!need_escape) {
								memset(ansi_c_tmp, 0, len + 1);
								WideCharToMultiByte(CP_ACP, 0, wstr_c_tmp, -1, ansi_c_tmp, len, nullptr, nullptr);
								ansi_with_ucs2 += ansi_c_tmp;
								continue;
							}
						}
					}
					ansi_with_ucs2 += wideChar2UCS2(it);
				}
				delete[] wstr_c_tmp;
				delete[] ansi_c_tmp;
				return ansi_with_ucs2;
			}
		}

		/// <summary>
		/// Escape wide strings
		/// </summary>
		/// <param name="wstr">Wide string containing the wide characters to be escaped</param>
		/// <param name="escape_wide_chars">Wide set of characters to be escaped</param>
		/// <warning>null</warning>
		/// <include>
		/// string
		/// </include>
		/// <bug>null</bug>
		/// <returns>The escaped wide string</returns>
		static std::wstring escapeWideChar(const std::wstring& wstr, const std::wstring& escape_wide_chars) {
			if (wstr.empty()) {
				return L"";
			}
			if (escape_wide_chars.empty()) {
				return wstr;
			}
			std::wstring wstr_with_ucs2;
			for (wchar_t wch : wstr) {
				if (escape_wide_chars.find(wch) == std::wstring::npos) {
					wstr_with_ucs2 += wch;
				}
				else {
					wstr_with_ucs2 += wideChar2wideCharUCS2(wch);
				}
			}
			return wstr_with_ucs2;
		}

		/// <summary>
		/// Inverse Escape Wide String
		/// </summary>
		/// <param name="wstr_with_ucs2">Wide strings to be inverse-translated</param>
		/// <param name="not_unescape_wide_chars">Wide character set without inverse escaping</param>
		/// <warning>null</warning>
		/// <include>
		/// string
		/// </include>
		/// <bug>null</bug>
		/// <returns>Wide string after inverse escape</returns>
		static std::wstring unescapeWideChar(const std::wstring& wstr_with_ucs2, const std::wstring& not_unescape_wide_chars) {
			if (wstr_with_ucs2.empty()) {
				return L"";
			}
			std::wstring wstr;
			wstr.reserve(wstr_with_ucs2.size());
			std::wstring ucs2_tmp;
			ucs2_tmp.reserve(6);
			for (auto it = wstr_with_ucs2.cbegin(), cend = wstr_with_ucs2.cend(); it != cend; it++) {
				if (*it == L'\\') {
					ucs2_tmp = L"\\";
					it++;
					if (it != cend && *it == L'u') {
						ucs2_tmp += L'u';
						it++;
						if (it != cend && isWideCharHex(*it)) {
							ucs2_tmp += *it;
							it++;
							if (it != cend && isWideCharHex(*it)) {
								ucs2_tmp += *it;
								it++;
								if (it != cend && isWideCharHex(*it)) {
									ucs2_tmp += *it;
									it++;
									if (it != cend && isWideCharHex(*it)) {
										ucs2_tmp += *it;
										auto wch = UCS22WideChar(ucs2_tmp);
										if (not_unescape_wide_chars.find(wch) == std::wstring::npos) {
											wstr += wch;
											continue;
										}
									}
								}
							}
						}
					}
					wstr += ucs2_tmp;
					if (it == cend) {
						break;
					}
				}
				wstr += *it;
			}
			return wstr;
		}

		/// <summary>
		/// Escape UTF8-encoded strings
		/// </summary>
		/// <param name="utf8">String containing the UTF8 encoding to be escaped</param>
		/// <param name="escape_utf8_chars">The character set of the UTF8 encoding to be escaped</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>The escaped UTF8 encoded string</returns>
		static std::string escapeUTF8(const std::string& utf8, const std::string& escape_utf8_chars) {
			return wideChar2UTF8(escapeWideChar(UTF82wideChar(utf8), UTF82wideChar(escape_utf8_chars)));
		}

		/// <summary>
		/// Inverted UTF8-encoded strings
		/// </summary>
		/// <param name="utf8_with_ucs2">UTF8 encoded string to be escaped</param>
		/// <param name="not_unescape_utf8_chars">UTF8 encoded character set without escaping</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>Reverse-escaped UTF8-encoded string</returns>
		static std::string unescapeUTF8(const std::string& utf8_with_ucs2, const std::string& not_unescape_utf8_chars) {
			return wideChar2UTF8(unescapeWideChar(UTF82wideChar(utf8_with_ucs2), UTF82wideChar(not_unescape_utf8_chars)));
		}

		/// <summary>
		/// UCS22WideChar
		/// </summary>
		/// <param name="ucs2">ucs2 value</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>wchar_t</returns>
		static wchar_t UCS22WideChar(const std::wstring& ucs2) {
			auto it = ucs2.cbegin();
			it += 2; // L'\\u'
			uint16_t wch_value = 0;
			for (auto i = 0; i < 4; i++) {
				wch_value <<= 4;
				wch_value += wideChar2hex(*it);
				it++;
			}
			auto wch = static_cast<wchar_t>(wch_value);
			return wch;
		}

		/// <summary>
		/// string2wcharStr
		/// </summary>
		/// <param name="ucs2">ucs2 value</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>wchar_t</returns>
		wchar_t* string2wcharStr(std::string value) {
			CString crpr((value).c_str());
			const wchar_t* u(crpr);
			wchar_t* u2 = const_cast<LPWSTR>(u);
			return u2;
		}


	protected:
	private:
		iType mType;
	};

	/// <summary>
	/// toStdString
	/// </summary>
	/// <param name="value">value</param>
	/// <warning></warning>
	/// <include></include>
	/// <bug></bug>
	/// <returns>Converted string</returns>
	template <typename T>
	inline std::string toStdString(T value) {
		return itype::toStdString(value);
	}

}//namespace i::icore



#endif //!___MIRACLEFOREST_I_TYPE___