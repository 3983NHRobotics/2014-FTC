void debug(const string str, int val);
void debug_l(const string str, int val);
void debug_clear();
string msg;

void debug_l(const string str, int val) {
	if (!defined(inDebug)) {
		inDebug = true;
	}
	if (inDebug) {
		StringFormat(msg, str, val);
		writeDebugStream(msg);
	}
}

void debug_l(const string str, string val) {
	if (!defined(inDebug)) {
		inDebug = true;
	}
	if (inDebug) {
		strcat(str, val);
		writeDebugStream(str);
	}
}

void debug(const string str, int val) {
	if (!defined(inDebug)) {
		inDebug = true;
	}
	if (inDebug) {
		StringFormat(msg, str, val);
		writeDebugStreamLine(msg);
	}
}

void debug(const string str, string val) {
	if (!defined(inDebug)) {
		inDebug = true;
	}
	if (inDebug) {
		strcat(str, val);
		writeDebugStreamLine(str);
	}
}

void debug_clear() {
	clearDebugStream();
}
