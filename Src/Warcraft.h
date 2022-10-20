#pragma once

namespace Warcraft {
	enum class Version : DWORD {
		NONE = 0,
		V100a = 4448,
		V101a = 4482,
		V101b = 4483,
		V102a = 4531,
		V102b = 4563,
		V103a = 4653,
		V104a = 4709,
		V104b = 4709,
		V104c = 4905,
		V105a = 4944,
		V106a = 5551,
		V107a = 5535,
		V110a = 5610,
		V111a = 5616,
		V112a = 5636,
		V113a = 5816,
		V113b = 5818,
		V114a = 5840,
		V114b = 5846,
		V115a = 5917,
		V116a = 5926,
		V117a = 5988,
		V118a = 6030,
		V119a = 6041,
		V119b = 6046,
		V120a = 6048,
		V120b = 6056,
		V120c = 6065,
		V120d = 6070,
		V120e = 6074,
		V121a = 6263,
		V121b = 6300,
		V122a = 6328,
		V123a = 6352,
		V124a = 6372,
		V124b = 6374,
		V124c = 6378,
		V124d = 6384,
		V124e = 6387,
		V125a = 6396,
		V125b = 6397,
		V126a = 6401,
		V127a = 52240,
		V127b = 7085,
		V128a = 7205,
		V128b = 7365,
		V128c = 7395,
		V128d = 7554,
		V128e = 7608,
		V128f = 7680,
	};

	VS_FIXEDFILEINFO* GetFileVersion(LPCSTR filename);
	Version GetWarcraftVersion();

	void PrintChat(LPCSTR text, float duration, DWORD color = 0xFFFFFFFF);
	DWORD GetTLSValueByIndex(UINT index);
	LPVOID ConvertHandle(UINT handle);
}