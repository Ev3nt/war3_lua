#include "pch.h"
#include "EasterEgg.h"

std::string GetEasterText(SYSTEMTIME& date) {
	WORD day = date.wDay;
	WORD month = date.wMonth;
	std::string text = "";

	if (day == 2	&&	month == 6	) {
		text = "~~~ Happy Birthday to Ev3nt! ~~~";
	}

	if (day == 1	&&	month == 1	) {
		text = "~~~ Happy New Year! ~~~";
	}

	if (day == 2	&&	month == 3	) {
		text = "~~~ Glory to Billy! ~~~";
	}

	if (day == 7	&&	month == 10	) {
		text = "~~~ Happy Birthday, the best president! ~~~";
	}

	if (day == 9	&&	month == 5	) {
		text = "~~~ Glory to the Red Army! ~~~";
	}

	if (day == 5	&&	month == 10	) {
		text = "~~~ Birthday of the best programming language! ~~~";
	}

	if (day == 16	&&	month == 12	) {
		text = "~~~ Happy Birthday, Warcraft III - Lua! ~~~";
	}

	if (day == 13	&&	month == 5	) {
		text = "~~~ Welcome to XGM! ~~~";
	}

	if (day == 24	&&	month == 10	) {
		text = "~~~ Three Hundred Bucks  ~~~";
	}

	if (day == 6	&&	month == 5	) {
		text = "~~~ Quro started his work...  ~~~";
	}

	if (day == 6	&&	month == 4  ) {
		text = "~~~ Kokomi's day  ~~~";
	}

	return text;
}