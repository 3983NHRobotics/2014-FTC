void debug(string str) {
	if (inDebug) {
		writeDebugStream(str);
	}
}

void debug_nl(string str) {
	if (inDebug) {
		writeDebugStreamLine(str);
	}
}

void debug_clear() {
	clearDebugStream();
}
