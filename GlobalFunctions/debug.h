void debug(const string str);
void debug_l(const string str);
void debug_clear();

void debug_l(const string str) {
	if (!defined(inDebug)) {
		inDebug = true;
	}
	if (inDebug) {
		writeDebugStream(str);
	}
}

void debug(const string str) {
	if (!defined(inDebug)) {
		inDebug = true;
	}
	if (inDebug) {
		writeDebugStreamLine(str);
	}
}

void debug_clear() {
	clearDebugStream();
}
