void debug(const string str);
void debug_nl(const string str);
void debug_clear();

void debug(const string str) {
	if (inDebug) {
		writeDebugStream(str);
	}
}

void debug_nl(const string str) {
	if (inDebug) {
		writeDebugStreamLine(str);
	}
}

void debug_clear() {
	clearDebugStream();
}
