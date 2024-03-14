#ifndef RECORD_H
#define RECORD_H

struct punto {
	short x;
	short y;
	short z;
};

struct punto_colorato {
	struct punto punto;
	char* colore;
};

#endif